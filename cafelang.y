%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_num;
extern int col_num;

void yyerror(const char *s);

FILE *output_file;

// Contador de labels
int label_counter = 0;
int temp_counter = 0;

// Funções auxiliares de geração de código
void emit(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(output_file, fmt, args);
    va_end(args);
}

void emit_comment(const char *comment) {
    fprintf(output_file, "; %s\n", comment);
}

int new_label() {
    return label_counter++;
}

const char* map_sensor(const char *sensor) {
    if (strcmp(sensor, "temp") == 0) return "TEMP_SENSOR";
    if (strcmp(sensor, "pressao") == 0) return "PRESSURE";
    if (strcmp(sensor, "agua") == 0) return "WATER_LEVEL";
    if (strcmp(sensor, "graos") == 0) return "BEAN_LEVEL";
    if (strcmp(sensor, "fluxo") == 0) return "FLOW_RATE";
    if (strcmp(sensor, "copo") == 0) return "CUP_PRESENT";
    if (strcmp(sensor, "porta") == 0) return "DOOR_OPEN";
    return "UNKNOWN";
}
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
    toplevel_list { 
        emit("\n; Fim do programa\n");
        emit("HALT\n");
    }
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
    RECEITA STRING bloco_receita {
        emit_comment("=== Fim da receita ===");
    }
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
    DEF IDENTIFIER COLON tipo SEMICOLON {
        emit("; variable declaration: %s\n", $2);
        free($2);
    }
    | DEF IDENTIFIER COLON tipo ASSIGN_OP expr SEMICOLON {
        emit("; variable declaration with init: %s\n", $2);
        emit("SET R0 %.2f\n", $<num>6);
        free($2);
    }
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
    lvalue ASSIGN_OP expr {
        emit("; assignment: %s := <expr>\n", $<str>1);
        emit("; Simplified: store result in memory location for %s\n", $<str>1);
    }
    ;

lvalue:
    IDENTIFIER
    ;

if_stmt:
    SE LPAREN expr RPAREN {
        int label_end = new_label();
        emit("; if statement\n");
        emit("SET R0 0\n");
        emit("CMP TEMP R0\n");
        emit("JE L%d\n", label_end);
        $<num>$ = label_end;
    } stmt {
        emit("L%d:\n", (int)$<num>5);
    }
    | SE LPAREN expr RPAREN {
        int label_else = new_label();
        emit("; if-else statement\n");
        emit("SET R0 0\n");
        emit("CMP TEMP R0\n");
        emit("JE L%d\n", label_else);
        $<num>$ = label_else;
    } stmt SENAO {
        int label_end = new_label();
        emit("GOTO L%d\n", label_end);
        emit("L%d:\n", (int)$<num>5);
        $<num>$ = label_end;
    } stmt {
        emit("L%d:\n", (int)$<num>8);
    }
    ;

while_stmt:
    ENQUANTO {
        int label_start = new_label();
        emit("L%d:\n", label_start);
        emit("; while loop\n");
        $<num>$ = label_start;
    } LPAREN expr RPAREN {
        int label_end = new_label();
        emit("SET R0 0\n");
        emit("CMP TEMP R0\n");
        emit("JE L%d\n", label_end);
        $<num>$ = label_end;
    } stmt {
        emit("GOTO L%d\n", (int)$<num>2);
        emit("L%d:\n", (int)$<num>6);
    }
    ;

repeat_stmt:
    REPETIR expr VEZES {
        emit("; repeat loop\n");
        emit("SET R1 %.0f\n", $<num>2);
        int label_start = new_label();
        int label_end = new_label();
        emit("L%d:\n", label_start);
        emit("DECJZ R1 L%d\n", label_end);
        $<num>$ = label_start;
        $<num>3 = label_end;
    } bloco {
        emit("GOTO L%d\n", (int)$<num>4);
        emit("L%d:\n", (int)$<num>3);
    }
    ;

