%{
#include "TSonga.h"
#include <stdio.h>
#include <stdlib.h>

struct element jean_louis[400];
int pointeur;
int portee;
int last_addr;

%}


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
%token tNB;
%token tID;


//Priorité des opérations arithmétiques
%right tEQU
%left tPLUS tMOINS
%left tSTAR tSLASH
%right tPARL
%left tPARR

%%
start : tMAIN tPARL tPARR tBRL instruction tBRR;	//Axiome de départ

instruction : tINT declint instruction		{ printf("action1\n"); }		//Declaration int
	 		| tCONST tINT declint instruction { printf("action2\n"); }		//Declaration const int
	 		| tID tEQU expr tPVR instruction  { printf("action3\n"); }		//Declaration expr artithmétique
			| 
;


declint : tID tEQU expr tVIR declint
		| tID tEQU expr tPVR
		| tID tPVR 
		| tID tVIR declint
;

expr : tID
	 | tNB
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



int main() {
	pointeur = -1;
	portee = 0;
	last_addr = 400;
	

	struct element lbd40 = {"abc", "char*", 400, 0};

	pointeur = push(jean_louis, pointeur, lbd40);
	printf("%d\n", pointeur);

	printf("var:   %s\n", jean_louis[pointeur].nom);
	
	int pos = guete(jean_louis, "abc", pointeur);
	printf("%d\n", pos);

	pointeur = pop(jean_louis, pointeur);
	printf("%d\n", pointeur);

	yyparse();
	return 1;
}



