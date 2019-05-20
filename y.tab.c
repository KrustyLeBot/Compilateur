/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntaxe.y" /* yacc.c:339  */

#include "TableSymboles.h"
#include <stdio.h>
#include <stdlib.h>

//Types d'opérations
typedef enum type_op {
	ADD,
	MUL,
	SOU,
	DIV,
	COP,
	AFC,
	LOAD,
	STORE,
	EQU,
	INF,
	INFE,
	SUP,
	SUPE,
	JMP,
	JMPC,
	DOUBLE_EQU,
	AND,
	OR,
}type_op;


//Structure d'une instructions
struct instr{
	char * id;
	int val1;
	int val2;
	int val3;
};

//Definition des fonctions
void yyerror(char *msg);
void add_line(char *id,int v1, int v2, int v3);
void var_temp();
void operation(type_op param);
void pop_main();
void print_lines();
void toBIN();
void rm_line_last();
void patch_line(int l,char* id,int v1,int v2,int v3);

//Definition variables globales
struct element jean_louis[400];
int pointeur; //val dernier elem jean_louis
int portee; //portéee d'une variable
int addr; //addresse de la prochaine varibale
struct instr ASM[5000]; //Tableau d'instruction assembleur
int line; //Ligne de la derniere instr




#line 125 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    tNB = 290,
    tID = 291
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
#define tNB 290
#define tID 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "syntaxe.y" /* yacc.c:355  */

	int intValue;
	char *stringValue;

#line 242 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 259 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   123,   123,   126,   127,   128,   129,   129,
     145,   145,   153,   154,   155,   156,   157,   161,   161,   170,
     177,   181,   187,   187,   195,   201,   205,   212,   219,   226,
     232,   237,   242,   248,   253,   254,   255,   256,   257,   263,
     264,   265,   266,   267,   268,   269,   279,   289,   297,   298,
     289,   304,   311,   304,   326,   327,   328,   331,   338,   331,
     347,   354,   361,   347,   370
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tMAIN", "tINTSTAR", "tINT", "tPLUS",
  "tMOINS", "tSTAR", "tSLASH", "tDEQU", "tEQU", "tINF", "tSUP", "tINFE",
  "tSUPE", "tPARL", "tPARR", "tBRL", "tBRR", "tVIR", "tPVR", "tQM", "tDP",
  "tIF", "tWHILE", "tFOR", "tELSE", "tTRUE", "tFALSE", "tCONST", "tPRINTF",
  "tAND", "tOR", "tESPER", "tNB", "tID", "$accept", "start", "corps",
  "$@1", "instructions", "$@2", "$@3", "declint", "$@4", "declintstar",
  "$@5", "idequ", "idequstar", "expr", "$@6", "$@7", "$@8", "if", "$@9",
  "$@10", "maybe_else", "while", "$@11", "$@12", "for", "$@13", "$@14",
  "$@15", "patch_line", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -17

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    -9,     8,    -4,  -111,     0,  -111,  -111,    96,  -111,
     -22,   -13,   -11,    10,  -111,    14,    51,    50,    45,    -1,
      96,    47,    55,    96,    47,    57,    47,    96,    96,    61,
      66,    96,   -13,    47,  -111,  -111,   -22,  -111,  -111,    47,
      42,    47,    43,  -111,    73,   121,  -111,   -13,  -111,  -111,
     131,    47,   159,  -111,  -111,    47,    52,  -111,    96,   172,
    -111,    25,  -111,   200,  -111,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,  -111,    47,    47,    67,  -111,
    -111,    76,   213,  -111,   241,    75,    47,  -111,  -111,    47,
    -111,   269,    25,    25,    79,    79,   269,   269,   269,   269,
     269,   269,   269,   -22,   -13,  -111,  -111,  -111,   269,    96,
     253,  -111,  -111,    96,     0,  -111,    77,  -111,    81,  -111,
    -111,     0,  -111,  -111,  -111,  -111,    47,  -111,    72,  -111,
     269,    47,   -12,  -111,  -111,  -111,   269,    10,  -111,    84,
    -111,  -111,    47,    83,   281,  -111,     0,  -111,  -111,    47,
    -111,   269,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     2,     0,    15,
       0,     0,     0,     0,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,    28,     0,    25,     7,     0,
       0,     0,     0,    30,    29,    22,    27,     0,    20,     5,
      17,     0,     0,    12,    13,     0,     0,    14,     0,     0,
      26,    38,    32,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,    21,
      19,     0,     0,    51,     0,     0,     0,     6,     8,     0,
      39,    31,    34,    35,    36,    37,    40,    41,    43,    42,
      44,    45,    46,     0,     0,    10,    64,    57,    60,     0,
       0,    23,    18,     0,     0,    64,     0,     9,     0,    11,
      52,     0,    64,    47,    64,    58,     0,    64,    56,    64,
      61,     0,     0,    53,    59,    64,    48,     0,    55,     0,
      64,    54,     0,     0,     0,    64,     0,    49,    62,     0,
      64,    50,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,  -110,  -111,     1,  -111,  -111,   -31,  -111,   -33,
    -111,    53,  -111,   -24,  -111,  -111,  -111,   -29,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     8,    18,   109,   113,    23,    81,    20,
      78,    24,    21,    45,   127,   140,   149,    27,   106,   124,
     133,    28,   115,   129,    31,   116,   135,   150,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    58,    52,    60,   120,     1,     6,     3,     4,    59,
      35,   125,   137,     5,    19,    61,    79,    63,     6,    36,
      37,    38,   138,    22,    49,    25,    26,    82,    53,    54,
      30,    84,    57,    68,    69,    70,   148,    71,    72,    73,
      74,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   114,   101,   102,    39,    40,    32,    76,    77,    87,
     121,    33,   108,    41,    34,   110,    46,   126,    51,   128,
     111,    56,   131,   112,   134,    47,    48,    55,    62,    64,
     139,    42,    43,    44,    65,   143,    46,   103,    85,    70,
     147,    71,    72,    73,    74,   152,   104,     9,   122,   132,
      10,    11,   130,   123,    12,   142,   145,   136,   141,    86,
     117,    76,    77,     0,   119,   -16,     0,     0,   144,     0,
      13,    14,    15,     0,     0,   151,    16,    66,    67,    68,
      69,    70,    17,    71,    72,    73,    74,    66,    67,    68,
      69,    70,    75,    71,    72,    73,    74,     0,     0,     0,
       0,     0,    80,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    77,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,     0,    83,     0,    66,    67,
      68,    69,    70,     0,    71,    72,    73,    74,     0,     0,
       0,    76,    77,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    77,    66,    67,    68,    69,
      89,     0,    71,    72,    73,    74,     0,    90,     0,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,     0,
       0,     0,    76,    77,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,     0,   107,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,     0,
     118,     0,     0,    76,    77,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    76,    77,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,     0,   146,     0,
       0,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    77
};

