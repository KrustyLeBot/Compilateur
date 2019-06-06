%{
#include "TableSymboles.h"
#include "Fonctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int yylex();
extern FILE *yyin;
//Types d'opérations
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
	AND,
	OR,
}type_op;
//Structure d'une instructions
struct instr{
	char * id;
	int val1;
	int val2;
	int val3;
};
//Definition des fonctions
int yyerror(FILE* input,char *msg);//fct error de base 
int yyerror2(char *msg);//fct erreur manuelle
int yywarning(char *msg);
void add_line(char *id,int v1, int v2, int v3);
void var_temp();
int ajout(char *nom_tmp,type typeparam_tmp,struct element *tab_tmp,int addr_tmp,int portee_tmp,int pointeur_tmp,int context_tmp);
void operation(type_op param);
void pop_main();
void print_lines();
void toBIN();
void rm_line_last();
void patch_line(int l,char* id,int v1,int v2,int v3);
//Definition variables globales
struct element jean_louis[400];
int pointeur; //val dernier elem jean_louis
int portee; //portee d'une variable
int context; //portee d'une fonction
int context_courant; //context courant lors de l'execution
int context_main; //context du main
int addr; //addresse de la prochaine varibale
struct instr ASM[5000]; //Tableau d'instruction assembleur
int line; //Ligne de la derniere instr
struct fonc tab_fct[50];//tab des fct
int line_fct;//nombre de def de fct
int addr_max_fct_prec;//addr max qui sera tapé par les fct avant
int error_count;//compteur d'erreur
int warn_count;//compteur de warning
%}
//Declaration types de retour
%union {
	int intValue;
	char *stringValue;
}
%parse-param{FILE* input}
//Declaration des tokens
%token tMAIN;
%token tINTSTAR;
%token tINT;
%token tPLUS;
%token tMOINS;
%token tSTAR;
%token tSLASH;
%token tDEQU;
%token tEQU;
%token tINF;
%token tSUP;
%token tINFE;
%token tSUPE;
%token tPARL;
%token tPARR;
%token tBRL;
%token tBRR;
%token tVIR;
%token tPVR;
%token tQM;
%token tDP;
%token tIF;
%token tWHILE;
%token tFOR;
%token tELSE;
%token tTRUE;
%token tFALSE;
%token tCONST;
%token tPRINTF;
%token tAND;
%token tOR;
%token tESPER;
%token tRETURN;
%token <intValue> tNB;
%token <stringValue> tID;
//Priorité des opérations arithmétiques
%right tEQU
%left tPLUS tMOINS
%left tSTAR tSLASH
%right tPARL
%left tPARR
//Definition des retour de chaque axiome
%type <intValue> expr;
%type <intValue> patch_line;
%type <intValue> maybe_else;
%type <intValue> decl_parameters;
%type <intValue> parameters;
%%
//Axiome de départ
start : {add_line("JMP",99,0,-1);} start_fonctions patch_line main {patch_line(0,"JMP",$3+1,0,-1);YYACCEPT;pop_main();portee--;}
;
start_fonctions: fct start_fonctions
		| 
;
//functions
fct : tINT tID  {
					char str[150];
					if(exist(tab_fct,line_fct,$2)){
						sprintf(str,"Two functions are defined under the same name: %s",$2);
						yyerror2(str);
					}
					else{
						context_courant = context;
                   		//get the adress to start the var
						addr = addr_max_fct_prec;
                	}
				}
  tPARL decl_parameters {
							//store fct
  							add_fct(tab_fct,$5,$2,line_fct,line,context,addr-4-$5*4);
  							line_fct++;
                       		//save return @ from reg 15
							addr = ajout("_RET@_",INT,jean_louis,addr,portee+1,pointeur,context_courant);
							pointeur++;
							add_line("STORE",jean_louis[pointeur].addr,15,-1);
                        }
  tPARR patch_line corps_fct patch_line {
                                        	//Load addr de retour
                                        	int j = guete(jean_louis,"_RET@_",pointeur,context_courant);
                                        	if(j==-1) {yyerror2("var not defined");}
                                        	add_line("LOAD",15,jean_louis[j].addr,-1);
                                        	add_line("RET",15,0,-1); //JUMP vers @ retour
                                        	pop_main();//pop des vars sauf les parametres et @retour
                                        	context++;
                                        }
