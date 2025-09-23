# CafeLang


## EBNF
```
(* Programa de alto nível *)
PROGRAM        = "programa", IDENT, BLOCK ;

BLOCK          = "{", { DECL | STMT }, "}" ;

(* Declarações *)
DECL           = VAR_DECL | FUNC_DECL ;

VAR_DECL       = "var", VAR_LIST, ":", TYPE, [ ASSIGN_INIT ], ";" ;
VAR_LIST       = IDENT, { ",", IDENT } ;
ASSIGN_INIT    = ":=", EXPR ;
TYPE           = "inteiro" | "real" | "bool" | "texto" 
               | ARRAY_TYPE ;
ARRAY_TYPE     = "array", "<", TYPE, ">", "[", EXPR, "]" ;

FUNC_DECL      = "func", IDENT, "(", [ PARAMS ], ")", [ "->", TYPE ], BLOCK ;
PARAMS         = PARAM, { ",", PARAM } ;
PARAM          = IDENT, ":", TYPE ;

(* Sentenças *)
STMT           = ASSIGN ";"
               | CALL ";"
               | RETURN_STMT ";"
               | IF_STMT
               | WHILE_STMT
               | FOR_STMT
               | BREAK_STMT ";"
               | CONTINUE_STMT ";"
               | BLOCK ;

ASSIGN         = LVALUE, (":=" | "="), EXPR ;
LVALUE         = IDENT | INDEXING ;
INDEXING       = IDENT, "[", EXPR, "]" ;

RETURN_STMT    = "retorna", [ EXPR ] ;

IF_STMT        = "se", "(", EXPR, ")", STMT, [ "senao", STMT ] ;

WHILE_STMT     = "enquanto", "(", EXPR, ")", STMT ;

FOR_STMT       = "para", "(", FOR_INIT, ";", [ EXPR ], ";", [ ASSIGN ], ")", STMT ;
FOR_INIT       = [ "var", IDENT, ":", TYPE, [ ASSIGN_INIT ] | ASSIGN ] ;

BREAK_STMT     = "quebra" ;
CONTINUE_STMT  = "continua" ;

(* Expressões *)
EXPR           = LOGIC_OR ;

LOGIC_OR       = LOGIC_AND, { ("ou" | "||"), LOGIC_AND } ;
LOGIC_AND      = EQUALITY,  { ("e"  | "&&"), EQUALITY  } ;

EQUALITY       = REL, { ("==" | "!="), REL } ;
REL            = ADD, { ("<" | "<=" | ">" | ">="), ADD } ;

ADD            = MUL, { ("+" | "-"), MUL } ;
MUL            = UNARY, { ("*" | "/" | "%"), UNARY } ;

UNARY          = [ ("+" | "-" | "!" | "nao") ], UNARY
               | PRIMARY ;

PRIMARY        = NUMBER
               | STRING
               | "verdadeiro"
               | "falso"
               | LVALUE
               | CALL
               | "(", EXPR, ")" ;

CALL           = IDENT, "(", [ ARGS ], ")" ;
ARGS           = EXPR, { ",", EXPR } ;

(* Literais e léxicos básicos *)
IDENT          = LETTER, { LETTER | DIGIT | "_" } ;
NUMBER         = DIGIT, { DIGIT }, [ ".", DIGIT, { DIGIT } ] ;
STRING         = "\"", { CHAR | ESCAPE }, "\"" ;
LETTER         = "A" | ... | "Z" | "a" | ... | "z" ;
DIGIT          = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
ESCAPE         = "\\" ( "\"" | "\\" | "n" | "t" ) ;
CHAR           = ? qualquer caractere exceto aspas duplas e nova linha, 
                  ou sequência ESCAPE ? ;

(* Built-ins de sensores e ações — como chamadas normais *)
SENSOR_CALL    = ( "temp" | "agua" | "graos" | "copo" | "porta" | "pressao" ), "(", ")" ;
ACTION_CALL    = ( "aquecer" | "moer" | "bombear" | "servir" 
                 | "vapor" | "beep" | "pausa" | "limpeza" ), 
                 "(", [ ARGS ], ")" ;
```

