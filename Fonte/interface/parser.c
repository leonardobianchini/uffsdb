#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#ifndef FMACROS
   #include "../macros.h"
#endif
#ifndef FTYPES
   #include "../types.h"
#endif
#ifndef FMISC
   #include "../misc.h"
#endif
#ifndef FDATABASE
   #include "../database.h"
#endif
#ifndef FSQLCOMMANDS
   #include "../sqlcommands.h"
#endif
#ifndef FPARSER
   #include "parser.h"
#endif

/* Estrutura global que guarda as informações obtidas pelo yacc
 * na identificação dos tokens
 */
rc_insert GLOBAL_DATA;

/* Estrutura auxiliar do reconhecedor.
 */
rc_parser GLOBAL_PARSER;




column *select_attributes = NULL;
column *select_attribute = NULL;
w_token *token_list = NULL;

void insert_token_list(w_token * nodo){
    w_token *p;

	if(token_list == NULL) token_list = nodo;

	else{
		for(p = token_list; p != NULL; p = p->next){
			if(p->next == NULL){
				p->next = nodo;
				nodo->next = NULL;
				break;
			}
		}
	}
}


void getToken(char * token, int type){
    w_token *novo;
    novo = (w_token *)malloc(sizeof(w_token));
    //printf("token: %s  tipo=%d\n", token, type);

    novo->tipo = type;
    novo->next = NULL;
    if(type == WT_ABRE_P){
        char *c = (char *)malloc(sizeof(char));
        *c = '(';
        novo->valor=c;
    }
    else if(type == WT_FECHA_P){
        char *c = (char *)malloc(sizeof(char));
        *c = ')';
        novo->valor=c;
    }
    else if(type == WT_NUMERO){
        int *c = malloc(sizeof(int));
        *c = convertI(token);
        novo->valor = c;
    }
    else if(type == WT_VALOR){
        int *c = malloc(sizeof(double));
        *c = convertD(token);
        novo->valor = c;
    }
    else{
        novo->valor=(void *)malloc(sizeof(token));
        strcpy(novo->valor,token);
    }
    insert_token_list(novo);
    novo = NULL;

}


void null_list(){
    w_token *p;
    w_token *a;
	for(p = token_list; p;){
		a = p->next;
        free(p);
        p = a;
	}
    token_list = NULL;

    column *q;
    column *b;
	for(q = select_attributes; q;){
		b = q->next;
        free(q);
        q = b;
	}
	select_attributes = NULL;
}

void start_list(){
	select_attributes = (column *)malloc(sizeof(column));
	select_attribute = (column *)malloc(sizeof(column));

	select_attributes->next = NULL;
	select_attributes->n = 0;

	select_attribute->next = NULL;
	select_attribute->n = 0;
}

void push_list(){
	column *p;

	if(select_attributes->n == 0){
		select_attributes = select_attribute;
		select_attributes->n++;
	}
	else if(select_attributes->n > 0){
		for(p = select_attributes; p != NULL; p = p->next){
			if(p->next == NULL){
				p->next = select_attribute;
				select_attribute->next = NULL;
				select_attributes->n++;
				break;
			}
		}
	}
}

void clear_list(){
	column *p;
	column *q;
	for(p = select_attributes; p != NULL;){
		q = p->next;
		free(p);
		p = q;
	}
	start_list();
}

void getAttr(int op, char **nome){
	if(op == -1){
		//	Faz nada
	}
	else if(op == 0){
		//select_attribute->nome = *nome;
		strcpy(select_attribute->nome, *nome);
	}
	else if(op == 1){
		//select_attribute->nomeCampo = *nome;
		strcpy(select_attribute->nomeCampo, *nome);
		push_list();

		select_attribute = (column *)malloc(sizeof(column));
		select_attribute->next = NULL;
		select_attribute->n = 0;
	}
	else{
		printf("ERRO: PASSADO OPCAO INVALIDA NA FUNCAO getattr()");
	}
}





