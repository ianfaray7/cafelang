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

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_num;
extern int col_num;

void yyerror(const char *s);

FILE *output_file;

#line 87 "cafelang.tab.c"

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
  YYSYMBOL_while_stmt = 123,               /* while_stmt  */
  YYSYMBOL_repeat_stmt = 124,              /* repeat_stmt  */
  YYSYMBOL_for_range_stmt = 125,           /* for_range_stmt  */
  YYSYMBOL_ato = 126,                      /* ato  */
  YYSYMBOL_acao = 127,                     /* acao  */
  YYSYMBOL_argumentos = 128,               /* argumentos  */
  YYSYMBOL_arg = 129,                      /* arg  */
  YYSYMBOL_expr = 130,                     /* expr  */
  YYSYMBOL_logic_or = 131,                 /* logic_or  */
  YYSYMBOL_logic_and = 132,                /* logic_and  */
  YYSYMBOL_equality = 133,                 /* equality  */
  YYSYMBOL_relational = 134,               /* relational  */
  YYSYMBOL_additive = 135,                 /* additive  */
  YYSYMBOL_multiplicative = 136,           /* multiplicative  */
  YYSYMBOL_unary = 137,                    /* unary  */
  YYSYMBOL_primary = 138,                  /* primary  */
  YYSYMBOL_bool_literal = 139,             /* bool_literal  */
  YYSYMBOL_sensor_zeroarg = 140,           /* sensor_zeroarg  */
  YYSYMBOL_sensor_nome = 141,              /* sensor_nome  */
  YYSYMBOL_medida_vol = 142,               /* medida_vol  */
  YYSYMBOL_medida_peso = 143,              /* medida_peso  */
  YYSYMBOL_medida_tempo = 144,             /* medida_tempo  */
  YYSYMBOL_medida_temp = 145               /* medida_temp  */
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
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

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
       0,    68,    68,    71,    72,    76,    77,    78,    79,    82,
      86,    89,    91,    95,    96,    97,    98,   102,   106,   107,
     108,   109,   110,   111,   115,   116,   117,   118,   121,   123,
     127,   128,   129,   130,   134,   135,   136,   137,   141,   145,
     149,   150,   154,   155,   159,   163,   164,   165,   166,   167,
     168,   169,   170,   174,   175,   176,   177,   178,   179,   180,
     181,   185,   188,   189,   193,   194,   195,   199,   203,   207,
     208,   212,   216,   220,   224,   225,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   242,   243,   247,   248,
     249,   250,   251,   252,   256,   260,   261,   262,   266,   267,
     268,   272,   273,   274,   278,   279,   280,   281,   282,   286,
     287,   288,   292,   293,   294,   295,   299,   300,   301,   302,
     303,   307,   308,   309,   310,   311,   312,   316,   317,   321,
     325,   326,   327,   328,   329,   330,   331,   335,   339,   343,
     344,   348,   349
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
  "if_stmt", "while_stmt", "repeat_stmt", "for_range_stmt", "ato", "acao",
  "argumentos", "arg", "expr", "logic_or", "logic_and", "equality",
  "relational", "additive", "multiplicative", "unary", "primary",
  "bool_literal", "sensor_zeroarg", "sensor_nome", "medida_vol",
  "medida_peso", "medida_tempo", "medida_temp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-120)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-94)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -120,    24,     1,  -120,   -42,   107,   -34,   -24,    21,    27,
     164,    35,    -4,    33,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,    48,    39,  -120,  -120,  -120,
    -120,    55,  -120,  -120,  -120,  -120,  -120,  -120,    61,    58,
      80,   164,   164,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,   164,   164,   164,   164,   164,  -120,  -120,  -120,
     100,   -30,   -26,    -7,   -48,     5,   -17,  -120,  -120,  -120,
    -120,    84,   157,  -120,  -120,   162,  -120,   164,  -120,  -120,
      38,   129,   129,    85,    86,  -120,    87,  -120,  -120,  -120,
      91,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,    89,   164,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,    90,   179,  -120,   103,    92,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,   -66,   105,   -22,   -22,  -120,
    -120,   -26,   -26,    -7,    -7,   -48,   -48,     5,     5,     5,
       5,   -17,   -17,  -120,  -120,  -120,  -120,   101,  -120,   -39,
      17,    94,  -120,  -120,  -120,  -120,  -120,  -120,   102,    95,
      96,    97,  -120,  -120,  -120,  -120,  -120,  -120,   109,  -120,
     164,  -120,   164,   144,  -120,   164,  -120,  -120,  -120,  -120,
    -120,  -120,   179,  -120,   -14,   110,   154,   176,   118,  -120,
     113,   115,   -22,    91,  -120,   -13,  -120,   121,   133,  -120,
    -120,  -120,  -120,    11,    11,    11,    11,   143,  -120,    68,
     146,  -120,  -120,  -120,  -120,  -120,   147,   148,   161,   163,
    -120,  -120,  -120,  -120,  -120,  -120
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    68,     4,     5,     6,     7,
      38,    40,    41,     8,    60,     0,     0,    54,    55,    56,
      57,     0,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     127,   128,     0,     0,     0,     0,     0,   123,   121,   125,
       0,    94,    95,    98,   101,   104,   109,   112,   116,   122,
     124,     0,     0,    58,    59,     0,    53,     0,    11,     9,
       0,     0,     0,     0,     0,   120,     0,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    61,    64,
      65,    63,     0,    74,    67,     0,     0,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,     0,   126,
      72,    96,    97,    99,   100,   102,   103,   106,   108,   105,
     107,   110,   111,   113,   114,   115,   129,     0,    66,   123,
     121,    75,    86,    88,    89,    90,    92,    91,     0,     0,
       0,     0,    10,    12,    13,    14,    39,    15,     0,    17,
       0,    42,     0,    69,    71,     0,   137,   138,   139,   140,
     141,   142,     0,    28,     0,     0,     0,     0,     0,    16,
       0,     0,     0,     0,    87,     0,    25,     0,     0,    43,
      44,    70,    73,     0,     0,     0,     0,     0,    29,     0,
       0,    27,    34,    35,    36,    37,     0,     0,     0,     0,
      24,    26,    30,    31,    32,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -119,  -120,  -120,   -64,  -120,  -120,   165,
     -73,   -87,  -120,  -120,  -120,    -2,  -120,  -120,  -120,  -120,
     -67,  -120,  -120,    34,    -9,  -120,    14,    20,    29,   -23,
      30,    -1,  -120,  -120,  -120,  -120,    15,  -120,    41,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    16,    17,    79,   125,   173,    18,    38,
     174,   205,   218,   226,    19,   175,    20,    21,    22,   135,
      23,    24,    75,   121,    25,    59,    27,    28,    29,    30,
     122,   123,   161,   162,   163,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   164,   165,   166,   167
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    60,   120,   140,     4,     5,   180,   213,   214,   215,
     216,   119,     8,   126,     9,    10,   181,    11,    12,    13,
      97,    98,    99,   100,     3,     6,     7,   222,   223,   224,
     225,    91,    83,    84,    92,     8,    93,     9,    10,    94,
      11,    12,    13,   -93,    86,   -93,   186,   187,   188,   189,
      31,    85,   177,    87,    88,    89,    14,    39,   178,    95,
      96,   176,   190,   191,   183,   184,   217,    40,   124,    15,
     103,   104,   105,    26,   147,   148,   149,   150,    73,    14,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     101,   102,    15,   190,   191,   227,   228,   229,   157,   188,
     189,    41,   153,   154,   155,   141,   142,    42,   168,   169,
     170,    77,   171,   143,   144,    74,   212,    32,    33,    34,
      35,    36,    37,    26,   145,   146,    72,     6,     7,   211,
      76,   151,   152,    78,    80,    26,    26,     8,    90,     9,
      10,    81,    11,    12,    13,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   127,   128,   129,   130,   131,
     132,   133,   134,    82,   106,   107,   137,   138,   139,    14,
     156,   200,   158,   201,   179,   185,   203,   182,   192,   202,
     193,    14,   172,   186,   207,   197,     6,     7,   194,   196,
     198,   199,   206,   208,    15,   209,     8,   210,     9,    10,
      26,    11,    12,    13,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   219,   221,    43,    44,    45,    46,
      47,    48,    49,    50,    51,   230,   204,    52,   231,   232,
     233,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      14,   118,    52,   234,    53,   235,   195,   136,   220,    54,
      55,     0,     0,    15,    56,    15,    57,    58,     0,    53,
       0,     0,     0,     0,    54,    55,     0,     0,     0,    56,
      15,   159,   160
};

