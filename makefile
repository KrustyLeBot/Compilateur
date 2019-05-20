compiler: lex.yy.o y.tab.o TableSymboles.o
	gcc -o compiler y.tab.o lex.yy.o TableSymboles.o -lg -ll

lex.yy.c: compiler.l
	flex compiler.l

y.tab.c: syntaxe.y
	yacc -d syntaxe.y
