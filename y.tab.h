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
    tINTSTAR = 259,
    tINT = 260,
    tPLUS = 261,
    tMOINS = 262,
    tSTAR = 263,
    tSLASH = 264,
    tDEQU = 265,
    tEQU = 266,
    tINF = 267,
    tSUP = 268,
    tINFE = 269,
    tSUPE = 270,
    tPARL = 271,
    tPARR = 272,
    tBRL = 273,
    tBRR = 274,
    tVIR = 275,
    tPVR = 276,
    tQM = 277,
    tDP = 278,
    tIF = 279,
    tWHILE = 280,
    tFOR = 281,
    tELSE = 282,
    tTRUE = 283,
    tFALSE = 284,
    tCONST = 285,
    tPRINTF = 286,
    tAND = 287,
    tOR = 288,
    tESPER = 289,
    tRETURN = 290,
    tNB = 291,
    tID = 292
  };
#endif
/* Tokens.  */
#define tMAIN 258
#define tINTSTAR 259
#define tINT 260
#define tPLUS 261
#define tMOINS 262
#define tSTAR 263
#define tSLASH 264
#define tDEQU 265
#define tEQU 266
#define tINF 267
#define tSUP 268
#define tINFE 269
#define tSUPE 270
#define tPARL 271
#define tPARR 272
#define tBRL 273
#define tBRR 274
#define tVIR 275
#define tPVR 276
#define tQM 277
#define tDP 278
#define tIF 279
#define tWHILE 280
#define tFOR 281
#define tELSE 282
#define tTRUE 283
#define tFALSE 284
#define tCONST 285
#define tPRINTF 286
#define tAND 287
#define tOR 288
#define tESPER 289
#define tRETURN 290
#define tNB 291
#define tID 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 75 "syntaxe.y" /* yacc.c:1909  */

	int intValue;
	char *stringValue;

#line 133 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (FILE* input);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
