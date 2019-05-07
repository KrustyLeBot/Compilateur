%{
#include "y.tab.h"	
%}

%%


[ \t\n]+	;

"main" return tMAIN;
"int" return tINT;
"+" return tPLUS;
"-" return tMOINS;
"*" return tSTAR;
"/" return tSLASH;
"==" return tDEQU
"=" return tEQU;
"(" return tPARL;
")" return tPARR;
"{" return tBRL;
"}" return tBRR;
"," return tVIR;
";" return tPVR;
"if" return tIF;
"else" return tELSE;
"True" return tTRUE;
"False" return tFALSE;
"const" return tCONST;
"printf" return tPRINTF;
"Balkany" printf("Je suis l'homme le plus honnete du monde\n");
[0-9]+  {yylval.intValue = atoi(yytext); return tNB;}
[A-Za-z][A-Za-z0-9_]* {yylval.stringValue = strdup(yytext); return tID;}
