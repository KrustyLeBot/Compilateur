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
	yyparse();
	struct element [256]; 
	return 1;
}



typedef struct element {
	char *nom;
	char *type;
	int portee;
};





/*

void Push(struct Table ** t, char *nomparam , int valeurparam , int porteeparam){
	struct Table *element = malloc(sizeof(struct Table));
	if (!element) exit(1); //Si l'allocation a échoué
	
	(element -> nom) = malloc(sizeof(nomparam));
	*(element -> nom) = *nomparam; 
	element -> valeur = valeurparam;
	element -> portee = porteeparam;
	element -> prec = *t;
	*t = element;	
} 

*/





