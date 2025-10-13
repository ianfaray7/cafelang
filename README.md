# CafeLang


## EBNF
```
PROGRAM         = { TOPLEVEL } ;

TOPLEVEL        = RECEITA | REACAO | DECL_GLOBAL | STMT ;

(************** Núcleo declarativo **************)
RECEITA         = "receita", STRING, BLOCO_RECEITA ;
BLOCO_RECEITA   = "{", { DECL_SENSO | DECL_LOCAL | STMT | ATO ";" }, "}" ;

REACAO          = "quando", EVENTO_TIPO, "->", ATO, ";" ;
EVENTO_TIPO     = "pronto" | "erro" | "sem_agua" | "superaquecimento"
                | "sem_copo" | "porta_aberta" ;

(************** Parâmetros sensoriais declarativos **************)
DECL_SENSO      = "perfil", "{", { PERF_ITEM }, "}" , ";"
                | "temperatura", MEDIDA_TEMP, ";"
                | "extrair", MEDIDA_VOL, "em", MEDIDA_TEMPO, ";"
                | "pressao_alvo", NUM, "bar", ";"
                ;

PERF_ITEM       = "corpo", NIVEL, ";"
                | "acidez", NIVEL, ";"
                | "aroma", NIVEL, ";"
                | "intensidade", NIVEL, ";"
                ;

NIVEL           = "suave" | "medio" | "forte" | "intenso" ;

(************** Declarações e tipos **************)
DECL_GLOBAL     = DECL ;
DECL_LOCAL      = DECL ;

DECL            = VAR_DECL | CONST_DECL ;

VAR_DECL        = "def", IDENT, ":", TIPO, [ ":=", EXPR ], ";" ;
CONST_DECL      = "const", IDENT, ":", TIPO, ":=", EXPR, ";" ;

TIPO            = "num" | "bool" | "texto" 
                | "ml" | "g" | "s" | "ms" | "celsius" ;

(************** Sentenças (imperativas) **************)
STMT            = ASSIGN ";"
                | IF_STMT
                | WHILE_STMT
                | REPEAT_STMT
                | FOR_RANGE_STMT
                | BREAK_STMT ";"
                | CONTINUE_STMT ";"
                | BLOCO
                ;

BLOCO           = "{", { DECL | STMT | ATO ";" }, "}" ;

ASSIGN          = LVALUE, ":=", EXPR ;
LVALUE          = IDENT ;

IF_STMT         = "se", "(", EXPR, ")", STMT, [ "senao", STMT ] ;

WHILE_STMT      = "enquanto", "(", EXPR, ")", STMT ;

REPEAT_STMT     = "repetir", EXPR, "vezes", BLOCO ;

FOR_RANGE_STMT  = "para", IDENT, "em", EXPR, "..", EXPR, BLOCO ;

BREAK_STMT      = "sair" ;
CONTINUE_STMT   = "pular" ;

(************** Ações de domínio (atos) **************)
ATO             = ACAO, [ ARGUMENTOS ] ;

ACAO            = "moer" | "aquecer" | "bombear" | "servir"
                | "vaporizar" | "pausar" | "tocar" | "limpar"
                | "enxaguar" | "despressurizar" ;

ARGUMENTOS      = ARG , { "," , ARG } ;
ARG             = EXPR
                | MEDIDA_VOL
                | MEDIDA_PESO
                | MEDIDA_TEMP
                | MEDIDA_TEMPO
                | STRING ;

(************** Expressões **************)
EXPR            = LOGIC_OR ;

LOGIC_OR        = LOGIC_AND, { ("ou" | "||"), LOGIC_AND } ;
LOGIC_AND       = EQUALITY , { ("e"  | "&&"), EQUALITY  } ;

EQUALITY        = REL, { ("==" | "!="), REL } ;
REL             = ADD, { ("<" | "<=" | ">" | ">="), ADD } ;

ADD             = MUL, { ("+" | "-"), MUL } ;
MUL             = UNARY, { ("*" | "/" | "%"), UNARY } ;

UNARY           = [ ("+" | "-" | "!" | "nao") ], UNARY
                | PRIMARY ;

PRIMARY         = NUMBER
                | BOOL
                | STRING
                | SENSOR_ZEROARG
                | LVALUE
                | "(", EXPR, ")"
                ;

BOOL            = "verdadeiro" | "falso" ;

(************** Sensores (somente leitura) **************)
SENSOR_ZEROARG  = SENSOR_NOME, "(", ")" ;
SENSOR_NOME     = "temp" | "pressao" | "agua" | "graos" | "fluxo" | "copo" | "porta" ;

(************** Literais com unidade **************)
MEDIDA_VOL      = NUM, "ml" ;
MEDIDA_PESO     = NUM, "g" ;
MEDIDA_TEMPO    = NUM, ("s" | "ms") ;
MEDIDA_TEMP     = NUM, ("°C" | "C") ;

(************** Léxico básico **************)
IDENT           = LETTER, { LETTER | DIGIT | "_" } ;
NUMBER          = NUM ;
NUM             = DIGIT, { DIGIT }, [ ".", DIGIT, { DIGIT } ] ;
STRING          = "\"", { CHAR | ESCAPE }, "\"" ;

LETTER          = "A" | ... | "Z" | "a" | ... | "z" ;
DIGIT           = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;

ESCAPE          = "\\" ( "\"" | "\\" | "n" | "t" ) ;
CHAR            = ? qualquer caractere exceto aspas duplas e nova linha ? ;
```