;
decl_parameters : decl_parameters tVIR decl_parameters {$$ = $1 + $3;}
		| tINT tID {$$ = 1;addr = ajout($2,INT,jean_louis,addr,portee+1,pointeur,context_courant);pointeur++;}
		| {$$ = 0;}
;
main : tMAIN tPARL tPARR patch_line {addr = addr_max_fct_prec; context_courant = context; context++; context_main = context_courant;} corps_fct 
;
//corps
corps : tBRL {portee++;} instructions tBRR {pop_main();portee --;} //a chaque bracket fermant, on depop les variables et on diminue la portée
;
//corps fct => on ne depop pas immediatement
corps_fct : tBRL {portee++;} instructions tBRR
;
//instructions du corps
instructions : tINT declint instructions		//Declaration int
			| tCONST tINT declint instructions 	//Declaration const int
			| tINTSTAR declintstar instructions		//Declaration int *
	 		| tID tEQU expr tPVR	{	// b = expr;
										int i = guete(jean_louis,$1,pointeur,context_courant);
                                  		if(i==-1) {yyerror2("var not defined");}
										if(jean_louis[i].typeparam == PTR){//si la var est un pointeur => on modif ce vers quoi on pointe 
											jean_louis[i].addr = $3;
											addr = pop_unique(jean_louis,pointeur);
											pointeur--;
										}
										else{//sinon
											add_line("LOAD",1,jean_louis[pointeur].addr,-1);
											add_line("STORE",jean_louis[i].addr,1,-1);
											addr = pop_unique(jean_louis,pointeur);
											pointeur--;
											}
										}
			instructions
			| tSTAR tID tEQU expr tPVR	{	//*b = expr;
											int i = guete(jean_louis,$2,pointeur,context_courant);
                                    		if(i==-1) {yyerror2("var not defined");}
											add_line("LOAD",1,jean_louis[pointeur].addr,-1);
											add_line("STORE",jean_louis[i].addr,1,-1);
											addr = pop_unique(jean_louis,pointeur);
											pointeur--;
										}
			instructions
			| tIF if instructions //if
			| tWHILE while instructions //while
			| tFOR for instructions //for
			|	appel_fct tPVR {pop_unique(jean_louis,pointeur);} instructions //fct
			|
			| tRETURN expr tPVR {	//retour de fct
			                    	//put return value in register 14
			                     	add_line("LOAD",14,jean_louis[pointeur].addr,-1);
			                     	addr = pop_unique(jean_louis,pointeur);
			                    	pointeur--;
			                   	}
			| error tPVR
;
//appel fct
appel_fct : tID patch_line 	{
                            	//store return @ in register 15
                            	add_line("AFC",15,99,-1);
                           	} 
    tPARL parameters tPARR 	{
								//get start_addr fct & param addr
								int m = get_start_line(tab_fct,line_fct,$1);
								int n = get_param_addr(tab_fct,line_fct,$1);
								int o = get_param(tab_fct,line_fct,$1);
								char str[150];
								if($5<o){
									sprintf(str,"Not enough parameters gaven for the function: %s",$1);
									yyerror2(str);
								}
								else if($5>o){
									sprintf(str,"Too much parameters gaven for the function: %s",$1);
									yyerror2(str);
								}
															
								//transfert des param puis depop var temp
							    for(int q=0;q<$5;q++){
									add_line("LOAD",1,addr-4,-1);
									add_line("STORE",(n+$5*4)-q*4,1,-1);
							    	addr = pop_unique(jean_louis,pointeur);
							    	pointeur--;
							    }
								//Jump to the called function
								add_line("JMP",m,0,-1);
								//get return value from register 14 and store it in a temp var
								var_temp();															
							    add_line("STORE",jean_louis[pointeur].addr,14,-1);
							    patch_line($2+1,"AFC",15,line-1,-1);
							}																
