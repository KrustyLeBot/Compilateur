%{
#include "TableSymboles.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum type_op {
	ADD,
	MUL,
	SOU,
	DIV,
	COP,
	AFC,
	LOAD,
	STORE,
	EQU,
	INF,
	INFE,
	SUP,
	SUPE,
	JMP,
	JMPC,
	DOUBLE_EQU,
}type_op;


struct instr{
	char * id;
	int val1;
	int val2;
	int val3;
};

void yyerror(char *msg);
void add_line(char *id,int v1, int v2, int v3);
void var_temp();
void operation(type_op param);
void pop_main();
void print_lines();
void toBIN();
void rm_line_last();
void patch_line(int l,char* id,int v1,int v2,int v3);

struct element jean_louis[400];
int pointeur; //val dernier elem jean_louis
int portee;
int addr;
struct instr ASM[5000];
int line;



%}

%union {
	int intValue;
	char *stringValue;
}


//declaration des tokens
%token tMAIN;
%token tINT;
%token tPLUS;
%token tMOINS;
%token tSTAR;
%token tSLASH;
%token tEQU;
%token tPARL;
%token tPARR;
%token tBRL;
%token tBRR;
%token tVIR;
%token tPVR;
%token tIF;
%token tELSE;
%token tTRUE;
%token tFALSE;
%token tCONST;
%token tPRINTF;
%token <intValue> tNB;
%token <stringValue> tID;


//Priorité des opérations arithmétiques
%right tEQU
%left tPLUS tMOINS
%left tSTAR tSLASH
%right tPARL
%left tPARR

%type <intValue> patch_line;
%type <intValue> maybe_else;

%%
start : tMAIN tPARL tPARR corps {toBIN();printf("line: %d\n",line);};	//Axiome de départ

corps : tBRL {portee++;} instructions tBRR {portee --; pop_main(); print_lines();};

instructions : tINT declint instructions		//Declaration int
			| tCONST tINT declint instructions 	//Declaration const int
	 		| tID tEQU expr tPVR			{
																	int i = guete(jean_louis,$1,pointeur);
																	add_line("LOAD",1,jean_louis[pointeur].addr,-1);
																	add_line("STORE",jean_louis[i].addr,1,-1);
																	addr = pop_unique(jean_louis,pointeur);
																	pointeur--;
																}
			instructions
//Declaration expr artithmétique
			| tIF if instructions
			| 
;

declint : idequ	expr			{	
														add_line("LOAD",1,jean_louis[pointeur].addr,-1);
														add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
														addr = pop_unique(jean_louis,pointeur);
														pointeur--;
													}
				
			tVIR declint
		
		|	idequ expr tPVR			{	
														add_line("LOAD",1,jean_louis[pointeur].addr,-1);
														add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
														addr = pop_unique(jean_louis,pointeur);
														pointeur--;
													}

		| tID tPVR			{
											addr = ajout($1,INT,jean_louis,addr,portee,pointeur);
											pointeur++;
										}
		| tID tVIR declint			{
															addr = ajout($1,INT,jean_louis,addr,portee,pointeur);
															pointeur++;
														}
;

idequ : tID tEQU			{
												addr = ajout($1,INT,jean_louis,addr,portee,pointeur);
												pointeur++;										
											}
;

expr : tID			{
									var_temp();
									int i = guete(jean_louis,$1,pointeur);
									add_line("LOAD",1,jean_louis[i].addr,-1);
									add_line("STORE",jean_louis[pointeur].addr,1,-1);
								}
	 | tNB			{
								var_temp();
								add_line("AFC",1,$1,-1);
								add_line("STORE",jean_louis[pointeur].addr,1,-1);
							}
	 | tID tEQU expr			{
													int i = guete(jean_louis,$1,pointeur);
													add_line("LOAD",1,jean_louis[pointeur].addr,-1);
													add_line("STORE",jean_louis[i].addr,1,-1);
												}
	 | expr tPLUS expr	{operation(ADD);}				
	 | expr tMOINS expr	{operation(SOU);}		
	 | expr tSTAR expr	{operation(MUL);}	
	 | expr tSLASH expr {operation(DIV);}		
	 | tMOINS expr			{
												add_line("AFC",1,0,-1);
												add_line("LOAD",2,jean_louis[pointeur].addr,-1);
												add_line("SOU",1,2,-1);
												add_line("STORE",jean_louis[pointeur].addr,1,-1);
											}	
	 | tPARL expr tPARR	
	 | expr tEQU tEQU expr	{operation(DOUBLE_EQU);printf("double equ\n");}
;

