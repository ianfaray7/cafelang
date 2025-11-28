/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cafelang.y"

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

#line 119 "cafelang.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "cafelang.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RECEITA = 3,                    /* RECEITA  */
  YYSYMBOL_QUANDO = 4,                     /* QUANDO  */
  YYSYMBOL_PERFIL = 5,                     /* PERFIL  */
  YYSYMBOL_TEMPERATURA = 6,                /* TEMPERATURA  */
  YYSYMBOL_EXTRAIR = 7,                    /* EXTRAIR  */
  YYSYMBOL_EM = 8,                         /* EM  */
  YYSYMBOL_PRESSAO_ALVO = 9,               /* PRESSAO_ALVO  */
  YYSYMBOL_PRONTO = 10,                    /* PRONTO  */
  YYSYMBOL_ERRO = 11,                      /* ERRO  */
  YYSYMBOL_SEM_AGUA = 12,                  /* SEM_AGUA  */
  YYSYMBOL_SUPERAQUECIMENTO = 13,          /* SUPERAQUECIMENTO  */
  YYSYMBOL_SEM_COPO = 14,                  /* SEM_COPO  */
  YYSYMBOL_PORTA_ABERTA = 15,              /* PORTA_ABERTA  */
  YYSYMBOL_SUAVE = 16,                     /* SUAVE  */
  YYSYMBOL_MEDIO = 17,                     /* MEDIO  */
  YYSYMBOL_FORTE = 18,                     /* FORTE  */
  YYSYMBOL_INTENSO = 19,                   /* INTENSO  */
  YYSYMBOL_CORPO = 20,                     /* CORPO  */
  YYSYMBOL_ACIDEZ = 21,                    /* ACIDEZ  */
  YYSYMBOL_AROMA = 22,                     /* AROMA  */
  YYSYMBOL_INTENSIDADE = 23,               /* INTENSIDADE  */
  YYSYMBOL_DEF = 24,                       /* DEF  */
  YYSYMBOL_CONST = 25,                     /* CONST  */
  YYSYMBOL_NUM_TYPE = 26,                  /* NUM_TYPE  */
  YYSYMBOL_BOOL_TYPE = 27,                 /* BOOL_TYPE  */
  YYSYMBOL_TEXTO_TYPE = 28,                /* TEXTO_TYPE  */
  YYSYMBOL_ML_TYPE = 29,                   /* ML_TYPE  */
  YYSYMBOL_G_TYPE = 30,                    /* G_TYPE  */
  YYSYMBOL_S_TYPE = 31,                    /* S_TYPE  */
  YYSYMBOL_MS_TYPE = 32,                   /* MS_TYPE  */
  YYSYMBOL_CELSIUS_TYPE = 33,              /* CELSIUS_TYPE  */
  YYSYMBOL_SE = 34,                        /* SE  */
  YYSYMBOL_SENAO = 35,                     /* SENAO  */
  YYSYMBOL_ENQUANTO = 36,                  /* ENQUANTO  */
  YYSYMBOL_REPETIR = 37,                   /* REPETIR  */
  YYSYMBOL_VEZES = 38,                     /* VEZES  */
  YYSYMBOL_PARA = 39,                      /* PARA  */
  YYSYMBOL_SAIR = 40,                      /* SAIR  */
  YYSYMBOL_PULAR = 41,                     /* PULAR  */
  YYSYMBOL_MOER = 42,                      /* MOER  */
  YYSYMBOL_AQUECER = 43,                   /* AQUECER  */
  YYSYMBOL_BOMBEAR = 44,                   /* BOMBEAR  */
  YYSYMBOL_SERVIR = 45,                    /* SERVIR  */
  YYSYMBOL_VAPORIZAR = 46,                 /* VAPORIZAR  */
  YYSYMBOL_PAUSAR = 47,                    /* PAUSAR  */
  YYSYMBOL_TOCAR = 48,                     /* TOCAR  */
  YYSYMBOL_LIMPAR = 49,                    /* LIMPAR  */
  YYSYMBOL_ENXAGUAR = 50,                  /* ENXAGUAR  */
  YYSYMBOL_DESPRESSURIZAR = 51,            /* DESPRESSURIZAR  */
  YYSYMBOL_TEMP = 52,                      /* TEMP  */
  YYSYMBOL_PRESSAO = 53,                   /* PRESSAO  */
  YYSYMBOL_AGUA = 54,                      /* AGUA  */
  YYSYMBOL_GRAOS = 55,                     /* GRAOS  */
  YYSYMBOL_FLUXO = 56,                     /* FLUXO  */
  YYSYMBOL_COPO = 57,                      /* COPO  */
  YYSYMBOL_PORTA = 58,                     /* PORTA  */
  YYSYMBOL_VERDADEIRO = 59,                /* VERDADEIRO  */
  YYSYMBOL_FALSO = 60,                     /* FALSO  */
  YYSYMBOL_OU = 61,                        /* OU  */
  YYSYMBOL_E = 62,                         /* E  */
  YYSYMBOL_NAO = 63,                       /* NAO  */
  YYSYMBOL_OR_OP = 64,                     /* OR_OP  */
  YYSYMBOL_AND_OP = 65,                    /* AND_OP  */
  YYSYMBOL_EQ_OP = 66,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 67,                     /* NE_OP  */
  YYSYMBOL_LE_OP = 68,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 69,                     /* GE_OP  */
  YYSYMBOL_LT_OP = 70,                     /* LT_OP  */
  YYSYMBOL_GT_OP = 71,                     /* GT_OP  */
  YYSYMBOL_ASSIGN_OP = 72,                 /* ASSIGN_OP  */
  YYSYMBOL_ARROW = 73,                     /* ARROW  */
  YYSYMBOL_RANGE = 74,                     /* RANGE  */
  YYSYMBOL_BAR = 75,                       /* BAR  */
  YYSYMBOL_CELSIUS_UNIT = 76,              /* CELSIUS_UNIT  */
  YYSYMBOL_C_UNIT = 77,                    /* C_UNIT  */
  YYSYMBOL_LBRACE = 78,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 79,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 80,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 81,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 82,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 83,                     /* COLON  */
  YYSYMBOL_COMMA = 84,                     /* COMMA  */
  YYSYMBOL_PLUS = 85,                      /* PLUS  */
  YYSYMBOL_MINUS = 86,                     /* MINUS  */
  YYSYMBOL_MULT = 87,                      /* MULT  */
  YYSYMBOL_DIV = 88,                       /* DIV  */
  YYSYMBOL_MOD = 89,                       /* MOD  */
  YYSYMBOL_NOT = 90,                       /* NOT  */
  YYSYMBOL_IDENTIFIER = 91,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 92,                    /* STRING  */
  YYSYMBOL_NUMBER = 93,                    /* NUMBER  */
  YYSYMBOL_UMINUS = 94,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 95,                     /* UPLUS  */
  YYSYMBOL_YYACCEPT = 96,                  /* $accept  */
  YYSYMBOL_program = 97,                   /* program  */
  YYSYMBOL_toplevel_list = 98,             /* toplevel_list  */
  YYSYMBOL_toplevel = 99,                  /* toplevel  */
  YYSYMBOL_receita = 100,                  /* receita  */
  YYSYMBOL_bloco_receita = 101,            /* bloco_receita  */
  YYSYMBOL_bloco_receita_items = 102,      /* bloco_receita_items  */
  YYSYMBOL_bloco_receita_item = 103,       /* bloco_receita_item  */
  YYSYMBOL_reacao = 104,                   /* reacao  */
  YYSYMBOL_evento_tipo = 105,              /* evento_tipo  */
  YYSYMBOL_decl_senso = 106,               /* decl_senso  */
  YYSYMBOL_perf_items = 107,               /* perf_items  */
  YYSYMBOL_perf_item = 108,                /* perf_item  */
  YYSYMBOL_nivel = 109,                    /* nivel  */
  YYSYMBOL_decl_global = 110,              /* decl_global  */
  YYSYMBOL_decl_local = 111,               /* decl_local  */
  YYSYMBOL_decl = 112,                     /* decl  */
  YYSYMBOL_var_decl = 113,                 /* var_decl  */
  YYSYMBOL_const_decl = 114,               /* const_decl  */
  YYSYMBOL_tipo = 115,                     /* tipo  */
  YYSYMBOL_stmt = 116,                     /* stmt  */
  YYSYMBOL_bloco = 117,                    /* bloco  */
  YYSYMBOL_bloco_items = 118,              /* bloco_items  */
  YYSYMBOL_bloco_item = 119,               /* bloco_item  */
  YYSYMBOL_assign = 120,                   /* assign  */
  YYSYMBOL_lvalue = 121,                   /* lvalue  */
  YYSYMBOL_if_stmt = 122,                  /* if_stmt  */
  YYSYMBOL_123_1 = 123,                    /* @1  */
  YYSYMBOL_124_2 = 124,                    /* @2  */
  YYSYMBOL_125_3 = 125,                    /* @3  */
  YYSYMBOL_while_stmt = 126,               /* while_stmt  */
  YYSYMBOL_127_4 = 127,                    /* @4  */
  YYSYMBOL_128_5 = 128,                    /* @5  */
  YYSYMBOL_repeat_stmt = 129,              /* repeat_stmt  */
  YYSYMBOL_130_6 = 130,                    /* @6  */
  YYSYMBOL_for_range_stmt = 131,           /* for_range_stmt  */
  YYSYMBOL_132_7 = 132,                    /* @7  */
  YYSYMBOL_ato = 133,                      /* ato  */
  YYSYMBOL_acao = 134,                     /* acao  */
  YYSYMBOL_argumentos = 135,               /* argumentos  */
  YYSYMBOL_arg = 136,                      /* arg  */
  YYSYMBOL_expr = 137,                     /* expr  */
  YYSYMBOL_logic_or = 138,                 /* logic_or  */
  YYSYMBOL_logic_and = 139,                /* logic_and  */
  YYSYMBOL_equality = 140,                 /* equality  */
  YYSYMBOL_relational = 141,               /* relational  */
  YYSYMBOL_additive = 142,                 /* additive  */
  YYSYMBOL_multiplicative = 143,           /* multiplicative  */
  YYSYMBOL_unary = 144,                    /* unary  */
  YYSYMBOL_primary = 145,                  /* primary  */
  YYSYMBOL_bool_literal = 146,             /* bool_literal  */
  YYSYMBOL_sensor_zeroarg = 147,           /* sensor_zeroarg  */
  YYSYMBOL_sensor_nome = 148,              /* sensor_nome  */
  YYSYMBOL_medida_vol = 149,               /* medida_vol  */
  YYSYMBOL_medida_peso = 150,              /* medida_peso  */
  YYSYMBOL_medida_tempo = 151,             /* medida_tempo  */
  YYSYMBOL_medida_temp = 152               /* medida_temp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   282

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   350


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   106,   107,   111,   112,   113,   114,   117,
     123,   126,   128,   132,   133,   134,   135,   139,   143,   144,
     145,   146,   147,   148,   152,   153,   154,   155,   158,   160,
     164,   165,   166,   167,   171,   172,   173,   174,   178,   182,
     186,   187,   191,   195,   203,   207,   208,   209,   210,   211,
     212,   213,   214,   218,   219,   220,   221,   222,   223,   224,
     225,   229,   232,   233,   237,   238,   239,   243,   250,   254,
     254,   264,   271,   264,   282,   287,   282,   300,   300,   316,
     316,   335,   341,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   361,   362,   366,   367,   368,   369,   370,
     371,   375,   379,   380,   381,   385,   386,   387,   391,   392,
     393,   397,   398,   399,   400,   401,   405,   406,   411,   419,
     420,   425,   431,   439,   440,   441,   442,   443,   447,   451,
     454,   459,   462,   467,   473,   477,   484,   493,   494,   495,
     496,   497,   498,   499,   503,   507,   511,   512,   516,   517
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RECEITA", "QUANDO",
  "PERFIL", "TEMPERATURA", "EXTRAIR", "EM", "PRESSAO_ALVO", "PRONTO",
  "ERRO", "SEM_AGUA", "SUPERAQUECIMENTO", "SEM_COPO", "PORTA_ABERTA",
  "SUAVE", "MEDIO", "FORTE", "INTENSO", "CORPO", "ACIDEZ", "AROMA",
  "INTENSIDADE", "DEF", "CONST", "NUM_TYPE", "BOOL_TYPE", "TEXTO_TYPE",
  "ML_TYPE", "G_TYPE", "S_TYPE", "MS_TYPE", "CELSIUS_TYPE", "SE", "SENAO",
  "ENQUANTO", "REPETIR", "VEZES", "PARA", "SAIR", "PULAR", "MOER",
  "AQUECER", "BOMBEAR", "SERVIR", "VAPORIZAR", "PAUSAR", "TOCAR", "LIMPAR",
  "ENXAGUAR", "DESPRESSURIZAR", "TEMP", "PRESSAO", "AGUA", "GRAOS",
  "FLUXO", "COPO", "PORTA", "VERDADEIRO", "FALSO", "OU", "E", "NAO",
  "OR_OP", "AND_OP", "EQ_OP", "NE_OP", "LE_OP", "GE_OP", "LT_OP", "GT_OP",
  "ASSIGN_OP", "ARROW", "RANGE", "BAR", "CELSIUS_UNIT", "C_UNIT", "LBRACE",
  "RBRACE", "LPAREN", "RPAREN", "SEMICOLON", "COLON", "COMMA", "PLUS",
  "MINUS", "MULT", "DIV", "MOD", "NOT", "IDENTIFIER", "STRING", "NUMBER",
  "UMINUS", "UPLUS", "$accept", "program", "toplevel_list", "toplevel",
  "receita", "bloco_receita", "bloco_receita_items", "bloco_receita_item",
  "reacao", "evento_tipo", "decl_senso", "perf_items", "perf_item",
  "nivel", "decl_global", "decl_local", "decl", "var_decl", "const_decl",
  "tipo", "stmt", "bloco", "bloco_items", "bloco_item", "assign", "lvalue",
  "if_stmt", "@1", "@2", "@3", "while_stmt", "@4", "@5", "repeat_stmt",
  "@6", "for_range_stmt", "@7", "ato", "acao", "argumentos", "arg", "expr",
  "logic_or", "logic_and", "equality", "relational", "additive",
  "multiplicative", "unary", "primary", "bool_literal", "sensor_zeroarg",
  "sensor_nome", "medida_vol", "medida_peso", "medida_tempo",
  "medida_temp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-171)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-101)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -171,    28,     0,  -171,   -57,   135,   -31,   -19,   -42,  -171,
      49,   -17,   -29,   -16,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,    -1,    55,  -171,  -171,  -171,
    -171,    54,  -171,  -171,  -171,  -171,  -171,  -171,    65,    74,
      89,    49,    99,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,    49,    49,    49,    49,    49,  -171,  -171,  -171,
     142,   -38,   -35,    10,   -13,   -43,   -25,  -171,  -171,  -171,
    -171,   105,   178,  -171,  -171,   187,  -171,    49,  -171,  -171,
      71,    57,    57,   106,    49,  -171,   107,  -171,  -171,  -171,
    -171,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,   108,    49,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,   109,   189,  -171,   119,   110,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,   -53,   118,  -171,   112,  -171,
     116,   -35,   -35,    10,    10,   -13,   -13,   -43,   -43,   -43,
     -43,   -25,   -25,  -171,  -171,  -171,  -171,   121,  -171,   -51,
      16,   115,  -171,  -171,  -171,  -171,  -171,  -171,   122,   103,
     113,   114,  -171,  -171,  -171,  -171,  -171,  -171,   120,  -171,
      49,  -171,    49,   -24,   -24,  -171,  -171,    49,  -171,  -171,
    -171,  -171,  -171,  -171,   189,  -171,     3,   123,   172,   195,
     133,  -171,   127,   131,  -171,   179,   -24,  -171,  -171,   -14,
    -171,   124,   134,  -171,  -171,  -171,  -171,   116,    78,    78,
      78,    78,   136,  -171,    68,   137,  -171,   -24,  -171,  -171,
    -171,  -171,  -171,   138,   140,   157,   158,  -171,  -171,  -171,
    -171,  -171,  -171,  -171
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,    62,    68,     4,     5,     6,     7,
      38,    40,    41,     8,    60,     0,     0,    54,    55,    56,
      57,     0,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,   137,   138,   139,   140,   141,   142,   143,
     134,   135,     0,     0,     0,     0,     0,   130,   128,   132,
       0,   101,   102,   105,   108,   111,   116,   119,   123,   129,
     131,     0,     0,    58,    59,     0,    53,     0,    11,     9,
       0,     0,     0,     0,     0,   127,     0,   124,   125,   126,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    61,    64,
      65,    63,     0,    81,    67,     0,     0,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    69,     0,   133,
       0,   103,   104,   106,   107,   109,   110,   113,   115,   112,
     114,   117,   118,   120,   121,   122,   136,     0,    66,   130,
     128,    82,    93,    95,    96,    97,    99,    98,     0,     0,
       0,     0,    10,    12,    13,    14,    39,    15,     0,    17,
       0,    42,     0,     0,     0,    75,    78,     0,   144,   145,
     146,   147,   148,   149,     0,    28,     0,     0,     0,     0,
       0,    16,     0,     0,    70,     0,     0,    79,    94,     0,
      25,     0,     0,    43,    44,    72,    76,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    27,     0,    80,    34,
      35,    36,    37,     0,     0,     0,     0,    24,    26,    73,
      30,    31,    32,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -170,  -171,  -171,   -64,  -171,  -171,   168,
     -73,  -135,  -171,  -171,  -171,    -2,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,   -66,  -171,  -171,
      21,    -9,  -171,    39,    43,    56,    77,    82,   -34,  -171,
    -171,  -171,  -171,    81,  -171,    42,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    16,    17,    79,   125,   173,    18,    38,
     174,   209,   223,   233,    19,   175,    20,    21,    22,   135,
      23,    24,    75,   121,    25,    59,    27,   183,   184,   227,
      28,    42,   206,    29,   140,    30,   217,   122,   123,   161,
     162,   163,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,   164,   165,   166,   167
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    60,   120,     4,     5,   186,   218,   219,   220,   221,
       8,   119,     9,    10,   126,    11,    12,    13,    85,   180,
      87,    88,    89,    91,     6,     7,    92,    93,     3,   181,
      94,  -100,    83,  -100,     8,    31,     9,    10,    41,    11,
      12,    13,   101,   102,    86,   188,   189,   190,   191,   234,
     235,   236,   177,    73,    14,    97,    98,    99,   100,   178,
      39,   176,   103,   104,   105,   222,    74,    15,   124,   153,
     154,   155,    40,    26,    72,   138,    95,    96,    14,   192,
     193,    76,   228,   127,   128,   129,   130,   131,   132,   133,
     134,    15,   192,   193,   229,   230,   231,   232,   157,   190,
     191,    43,    44,    45,    46,    47,    48,    49,    50,    51,
     204,   205,    52,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    26,   168,   169,   170,    77,   171,    53,
     141,   142,    78,   216,    54,    55,   143,   144,    80,    56,
      15,    57,    58,     6,     7,    32,    33,    34,    35,    36,
      37,   145,   146,     8,   239,     9,    10,    81,    11,    12,
      13,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   202,    82,   203,   147,   148,   149,   150,   207,    84,
      90,    26,    26,   151,   152,   106,   107,   137,   139,   156,
     182,   158,   179,   185,    14,   187,   196,    14,   172,   194,
     195,   188,   201,   211,    26,   210,   198,   200,   212,   213,
      15,     6,     7,   214,   215,   208,   226,   224,   237,   238,
     240,     8,   241,     9,    10,    26,    11,    12,    13,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   242,
     243,    43,    44,    45,    46,    47,    48,    49,    50,    51,
     136,   199,    52,   225,   197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,   118,     0,     0,    53,
       0,     0,     0,     0,    54,    55,     0,     0,    15,    56,
      15,   159,   160
};

static const yytype_int16 yycheck[] =
{
       2,    10,    75,     3,     4,   140,    20,    21,    22,    23,
      34,    75,    36,    37,    80,    39,    40,    41,    52,    72,
      54,    55,    56,    61,    24,    25,    64,    62,     0,    82,
      65,    82,    41,    84,    34,    92,    36,    37,    80,    39,
      40,    41,    85,    86,    53,    29,    30,    31,    32,   219,
     220,   221,   125,    82,    78,    68,    69,    70,    71,   125,
      91,   125,    87,    88,    89,    79,    82,    91,    77,   103,
     104,   105,    91,    75,    91,    84,    66,    67,    78,    76,
      77,    82,   217,    26,    27,    28,    29,    30,    31,    32,
      33,    91,    76,    77,    16,    17,    18,    19,   107,    31,
      32,    52,    53,    54,    55,    56,    57,    58,    59,    60,
     183,   184,    63,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,   125,     5,     6,     7,    72,     9,    80,
      91,    92,    78,   206,    85,    86,    93,    94,    73,    90,
      91,    92,    93,    24,    25,    10,    11,    12,    13,    14,
      15,    95,    96,    34,   227,    36,    37,    83,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,   180,    83,   182,    97,    98,    99,   100,   187,    80,
      38,   183,   184,   101,   102,    80,     8,    81,    81,    81,
      72,    82,    82,    81,    78,    74,    93,    78,    79,    84,
      78,    29,    82,     8,   206,    82,    93,    93,    75,    82,
      91,    24,    25,    82,    35,   194,    82,    93,    82,    82,
      82,    34,    82,    36,    37,   227,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    82,
      82,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      82,   170,    63,   211,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    91,    90,
      91,    92,    93
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,    98,     0,     3,     4,    24,    25,    34,    36,
      37,    39,    40,    41,    78,    91,    99,   100,   104,   110,
     112,   113,   114,   116,   117,   120,   121,   122,   126,   129,
     131,    92,    10,    11,    12,    13,    14,    15,   105,    91,
      91,    80,   127,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    63,    80,    85,    86,    90,    92,    93,   121,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    91,    82,    82,   118,    82,    72,    78,   101,
      73,    83,    83,   137,    80,   144,   137,   144,   144,   144,
      38,    61,    64,    62,    65,    66,    67,    68,    69,    70,
      71,    85,    86,    87,    88,    89,    80,     8,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    79,   112,
     116,   119,   133,   134,   137,   102,   133,    26,    27,    28,
      29,    30,    31,    32,    33,   115,   115,    81,   137,    81,
     130,   139,   139,   140,   140,   141,   141,   142,   142,   142,
     142,   143,   143,   144,   144,   144,    81,   137,    82,    92,
      93,   135,   136,   137,   149,   150,   151,   152,     5,     6,
       7,     9,    79,   103,   106,   111,   112,   116,   133,    82,
      72,    82,    72,   123,   124,    81,   117,    74,    29,    30,
      31,    32,    76,    77,    84,    78,    93,   152,    93,   149,
      93,    82,   137,   137,   116,   116,   128,   137,   136,   107,
      82,     8,    75,    82,    82,    35,   116,   132,    20,    21,
      22,    23,    79,   108,    93,   151,    82,   125,   117,    16,
      17,    18,    19,   109,   109,   109,   109,    82,    82,   116,
      82,    82,    82,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    98,    99,    99,    99,    99,   100,
     101,   102,   102,   103,   103,   103,   103,   104,   105,   105,
     105,   105,   105,   105,   106,   106,   106,   106,   107,   107,
     108,   108,   108,   108,   109,   109,   109,   109,   110,   111,
     112,   112,   113,   113,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   118,   118,   119,   119,   119,   120,   121,   123,
     122,   124,   125,   122,   127,   128,   126,   130,   129,   132,
     131,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   135,   135,   136,   136,   136,   136,   136,
     136,   137,   138,   138,   138,   139,   139,   139,   140,   140,
     140,   141,   141,   141,   141,   141,   142,   142,   142,   143,
     143,   143,   143,   144,   144,   144,   144,   144,   145,   145,
     145,   145,   145,   145,   146,   146,   147,   148,   148,   148,
     148,   148,   148,   148,   149,   150,   151,   151,   152,   152
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     3,
       3,     0,     2,     1,     1,     1,     2,     5,     1,     1,
       1,     1,     1,     1,     5,     3,     5,     4,     0,     2,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     7,     7,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     3,     0,     2,     1,     1,     2,     3,     1,     0,
       6,     0,     0,     9,     0,     0,     7,     0,     5,     0,
       8,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: toplevel_list  */