static const yytype_int16 yycheck[] =
{
      24,    32,    26,    36,   114,     3,    18,    16,     0,    33,
      11,   121,    24,    17,    36,    39,    47,    41,    18,    20,
      21,    20,   132,    36,    23,    36,    16,    51,    27,    28,
      16,    55,    31,     8,     9,    10,   146,    12,    13,    14,
      15,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   106,    76,    77,     7,     8,     5,    32,    33,    58,
     115,    11,    86,    16,    19,    89,    11,   122,    11,   124,
     103,     5,   127,   104,   129,    20,    21,    16,    36,    36,
     135,    34,    35,    36,    11,   140,    11,    20,    36,    10,
     145,    12,    13,    14,    15,   150,    20,     1,    21,    27,
       4,     5,   126,    22,     8,    21,    23,   131,   137,    56,
     109,    32,    33,    -1,   113,    19,    -1,    -1,   142,    -1,
      24,    25,    26,    -1,    -1,   149,    30,     6,     7,     8,
       9,    10,    36,    12,    13,    14,    15,     6,     7,     8,
       9,    10,    21,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    21,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    -1,    17,    -1,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      -1,    32,    33,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    -1,    17,    -1,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    -1,
      -1,    -1,    32,    33,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    -1,    17,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    32,    33,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    32,    33,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    38,    16,     0,    17,    18,    39,    40,     1,
       4,     5,     8,    24,    25,    26,    30,    36,    41,    36,
      46,    49,    36,    44,    48,    36,    16,    54,    58,    65,
      16,    61,     5,    11,    19,    11,    20,    21,    41,     7,
       8,    16,    34,    35,    36,    50,    11,    20,    21,    41,
      50,    11,    50,    41,    41,    16,     5,    41,    44,    50,
      46,    50,    36,    50,    36,    11,     6,     7,     8,     9,
      10,    12,    13,    14,    15,    21,    32,    33,    47,    44,
      21,    45,    50,    17,    50,    36,    48,    41,    21,    10,
      17,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    20,    20,    21,    55,    17,    50,    42,
      50,    46,    44,    43,    65,    59,    62,    41,    17,    41,
      39,    65,    21,    22,    56,    39,    65,    51,    65,    60,
      50,    65,    27,    57,    65,    63,    50,    24,    39,    65,
      52,    54,    21,    65,    50,    23,    17,    65,    39,    53,
      64,    50,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    40,    39,    41,    41,    41,    42,    41,
      43,    41,    41,    41,    41,    41,    41,    45,    44,    44,
      44,    44,    47,    46,    46,    46,    46,    48,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    52,    53,
      50,    55,    56,    54,    57,    57,    57,    59,    60,    58,
      62,    63,    64,    61,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     4,     3,     4,     3,     0,     6,
       0,     7,     3,     3,     3,     1,     0,     0,     5,     3,
       2,     3,     0,     5,     3,     2,     3,     2,     2,     1,
       1,     3,     2,     2,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     0,     0,
      15,     0,     0,     9,     3,     2,     0,     0,     0,     9,
       0,     0,     0,    16,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 119 "syntaxe.y" /* yacc.c:1646  */
    {YYACCEPT;}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 123 "syntaxe.y" /* yacc.c:1646  */
    {portee++;}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 123 "syntaxe.y" /* yacc.c:1646  */
    {pop_main();portee --;}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 129 "syntaxe.y" /* yacc.c:1646  */
    { // b = expr;
																	int i = guete(jean_louis,(yyvsp[-3].stringValue),pointeur);
																	if(jean_louis[i].typeparam == PTR){//si la var est un pointeur => on modif ce vers quoi on pointe 
																		jean_louis[i].addr = (yyvsp[-1].intValue);
																		addr = pop_unique(jean_louis,pointeur);
																		pointeur--;
																	}
																	else{//sinon
																		add_line("LOAD",1,jean_louis[pointeur].addr,-1);
																		add_line("STORE",jean_louis[i].addr,1,-1);
																		addr = pop_unique(jean_louis,pointeur);
																		pointeur--;
																	}
																}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 145 "syntaxe.y" /* yacc.c:1646  */
    { //*b = expr;
																		int i = guete(jean_louis,(yyvsp[-3].stringValue),pointeur);
																		add_line("LOAD",1,jean_louis[pointeur].addr,-1);
																		add_line("STORE",jean_louis[i].addr,1,-1);
																		addr = pop_unique(jean_louis,pointeur);
																		pointeur--;
																	}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 156 "syntaxe.y" /* yacc.c:1646  */
    {printf("erreur idiot\n");}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 161 "syntaxe.y" /* yacc.c:1646  */
    {	 //int b = expr, a = expr...
														add_line("LOAD",1,jean_louis[pointeur].addr,-1);
														add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
														addr = pop_unique(jean_louis,pointeur);
														pointeur--;
													}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 170 "syntaxe.y" /* yacc.c:1646  */
    {	//int b = expr;
														add_line("LOAD",1,jean_louis[pointeur].addr,-1);
														add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
														addr = pop_unique(jean_louis,pointeur);
														pointeur--;
													}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 177 "syntaxe.y" /* yacc.c:1646  */
    {	//int a;
											addr = ajout((yyvsp[-1].stringValue),INT,jean_louis,addr,portee,pointeur);
											pointeur++;
										}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 181 "syntaxe.y" /* yacc.c:1646  */
    { //int a, b...
															addr = ajout((yyvsp[-2].stringValue),INT,jean_louis,addr,portee,pointeur);
															pointeur++;
														}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 187 "syntaxe.y" /* yacc.c:1646  */
    {	
																		jean_louis[pointeur-1].addr = (yyvsp[0].intValue);
																		addr = pop_unique(jean_louis,pointeur);
																		pointeur--;
																	}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 195 "syntaxe.y" /* yacc.c:1646  */
    {	
																jean_louis[pointeur-1].addr = (yyvsp[-1].intValue);
																addr = pop_unique(jean_louis,pointeur);
																pointeur--;
															}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 201 "syntaxe.y" /* yacc.c:1646  */
    {
											ajout((yyvsp[-1].stringValue),PTR,jean_louis,0,portee,pointeur);
											pointeur++;
										}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 205 "syntaxe.y" /* yacc.c:1646  */
    {
																	ajout((yyvsp[-2].stringValue),PTR,jean_louis,0,portee,pointeur);
																	pointeur++;
																}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 212 "syntaxe.y" /* yacc.c:1646  */
    {
												addr = ajout((yyvsp[-1].stringValue),INT,jean_louis,addr,portee,pointeur);
												pointeur++;										
											}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 219 "syntaxe.y" /* yacc.c:1646  */
    {
														ajout((yyvsp[-1].stringValue),PTR,jean_louis,0,portee,pointeur);
														pointeur++;										
													}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 226 "syntaxe.y" /* yacc.c:1646  */
    { //nom de var
									var_temp();
									int i = guete(jean_louis,(yyvsp[0].stringValue),pointeur);
									add_line("LOAD",1,jean_louis[i].addr,-1);
									add_line("STORE",jean_louis[pointeur].addr,1,-1);
								}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 232 "syntaxe.y" /* yacc.c:1646  */
    { //chiffres
								var_temp();
								add_line("AFC",1,(yyvsp[0].intValue),-1);
								add_line("STORE",jean_louis[pointeur].addr,1,-1);
							}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 237 "syntaxe.y" /* yacc.c:1646  */
    { // a = expr
													int i = guete(jean_louis,(yyvsp[-2].stringValue),pointeur);
													add_line("LOAD",1,jean_louis[pointeur].addr,-1);
													add_line("STORE",jean_louis[i].addr,1,-1);
												}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 242 "syntaxe.y" /* yacc.c:1646  */
    { // *b renvoit val addr dans b
									var_temp();
									int i = guete(jean_louis,(yyvsp[0].stringValue),pointeur);
									add_line("LOAD",1,jean_louis[i].addr,-1);
									add_line("STORE",jean_louis[pointeur].addr,1,-1);
								}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 248 "syntaxe.y" /* yacc.c:1646  */
    { // &a revoit addr de a
									var_temp();
									int i = guete(jean_louis,(yyvsp[0].stringValue),pointeur);
									(yyval.intValue) = jean_louis[i].addr;
								}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 253 "syntaxe.y" /* yacc.c:1646  */
    {operation(ADD);}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 254 "syntaxe.y" /* yacc.c:1646  */
    {operation(SOU);}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 255 "syntaxe.y" /* yacc.c:1646  */
    {operation(MUL);}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 256 "syntaxe.y" /* yacc.c:1646  */
    {operation(DIV);}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 257 "syntaxe.y" /* yacc.c:1646  */
    { // -expr
												add_line("AFC",1,0,-1);
												add_line("LOAD",2,jean_louis[pointeur].addr,-1);
												add_line("SOU",1,2,-1);
												add_line("STORE",jean_louis[pointeur].addr,1,-1);
											}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 263 "syntaxe.y" /* yacc.c:1646  */
    {(yyval.intValue) = (yyvsp[-1].intValue);}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 264 "syntaxe.y" /* yacc.c:1646  */
    {operation(DOUBLE_EQU);}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 265 "syntaxe.y" /* yacc.c:1646  */
    {operation(INF);}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 266 "syntaxe.y" /* yacc.c:1646  */
    {operation(INFE);}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 267 "syntaxe.y" /* yacc.c:1646  */
    {operation(SUP);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 268 "syntaxe.y" /* yacc.c:1646  */
    {operation(SUPE);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 269 "syntaxe.y" /* yacc.c:1646  */
    {	 //expr && expr
											add_line("LOAD",1,jean_louis[pointeur-1].addr,-1);
											add_line("LOAD",2,jean_louis[pointeur].addr,-1);	
											add_line("AFC",3,1,-1);//R3 = 1
											add_line("EQU",1,3,-1);//R1 = (R1 == 1)
											add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
											add_line("EQU",2,3,-1);//R2 = (R2 == 1)
											add_line("STORE",jean_louis[pointeur].addr,2,-1);
											operation(AND);
										}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 279 "syntaxe.y" /* yacc.c:1646  */
    {	 //expr || expr
											add_line("LOAD",1,jean_louis[pointeur-1].addr,-1);
											add_line("LOAD",2,jean_louis[pointeur].addr,-1);	
											add_line("AFC",3,1,-1);//R3 = 1
											add_line("EQU",1,3,-1);//R1 = (R1 == 1)
											add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
											add_line("EQU",2,3,-1);//R2 = (R2 == 1)
											add_line("STORE",jean_louis[pointeur].addr,2,-1);
											operation(OR);
										}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 289 "syntaxe.y" /* yacc.c:1646  */
    { //ternary expression
	 																			//on fait un jump conditionel vers la partie apres les 2 pts
	 																			operation(DOUBLE_EQU);
	 																			add_line("LOAD",0,jean_louis[pointeur].addr,-1);
	 																			add_line("JCMP",99,0,-1);
	 																			addr = pop_unique(jean_louis,pointeur);
	 																			pointeur--;
	 																		}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 297 "syntaxe.y" /* yacc.c:1646  */
    {add_line("JMP",99,-1,-1);}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 298 "syntaxe.y" /* yacc.c:1646  */
    {addr = pop_unique(jean_louis,pointeur);pointeur--;}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 298 "syntaxe.y" /* yacc.c:1646  */
    {
																																													patch_line((yyvsp[-4].intValue),"JMP",line,0,-1);
																																													patch_line((yyvsp[-7].intValue),"JCMP",(yyvsp[-2].intValue)+1,0,-1);
																																												}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 304 "syntaxe.y" /* yacc.c:1646  */
    {
														add_line("LOAD",0,jean_louis[pointeur].addr,-1);
														//on fait un jump conditionel vers le else
														add_line("JCMP",99,0,-1);
														addr = pop_unique(jean_louis,pointeur);
														pointeur--;
													}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 311 "syntaxe.y" /* yacc.c:1646  */
    {add_line("JMP",99,-1,-1);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 312 "syntaxe.y" /* yacc.c:1646  */
    {
																	if((yyvsp[0].intValue)){
																	//si else on patch le JMP endif vers la fin du else et le JCMP before if vers le patch_line avant le else
																	patch_line((yyvsp[-1].intValue),"JMP",line,0,-1);
																	patch_line((yyvsp[-4].intValue),"JCMP",(yyvsp[-1].intValue)+1,0,-1);
																	}
																	else{
																		//sinon on del le JMP a la fin du else et on patch le JCMP vers le dernier patch_line
																		rm_line_last();
																		patch_line((yyvsp[-4].intValue),"JCMP",line,0,-1);
																	}
																}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 326 "syntaxe.y" /* yacc.c:1646  */
    {(yyval.intValue) = 1;}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 327 "syntaxe.y" /* yacc.c:1646  */
    {(yyval.intValue) = 1;}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 328 "syntaxe.y" /* yacc.c:1646  */
    {(yyval.intValue) = 0;}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 331 "syntaxe.y" /* yacc.c:1646  */
    {
																					add_line("LOAD",0,jean_louis[pointeur].addr,-1);
																					//on fait un jump conditionel vers la fin du while
																					add_line("JCMP",99,0,-1);
																					addr = pop_unique(jean_louis,pointeur);
																					pointeur--;
																				}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 338 "syntaxe.y" /* yacc.c:1646  */
    {add_line("JMP",99,-1,-1);}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 339 "syntaxe.y" /* yacc.c:1646  */
    {
												//on patch le JCMP post while vers la ligne apres le corps et le JMP de fin de while vers la ligne au dessus de la condition pour pouvoir la reevaluer
												patch_line((yyvsp[0].intValue),"JMP",(yyvsp[-8].intValue)+1,0,-1);
												patch_line((yyvsp[-3].intValue),"JCMP",(yyvsp[0].intValue)+1,0,-1);
											}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 347 "syntaxe.y" /* yacc.c:1646  */
    {
															//creation du int temporaire
															add_line("LOAD",1,jean_louis[pointeur].addr,-1);
															add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
															addr = pop_unique(jean_louis,pointeur);
															pointeur--;			
														}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 354 "syntaxe.y" /* yacc.c:1646  */
    { 
													 		add_line("LOAD",0,jean_louis[pointeur].addr,-1);
															//on fait un jump conditionel vers la fin du for
															add_line("JCMP",99,0,-1);
															addr = pop_unique(jean_louis,pointeur);
															pointeur--;
													 }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 361 "syntaxe.y" /* yacc.c:1646  */
    {add_line("JMP",99,-1,-1);}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 362 "syntaxe.y" /* yacc.c:1646  */
    {
												//on patch le JCMP post for vers la ligne apres le corps et le JMP de fin de for vers la ligne au dessus de la condition pour pouvoir la reevaluer
												patch_line((yyvsp[0].intValue),"JMP",(yyvsp[-9].intValue)+1,0,-1);
												patch_line((yyvsp[-6].intValue),"JCMP",(yyvsp[0].intValue)+1,0,-1);
											}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 370 "syntaxe.y" /* yacc.c:1646  */
    {(yyval.intValue) = line-1;}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1930 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 373 "syntaxe.y" /* yacc.c:1906  */


void yyerror(char *msg) {
	printf("error: %s\n", msg);
	exit(2);
}


////////////////////////////////////////////////////////////////////////

//Affichage des lignes d'assembleur
void print_lines(){
	for(int i = 0; i < line; i++){
		printf("%d: ",i);
		if(strcmp(ASM[i].id,"LOAD")==0){
			printf("%s R%d @%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}

		else if(strcmp(ASM[i].id,"STORE")==0){
			printf("%s @%d R%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		else if(strcmp(ASM[i].id,"JCMP")==0){
			printf("%s @%d R%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		else if(strcmp(ASM[i].id,"JMP")==0){
			printf("%s @%d\n", ASM[i].id,ASM[i].val1);
		}
		else if(strcmp(ASM[i].id,"AFC")==0){
			printf("%s R%d %d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
		else {
			printf("%s R%d R%d\n", ASM[i].id,ASM[i].val1,ASM[i].val2);
		}
	}	
		
}

//Ajout ligne assembleur
void add_line(char *id,int v1, int v2, int v3){
	int val3 = 0;
	if(v3 != -1) val3 = v3;
	struct instr tmp = {id, v1, v2, val3};
	ASM[line] = tmp;
	line ++;
}

//Patch ligne assembleur
void patch_line(int l,char* id,int v1,int v2,int v3){
	int val3 = 0;
	if(v3 != -1) val3 = v3;
	struct instr tmp = {id, v1, v2, val3};
	ASM[l] = tmp;
}

//Suppr derniere ligne assembleur
void rm_line_last(){
	ASM[line] = ASM[line+1];
	line--;
}

//Creation d'une variable temporaire
void var_temp(){ 
	addr = ajout("temp",INT,jean_louis,addr,portee,pointeur);
	pointeur++;
}

//Operations assembleur
void operation(type_op param){
	add_line("LOAD",1,jean_louis[pointeur-1].addr,-1);
	add_line("LOAD",2,jean_louis[pointeur].addr,-1);	
	switch(param){
		case (ADD):
			add_line("ADD",1,2,-1);
			break;
		case(MUL):
			add_line("MUL",1,2,-1);
			break;
		case(SOU):
			add_line("SOU",1,2,-1);
			break;
		case(DIV):
			add_line("DIV",1,2,-1);
			break;
		case(EQU):
			add_line("MOV",1,2,-1);
			break;
		case(DOUBLE_EQU):
			add_line("EQU",1,2,-1);
			break;
		case(INF):
			add_line("INF",1,2,-1);
			break;
		case(INFE):
			add_line("INFE",1,2,-1);
			break;
		case(SUP):
			add_line("SUP",1,2,-1);
			break;
		case(SUPE):
			add_line("SUPE",1,2,-1);
			break;
		case(AND):
			add_line("EQU",1,2,-1);//R1 = (R1 == R2)
			break;
		case(OR):
			add_line("AFC",3,1,-1);//R3 = 1
			add_line("ADD",1,2,-1);//R1 = R1 + R2
			add_line("SUPE",1,3,-1);//R1 = (R1 >= 1)
			break;
	}
	add_line("STORE",jean_louis[pointeur-1].addr,1,-1);
	addr = pop_unique(jean_louis,pointeur);
	pointeur--;
}

//depop toutes les var de meme portee
void pop_main(){
	pointeur = pop(jean_louis, pointeur, portee);
	
	int tmp = 0;
	switch(jean_louis[pointeur].typeparam){
		case(INT):
			tmp = 4;
			break;
		case(CHAR):
			tmp = 1;
			break;
	}
	addr = jean_louis[pointeur].addr + tmp;
}

//Transforme le tableau d'assembleur en un fichier binaire
void toBIN(){
	FILE* fichier = NULL;
	remove("sortie.banane");
	fichier = fopen("sortie.banane", "w");

    if (fichier != NULL)
    {
		int8_t * tmp = malloc(sizeof(char));
		for(int i = 0; i < line; i++){
			if(strcmp(ASM[i].id, "STORE") == 0 || strcmp(ASM[i].id, "LOAD") == 0 || strcmp(ASM[i].id, "JMP") == 0 || strcmp(ASM[i].id, "JCMP") == 0){
				if(strcmp(ASM[i].id, "LOAD") == 0){
				*tmp=7;
				fwrite(tmp,sizeof(int8_t), 1, fichier);

				*tmp = (int8_t) ASM[i].val1;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				
				*tmp = (int8_t) ASM[i].val2;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				
				*tmp = (int8_t) (ASM[i].val2>>8);
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "STORE") == 0){
					*tmp=8;
					fwrite(tmp,sizeof(int8_t), 1, fichier);

					*tmp = (int8_t) ASM[i].val1;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) ASM[i].val2;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) (ASM[i].val1>>8);
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "JMP") == 0){
					*tmp=14;
					fwrite(tmp,sizeof(int8_t), 1, fichier);

					*tmp = (int8_t) ASM[i].val1;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) ASM[i].val2;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) (ASM[i].val1>>8);
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "JCMP") == 0){
					*tmp=15;
					fwrite(tmp,sizeof(int8_t), 1, fichier);

					*tmp = (int8_t) ASM[i].val1;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) ASM[i].val2;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				
					*tmp = (int8_t) (ASM[i].val1>>8);
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
			}
			else{
				if(strcmp(ASM[i].id, "ADD") == 0){
					*tmp=1;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "MUL") == 0){
					*tmp=2;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "SOU") == 0){
					*tmp=3;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "DIV") == 0){
					*tmp=4;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "AFC") == 0){
					*tmp=6;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "MOV") == 0){
					*tmp=5;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "EQU") == 0){
					*tmp=9;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "INF") == 0){
					*tmp=10;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "INFE") == 0){
					*tmp=11;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "SUP") == 0){
					*tmp=12;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}
				if(strcmp(ASM[i].id, "SUPE") == 0){
					*tmp=13;
					fwrite(tmp,sizeof(int8_t), 1, fichier);
				}

				*tmp = (int8_t) ASM[i].val1;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				
				*tmp = (int8_t) ASM[i].val2;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
				
				*tmp = (int8_t) ASM[i].val3;
				fwrite(tmp,sizeof(int8_t), 1, fichier);
			}					
		}
		*tmp = 255;
		fwrite(tmp,sizeof(int8_t), 1, fichier);
		fwrite(tmp,sizeof(int8_t), 1, fichier);
		fwrite(tmp,sizeof(int8_t), 1, fichier);
		fwrite(tmp,sizeof(int8_t), 1, fichier);
		fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur
        printf("Impossible d'ouvrir le fichier sortie.banane");
    }
}
////////////////////////////////////////////////////////////////////////

int main() {
	pointeur = -1; //derniere var
	portee = 0; //portee actuelle
	addr = 0; //addr prochaine var
	line = 0; //ligne prochaine instr
	
	printf("      === Flex et Yacc compilator ===\n");
	printf("   ***Auteurs: Bravais J. et Wowk T.***\n");
	yyparse(); //Parsing
	print_lines(); 
	toBIN();
	printf("      	=== FIN DE COMPILATION ===\n");	
	printf("***python Interpret.py pour l'interpreteur***\n");
	return 1;
}