;
parameters : parameters tVIR parameters {$$ = $1 + $3;}
		| expr {$$ = 1;}
		| {$$ = 0;}
;
//declaration int
declint : idequ	expr	{	//int b = expr, a = expr...
							add_line("LOAD",1,jean_louis[pointeur].addr,-1);
							add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
							addr = pop_unique(jean_louis,pointeur);
							pointeur--;
						}
				
			tVIR declint
		
		|	idequ expr tPVR	{	//int b = expr;
								add_line("LOAD",1,jean_louis[pointeur].addr,-1);
								add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
								addr = pop_unique(jean_louis,pointeur);
								pointeur--;
							}
		| tID tPVR	{	//int a;
						addr = ajout($1,INT,jean_louis,addr,portee,pointeur, context_courant);
						pointeur++;
					}
		| tID tVIR declint	{ 	//int a, b...
								addr = ajout($1,INT,jean_louis,addr,portee,pointeur, context_courant);
								pointeur++;
							}
;
//declaration int *
declintstar : idequstar	expr	{	
									jean_louis[pointeur-1].addr = $2;
									addr = pop_unique(jean_louis,pointeur);
									pointeur--;
								}
				
			tVIR declintstar
		
		|	idequstar expr tPVR	{	
									jean_louis[pointeur-1].addr = $2;
									addr = pop_unique(jean_louis,pointeur);
									pointeur--;
								}
		| tID tPVR	{
						ajout($1,PTR,jean_louis,0,portee,pointeur, context_courant);
						pointeur++;
					}
		| tID tVIR declintstar	{
									ajout($1,PTR,jean_louis,0,portee,pointeur, context_courant);
									pointeur++;
								}
;
//creation int
idequ : tID tEQU	{
						addr = ajout($1,INT,jean_louis,addr,portee,pointeur, context_courant);
						pointeur++;										
					}
;
//creation int *
idequstar : tID tEQU	{
							ajout($1,PTR,jean_louis,0,portee,pointeur, context_courant);
							pointeur++;										
						}
