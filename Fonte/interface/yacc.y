%{
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

%}

%union {
    int intval;
    double floatval;
    int subtok;
    char *strval;
}


%token  INSERT      INTO        VALUES      SELECT      FROM
        CREATE      TABLE       INTEGER     VARCHAR     DOUBLE
        CHAR        PRIMARY     KEY         REFERENCES  DATABASE
        DROP        OBJECT      NUMBER      VALUE       QUIT
        LIST_TABLES LIST_TABLE  ALPHANUM    CONNECT     HELP
        LIST_DBASES CLEAR       CONTR		WHERE		ARITMETIC
        RELATIONAL	LOGICAL		AND			OR          ASTERISCO
        MAIS        MENOS       ABRE_P      FECHA_P;

%%

start: insert | select | create_table | create_database | drop_table | drop_database
     | table_attr | list_tables | connection | exit_program | semicolon {GLOBAL_PARSER.consoleFlag = 1; return 0;}
     | parentesis_open | parentesis_close| help_pls | list_databases | clear | contributors
     | qualquer_coisa | /*nothing*/;

/*--------------------------------------------------*/
/**************** GENERAL FUNCTIONS *****************/
/*--------------------------------------------------*/

/* CONNECTION */
connection: CONNECT OBJECT {connect(*yytext); GLOBAL_PARSER.consoleFlag = 1; return 0;};

qualquer_coisa: OBJECT {GLOBAL_PARSER.consoleFlag = 1; GLOBAL_PARSER.noerror = 0; return 0;};

/* EXIT */
exit_program: QUIT {exit(0);};

clear: CLEAR {clear(); GLOBAL_PARSER.consoleFlag = 1; return 0;};

parentesis_open: ABRE_P {GLOBAL_PARSER.parentesis++;};

parentesis_close: FECHA_P {GLOBAL_PARSER.parentesis--;};