#line 100 "cafelang.y"
                  { 
        emit("\n; Fim do programa\n");
        emit("HALT\n");
    }
#line 1460 "cafelang.tab.c"
    break;

  case 9: /* receita: RECEITA STRING bloco_receita  */
#line 117 "cafelang.y"
                                 {
        emit_comment("=== Fim da receita ===");
    }
#line 1468 "cafelang.tab.c"
    break;

  case 42: /* var_decl: DEF IDENTIFIER COLON tipo SEMICOLON  */
#line 191 "cafelang.y"
                                        {
        emit("; variable declaration: %s\n", (yyvsp[-3].str));
        free((yyvsp[-3].str));
    }
#line 1477 "cafelang.tab.c"
    break;

  case 43: /* var_decl: DEF IDENTIFIER COLON tipo ASSIGN_OP expr SEMICOLON  */
#line 195 "cafelang.y"
                                                         {
        emit("; variable declaration with init: %s\n", (yyvsp[-5].str));
        emit("SET R0 %.2f\n", (yyvsp[-1].num));
        free((yyvsp[-5].str));
    }
#line 1487 "cafelang.tab.c"
    break;

  case 67: /* assign: lvalue ASSIGN_OP expr  */
#line 243 "cafelang.y"
                          {
        emit("; assignment: %s := <expr>\n", (yyvsp[-2].str));
        emit("; Simplified: store result in memory location for %s\n", (yyvsp[-2].str));
    }