;
//Expressions
expr : appel_fct {$$=0;} //fct 
  | tID		{ 	//nom de var
				var_temp();
				int i = guete(jean_louis,$1,pointeur,context_courant);
                if(i==-1) {yyerror2("var not defined");}
				add_line("LOAD",1,jean_louis[i].addr,-1);
				add_line("STORE",jean_louis[pointeur].addr,1,-1);
			}
	 | tNB		{ 	//chiffres
					var_temp();
					add_line("AFC",1,$1,-1);
					add_line("STORE",jean_louis[pointeur].addr,1,-1);
				}
	 | tID tEQU expr	{ 	// a = expr
							int i = guete(jean_louis,$1,pointeur,context_courant);
                          	if(i==-1) {yyerror2("var not defined");}
							add_line("LOAD",1,jean_louis[pointeur].addr,-1);
							add_line("STORE",jean_louis[i].addr,1,-1);
						}
	 | tSTAR tID	{ 	// *b renvoit val addr dans b
						var_temp();
						int i = guete(jean_louis,$2,pointeur,context_courant);
                  		if(i==-1) {yyerror2("var not defined");}
						add_line("LOAD",1,jean_louis[i].addr,-1);
						add_line("STORE",jean_louis[pointeur].addr,1,-1);
					}
	 | tESPER tID	{ 	// &a revoit addr de a
						var_temp();
						int i = guete(jean_louis,$2,pointeur,context_courant);
                  		if(i==-1) {yyerror2("var not definedf");}
						$$ = jean_louis[i].addr;
					}
	 | expr tPLUS expr	{operation(ADD);} //expr + expr	
	 | expr tMOINS expr	{operation(SOU);}	//expr - expr
	 | expr tSTAR expr	{operation(MUL);}	//expr * expr
	 | expr tSLASH expr {operation(DIV);}	//expr / expr
	 | tMOINS expr	{ 	// -expr
						add_line("AFC",1,0,-1);
						add_line("LOAD",2,jean_louis[pointeur].addr,-1);
						add_line("SOU",1,2,-1);
						add_line("STORE",jean_louis[pointeur].addr,1,-1);
					}	
	 | tPARL expr tPARR {$$ = $2;} //(expr)
	 | expr tDEQU expr {operation(DOUBLE_EQU);}//expr == expr
	 | tPARL expr tDEQU expr tPARR {operation(DOUBLE_EQU);}//(expr == expr)
	 | expr tINF expr {operation(INF);} //expr < expr
	 | expr tINFE expr {operation(INFE);} //expr <= expr
	 | expr tSUP expr {operation(SUP);} //expr > expr
	 | expr tSUPE expr {operation(SUPE);} //expr >= expr
	 | expr tAND expr	{	//expr && expr
							add_line("LOAD",1,jean_louis[pointeur-1].addr,-1);
							add_line("LOAD",2,jean_louis[pointeur].addr,-1);	
							add_line("AFC",3,1,-1);//R3 = 1
							add_line("EQU",1,3,-1);//R1 = (R1 == 1)
							add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
							add_line("EQU",2,3,-1);//R2 = (R2 == 1)
							add_line("STORE",jean_louis[pointeur].addr,2,-1);
							operation(AND);
						}
	 | expr tOR expr 	{	//expr || expr
							add_line("LOAD",1,jean_louis[pointeur-1].addr,-1);
							add_line("LOAD",2,jean_louis[pointeur].addr,-1);	
							add_line("AFC",3,1,-1);//R3 = 1
							add_line("EQU",1,3,-1);//R1 = (R1 == 1)
							add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
							add_line("EQU",2,3,-1);//R2 = (R2 == 1)
							add_line("STORE",jean_louis[pointeur].addr,2,-1);
							operation(OR);
						}
	 | tPARL expr tDEQU expr tPARR tQM	{ 	//ternary expression
	 										//on fait un jump conditionel vers la partie apres les 2 pts
	 										operation(DOUBLE_EQU);
	 										add_line("LOAD",0,jean_louis[pointeur].addr,-1);
	 										add_line("JCMP",99,0,-1);
	 										addr = pop_unique(jean_louis,pointeur);
	 										pointeur--;
	 									}
		patch_line expr {add_line("JMP",99,-1,-1);}//apres 1ere partie, on jump a la fin
		patch_line tDP patch_line {addr = pop_unique(jean_louis,pointeur);pointeur--;} expr	{
																								patch_line($11,"JMP",line,0,-1);
																								patch_line($8,"JCMP",$13+1,0,-1);
																							}
;
if : tPARL expr tPARR	{
							add_line("LOAD",0,jean_louis[pointeur].addr,-1);
							//on fait un jump conditionel vers le else
							add_line("JCMP",99,0,-1);
							addr = pop_unique(jean_louis,pointeur);
							pointeur--;
						}
			patch_line corps {add_line("JMP",99,-1,-1);}
			patch_line maybe_else	{
										if($9){
										//si else on patch le JMP endif vers la fin du else et le JCMP before if vers le patch_line avant le else
										patch_line($8,"JMP",line,0,-1);
										patch_line($5,"JCMP",$8+1,0,-1);
										}
										else{
											//sinon on del le JMP a la fin du else et on patch le JCMP vers le dernier patch_line
											rm_line_last();
											patch_line($5,"JCMP",line,0,-1);
										}
									}
;
maybe_else : tELSE tIF if {$$ = 1;} //else if
	 | tELSE corps {$$ = 1;} //else classique
	 | {$$ = 0;} //pas de else
