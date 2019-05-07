/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tMAIN = 258,
    tINT = 259,
    tPLUS = 260,
    tMOINS = 261,
    tSTAR = 262,
    tSLASH = 263,
    tDEQU = 264,
    tEQU = 265,
    tPARL = 266,
    tPARR = 267,
    tBRL = 268,
    tBRR = 269,
    tVIR = 270,
    tPVR = 271,
    tIF = 272,
    tELSE = 273,
    tTRUE = 274,
    tFALSE = 275,
    tCONST = 276,
    tPRINTF = 277,
    tNB = 278,
    tID = 279
  };
#endif
/* Tokens.  */
#define tMAIN 258
#define tINT 259
#define tPLUS 260
#define tMOINS 261
#define tSTAR 262
#define tSLASH 263
#define tDEQU 264
#define tEQU 265
#define tPARL 266
#define tPARR 267
#define tBRL 268
#define tBRR 269
#define tVIR 270
#define tPVR 271
#define tIF 272
#define tELSE 273
#define tTRUE 274
#define tFALSE 275
#define tCONST 276
#define tPRINTF 277
#define tNB 278
#define tID 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 54 "syntaxe.y" /* yacc.c:1909  */

	int intValue;
	char *stringValue;

#line 107 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
