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
}type_op;


void yyerror(char *msg);

struct element jean_louis[400];
int pointeur;
int portee;
int addr;
struct instr ASM[5000];
int line;


struct instr{
	char * id;
	int val1;
	int val2;
	int val3;
};

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

%%
start : tMAIN tPARL tPARR corps;	//Axiome de départ

corps : tBRL {portee++;} instructions tBRR {portee --;};

instructions : tINT declint instructions		{ printf("action1\n"); }		//Declaration int
	 		| tCONST tINT declint instructions { printf("action2\n"); }		//Declaration const int
	 		| tID tEQU expr tPVR instructions  { printf("action3\n"); }		//Declaration expr artithmétique
			//| tIF tPARL expr tPARR corps
			| 
;

declint : idequ	expr		{add_line("STORE",jean_louis[pointeur-1].addr,jean_louis[pointeur].addr);}
				
		  tVIR declint
		
		| idequ expr tPVR 				{add_line("STORE %d %d",jean_louis[pointeur-1].addr,jean_louis[pointeur].addr);}

		| tID tPVR 							{
												addr = ajout($1,INT,jean_louis,addr,portee,pointeur);
												pointeur++;
											}
		| tID tVIR declint					{
												addr = ajout($1,INT,jean_louis,addr,portee,pointeur);
												pointeur++;
											}
;

idequ : tID tEQU		{
							addr = ajout($1,INT,jean_louis,addr,portee,pointeur);
							pointeur++;										
						}
;

expr : tID									{
												var_temp();
												int i = guete(jean_louis,$1,pointeur);
												add_line("LOAD",0,jean_louis[i].addr);
												add_line("STORE",jean_louis[pointeur].addr,0);
											}
	 | tNB									{
												var_temp();
												add_line("AFC",0,$1);
												add_line("STORE",jean_louis[pointeur].addr,0);
											}
	 | tID tEQU expr 
	 | expr tPLUS expr						
	 | expr tMOINS expr		
	 | expr tSTAR expr		
	 | expr tSLASH expr		
	 | tMOINS expr	%prec tSTAR
	 | tPARL expr tPARR
;
	 
%%

void yyerror(char *msg) {
	printf("error: %s\n", msg);
	exit(2);
}

void add_line(char *id,int v1, int v2, int v3){
	struct instr tmp = {id, v1, v2, v3};
	ASM[line] = tmp;
	line ++;
}


void var_temp(){ 
	addr = ajout(NULL,INT,jean_louis,addr,portee,pointeur);
	
}

void operation(type_op param){
	add_line("LOAD",jean_louis[pointeur-1].addr);
	add_line("LOAD",jean_louis[pointeur].addr);	
	switch(param){
		case (ADD):
			add_line("ADD",);
			break;
		case(MUL):
			add_line("MUL",);
			break;
		case(SOU):
			add_line("SOU",);
			break;
		case(DIV):
			add_line("DIV",);
			break;
		case(EQU):
			add_line("MOV",);
			break;
	}
	add_line("STORE",jean_louis[pointeur-1].addr);
	addr = pop_unique(jean_louis,pointeur);
}

void pop_main(){
	pointeur = pop(jean_louis, pointeur);
	
	int tmp = 0;
	switch(jean_louis[pointeur].type){
		case(INT):
			tmp = 4;
			break;
		case(CHAR):
			tmp = 1;
			break;
	}
	addr = jean_louis[pointeur].addr + tmp;
}


int main() {
	pointeur = -1;
	portee = 0;
	addr = 400;
	line = 0;
	
	add_line("wololozaezaezaaazzeaezaezaezaeazezaeaz");
	printf("truc : %s\n",ASM[0]);

	printf("     === Salam alekoum compilator ===     \n");
	printf("       ***Auteurs : Le Djo et Jacky***\n");
						

	yyparse();
	return 1;
}