;
while : patch_line tPARL expr tPARR		{
											add_line("LOAD",0,jean_louis[pointeur].addr,-1);
											//on fait un jump conditionel vers la fin du while
											add_line("JCMP",99,0,-1);
											addr = pop_unique(jean_louis,pointeur);
											pointeur--;
										}
			patch_line corps {add_line("JMP",99,-1,-1);}
			patch_line 	{
							//on patch le JCMP post while vers la ligne apres le corps et le JMP de fin de while vers la ligne au dessus de la condition pour pouvoir la reevaluer
							patch_line($9,"JMP",$1+1,0,-1);
							patch_line($6,"JCMP",$9+1,0,-1);
						}
;
// for(int i = expr;i<10;i=i+1)
for : tPARL tINT idequ expr 	{
									//creation du int temporaire
									add_line("LOAD",1,jean_louis[pointeur].addr,-1);
									add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
									addr = pop_unique(jean_louis,pointeur);
									pointeur--;			
								}
			tPVR patch_line expr 	{ 
										add_line("LOAD",0,jean_louis[pointeur].addr,-1);
										//on fait un jump conditionel vers la fin du for
										add_line("JCMP",99,0,-1);
										addr = pop_unique(jean_louis,pointeur);
										pointeur--;
									}
			patch_line tPVR  expr tPARR corps {add_line("JMP",99,-1,-1);}
			patch_line	{
							//on patch le JCMP post for vers la ligne apres le corps et le JMP de fin de for vers la ligne au dessus de la condition pour pouvoir la reevaluer
							patch_line($16,"JMP",$7+1,0,-1);
							patch_line($10,"JCMP",$16+1,0,-1);
						}
