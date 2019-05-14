compiler: y.tab.o lex.yy.o TableSymboles.o
	gcc -o compiler y.tab.o lex.yy.o TableSymboles.o -lg -ll

y.tab.c: syntaxe.y
	yacc -d syntaxe.y

lex.yy.c: compiler.l
	flex compiler.l