#line 1496 "cafelang.tab.c"
    break;

  case 69: /* @1: %empty  */
#line 254 "cafelang.y"
                          {
        int label_end = new_label();
        emit("; if statement\n");
        emit("SET R0 0\n");
        emit("CMP TEMP R0\n");
        emit("JE L%d\n", label_end);
        (yyval.num) = label_end;
    }
#line 1509 "cafelang.tab.c"
    break;

  case 70: /* if_stmt: SE LPAREN expr RPAREN @1 stmt  */
#line 261 "cafelang.y"
           {
        emit("L%d:\n", (int)(yyvsp[-1].num));
    }
#line 1517 "cafelang.tab.c"
    break;

  case 71: /* @2: %empty  */
#line 264 "cafelang.y"
                            {
        int label_else = new_label();
        emit("; if-else statement\n");
        emit("SET R0 0\n");
        emit("CMP TEMP R0\n");
        emit("JE L%d\n", label_else);
        (yyval.num) = label_else;
    }
#line 1530 "cafelang.tab.c"
    break;

  case 72: /* @3: %empty  */
#line 271 "cafelang.y"
                 {
        int label_end = new_label();
        emit("GOTO L%d\n", label_end);
        emit("L%d:\n", (int)(yyvsp[-2].num));
        (yyval.num) = label_end;
    }