static const yytype_int16 yycheck[] =
{
       2,    10,    75,    90,     3,     4,    72,    20,    21,    22,
      23,    75,    34,    80,    36,    37,    82,    39,    40,    41,
      68,    69,    70,    71,     0,    24,    25,    16,    17,    18,
      19,    61,    41,    42,    64,    34,    62,    36,    37,    65,
      39,    40,    41,    82,    53,    84,    29,    30,    31,    32,
      92,    52,   125,    54,    55,    56,    78,    91,   125,    66,
      67,   125,    76,    77,   137,   138,    79,    91,    77,    91,
      87,    88,    89,    75,    97,    98,    99,   100,    82,    78,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      85,    86,    91,    76,    77,   214,   215,   216,   107,    31,
      32,    80,   103,   104,   105,    91,    92,    80,     5,     6,
       7,    72,     9,    93,    94,    82,   203,    10,    11,    12,
      13,    14,    15,   125,    95,    96,    91,    24,    25,   202,
      82,   101,   102,    78,    73,   137,   138,    34,    38,    36,
      37,    83,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    26,    27,    28,    29,    30,
      31,    32,    33,    83,    80,     8,    81,    81,    81,    78,
      81,   180,    82,   182,    82,    74,   185,    72,    84,    35,
      78,    78,    79,    29,     8,   170,    24,    25,    93,    93,
      93,    82,    82,    75,    91,    82,    34,    82,    36,    37,
     202,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    93,    82,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    82,   192,    63,    82,    82,
      82,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      78,    79,    63,    82,    80,    82,   169,    82,   207,    85,
      86,    -1,    -1,    91,    90,    91,    92,    93,    -1,    80,
      -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    90,
      91,    92,    93
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,    98,     0,     3,     4,    24,    25,    34,    36,
      37,    39,    40,    41,    78,    91,    99,   100,   104,   110,
     112,   113,   114,   116,   117,   120,   121,   122,   123,   124,
     125,    92,    10,    11,    12,    13,    14,    15,   105,    91,
      91,    80,    80,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    63,    80,    85,    86,    90,    92,    93,   121,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    91,    82,    82,   118,    82,    72,    78,   101,
      73,    83,    83,   130,   130,   137,   130,   137,   137,   137,
      38,    61,    64,    62,    65,    66,    67,    68,    69,    70,
      71,    85,    86,    87,    88,    89,    80,     8,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    79,   112,
     116,   119,   126,   127,   130,   102,   126,    26,    27,    28,
      29,    30,    31,    32,    33,   115,   115,    81,    81,    81,
     117,   132,   132,   133,   133,   134,   134,   135,   135,   135,
     135,   136,   136,   137,   137,   137,    81,   130,    82,    92,
      93,   128,   129,   130,   142,   143,   144,   145,     5,     6,
       7,     9,    79,   103,   106,   111,   112,   116,   126,    82,
      72,    82,    72,   116,   116,    74,    29,    30,    31,    32,
      76,    77,    84,    78,    93,   145,    93,   142,    93,    82,
     130,   130,    35,   130,   129,   107,    82,     8,    75,    82,
      82,   116,   117,    20,    21,    22,    23,    79,   108,    93,
     144,    82,    16,    17,    18,    19,   109,   109,   109,   109,
      82,    82,    82,    82,    82,    82
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
     116,   117,   118,   118,   119,   119,   119,   120,   121,   122,
     122,   123,   124,   125,   126,   126,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   130,   131,   131,   131,   132,   132,
     132,   133,   133,   133,   134,   134,   134,   134,   134,   135,
     135,   135,   136,   136,   136,   136,   137,   137,   137,   137,
     137,   138,   138,   138,   138,   138,   138,   139,   139,   140,
     141,   141,   141,   141,   141,   141,   141,   142,   143,   144,
     144,   145,   145
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
       1,     3,     0,     2,     1,     1,     2,     3,     1,     5,
       7,     5,     4,     7,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2
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

#line 1408 "cafelang.tab.c"

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

#line 352 "cafelang.y"


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
