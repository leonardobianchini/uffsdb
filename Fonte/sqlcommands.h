#define FSQLCOMMANDS 1   // flag para garantir a não reinclusão

#ifndef FMACROS // garante que macros.h não seja reincluída
   #include "macros.h"
#endif
///
#ifndef FTYPES // garante que types.h não seja reincluída
  #include "types.h"
#endif
/* insert: Recebe uma estrutura rc_insert e valida os tokens encontrados pela interface().
 *         Se os valores forem válidos, insere um novo valor.
 */
void insert(rc_insert *);
int allColumnsExists(rc_insert *, table *);
char getInsertedType(rc_insert *, char *c, table *);
char *getInsertedValue(rc_insert *, char *, table *);
int typesCompatible(char , char);
/*
    Esta função finaliza a inserção de valores em uma tabela. Assume que o usuário entrou com todos
    os campos de uma tupla completa.
    Retorna:
        -> ERRO_ABRIR_ARQUIVO, quando ocorreu um erro ao abrir o arquivo fs_object.dat ou fs_schema.dat;
        -> ERRO_NO_TAMANHO_STRING, quando ocorreu um erro no tamanho da string inserida;
        -> ERRO_NOME_CAMPO, quando o nome do campo passado na estrutura;
        -> ERRO_NO_TIPO_INTEIRO, quando o valor passado não é um inteiro;
        -> ERRO_NO_TIPO_DOUBLE, quando o valor passado não é um double;
        -> ERRO_NO_TIPO_CHAR, quando o valor passado é maior que 1byte;
        -> SUCCESS, quando a função teve sucesso em sua operação de inserção na tabela.
    *nome - Nome da tabela que vai ser inserido os valores da estrutura *c.
    *c - Estrutura com o valores que vão ser inseridos na tabela *nome.
*/
int finalizaInsert(char *, column *);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Utilizada para impressão de tabelas.
    Parametros: Nome da tabela (char).
    Retorno:    void.
   ---------------------------------------------------------------------------------------------*/
/*
Essa função é a receita do sucesso
*/
void pulpfic(column *, char [], w_token *);

void imprime(char [] );
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Função para exclusão de tabelas.
    Parametros: Nome da tabela (char).
    Retorno:    INT
                SUCCESS,
                ERRO_REMOVER_ARQUIVO_OBJECT,
                ERRO_REMOVER_ARQUIVO_SCHEMA,
                ERRO_LEITURA_DADOS.
   ---------------------------------------------------------------------------------------------*/
int excluirTabela(char *);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Copia todas as informações menos a tabela do objeto, que será removida.
    Parametros: Objeto que será removido do schema.
    Retorno:    INT
                SUCCESS,
                ERRO_REMOVER_ARQUIVO_SCHEMA
   ---------------------------------------------------------------------------------------------*/
int procuraSchemaArquivo(struct fs_objects);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Gera as verificações em relação a chave FK.
    Parametros: Nome da Tabela, Coluna C, Nome do Campo, Valor do Campo, Tabela Apontada e Atributo Apontado.
    Retorno:    INT
                SUCCESS,
                ERRO_DE_PARAMETRO,
                ERRO_CHAVE_ESTRANGEIRA
   ---------------------------------------------------------------------------------------------*/
int verificaChaveFK(char *, column *, char *, char *, char *, char *);

/* ----------------------------------------------------------------------------------------------
    Objetivo:   Gera as verificações em relação a chave pK.
    Parametros: Nome da Tabela, Coluna C, Nome do Campo, Valor do Campo
    Retorno:    INT
                SUCCESS,
                ERRO_DE_PARAMETRO,
                ERRO_CHAVE_PRIMARIA
   ---------------------------------------------------------------------------------------------*/
int verificaChavePK(char *, column *, char *, char *);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Inicializa os atributos necessários para a verificação de FK e PK.
    Parametros: Objeto da tabela, Tabela, Buffer e nome da tabela.
    Retorno:    INT
                SUCCESS,
                ERRO_DE_PARAMETRO,
   ---------------------------------------------------------------------------------------------*/
int iniciaAtributos(struct fs_objects *, tp_table **, tp_buffer **, char *);
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Recebe o nome de uma tabela e engloba as funções leObjeto() e leSchema().
    Parametros: Nome da Tabela, Objeto da Tabela e tabela.
    Retorno:    tp_table
   ---------------------------------------------------------------------------------------------*/
tp_table *abreTabela(char *, struct fs_objects *, tp_table **);
/* createTable: Recebe uma estrutura contendo os parâmetros do CREATE TABLE
 *              e cria uma tabela no banco corrente
 */
void createTable(rc_insert *);
////
int verifyFieldName(char **, int );
////
int verifyFK(char *, char *);


//  Função adaptada para fazer seleção das tuplas do banco
void imprime2(char nomeTabela[], column * l, w_token * token_list);

//  Recebe uma pagina e retorna uma lista com as colunas selecionadas
column * select_list(column * pages, column * attr, int nAttr, int nTuplas, w_token * token_list);

//  Verifica se o identificador de a está em b
int inList(column *a, column *b);

//  Converte uma lista de colunas em um vetor de colunas
column * list_like_page(column * lista);

//  Converte um vetor de colunas em uma lista de colunas
column * table_to_list(char nomeTabela[]);

//  Retorna verdadeiro quando satisfaz a cláusula where
int verify_where(w_token* tklist);

//  Insere um nodo na lista de colunas
column * insert_column_list(column * l, column * novo);

//  Insere um nodo na lista de tokens
w_token * insert_token(w_token * l, w_token * nodo);

//  Quando encontrado valor do tipo objeto faz a troca com o valor referenciado
//  na população do banco e aloca espaço para o conteúdo que está na cláusula where
w_token * subs_tokens(w_token * token_list, column * tupla, int nAttr);

//  Retorna verdadeiro quando satisfaz a cláusula where
int remove_aritmetico(w_token* l);

//  Converte tipo de token para tipo de coluna
char type_to_type(int a);

//  Imprime o valor do token
void print_token(w_token * ind);

//  Recebe dois operandos e um relacional e retorna a solução da relação
int compara_relacional(w_token * r, w_token * rel, w_token * t2);

//  Função para validar nome e atributos de tabelas
int tableName_test(w_token * token_list, char nomeTabela[]);