#line 1541 "cafelang.tab.c"
    break;

  case 73: /* if_stmt: SE LPAREN expr RPAREN @2 stmt SENAO @3 stmt  */
#line 276 "cafelang.y"
           {
        emit("L%d:\n", (int)(yyvsp[-1].num));
    }
#line 1549 "cafelang.tab.c"
    break;

  case 74: /* @4: %empty  */
#line 282 "cafelang.y"
             {
        int label_start = new_label();
        emit("L%d:\n", label_start);
        emit("; while loop\n");
        (yyval.num) = label_start;
    }
#line 1560 "cafelang.tab.c"
    break;

  case 75: /* @5: %empty  */
#line 287 "cafelang.y"
                         {
        int label_end = new_label();
        emit("SET R0 0\n");
        emit("CMP TEMP R0\n");
        emit("JE L%d\n", label_end);
        (yyval.num) = label_end;
    }
#line 1572 "cafelang.tab.c"
    break;

  case 76: /* while_stmt: ENQUANTO @4 LPAREN expr RPAREN @5 stmt  */
#line 293 "cafelang.y"
           {
        emit("GOTO L%d\n", (int)(yyvsp[-5].num));
        emit("L%d:\n", (int)(yyvsp[-1].num));
    }
#line 1581 "cafelang.tab.c"
    break;

  case 77: /* @6: %empty  */