if : tPARL expr tPARR			{
														add_line("LOAD",0,jean_louis[pointeur].addr,-1);
														//on fait un jump conditionel vers le else
														add_line("JCVD",99,0,-1);
													}
			patch_line corps {add_line("JMP",99,-1,-1);}
			patch_line maybe_else			{
																	if($9){
																	//si else on patch le JMP endif vers la fin du else et le JCVD before if vers le patch_line avant le else
																	patch_line($8,"JMP",line,-1,-1);
																	printf("%d\n",$8);
																	patch_line($5,"JCVD",$8,0,-1);
																	}
																	else{
																		//sinon on del le JMP a la fin du else et on patch le JCVD vers le dernier patch_line
																		rm_line_last();
																		patch_line($5,"JCVD",line,0,-1);
																	}
																}
;

maybe_else : tELSE corps {$$ = 1;}
	 | {$$ = 0;}
;

patch_line : {$$ = line-1;}
;

%%

void yyerror(char *msg) {
	printf("error: %s\n", msg);
	exit(2);
}



////////////////////////////////////////////////////////////////////////

void print_lines(){
	for(int i = 0; i < line; i++){
		if(strcmp(ASM[i].id,"LOAD")==0){
			printf("%s R%d @%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}

		else if(strcmp(ASM[i].id,"STORE")==0){
			printf("%s @%d R%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		else if(strcmp(ASM[i].id,"JCVD")==0){
			printf("%s @%d R%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		
		else if(strcmp(ASM[i].id,"AFC")==0){
			printf("%s R%d %d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		else {
			printf("%s R%d R%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
	}	
		
}
void add_line(char *id,int v1, int v2, int v3){
	int val3 = 0;
	if(v3 != -1) val3 = v3;
	struct instr tmp = {id, v1, v2, val3};
	ASM[line] = tmp;
	line ++;
}

void patch_line(int l,char* id,int v1,int v2,int v3){
	int val3 = 0;
	if(v3 != -1) val3 = v3;
	struct instr tmp = {id, v1, v2, val3};
	ASM[l] = tmp;
}

void rm_line_last(){
	ASM[line] = ASM[line+1];
	line--;
}

void var_temp(){ 
	addr = ajout("temp",INT,jean_louis,addr,portee,pointeur);
	pointeur++;
}

void operation(type_op param){
	add_line("LOAD",1,jean_louis[pointeur-1].addr,-1);
	add_line("LOAD",2,jean_louis[pointeur].addr,-1);	
	switch(param){
		case (ADD):
			add_line("ADD",1,2,-1);
			break;
		case(MUL):
			add_line("MUL",1,2,-1);
			break;
		case(SOU):
			add_line("SOU",1,2,-1);
			break;
		case(DIV):
			add_line("DIV",1,2,-1);
			break;
		case(EQU):
			add_line("MOV",1,2,-1);
			break;
		case(DOUBLE_EQU):
			add_line("EQU",1,2,-1);
			break;
	}
	add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
	addr = pop_unique(jean_louis,pointeur);
	pointeur--;
}

void pop_main(){
	pointeur = pop(jean_louis, pointeur);
	
	int tmp = 0;
	switch(jean_louis[pointeur].typeparam){
		case(INT):
			tmp = 4;
			break;
		case(CHAR):
			tmp = 1;
			break;
	}
	addr = jean_louis[pointeur].addr + tmp;
}

void toBIN(){
	FILE* fichier = NULL;
	remove("sortie.banane");
	fichier = fopen("sortie.banane", "w");

    if (fichier != NULL)
    {
		int8_t * tmp = malloc(sizeof(char));
		for(int i = 0; i < line; i++){
			if(strcmp(ASM[i].id, "STORE") == 0 || strcmp(ASM[i].id, "LOAD") == 0){
				if(strcmp(ASM[i].id, "LOAD") == 0){
				*tmp=7;
				fwrite(tmp,sizeof(int8_t), 1, fichier);

				*tmp = (int8_t) ASM[i].val1;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				
				*tmp = (int8_t) ASM[i].val2;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				
				*tmp = (int8_t) (ASM[i].val2>>8);
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "STORE") == 0){
					*tmp=8;
					fwrite(tmp,sizeof(int8_t), 1, fichier);

					*tmp = (int8_t) ASM[i].val1;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) ASM[i].val2;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) (ASM[i].val1>>8);
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
			}
			else{
				if(strcmp(ASM[i].id, "ADD") == 0){
					*tmp=1;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "MUL") == 0){
					*tmp=2;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "SOU") == 0){
					*tmp=3;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "DIV") == 0){
					*tmp=4;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "AFC") == 0){
					*tmp=6;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "MOV") == 0){
					*tmp=5;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				*tmp = (int8_t) ASM[i].val1;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				
				*tmp = (int8_t) ASM[i].val2;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				
				*tmp = (int8_t) ASM[i].val3;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
			}					
		}
		fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier sortie.banane");
    }
}
////////////////////////////////////////////////////////////////////////



int main() {
	pointeur = -1;
	portee = 0;
	addr = 400;
	line = 0;
	

	printf("      === Flex et yacc compilator ===     \n");
	printf("   ***Auteurs: Bravais J. et Wowk T.***\n");
						

	yyparse();
	return 1;
}



