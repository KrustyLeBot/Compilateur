compiler: y.tab.c lex.yy.c TableSymboles.o
	gcc -o compiler y.tab.c lex.yy.c TableSymboles.o -lg -ll

TableSymboles.o: TableSymboles.c
	gcc -o TableSymboles.o -c TableSymboles.c

y.tab.c: syntaxe.y
	yacc -d syntaxe.y

lex.yy.c: compiler.l
	flex compiler.l