#line 300 "cafelang.y"
                       {
        emit("; repeat loop\n");
        emit("SET R1 %.0f\n", (yyvsp[-1].num));
        int label_start = new_label();
        int label_end = new_label();
        emit("L%d:\n", label_start);
        emit("DECJZ R1 L%d\n", label_end);
        (yyval.num) = label_start;
        (yyvsp[0].num) = label_end;
    }
#line 1596 "cafelang.tab.c"
    break;

  case 78: /* repeat_stmt: REPETIR expr VEZES @6 bloco  */
#line 309 "cafelang.y"
            {
        emit("GOTO L%d\n", (int)(yyvsp[-1].num));
        emit("L%d:\n", (int)(yyvsp[-2].num));
    }
#line 1605 "cafelang.tab.c"
    break;

  case 79: /* @7: %empty  */
#line 316 "cafelang.y"
                                       {
        emit("; for-range loop: %s\n", (yyvsp[-4].str));
        emit("SET R2 %.0f\n", (yyvsp[-2].num));  // start
        emit("SET R3 %.0f\n", (yyvsp[0].num));  // end
        int label_start = new_label();
        int label_end = new_label();
        emit("L%d:\n", label_start);
        emit("CMP R2 R3\n");
        emit("JG L%d\n", label_end);
        (yyval.num) = label_start;
        (yyvsp[0].num) = label_end;
    }