void connect(char *nome) {
    int r;
    r = connectDB(nome);
	if (r == SUCCESS) {
        connected.db_name = malloc(sizeof(char)*((strlen(nome)+1)));

        strcpylower(connected.db_name, nome);

        connected.conn_active = 1;
        printf("You are now connected to database \"%s\" as user \"uffsdb\".\n", nome);
    } else {
    	printf("ERROR: Failed to establish connection with database named \"%s\". (Error code: %d)\n", nome, r);
    }
}

void invalidCommand(char *command) {
    printf("ERROR: Invalid command '%s'. Type \"help\" for help.\n", command);
}

void notConnected() {
    printf("ERROR: you are not connected to any database.\n");
}

void setObjName(char **nome) {
    if (GLOBAL_PARSER.mode != 0) {
        GLOBAL_DATA.objName = malloc(sizeof(char)*((strlen(*nome)+1)));

        strcpylower(GLOBAL_DATA.objName, *nome);
        GLOBAL_DATA.objName[strlen(*nome)] = '\0';
        GLOBAL_PARSER.step++;
    } else
        return;
}

void setColumnInsert(char **nome) {
    GLOBAL_DATA.columnName = realloc(GLOBAL_DATA.columnName, (GLOBAL_PARSER.col_count+1)*sizeof(char *));

    GLOBAL_DATA.columnName[GLOBAL_PARSER.col_count] = malloc(sizeof(char)*(strlen(*nome)+1));
    strcpylower(GLOBAL_DATA.columnName[GLOBAL_PARSER.col_count], *nome);
    GLOBAL_DATA.columnName[GLOBAL_PARSER.col_count][strlen(*nome)] = '\0';

    GLOBAL_PARSER.col_count++;
}

void setValueInsert(char *nome, char type) {
    int i;
    GLOBAL_DATA.values  = realloc(GLOBAL_DATA.values, (GLOBAL_PARSER.val_count+1)*sizeof(char *));
    GLOBAL_DATA.type    = realloc(GLOBAL_DATA.type, (GLOBAL_PARSER.val_count+1)*sizeof(char));

    // Adiciona o valor no vetor de strings
    GLOBAL_DATA.values[GLOBAL_PARSER.val_count] = malloc(sizeof(char)*(strlen(nome)+1));
    if (type == 'I' || type == 'D') {
        strcpy(GLOBAL_DATA.values[GLOBAL_PARSER.val_count], nome);
        GLOBAL_DATA.values[GLOBAL_PARSER.val_count][strlen(nome)] = '\0';
    } else if (type == 'S') {
        for (i = 1; i < strlen(nome)-1; i++) {
            GLOBAL_DATA.values[GLOBAL_PARSER.val_count][i-1] = nome[i];
        }
        GLOBAL_DATA.values[GLOBAL_PARSER.val_count][strlen(nome)-2] = '\0';
    }

    GLOBAL_DATA.type[GLOBAL_PARSER.val_count] = type;

    GLOBAL_PARSER.val_count++;
}

void setColumnCreate(char **nome) {
    GLOBAL_DATA.columnName  = realloc(GLOBAL_DATA.columnName, (GLOBAL_PARSER.col_count+1)*sizeof(char *));
    GLOBAL_DATA.attribute   = realloc(GLOBAL_DATA.attribute, (GLOBAL_PARSER.col_count+1)*sizeof(int));
    GLOBAL_DATA.fkColumn    = realloc(GLOBAL_DATA.fkColumn, (GLOBAL_PARSER.col_count+1)*sizeof(char *));
    GLOBAL_DATA.fkTable     = realloc(GLOBAL_DATA.fkTable, (GLOBAL_PARSER.col_count+1)*sizeof(char *));
    GLOBAL_DATA.values      = realloc(GLOBAL_DATA.values, (GLOBAL_PARSER.col_count+1)*sizeof(char *));
    GLOBAL_DATA.type        = realloc(GLOBAL_DATA.type, (GLOBAL_PARSER.col_count+1)*sizeof(char *));

    GLOBAL_DATA.values[GLOBAL_PARSER.col_count] = malloc(sizeof(char));
    GLOBAL_DATA.fkTable[GLOBAL_PARSER.col_count] = malloc(sizeof(char));
    GLOBAL_DATA.fkColumn[GLOBAL_PARSER.col_count] = malloc(sizeof(char));
    GLOBAL_DATA.columnName[GLOBAL_PARSER.col_count] = malloc(sizeof(char)*(strlen(*nome)+1));

    strcpylower(GLOBAL_DATA.columnName[GLOBAL_PARSER.col_count], *nome);

    GLOBAL_DATA.columnName[GLOBAL_PARSER.col_count][strlen(*nome)] = '\0';
    GLOBAL_DATA.type[GLOBAL_PARSER.col_count] = 0;
    GLOBAL_DATA.attribute[GLOBAL_PARSER.col_count] = NPK;

    GLOBAL_PARSER.col_count++;
    GLOBAL_PARSER.step = 2;
}

