%{
#include <stdio.h>
#include <string.h>
#include "cafelang.tab.h"

int line_num = 1;
int col_num = 1;

#define YY_USER_ACTION col_num += yyleng;
%}

%option noyywrap
%option yylineno

DIGIT       [0-9]
LETTER      [a-zA-Z]
IDENT       {LETTER}({LETTER}|{DIGIT}|_)*
NUM         {DIGIT}+(\.{DIGIT}+)?
WHITESPACE  [ \t\r]+
NEWLINE     \n

%%

"//".*                  { /* Comentário de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* Comentário de bloco */ }

"receita"               { return RECEITA; }
"quando"                { return QUANDO; }
"perfil"                { return PERFIL; }
"temperatura"           { return TEMPERATURA; }
"extrair"               { return EXTRAIR; }
"em"                    { return EM; }
"pressao_alvo"          { return PRESSAO_ALVO; }

"pronto"                { return PRONTO; }
"erro"                  { return ERRO; }
"sem_agua"              { return SEM_AGUA; }
"superaquecimento"      { return SUPERAQUECIMENTO; }
"sem_copo"              { return SEM_COPO; }
"porta_aberta"          { return PORTA_ABERTA; }

"suave"                 { return SUAVE; }
"medio"                 { return MEDIO; }
"forte"                 { return FORTE; }
"intenso"               { return INTENSO; }

"corpo"                 { return CORPO; }
"acidez"                { return ACIDEZ; }
"aroma"                 { return AROMA; }
"intensidade"           { return INTENSIDADE; }

"def"                   { return DEF; }
"const"                 { return CONST; }

"num"                   { return NUM_TYPE; }
"bool"                  { return BOOL_TYPE; }
"texto"                 { return TEXTO_TYPE; }
"ml"                    { return ML_TYPE; }
"g"                     { return G_TYPE; }
"s"                     { return S_TYPE; }
"ms"                    { return MS_TYPE; }
"celsius"               { return CELSIUS_TYPE; }

"se"                    { return SE; }
"senao"                 { return SENAO; }
"enquanto"              { return ENQUANTO; }
"repetir"               { return REPETIR; }
"vezes"                 { return VEZES; }
"para"                  { return PARA; }
"sair"                  { return SAIR; }
"pular"                 { return PULAR; }

"moer"                  { return MOER; }
"aquecer"               { return AQUECER; }
"bombear"               { return BOMBEAR; }
"servir"                { return SERVIR; }
"vaporizar"             { return VAPORIZAR; }
"pausar"                { return PAUSAR; }
"tocar"                 { return TOCAR; }
"limpar"                { return LIMPAR; }
"enxaguar"              { return ENXAGUAR; }
"despressurizar"        { return DESPRESSURIZAR; }

"temp"                  { return TEMP; }
"pressao"               { return PRESSAO; }
"agua"                  { return AGUA; }
"graos"                 { return GRAOS; }
"fluxo"                 { return FLUXO; }
"copo"                  { return COPO; }
"porta"                 { return PORTA; }

"verdadeiro"            { return VERDADEIRO; }
"falso"                 { return FALSO; }

"ou"                    { return OU; }
"e"                     { return E; }
"nao"                   { return NAO; }

"||"                    { return OR_OP; }
"&&"                    { return AND_OP; }
"=="                    { return EQ_OP; }
"!="                    { return NE_OP; }
"<="                    { return LE_OP; }
">="                    { return GE_OP; }
"<"                     { return LT_OP; }
">"                     { return GT_OP; }
":="                    { return ASSIGN_OP; }
"->"                    { return ARROW; }
".."                    { return RANGE; }

"bar"                   { return BAR; }
"°C"                    { return CELSIUS_UNIT; }
"C"                     { return C_UNIT; }

"{"                     { return LBRACE; }
"}"                     { return RBRACE; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
";"                     { return SEMICOLON; }
":"                     { return COLON; }
","                     { return COMMA; }

"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return MULT; }
"/"                     { return DIV; }
"%"                     { return MOD; }
"!"                     { return NOT; }

{IDENT}                 { 
                            yylval.str = strdup(yytext); 
                            return IDENTIFIER; 
                        }

{NUM}                   { 
                            yylval.num = atof(yytext); 
                            return NUMBER; 
                        }

\"([^\"\\\n]|\\(.|\n))*\" { 
                            yylval.str = strdup(yytext); 
                            return STRING; 
                        }

{WHITESPACE}            { /* Ignora espaços em branco */ }
{NEWLINE}               { line_num++; col_num = 1; }

.                       { 
                            fprintf(stderr, "Erro léxico: caractere não reconhecido '%s' na linha %d, coluna %d\n", 
                                    yytext, line_num, col_num); 
                        }

%%
