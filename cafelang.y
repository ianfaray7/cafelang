%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_num;
extern int col_num;

void yyerror(const char *s);

FILE *output_file;
%}

%union {
    double num;
    char *str;
}

%token RECEITA QUANDO PERFIL TEMPERATURA EXTRAIR EM PRESSAO_ALVO

%token PRONTO ERRO SEM_AGUA SUPERAQUECIMENTO SEM_COPO PORTA_ABERTA

%token SUAVE MEDIO FORTE INTENSO

%token CORPO ACIDEZ AROMA INTENSIDADE

%token DEF CONST

%token NUM_TYPE BOOL_TYPE TEXTO_TYPE ML_TYPE G_TYPE S_TYPE MS_TYPE CELSIUS_TYPE

%token SE SENAO ENQUANTO REPETIR VEZES PARA SAIR PULAR

%token MOER AQUECER BOMBEAR SERVIR VAPORIZAR PAUSAR TOCAR LIMPAR ENXAGUAR DESPRESSURIZAR

%token TEMP PRESSAO AGUA GRAOS FLUXO COPO PORTA

%token VERDADEIRO FALSO

%token OU E NAO

%token OR_OP AND_OP EQ_OP NE_OP LE_OP GE_OP LT_OP GT_OP ASSIGN_OP ARROW RANGE

%token BAR CELSIUS_UNIT C_UNIT

%token LBRACE RBRACE LPAREN RPAREN SEMICOLON COLON COMMA

%token PLUS MINUS MULT DIV MOD NOT

%token <str> IDENTIFIER STRING
%token <num> NUMBER

%left OU OR_OP
%left E AND_OP
%left EQ_OP NE_OP
%left LT_OP LE_OP GT_OP GE_OP
%left PLUS MINUS
%left MULT DIV MOD
%right NOT NAO UMINUS UPLUS

%start program

%%

program:
    toplevel_list
    ;

toplevel_list:
    | toplevel_list toplevel
    ;

toplevel:
    receita
    | reacao
    | decl_global
    | stmt
    ;
receita:
    RECEITA STRING bloco_receita
    ;

bloco_receita:
    LBRACE bloco_receita_items RBRACE
    ;

bloco_receita_items:
    /* vazio */
    | bloco_receita_items bloco_receita_item
    ;

bloco_receita_item:
    decl_senso
    | decl_local
    | stmt
    | ato SEMICOLON
    ;

reacao:
    QUANDO evento_tipo ARROW ato SEMICOLON
    ;

evento_tipo:
    PRONTO
    | ERRO
    | SEM_AGUA
    | SUPERAQUECIMENTO
    | SEM_COPO
    | PORTA_ABERTA
    ;

decl_senso:
    PERFIL LBRACE perf_items RBRACE SEMICOLON
    | TEMPERATURA medida_temp SEMICOLON
    | EXTRAIR medida_vol EM medida_tempo SEMICOLON
    | PRESSAO_ALVO NUMBER BAR SEMICOLON
    ;

perf_items:
    /* vazio */
    | perf_items perf_item
    ;

perf_item:
    CORPO nivel SEMICOLON
    | ACIDEZ nivel SEMICOLON
    | AROMA nivel SEMICOLON
    | INTENSIDADE nivel SEMICOLON
    ;

nivel:
    SUAVE
    | MEDIO
    | FORTE
    | INTENSO
    ;

decl_global:
    decl
    ;

decl_local:
    decl
    ;

decl:
    var_decl
    | const_decl
    ;

var_decl:
    DEF IDENTIFIER COLON tipo SEMICOLON
    | DEF IDENTIFIER COLON tipo ASSIGN_OP expr SEMICOLON
    ;

const_decl:
    CONST IDENTIFIER COLON tipo ASSIGN_OP expr SEMICOLON
    ;

tipo:
    NUM_TYPE
    | BOOL_TYPE
    | TEXTO_TYPE
    | ML_TYPE
    | G_TYPE
    | S_TYPE
    | MS_TYPE
    | CELSIUS_TYPE
    ;

