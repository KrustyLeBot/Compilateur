%{
#include "y.tab.h"	
%}

%%


[ \t\n]+	;

[/][*][A-Za-z][A-Za-z0-9_ ]*[*][/]	;
"main" return tMAIN;
"int*" return tINTSTAR;
"int" return tINT;
"+" return tPLUS;
"-" return tMOINS;
"*" return tSTAR;
"/" return tSLASH;
"==" return tDEQU;
"=" return tEQU;
"<" return tINF;
">" return tSUP;
"<=" return tINFE;
">=" return tSUPE;
"(" return tPARL;
")" return tPARR;
"{" return tBRL;
"}" return tBRR;
"," return tVIR;
";" return tPVR;
"?" return tQM;
":" return tDP;
"if" return tIF;
"while" return tWHILE;
"for" return tFOR;
"else" return tELSE;
"True" return tTRUE;
"False" return tFALSE;
"const" return tCONST;
"printf" return tPRINTF;
"&&" return tAND;
"||" return tOR;
"&" return tESPER;
"balkany" printf("Je suis l'homme le plus honnete du monde\n");
"return" return tRETURN;
[0-9]+  {yylval.intValue = atoi(yytext); return tNB;}
[A-Za-z][A-Za-z0-9_]* {yylval.stringValue = strdup(yytext); return tID;}
