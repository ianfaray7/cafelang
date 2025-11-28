/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CAFELANG_TAB_H_INCLUDED
# define YY_YY_CAFELANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    RECEITA = 258,                 /* RECEITA  */
    QUANDO = 259,                  /* QUANDO  */
    PERFIL = 260,                  /* PERFIL  */
    TEMPERATURA = 261,             /* TEMPERATURA  */
    EXTRAIR = 262,                 /* EXTRAIR  */
    EM = 263,                      /* EM  */
    PRESSAO_ALVO = 264,            /* PRESSAO_ALVO  */
    PRONTO = 265,                  /* PRONTO  */
    ERRO = 266,                    /* ERRO  */
    SEM_AGUA = 267,                /* SEM_AGUA  */
    SUPERAQUECIMENTO = 268,        /* SUPERAQUECIMENTO  */
    SEM_COPO = 269,                /* SEM_COPO  */
    PORTA_ABERTA = 270,            /* PORTA_ABERTA  */
    SUAVE = 271,                   /* SUAVE  */
    MEDIO = 272,                   /* MEDIO  */
    FORTE = 273,                   /* FORTE  */
    INTENSO = 274,                 /* INTENSO  */
    CORPO = 275,                   /* CORPO  */
    ACIDEZ = 276,                  /* ACIDEZ  */
    AROMA = 277,                   /* AROMA  */
    INTENSIDADE = 278,             /* INTENSIDADE  */
    DEF = 279,                     /* DEF  */
    CONST = 280,                   /* CONST  */
    NUM_TYPE = 281,                /* NUM_TYPE  */
    BOOL_TYPE = 282,               /* BOOL_TYPE  */
    TEXTO_TYPE = 283,              /* TEXTO_TYPE  */
    ML_TYPE = 284,                 /* ML_TYPE  */
    G_TYPE = 285,                  /* G_TYPE  */
    S_TYPE = 286,                  /* S_TYPE  */
    MS_TYPE = 287,                 /* MS_TYPE  */
    CELSIUS_TYPE = 288,            /* CELSIUS_TYPE  */
    SE = 289,                      /* SE  */
    SENAO = 290,                   /* SENAO  */
    ENQUANTO = 291,                /* ENQUANTO  */
    REPETIR = 292,                 /* REPETIR  */
    VEZES = 293,                   /* VEZES  */
    PARA = 294,                    /* PARA  */
    SAIR = 295,                    /* SAIR  */
    PULAR = 296,                   /* PULAR  */
    MOER = 297,                    /* MOER  */
    AQUECER = 298,                 /* AQUECER  */
    BOMBEAR = 299,                 /* BOMBEAR  */
    SERVIR = 300,                  /* SERVIR  */
    VAPORIZAR = 301,               /* VAPORIZAR  */
    PAUSAR = 302,                  /* PAUSAR  */
    TOCAR = 303,                   /* TOCAR  */
    LIMPAR = 304,                  /* LIMPAR  */
    ENXAGUAR = 305,                /* ENXAGUAR  */
    DESPRESSURIZAR = 306,          /* DESPRESSURIZAR  */
    TEMP = 307,                    /* TEMP  */
    PRESSAO = 308,                 /* PRESSAO  */
    AGUA = 309,                    /* AGUA  */
    GRAOS = 310,                   /* GRAOS  */
    FLUXO = 311,                   /* FLUXO  */
    COPO = 312,                    /* COPO  */
    PORTA = 313,                   /* PORTA  */
    VERDADEIRO = 314,              /* VERDADEIRO  */
    FALSO = 315,                   /* FALSO  */
    OU = 316,                      /* OU  */
    E = 317,                       /* E  */
    NAO = 318,                     /* NAO  */
    OR_OP = 319,                   /* OR_OP  */
    AND_OP = 320,                  /* AND_OP  */
    EQ_OP = 321,                   /* EQ_OP  */
    NE_OP = 322,                   /* NE_OP  */
    LE_OP = 323,                   /* LE_OP  */
    GE_OP = 324,                   /* GE_OP  */
    LT_OP = 325,                   /* LT_OP  */
    GT_OP = 326,                   /* GT_OP  */
    ASSIGN_OP = 327,               /* ASSIGN_OP  */
    ARROW = 328,                   /* ARROW  */
    RANGE = 329,                   /* RANGE  */
    BAR = 330,                     /* BAR  */
    CELSIUS_UNIT = 331,            /* CELSIUS_UNIT  */
    C_UNIT = 332,                  /* C_UNIT  */
    LBRACE = 333,                  /* LBRACE  */
    RBRACE = 334,                  /* RBRACE  */
    LPAREN = 335,                  /* LPAREN  */
    RPAREN = 336,                  /* RPAREN  */
    SEMICOLON = 337,               /* SEMICOLON  */
    COLON = 338,                   /* COLON  */
    COMMA = 339,                   /* COMMA  */
    PLUS = 340,                    /* PLUS  */
    MINUS = 341,                   /* MINUS  */
    MULT = 342,                    /* MULT  */
    DIV = 343,                     /* DIV  */
    MOD = 344,                     /* MOD  */
    NOT = 345,                     /* NOT  */
    IDENTIFIER = 346,              /* IDENTIFIER  */
    STRING = 347,                  /* STRING  */
    NUMBER = 348,                  /* NUMBER  */
    UMINUS = 349,                  /* UMINUS  */
    UPLUS = 350                    /* UPLUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "cafelang.y"

    double num;
    char *str;

#line 164 "cafelang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CAFELANG_TAB_H_INCLUDED  */