stmt:
    assign SEMICOLON
    | if_stmt
    | while_stmt
    | repeat_stmt
    | for_range_stmt
    | SAIR SEMICOLON
    | PULAR SEMICOLON
    | bloco
    ;

bloco:
    LBRACE bloco_items RBRACE
    ;

bloco_items:
    | bloco_items bloco_item
    ;

bloco_item:
    decl
    | stmt
    | ato SEMICOLON
    ;

assign:
    lvalue ASSIGN_OP expr
    ;

lvalue:
    IDENTIFIER
    ;

if_stmt:
    SE LPAREN expr RPAREN stmt
    | SE LPAREN expr RPAREN stmt SENAO stmt
    ;

while_stmt:
    ENQUANTO LPAREN expr RPAREN stmt
    ;

repeat_stmt:
    REPETIR expr VEZES bloco
    ;

for_range_stmt:
    PARA IDENTIFIER EM expr RANGE expr bloco
    ;

ato:
    acao
    | acao argumentos
    ;

acao:
    MOER
    | AQUECER
    | BOMBEAR
    | SERVIR
    | VAPORIZAR
    | PAUSAR
    | TOCAR
    | LIMPAR
    | ENXAGUAR
    | DESPRESSURIZAR
    ;

argumentos:
    arg
    | argumentos COMMA arg
    ;

arg:
    expr
    | medida_vol
    | medida_peso
    | medida_temp
    | medida_tempo
    | STRING
    ;

expr:
    logic_or
    ;

logic_or:
    logic_and
    | logic_or OU logic_and
    | logic_or OR_OP logic_and
    ;

logic_and:
    equality
    | logic_and E equality
    | logic_and AND_OP equality
    ;

equality:
    relational
    | equality EQ_OP relational
    | equality NE_OP relational
    ;

relational:
    additive
    | relational LT_OP additive
    | relational LE_OP additive
    | relational GT_OP additive
    | relational GE_OP additive
    ;

additive:
    multiplicative
    | additive PLUS multiplicative
    | additive MINUS multiplicative
    ;

multiplicative:
    unary
    | multiplicative MULT unary
    | multiplicative DIV unary
    | multiplicative MOD unary
    ;

unary:
    primary
    | PLUS unary %prec UPLUS
    | MINUS unary %prec UMINUS
    | NOT unary
    | NAO unary
    ;

primary:
    NUMBER
    | bool_literal
    | STRING
    | sensor_zeroarg
    | lvalue
    | LPAREN expr RPAREN
    ;

bool_literal:
    VERDADEIRO
    | FALSO
    ;

sensor_zeroarg:
    sensor_nome LPAREN RPAREN
    ;

sensor_nome:
    TEMP
    | PRESSAO
    | AGUA
    | GRAOS
    | FLUXO
    | COPO
    | PORTA
    ;

medida_vol:
    NUMBER ML_TYPE
    ;

medida_peso:
    NUMBER G_TYPE
    ;

medida_tempo:
    NUMBER S_TYPE
    | NUMBER MS_TYPE
    ;

medida_temp:
    NUMBER CELSIUS_UNIT
    | NUMBER C_UNIT
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe na linha %d, coluna %d: %s\n", line_num, col_num, s);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Erro ao abrir arquivo de entrada: %s\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }

    // Arquivo de saída (assembly da VM)
    if (argc > 2) {
        output_file = fopen(argv[2], "w");
        if (!output_file) {
            fprintf(stderr, "Erro ao criar arquivo de saída: %s\n", argv[2]);
            return 1;
        }
    } else {
        output_file = fopen("output.asm", "w");
    }

    fprintf(output_file, "; Código assembly gerado pelo compilador CafeLang\n");
    fprintf(output_file, "; Análise sintática concluída com sucesso\n\n");

    int result = yyparse();
    
    if (result == 0) {
        printf("Análise sintática concluída com sucesso!\n");
        fprintf(output_file, "\n; Programa analisado sem erros\n");
    } else {
        printf("Análise sintática falhou.\n");
        fprintf(output_file, "\n; Programa contém erros\n");
    }

    if (yyin != stdin) {
        fclose(yyin);
    }
    fclose(output_file);

    return result;
}