#line 1622 "cafelang.tab.c"
    break;

  case 80: /* for_range_stmt: PARA IDENTIFIER EM expr RANGE expr @7 bloco  */
#line 327 "cafelang.y"
            {
        emit("INC R2\n");
        emit("GOTO L%d\n", (int)(yyvsp[-1].num));
        emit("L%d:\n", (int)(yyvsp[-2].num));
    }
#line 1632 "cafelang.tab.c"
    break;

  case 81: /* ato: acao  */
#line 335 "cafelang.y"
         {
        // Ação sem argumentos
        char action_name[64];
        sprintf(action_name, "ACTION %s", (yyvsp[0].str));
        emit("%s\n", action_name);
    }
#line 1643 "cafelang.tab.c"
    break;

  case 82: /* ato: acao argumentos  */
#line 341 "cafelang.y"
                      {
        // Ação com argumentos (simplificado)
        emit("; Acao com argumentos\n");
    }
#line 1652 "cafelang.tab.c"
    break;

  case 83: /* acao: MOER  */
#line 348 "cafelang.y"
         { (yyval.str) = strdup("moer"); }
#line 1658 "cafelang.tab.c"
    break;

  case 84: /* acao: AQUECER  */
#line 349 "cafelang.y"
              { (yyval.str) = strdup("aquecer"); }