void setColumnTypeCreate(char type) {
    GLOBAL_DATA.type[GLOBAL_PARSER.col_count-1] = type;
    GLOBAL_PARSER.step++;
}

void setColumnSizeCreate(char *size) {
    GLOBAL_DATA.values[GLOBAL_PARSER.col_count-1] = realloc(GLOBAL_DATA.values[GLOBAL_PARSER.col_count-1], sizeof(char)*(strlen(size)+1));
    strcpy(GLOBAL_DATA.values[GLOBAL_PARSER.col_count-1], size);
    GLOBAL_DATA.values[GLOBAL_PARSER.col_count-1][strlen(size)-1] = '\0';
}

void setColumnPKCreate() {
    GLOBAL_DATA.attribute[GLOBAL_PARSER.col_count-1] = PK;
}

void setColumnFKTableCreate(char **nome) {
    GLOBAL_DATA.fkTable[GLOBAL_PARSER.col_count-1] = realloc(GLOBAL_DATA.fkTable[GLOBAL_PARSER.col_count-1], sizeof(char)*(strlen(*nome)+1));
    strcpylower(GLOBAL_DATA.fkTable[GLOBAL_PARSER.col_count-1], *nome);
    GLOBAL_DATA.fkTable[GLOBAL_PARSER.col_count-1][strlen(*nome)] = '\0';
    GLOBAL_DATA.attribute[GLOBAL_PARSER.col_count-1] = FK;
    GLOBAL_PARSER.step++;
}

void setColumnFKColumnCreate(char **nome) {
    GLOBAL_DATA.fkColumn[GLOBAL_PARSER.col_count-1] = realloc(GLOBAL_DATA.fkColumn[GLOBAL_PARSER.col_count-1], sizeof(char)*(strlen(*nome)+1));
    strcpylower(GLOBAL_DATA.fkColumn[GLOBAL_PARSER.col_count-1], *nome);
    GLOBAL_DATA.fkColumn[GLOBAL_PARSER.col_count-1][strlen(*nome)] = '\0';
    GLOBAL_PARSER.step++;
}


void clearGlobalStructs() {
    int i;

    if (GLOBAL_DATA.objName) {
        free(GLOBAL_DATA.objName);
        GLOBAL_DATA.objName = NULL;
    }

    for (i = 0; i < GLOBAL_DATA.N; i++ ) {
        if (GLOBAL_DATA.columnName)
            free(GLOBAL_DATA.columnName[i]);
        if (GLOBAL_DATA.values)
            free(GLOBAL_DATA.values[i]);
        if (GLOBAL_DATA.fkTable)
            free(GLOBAL_DATA.fkTable[i]);
        if (GLOBAL_DATA.fkColumn)
            free(GLOBAL_DATA.fkColumn[i]);
    }

    free(GLOBAL_DATA.columnName);
    GLOBAL_DATA.columnName = NULL;

    free(GLOBAL_DATA.values);
    GLOBAL_DATA.values = NULL;

    free(GLOBAL_DATA.fkTable);
    GLOBAL_DATA.fkTable = NULL;

    free(GLOBAL_DATA.fkColumn);
    GLOBAL_DATA.fkColumn = NULL;

    free(GLOBAL_DATA.type);
    GLOBAL_DATA.type = (char *)malloc(sizeof(char));

    free(GLOBAL_DATA.attribute);
    GLOBAL_DATA.attribute = (int *)malloc(sizeof(int));

    yylex_destroy();

    GLOBAL_DATA.N = 0;

    GLOBAL_PARSER.mode              = 0;
    GLOBAL_PARSER.parentesis        = 0;
    GLOBAL_PARSER.noerror           = 1;
    GLOBAL_PARSER.col_count         = 0;
    GLOBAL_PARSER.val_count         = 0;
    GLOBAL_PARSER.step              = 0;
}

