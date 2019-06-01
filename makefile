compiler: lex.yy.o y.tab.o TableSymboles.o Fonctions.o
	gcc -o compiler y.tab.o lex.yy.o TableSymboles.o Fonctions.o -lg -ll
	rm *.o
	rm y.tab.c
	rm lex.yy.c

lex.yy.c: compiler.l
	flex compiler.l

y.tab.c: syntaxe.y
	yacc -d syntaxe.y