#line 1664 "cafelang.tab.c"
    break;

  case 85: /* acao: BOMBEAR  */
#line 350 "cafelang.y"
              { (yyval.str) = strdup("bombear"); }
#line 1670 "cafelang.tab.c"
    break;

  case 86: /* acao: SERVIR  */
#line 351 "cafelang.y"
             { (yyval.str) = strdup("servir"); }
#line 1676 "cafelang.tab.c"
    break;

  case 87: /* acao: VAPORIZAR  */
#line 352 "cafelang.y"
                { (yyval.str) = strdup("vaporizar"); }
#line 1682 "cafelang.tab.c"
    break;

  case 88: /* acao: PAUSAR  */
#line 353 "cafelang.y"
             { (yyval.str) = strdup("pausar"); }
#line 1688 "cafelang.tab.c"
    break;

  case 89: /* acao: TOCAR  */
#line 354 "cafelang.y"
            { (yyval.str) = strdup("tocar"); }
#line 1694 "cafelang.tab.c"
    break;

  case 90: /* acao: LIMPAR  */
#line 355 "cafelang.y"
             { (yyval.str) = strdup("limpar"); }
#line 1700 "cafelang.tab.c"
    break;

  case 91: /* acao: ENXAGUAR  */
#line 356 "cafelang.y"
               { (yyval.str) = strdup("enxaguar"); }
#line 1706 "cafelang.tab.c"
    break;

  case 92: /* acao: DESPRESSURIZAR  */
#line 357 "cafelang.y"
                     { (yyval.str) = strdup("despressurizar"); }
#line 1712 "cafelang.tab.c"
    break;

  case 116: /* additive: multiplicative  */
#line 405 "cafelang.y"
                   { (yyval.num) = (yyvsp[0].num); }
#line 1718 "cafelang.tab.c"
    break;

  case 117: /* additive: additive PLUS multiplicative  */
#line 406 "cafelang.y"
                                   {
        emit("; addition\n");
        emit("ADD TEMP R0\n");
        (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num);
    }
#line 1728 "cafelang.tab.c"
    break;

  case 118: /* additive: additive MINUS multiplicative  */
#line 411 "cafelang.y"
                                    {
        emit("; subtraction\n");
        emit("SUB TEMP R0\n");
        (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num);
    }
