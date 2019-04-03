yacc -d syntaxe.y
flex compiler.l
gcc -o compiler y.tab.c lex.yy.c TableSymboles.c -lg -ll