for_range_stmt:
    PARA IDENTIFIER EM expr RANGE expr {
        emit("; for-range loop: %s\n", $2);
        emit("SET R2 %.0f\n", $<num>4);  // start
        emit("SET R3 %.0f\n", $<num>6);  // end
        int label_start = new_label();
        int label_end = new_label();
        emit("L%d:\n", label_start);
        emit("CMP R2 R3\n");
        emit("JG L%d\n", label_end);
        $<num>$ = label_start;
        $<num>6 = label_end;
    } bloco {
        emit("INC R2\n");
        emit("GOTO L%d\n", (int)$<num>7);
        emit("L%d:\n", (int)$<num>6);
    }
    ;

ato:
    acao {
        // Ação sem argumentos
        char action_name[64];
        sprintf(action_name, "ACTION %s", $<str>1);
        emit("%s\n", action_name);
    }
    | acao argumentos {
        // Ação com argumentos (simplificado)
        emit("; Acao com argumentos\n");
    }
    ;

acao:
    MOER { $<str>$ = strdup("moer"); }
    | AQUECER { $<str>$ = strdup("aquecer"); }
    | BOMBEAR { $<str>$ = strdup("bombear"); }
    | SERVIR { $<str>$ = strdup("servir"); }
    | VAPORIZAR { $<str>$ = strdup("vaporizar"); }
    | PAUSAR { $<str>$ = strdup("pausar"); }
    | TOCAR { $<str>$ = strdup("tocar"); }
    | LIMPAR { $<str>$ = strdup("limpar"); }
    | ENXAGUAR { $<str>$ = strdup("enxaguar"); }
    | DESPRESSURIZAR { $<str>$ = strdup("despressurizar"); }
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
    multiplicative { $<num>$ = $<num>1; }
    | additive PLUS multiplicative {
        emit("; addition\n");
        emit("ADD TEMP R0\n");
        $<num>$ = $<num>1 + $<num>3;
    }
    | additive MINUS multiplicative {
        emit("; subtraction\n");
        emit("SUB TEMP R0\n");
        $<num>$ = $<num>1 - $<num>3;
    }
    ;

multiplicative:
    unary { $<num>$ = $<num>1; }
    | multiplicative MULT unary {
        emit("; multiplication\n");
        emit("MUL TEMP R0\n");
        $<num>$ = $<num>1 * $<num>3;
    }
    | multiplicative DIV unary {
        emit("; division\n");
        emit("DIV TEMP R0\n");
        if ($<num>3 != 0) $<num>$ = $<num>1 / $<num>3;
        else $<num>$ = 0;
    }
    | multiplicative MOD unary {
        emit("; modulo\n");
        emit("MOD TEMP R0\n");
        $<num>$ = 0;
    }
    ;

unary:
    primary
    | PLUS unary %prec UPLUS
    | MINUS unary %prec UMINUS
    | NOT unary
    | NAO unary
    ;

primary:
    NUMBER { 
        $<num>$ = $1;
        emit("; push number %.2f\n", $1);
    }
    | bool_literal {
        $<num>$ = $<num>1;
    }
    | STRING { 
        emit("; string literal: %s\n", $1);
        free($1);
        $<num>$ = 0;
    }
    | sensor_zeroarg {
        $<num>$ = 0;
    }
    | lvalue {
        emit("; load variable: %s\n", $<str>1);
        free($<str>1);
        $<num>$ = 0;
    }
    | LPAREN expr RPAREN {
        $<num>$ = $<num>2;
    }
    ;

bool_literal:
    VERDADEIRO { 
        $<num>$ = 1.0;
        emit("; boolean true\n");
    }
    | FALSO { 
        $<num>$ = 0.0;
        emit("; boolean false\n");
    }
    ;

sensor_zeroarg:
    sensor_nome LPAREN RPAREN {
        const char *mapped = map_sensor($<str>1);
        emit("; sensor read: %s\n", $<str>1);
        emit("LOAD TEMP %s\n", mapped);
        free($<str>1);
    }
    ;

sensor_nome:
    TEMP { $<str>$ = strdup("temp"); }
    | PRESSAO { $<str>$ = strdup("pressao"); }
    | AGUA { $<str>$ = strdup("agua"); }
    | GRAOS { $<str>$ = strdup("graos"); }
    | FLUXO { $<str>$ = strdup("fluxo"); }
    | COPO { $<str>$ = strdup("copo"); }
    | PORTA { $<str>$ = strdup("porta"); }
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