/* TABLE ATTRIBUTES */
table_attr: LIST_TABLE OBJECT {
    if(connected.conn_active) {
        printTable(yylval.strval);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
};

/* LIST TABLES */
list_tables: LIST_TABLES {
    if(connected.conn_active) {
        printTable(NULL);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
};

/* LIST DATABASES */
list_databases: LIST_DBASES {
    showDB();
    GLOBAL_PARSER.consoleFlag = 1;
    return 0;
}

/* HELP */
help_pls: HELP {help(); GLOBAL_PARSER.consoleFlag = 1; return 0;}

/* CONTRIBUTORS */
contributors: CONTR {contr(); GLOBAL_PARSER.consoleFlag = 1; return 0;}

/*--------------------------------------------------*/
/****************** SQL STATEMENTS ******************/
/*--------------------------------------------------*/

/* INSERT */
insert: INSERT INTO {setMode(OP_INSERT);} table opt_column_list VALUES parentesis_open value_list parentesis_close semicolon {
    if (GLOBAL_PARSER.col_count == GLOBAL_PARSER.val_count || GLOBAL_DATA.columnName == NULL)
        GLOBAL_DATA.N = GLOBAL_PARSER.val_count;
    else {
        printf("ERROR: The column counter doesn't match the value counter.\n");
        GLOBAL_PARSER.noerror=0;
    }
    return 0;
};

semicolon: ';';

table: OBJECT {setObjName(yytext);};

opt_column_list: /*optional*/ | parentesis_open column_list parentesis_close;

column_list: column | column ',' column_list;

column: OBJECT {setColumnInsert(yytext);};

value_list: value | value ',' value_list;

value: VALUE {setValueInsert(yylval.strval, 'D');}
     | NUMBER {setValueInsert(yylval.strval, 'I');}
     | ALPHANUM {setValueInsert(yylval.strval, 'S');};

/* CREATE TABLE */
create_table: CREATE TABLE {setMode(OP_CREATE_TABLE);} table parentesis_open table_column_attr parentesis_close semicolon {
    GLOBAL_DATA.N = GLOBAL_PARSER.col_count;

    return 0;
};

table_column_attr: column_create type attribute | column_create type attribute ',' table_column_attr;

type: INTEGER {setColumnTypeCreate('I');}
    | VARCHAR {setColumnTypeCreate('S');} parentesis_open NUMBER parentesis_close {setColumnSizeCreate(yylval.strval);}
    | DOUBLE {setColumnTypeCreate('D');};
    | CHAR {setColumnTypeCreate('C');};

column_create: OBJECT {setColumnCreate(yytext);};

attribute: /*optional*/
         | PRIMARY KEY {setColumnPKCreate();}
         | REFERENCES table_fk '(' column_fk ')';

table_fk: OBJECT {setColumnFKTableCreate(yytext);};

column_fk: OBJECT {setColumnFKColumnCreate(yytext);};

/* DROP TABLE */
drop_table: DROP TABLE {setMode(OP_DROP_TABLE);} OBJECT {setObjName(yytext);} semicolon  {return 0;};

/* CREATE DATABASE */
create_database: CREATE DATABASE {setMode(OP_CREATE_DATABASE);} OBJECT {setObjName(yytext);} semicolon {return 0;};

/* DROP DATABASE */
drop_database: DROP DATABASE {setMode(OP_DROP_DATABASE);} OBJECT {setObjName(yytext);} semicolon {return 0;};









/* SELECT */
select: SELECT {setMode(OP_SELECT_ALL); null_list();} pos_select FROM table_select where semicolon {return 0;};

table_select: OBJECT {setObjName(yytext);};

pos_select: ASTERISCO {getAttr(-1, yytext);} | OBJECT {clear_list(); GLOBAL_PARSER.step++; getAttr(0, yytext);} '.' OBJECT {GLOBAL_PARSER.step++; getAttr(1, yytext);} pos_select2
pos_select2:    | ',' pos_select3
pos_select3: OBJECT {GLOBAL_PARSER.step++; getAttr(0, yytext);} '.' OBJECT {GLOBAL_PARSER.step++; getAttr(1, yytext);} pos_select2


where:  
	| WHERE {GLOBAL_PARSER.step++;} logical_oper;


operand:	OBJECT {GLOBAL_PARSER.step++; getToken(yylval.strval,WT_OBJECT);} '.' OBJECT {GLOBAL_PARSER.step++; getToken(yylval.strval,WT_OBJECT);} 
		| valor {getToken(yylval.strval,WT_VALOR);}
		| numero {getToken(yylval.strval,WT_NUMERO);}
		| ALPHANUM {getToken(yylval.strval,WT_ALPHANUM);}

/* select * from oi where */

sinal: MAIS | MENOS
    
numero: NUMBER {GLOBAL_PARSER.step++;}
    |   sinal NUMBER {GLOBAL_PARSER.step++;}

valor: VALUE {GLOBAL_PARSER.step++;}
    | sinal {getToken(yylval.strval,WT_SINAL);} VALUE {GLOBAL_PARSER.step++; getToken(yylval.strval,WT_VALUE);}

paren: operand paren2 | ABRE_P paren FECHA_P paren2
paren2: /* nothing */
	| ARITMETIC {GLOBAL_PARSER.step++; getToken(yylval.strval, WT_ARITMETIC);} paren
    | sinal {getToken(yylval.strval, WT_SINAL);} paren
    | ASTERISCO {getToken(yylval.strval, WT_ASTERISCO);} paren

equation: paren RELATIONAL {GLOBAL_PARSER.step++; getToken(yylval.strval, WT_RELATIONAL);} paren

logical_oper: equation lo | ABRE_P logical_oper FECHA_P lo
lo: /* nothing */
	| logico logical_oper

logico: AND {GLOBAL_PARSER.step++; getToken(yylval.strval, WT_LOGICO);}
	| OR {GLOBAL_PARSER.step++; getToken(yylval.strval, WT_LOGICO);}


/* END */
%%