#line 1738 "cafelang.tab.c"
    break;

  case 119: /* multiplicative: unary  */
#line 419 "cafelang.y"
          { (yyval.num) = (yyvsp[0].num); }
#line 1744 "cafelang.tab.c"
    break;

  case 120: /* multiplicative: multiplicative MULT unary  */
#line 420 "cafelang.y"
                                {
        emit("; multiplication\n");
        emit("MUL TEMP R0\n");
        (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num);
    }
#line 1754 "cafelang.tab.c"
    break;

  case 121: /* multiplicative: multiplicative DIV unary  */
#line 425 "cafelang.y"
                               {
        emit("; division\n");
        emit("DIV TEMP R0\n");
        if ((yyvsp[0].num) != 0) (yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num);
        else (yyval.num) = 0;
    }
#line 1765 "cafelang.tab.c"
    break;

  case 122: /* multiplicative: multiplicative MOD unary  */
#line 431 "cafelang.y"
                               {
        emit("; modulo\n");
        emit("MOD TEMP R0\n");
        (yyval.num) = 0;
    }
#line 1775 "cafelang.tab.c"
    break;

  case 128: /* primary: NUMBER  */
#line 447 "cafelang.y"
           { 
        (yyval.num) = (yyvsp[0].num);
        emit("; push number %.2f\n", (yyvsp[0].num));
    }
#line 1784 "cafelang.tab.c"
    break;

  case 129: /* primary: bool_literal  */
#line 451 "cafelang.y"
                   {
        (yyval.num) = (yyvsp[0].num);
    }
#line 1792 "cafelang.tab.c"
    break;

  case 130: /* primary: STRING  */
#line 454 "cafelang.y"
             { 
        emit("; string literal: %s\n", (yyvsp[0].str));
        free((yyvsp[0].str));
        (yyval.num) = 0;
    }
#line 1802 "cafelang.tab.c"
    break;

  case 131: /* primary: sensor_zeroarg  */
#line 459 "cafelang.y"
                     {
        (yyval.num) = 0;
    }
#line 1810 "cafelang.tab.c"
    break;

  case 132: /* primary: lvalue  */
#line 462 "cafelang.y"
             {
        emit("; load variable: %s\n", (yyvsp[0].str));
        free((yyvsp[0].str));
        (yyval.num) = 0;
    }
#line 1820 "cafelang.tab.c"
    break;

  case 133: /* primary: LPAREN expr RPAREN  */
#line 467 "cafelang.y"
                         {
        (yyval.num) = (yyvsp[-1].num);
    }
#line 1828 "cafelang.tab.c"
    break;

  case 134: /* bool_literal: VERDADEIRO  */
#line 473 "cafelang.y"
               { 
        (yyval.num) = 1.0;
        emit("; boolean true\n");
    }
#line 1837 "cafelang.tab.c"
    break;

  case 135: /* bool_literal: FALSO  */
#line 477 "cafelang.y"
            { 
        (yyval.num) = 0.0;
        emit("; boolean false\n");
    }
#line 1846 "cafelang.tab.c"
    break;

  case 136: /* sensor_zeroarg: sensor_nome LPAREN RPAREN  */
#line 484 "cafelang.y"
                              {
        const char *mapped = map_sensor((yyvsp[-2].str));
        emit("; sensor read: %s\n", (yyvsp[-2].str));
        emit("LOAD TEMP %s\n", mapped);
        free((yyvsp[-2].str));
    }
#line 1857 "cafelang.tab.c"
    break;

  case 137: /* sensor_nome: TEMP  */
#line 493 "cafelang.y"
         { (yyval.str) = strdup("temp"); }
#line 1863 "cafelang.tab.c"
    break;

  case 138: /* sensor_nome: PRESSAO  */
#line 494 "cafelang.y"
              { (yyval.str) = strdup("pressao"); }
#line 1869 "cafelang.tab.c"
    break;

  case 139: /* sensor_nome: AGUA  */
#line 495 "cafelang.y"
           { (yyval.str) = strdup("agua"); }
#line 1875 "cafelang.tab.c"
    break;

  case 140: /* sensor_nome: GRAOS  */
#line 496 "cafelang.y"
            { (yyval.str) = strdup("graos"); }
#line 1881 "cafelang.tab.c"
    break;

  case 141: /* sensor_nome: FLUXO  */
#line 497 "cafelang.y"
            { (yyval.str) = strdup("fluxo"); }
#line 1887 "cafelang.tab.c"
    break;

  case 142: /* sensor_nome: COPO  */
#line 498 "cafelang.y"
           { (yyval.str) = strdup("copo"); }
#line 1893 "cafelang.tab.c"
    break;

  case 143: /* sensor_nome: PORTA  */
#line 499 "cafelang.y"
            { (yyval.str) = strdup("porta"); }
#line 1899 "cafelang.tab.c"
    break;


#line 1903 "cafelang.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 520 "cafelang.y"


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
