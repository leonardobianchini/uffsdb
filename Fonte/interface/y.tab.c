/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20141128

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "yacc.y"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#ifndef FMACROS
   #include "../macros.h"
#endif
#ifndef FTYPES
   #include "../types.h"
#endif
#ifndef FMISC
   #include "../misc.h"
#endif
#ifndef FDICTIONARY
   #include "../dictionary.h"
#endif
#ifndef FSQLCOMMANDS
   #include "../sqlcommands.h"
#endif
#ifndef FDATABASE
   #include "../database.h"
#endif
#ifndef FPARSER
   #include "parser.h"
#endif

extern char* yytext[];
extern FILE * yyin;
extern FILE* outFile_p;

int yywrap() {
    return 1;
}

#line 38 "yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int intval;
    double floatval;
    int subtok;
    char *strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 70 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INSERT 257
#define INTO 258
#define VALUES 259
#define SELECT 260
#define FROM 261
#define CREATE 262
#define TABLE 263
#define INTEGER 264
#define VARCHAR 265
#define DOUBLE 266
#define CHAR 267
#define PRIMARY 268
#define KEY 269
#define REFERENCES 270
#define DATABASE 271
#define DROP 272
#define OBJECT 273
#define NUMBER 274
#define VALUE 275
#define QUIT 276
#define LIST_TABLES 277
#define LIST_TABLE 278
#define ALPHANUM 279
#define CONNECT 280
#define HELP 281
#define LIST_DBASES 282
#define CLEAR 283
#define CONTR 284
#define WHERE 285
#define ARITMETIC 286
#define RELATIONAL 287
#define LOGICAL 288
#define AND 289
#define OR 290
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    9,
   18,   10,   16,   12,   13,    7,    8,   15,   14,   17,
   20,    1,   11,   19,   21,   21,   23,   23,   24,   22,
   22,   25,   25,   25,   26,    3,   27,   27,   29,   31,
   29,   29,   29,   28,   30,   30,   30,   32,   33,   34,
   35,    5,   36,   37,    4,   38,   39,    6,   40,    2,
   41,   42,   42,   45,   44,   44,   44,   46,   46,   47,
   47,   48,   43,   43,   49,   49,   50,   50,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    0,    2,
    1,    1,    1,    1,    1,    2,    1,    1,    1,    1,
    0,   10,    1,    1,    0,    3,    1,    3,    1,    1,
    3,    1,    1,    1,    0,    8,    3,    5,    1,    0,
    5,    1,    1,    1,    0,    2,    5,    1,    1,    0,
    0,    6,    0,    0,    6,    0,    0,    6,    0,    7,
    1,    0,    2,    0,    4,    1,    1,    2,    4,    0,
    2,    3,    2,    4,    0,    2,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   69,    0,    0,   21,   22,   27,    0,    0,   29,
   28,   23,   30,   24,   25,   33,    0,    1,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
   14,   15,   16,   17,   18,   31,    0,   45,   63,   60,
   66,   26,   20,    0,    0,    0,    0,    0,    0,   34,
    0,    0,    0,   64,   61,   67,    0,    0,   71,    0,
    0,    0,    0,    0,   39,    0,    0,    0,    0,    0,
   54,    0,    0,   65,   62,   68,   36,    0,    0,   74,
   77,   76,    0,   73,    0,    0,    0,   70,    0,   49,
   50,   52,   53,    0,   38,   43,   42,   44,    0,    0,
    0,    0,    0,    0,   78,    0,   87,   88,   83,    0,
   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   81,   82,   86,    0,   56,   58,    0,    0,   32,
   41,   75,   84,   79,    0,    0,    0,   48,   51,   59,
    0,   57,
};
static const YYINT yydgoto[] = {                         17,
   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
   28,   29,   30,   31,   32,   33,   34,   35,   51,   44,
   58,   99,   66,   67,  100,   46,   72,   73,   94,  115,
  112,  128,  141,   48,   63,   47,   62,   49,   64,   37,
   60,   70,   84,   85,  101,   86,  105,   87,  109,  110,
};
static const YYINT yysindex[] = {                       -21,
 -235,    0, -239, -234,    0,    0,    0, -246, -225,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -3,    0,    0,    0,
    0,    0,    0, -224, -227, -224, -223, -222, -221,    0,
   13, -219,   13,    0,    0,    0, -218, -203,    0, -226,
 -216,   -1,   -1,   -1,    0,   19,   17,   13,  -31,   -1,
    0,   19, -220,    0,    0,    0,    0, -218, -262,    0,
    0,    0,  -31,    0, -217, -214, -279,    0,   -1,    0,
    0,    0,    0, -228,    0,    0,    0,    0,   19,   18,
   20,   22,  -40,   -9,    0,   -9,    0,    0,    0,  -31,
    0,   13, -205, -206,   26,   -1, -262, -202, -279, -217,
   -9,    0,    0,    0, -200,    0,    0,   35, -216,    0,
    0,    0,    0,    0,   36,   19, -197,    0,    0,    0,
   37,    0,
};
static const YYINT yyrindex[] = {                        79,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -179,    0,    0,    0,    0,    0,    0,    0,    0,   23,
    0,    0,    0,    0,    0,    0,   40,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -41,    0,  -34,    0,    0,    0,
    0,    0,    0,   -8,    0,    0,    0,    0,    0,   42,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   43,    0,    0,    0,  -34,  -41,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -48,  -47,  -64,    0,    0,    0,    0,    0,   39,    0,
    0,  -30,    8,    0,    0,    0,  -39,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -80,    0,    0,  -78,  -32,    0,  -28,    0,
};
#define YYTABLESIZE 266
static const YYINT yytable[] = {                         80,
  120,   77,  102,   57,  103,   61,   85,   89,   83,  107,
  108,   96,   97,   74,   75,   76,   98,   80,   14,   15,
   79,   88,   36,   38,   85,  122,   42,  123,   40,  124,
  121,   39,   55,   52,  116,   55,   41,   16,   45,  113,
  111,  114,  135,   90,   91,   92,   93,   43,   50,   54,
   55,   56,   14,   59,   65,   68,   71,   16,   69,   15,
   78,  117,  119,  126,  125,  118,  127,  130,  104,  129,
  132,  139,  106,  136,  137,  140,  120,  142,   19,   35,
   37,   72,   40,   47,   53,   95,  131,  134,    0,  138,
  133,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    2,    0,
    3,   80,   81,   82,    0,   80,  106,   80,   80,    0,
    4,    5,    0,    0,    6,    7,    8,    0,    9,   10,
   11,   12,   13,   80,   81,   82,
};
static const YYINT yycheck[] = {                         41,
   41,   66,   83,   51,   83,   53,   41,   72,   40,  289,
  290,  274,  275,   62,   63,   64,  279,   59,   40,   41,
   68,   70,  258,  263,   59,  104,  273,  106,  263,  110,
   40,  271,   41,  261,   99,   44,  271,   59,   42,  268,
   89,  270,  121,  264,  265,  266,  267,  273,  273,  273,
  273,  273,   40,  273,  273,  259,  273,   59,  285,   41,
   44,   44,   41,  269,  112,   46,  273,  116,  286,   44,
  273,  136,  287,  274,   40,  273,   41,   41,    0,  259,
   41,   59,   41,   41,   46,   78,  117,  120,   -1,  129,
  119,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,  260,   -1,
  262,  273,  274,  275,   -1,  287,  287,  289,  290,   -1,
  272,  273,   -1,   -1,  276,  277,  278,   -1,  280,  281,
  282,  283,  284,  273,  274,  275,
};
#define YYFINAL 17
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 343
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INSERT",
"INTO","VALUES","SELECT","FROM","CREATE","TABLE","INTEGER","VARCHAR","DOUBLE",
"CHAR","PRIMARY","KEY","REFERENCES","DATABASE","DROP","OBJECT","NUMBER","VALUE",
"QUIT","LIST_TABLES","LIST_TABLE","ALPHANUM","CONNECT","HELP","LIST_DBASES",
"CLEAR","CONTR","WHERE","ARITMETIC","RELATIONAL","LOGICAL","AND","OR",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : insert",
"start : select",
"start : create_table",
"start : create_database",
"start : drop_table",
"start : drop_database",
"start : table_attr",
"start : list_tables",
"start : connection",
"start : exit_program",
"start : semicolon",
"start : parentesis_open",
"start : parentesis_close",
"start : help_pls",
"start : list_databases",
"start : clear",
"start : contributors",
"start : qualquer_coisa",
"start :",
"connection : CONNECT OBJECT",
"qualquer_coisa : OBJECT",
"exit_program : QUIT",
"clear : CLEAR",
"parentesis_open : '('",
"parentesis_close : ')'",
"table_attr : LIST_TABLE OBJECT",
"list_tables : LIST_TABLES",
"list_databases : LIST_DBASES",
"help_pls : HELP",
"contributors : CONTR",
"$$1 :",
"insert : INSERT INTO $$1 table opt_column_list VALUES parentesis_open value_list parentesis_close semicolon",
"semicolon : ';'",
"table : OBJECT",
"opt_column_list :",
"opt_column_list : parentesis_open column_list parentesis_close",
"column_list : column",
"column_list : column ',' column_list",
"column : OBJECT",
"value_list : value",
"value_list : value ',' value_list",
"value : VALUE",
"value : NUMBER",
"value : ALPHANUM",
"$$2 :",
"create_table : CREATE TABLE $$2 table parentesis_open table_column_attr parentesis_close semicolon",
"table_column_attr : column_create type attribute",
"table_column_attr : column_create type attribute ',' table_column_attr",
"type : INTEGER",
"$$3 :",
"type : VARCHAR $$3 parentesis_open NUMBER parentesis_close",
"type : DOUBLE",
"type : CHAR",
"column_create : OBJECT",
"attribute :",
"attribute : PRIMARY KEY",
"attribute : REFERENCES table_fk '(' column_fk ')'",
"table_fk : OBJECT",
"column_fk : OBJECT",
"$$4 :",
"$$5 :",
"drop_table : DROP TABLE $$4 OBJECT $$5 semicolon",
"$$6 :",
"$$7 :",
"create_database : CREATE DATABASE $$6 OBJECT $$7 semicolon",
"$$8 :",
"$$9 :",
"drop_database : DROP DATABASE $$8 OBJECT $$9 semicolon",
"$$10 :",
"select : SELECT $$10 '*' FROM table_select where semicolon",
"table_select : OBJECT",
"where :",
"where : WHERE logical_oper",
"$$11 :",
"operand : OBJECT $$11 '.' OBJECT",
"operand : VALUE",
"operand : NUMBER",
"paren : operand paren2",
"paren : '(' paren ')' paren2",
"paren2 :",
"paren2 : ARITMETIC paren",
"equation : paren RELATIONAL paren",
"logical_oper : equation lo",
"logical_oper : '(' logical_oper ')' lo",
"lo :",
"lo : logico logical_oper",
"logico : AND",
"logico : OR",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 11:
#line 57 "yacc.y"
	{GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 20:
#line 66 "yacc.y"
	{connect(*yytext); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 21:
#line 68 "yacc.y"
	{GLOBAL_PARSER.consoleFlag = 1; GLOBAL_PARSER.noerror = 0; return 0;}
break;
case 22:
#line 71 "yacc.y"
	{exit(0);}
break;
case 23:
#line 73 "yacc.y"
	{clear(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 24:
#line 75 "yacc.y"
	{GLOBAL_PARSER.parentesis++;}
break;
case 25:
#line 77 "yacc.y"
	{GLOBAL_PARSER.parentesis--;}
break;
case 26:
#line 80 "yacc.y"
	{
    if(connected.conn_active) {
        printTable(yylval.strval);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
}
break;
case 27:
#line 90 "yacc.y"
	{
    if(connected.conn_active) {
        printTable(NULL);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
}
break;
case 28:
#line 100 "yacc.y"
	{
    showDB();
    GLOBAL_PARSER.consoleFlag = 1;
    return 0;
}
break;
case 29:
#line 107 "yacc.y"
	{help(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 30:
#line 110 "yacc.y"
	{contr(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
break;
case 31:
#line 117 "yacc.y"
	{setMode(OP_INSERT);}
break;
case 32:
#line 117 "yacc.y"
	{
    if (GLOBAL_PARSER.col_count == GLOBAL_PARSER.val_count || GLOBAL_DATA.columnName == NULL)
        GLOBAL_DATA.N = GLOBAL_PARSER.val_count;
    else {
        printf("ERROR: The column counter doesn't match the value counter.\n");
        GLOBAL_PARSER.noerror=0;
    }
    return 0;
}
break;
case 34:
#line 129 "yacc.y"
	{setObjName(yytext);}
break;
case 39:
#line 135 "yacc.y"
	{setColumnInsert(yytext);}
break;
case 42:
#line 139 "yacc.y"
	{setValueInsert(yylval.strval, 'D');}
break;
case 43:
#line 140 "yacc.y"
	{setValueInsert(yylval.strval, 'I');}
break;
case 44:
#line 141 "yacc.y"
	{setValueInsert(yylval.strval, 'S');}
break;
case 45:
#line 144 "yacc.y"
	{setMode(OP_CREATE_TABLE);}
break;
case 46:
#line 144 "yacc.y"
	{
    GLOBAL_DATA.N = GLOBAL_PARSER.col_count;

    return 0;
}
break;
case 49:
#line 152 "yacc.y"
	{setColumnTypeCreate('I');}
break;
case 50:
#line 153 "yacc.y"
	{setColumnTypeCreate('S');}
break;
case 51:
#line 153 "yacc.y"
	{setColumnSizeCreate(yylval.strval);}
break;
case 52:
#line 154 "yacc.y"
	{setColumnTypeCreate('D');}
break;
case 53:
#line 155 "yacc.y"
	{setColumnTypeCreate('C');}
break;
case 54:
#line 157 "yacc.y"
	{setColumnCreate(yytext);}
break;
case 56:
#line 160 "yacc.y"
	{setColumnPKCreate();}
break;
case 58:
#line 163 "yacc.y"
	{setColumnFKTableCreate(yytext);}
break;
case 59:
#line 165 "yacc.y"
	{setColumnFKColumnCreate(yytext);}
break;
case 60:
#line 168 "yacc.y"
	{setMode(OP_DROP_TABLE);}
break;
case 61:
#line 168 "yacc.y"
	{setObjName(yytext);}
break;
case 62:
#line 168 "yacc.y"
	{return 0;}
break;
case 63:
#line 171 "yacc.y"
	{setMode(OP_CREATE_DATABASE);}
break;
case 64:
#line 171 "yacc.y"
	{setObjName(yytext);}
break;
case 65:
#line 171 "yacc.y"
	{return 0;}
break;
case 66:
#line 174 "yacc.y"
	{setMode(OP_DROP_DATABASE);}
break;
case 67:
#line 174 "yacc.y"
	{setObjName(yytext);}
break;
case 68:
#line 174 "yacc.y"
	{return 0;}
break;
case 69:
#line 177 "yacc.y"
	{setMode(OP_SELECT_ALL);}
break;
case 70:
#line 177 "yacc.y"
	{return 0;}
break;
case 71:
#line 179 "yacc.y"
	{setObjName(yytext);}
break;
case 74:
#line 185 "yacc.y"
	{GLOBAL_PARSER.step++;}
break;
case 75:
#line 185 "yacc.y"
	{GLOBAL_PARSER.step++;}
break;
#line 843 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