void setMode(char mode) {
    GLOBAL_PARSER.mode = mode;
    GLOBAL_PARSER.step++;
}


int interface() {
    pthread_t pth;

    pthread_create(&pth, NULL, (void*)clearGlobalStructs, NULL);
    pthread_join(pth, NULL);

    connect("uffsdb"); // conecta automaticamente no banco padrão

    while(1){
        if (!connected.conn_active) {
            printf(">");
        } else {
            printf("%s=# ", connected.db_name);
        }

        pthread_create(&pth, NULL, (void*)yyparse, &GLOBAL_PARSER);
        pthread_join(pth, NULL);

        if (GLOBAL_PARSER.noerror) {
            if (GLOBAL_PARSER.mode != 0) {
                if (!connected.conn_active) {
                    notConnected();
                } else {
                    switch(GLOBAL_PARSER.mode) {
                        case OP_INSERT:
                            if (GLOBAL_DATA.N > 0) {
                                insert(&GLOBAL_DATA);
                            }
                            else
                                printf("WARNING: Nothing to be inserted. Command ignored.\n");
                            break;
                        case OP_SELECT_ALL:
                            pulpfic(select_attributes, GLOBAL_DATA.objName, token_list);
                            /*w_token *jujuba;
                            for(jujuba=token_list;jujuba;jujuba=jujuba->next){
                                printf("jujuba = %s\n",(char*)jujuba->valor);
                            }*/
                            break;
                        case OP_CREATE_TABLE:
                            createTable(&GLOBAL_DATA);
                            break;
                        case OP_CREATE_DATABASE:
                            createDB(GLOBAL_DATA.objName);
                            break;
                        case OP_DROP_TABLE:
                            excluirTabela(GLOBAL_DATA.objName);
                            break;
                        case OP_DROP_DATABASE:
                            dropDatabase(GLOBAL_DATA.objName);
                            break;
                        default: break;
                    }

                }
            }
        } else {
            GLOBAL_PARSER.consoleFlag = 1;
            switch(GLOBAL_PARSER.mode) {
                case OP_CREATE_DATABASE:
                case OP_DROP_DATABASE:
                case OP_CREATE_TABLE:
                case OP_DROP_TABLE:
                case OP_SELECT_ALL:
                case OP_INSERT:
                    if (GLOBAL_PARSER.step == 1) {
                        GLOBAL_PARSER.consoleFlag = 0;
                        printf("Expected object name.\n");
                    }
                break;

                default: break;
            }

            if (GLOBAL_PARSER.mode == OP_CREATE_TABLE) {
                if (GLOBAL_PARSER.step == 2) {
                    printf("Column not specified correctly.\n");
                    GLOBAL_PARSER.consoleFlag = 0;
                }
            } else if (GLOBAL_PARSER.mode == OP_INSERT) {
                if (GLOBAL_PARSER.step == 2) {
                    printf("Expected token \"VALUES\" after object name.\n");
                    GLOBAL_PARSER.consoleFlag = 0;
                }
            }

            printf("ERROR: syntax error.\n");
            GLOBAL_PARSER.noerror = 1;
        }

        if (GLOBAL_PARSER.mode != 0) {
            pthread_create(&pth, NULL, (void*)clearGlobalStructs, NULL);
            pthread_join(pth, NULL);
        }
    }
    return 0;
}

void yyerror(char *s, ...) {
    GLOBAL_PARSER.noerror = 0;
    /*extern yylineno;

    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "%d: error: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
    */
}
