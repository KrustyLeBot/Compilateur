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
"=" return tEQU;
"(" return tPARL;
")" return tPARR;
"{" return tBRL;
"}" return tBRR;
"," return tVIR;
";" return tPVR;
"const" return tCONST;
"printf" return tPRINTF;
[0-9]+ return tNB;
[A-Za-z][A-Za-z0-9_]* return tID;