;
//fct pour revoyer les numero de ligne a patcher
patch_line : {$$ = line-1;}
;
%%
int yyerror(FILE* input,char *msg) {
	printf("Error: %s\n", msg);
	error_count++;
	return 0;
}
int yyerror2(char *msg) {
	printf("Error: %s\n", msg);
	error_count++;
	return 0;
}
int yywarning(char *msg) {
	printf("Warning: %s\n", msg);
	warn_count++;
	return 0;
}
////////////////////////////////////////////////////////////////////////
//Affichage des lignes d'assembleur
void print_lines(){
	for(int i = 0; i < line; i++){
		printf("%d: ",i);
		if(strcmp(ASM[i].id,"LOAD")==0){
			printf("%s R%d @%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		else if(strcmp(ASM[i].id,"STORE")==0){
			printf("%s @%d R%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		else if(strcmp(ASM[i].id,"JCMP")==0){
			printf("%s @%d R%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		else if(strcmp(ASM[i].id,"JMP")==0){
			printf("%s @%d\n", ASM[i].id,ASM[i].val1);
		}
		else if(strcmp(ASM[i].id,"RET")==0){
			printf("%s R%d\n", ASM[i].id,ASM[i].val1);
		}
		else if(strcmp(ASM[i].id,"AFC")==0){
			printf("%s R%d %d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		else {
			printf("%s R%d R%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
	}	
}
//Ajout ligne assembleur
void add_line(char *id,int v1, int v2, int v3){
	int val3 = 0;
	if(v3 != -1) val3 = v3;
	struct instr tmp = {id, v1, v2, val3};
	ASM[line] = tmp;
	line ++;
}
//Patch ligne assembleur
void patch_line(int l,char* id,int v1,int v2,int v3){
	int val3 = 0;
	if(v3 != -1) val3 = v3;
	struct instr tmp = {id, v1, v2, val3};
	ASM[l] = tmp;
}
//Suppr derniere ligne assembleur
void rm_line_last(){
	ASM[line] = ASM[line+1];
	line--;
}
//Creation d'une variable temporaire
void var_temp(){ 
	addr = ajout("temp",INT,jean_louis,addr,portee,pointeur,context_courant);
	pointeur++;
	addr_max_fct_prec+=4;
}
//creation d'une var classique
int ajout(char *nom_tmp,type typeparam_tmp,struct element *tab_tmp,int addr_tmp,int portee_tmp,int pointeur_tmp,int context_tmp){
	addr_max_fct_prec+=4;
	if(strcmp(nom_tmp,"temp") != 0)	printf("context: %d, var: %s, @addr: %d\n",context_tmp,nom_tmp,addr_tmp);
	return ajout_var(nom_tmp,typeparam_tmp,tab_tmp,addr_tmp,portee_tmp,pointeur_tmp,context_tmp);
}
//Operations assembleur
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
		case(INF):
			add_line("INF",1,2,-1);
			break;
		case(INFE):
			add_line("INFE",1,2,-1);
			break;
		case(SUP):
			add_line("SUP",1,2,-1);
			break;
		case(SUPE):
			add_line("SUPE",1,2,-1);
			break;
		case(AND):
			add_line("EQU",1,2,-1);//R1 = (R1 == R2)
			break;
		case(OR):
			add_line("AFC",3,1,-1);//R3 = 1
			add_line("ADD",1,2,-1);//R1 = R1 + R2
			add_line("SUPE",1,3,-1);//R1 = (R1 >= 1)
			break;
	}
	add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
	addr = pop_unique(jean_louis,pointeur);
	pointeur--;
}
//depop toutes les var de meme portee
void pop_main(){
	pointeur = pop(jean_louis, pointeur, portee, context_courant);
	
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
//Transforme le tableau d'assembleur en un fichier binaire
void toBIN(){
	FILE* fichier = NULL;
	fichier = fopen("sortie.banane", "w");
    	if (fichier != NULL)
    	{
		int8_t * tmp = malloc(sizeof(char));
		for(int i = 0; i < line; i++){
			if(strcmp(ASM[i].id, "STORE") == 0 || strcmp(ASM[i].id, "LOAD") == 0 || strcmp(ASM[i].id, "JMP") == 0 || strcmp(ASM[i].id, "JCMP") == 0){
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
				if(strcmp(ASM[i].id, "JMP") == 0){
					*tmp=14;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
					*tmp = (int8_t) ASM[i].val1;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) ASM[i].val2;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) (ASM[i].val1>>8);
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "JCMP") == 0){
					*tmp=15;
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
				if(strcmp(ASM[i].id, "EQU") == 0){
					*tmp=9;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "INF") == 0){
					*tmp=10;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "INFE") == 0){
					*tmp=11;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "SUP") == 0){
					*tmp=12;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "SUPE") == 0){
					*tmp=13;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "RET") == 0){
					*tmp=21;
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
		
		//ecriture de fin de fichier
		*tmp = 255;
		fwrite(tmp,sizeof(int8_t), 1, fichier);
		fwrite(tmp,sizeof(int8_t), 1, fichier);
		fwrite(tmp,sizeof(int8_t), 1, fichier);
		fwrite(tmp,sizeof(int8_t), 1, fichier);
		fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur
        printf("Impossible d'ouvrir le fichier sortie.banane");
    }
}
////////////////////////////////////////////////////////////////////////
int main() {
	remove("sortie.banane");//on del le fichier de sortie si deja existant
	pointeur = -1; //derniere var
	portee = 0; //portee actuelle
  context = 0;
	addr = 0; //addr prochaine var
	line = 0; //ligne prochaine instr
	line_fct = 0; //ligne prochaine fonction
	addr_max_fct_prec = 0;
	//get the input file
	FILE* input = NULL;
	input = fopen("input.c", "r");
    if (input != NULL)
    { 
		printf("      === Flex et Yacc compilator ===\n");
		printf("   ***Auteurs: Bravais J. et Wowk T.***\n\n");
		
		yyin = input;
		do
		{
			yyparse(input); //Parsing the file
		}while(!feof(yyin));
		fclose(input);
		printf("\nTotal of %d warning during compilation\n",warn_count);
		if(error_count==0){
			print_lines(); 
			toBIN();
			printf("      	=== FIN DE COMPILATION ===\n");	
			printf("***python Interpret.py pour l'interpreteur***\n");
		}
		else{
			printf("Total of %d error during compilation\n",error_count);
		}
	}
	else
	{
		printf("No input file found for the compilator\n");
	}
	return 1;
}

