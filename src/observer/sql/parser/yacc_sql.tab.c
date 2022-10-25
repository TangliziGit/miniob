/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t value_length;
  Value values[MAX_NUM];
  size_t function_length;
  RelAttr functions[MAX_NUM];
  size_t parameter_length;
  Parameter parameters[MAX_NUM];
  size_t group_by_attr_length;
  RelAttr group_by_attrs[MAX_NUM];
  size_t having_condition_length;
  Condition having_conditions[MAX_NUM];
  size_t insert_num;
  size_t insert_value_length[MAX_NUM];
  Value insert_values[MAX_NUM][MAX_NUM];
  Condition conditions[MAX_NUM];
  CompOp comp;
  size_t order_attr_size;
  RelAttr order_attrs[MAX_NUM];
  OrderFlag order_flag[MAX_NUM];
  size_t id_num;
  char id[MAX_NUM][MAX_NUM];
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  memset(context->insert_value_length,0,sizeof(context->insert_value_length));
  context->insert_num=0;
  context->id_num=0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)


#line 145 "yacc_sql.tab.c"

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

#include "yacc_sql.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_INDEX = 8,                      /* INDEX  */
  YYSYMBOL_SELECT = 9,                     /* SELECT  */
  YYSYMBOL_DESC = 10,                      /* DESC  */
  YYSYMBOL_SHOW = 11,                      /* SHOW  */
  YYSYMBOL_SYNC = 12,                      /* SYNC  */
  YYSYMBOL_INSERT = 13,                    /* INSERT  */
  YYSYMBOL_DELETE = 14,                    /* DELETE  */
  YYSYMBOL_UPDATE = 15,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 17,                    /* RBRACE  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 19,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 20,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 21,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 22,                     /* INT_T  */
  YYSYMBOL_STRING_T = 23,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 24,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 25,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 26,                    /* TEXT_T  */
  YYSYMBOL_HELP = 27,                      /* HELP  */
  YYSYMBOL_EXIT = 28,                      /* EXIT  */
  YYSYMBOL_DOT = 29,                       /* DOT  */
  YYSYMBOL_INTO = 30,                      /* INTO  */
  YYSYMBOL_VALUES = 31,                    /* VALUES  */
  YYSYMBOL_FROM = 32,                      /* FROM  */
  YYSYMBOL_WHERE = 33,                     /* WHERE  */
  YYSYMBOL_GROUP = 34,                     /* GROUP  */
  YYSYMBOL_HAVING = 35,                    /* HAVING  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_SET = 37,                       /* SET  */
  YYSYMBOL_ON = 38,                        /* ON  */
  YYSYMBOL_LOAD = 39,                      /* LOAD  */
  YYSYMBOL_DATA = 40,                      /* DATA  */
  YYSYMBOL_INFILE = 41,                    /* INFILE  */
  YYSYMBOL_EQ = 42,                        /* EQ  */
  YYSYMBOL_LT = 43,                        /* LT  */
  YYSYMBOL_GT = 44,                        /* GT  */
  YYSYMBOL_LE = 45,                        /* LE  */
  YYSYMBOL_GE = 46,                        /* GE  */
  YYSYMBOL_NE = 47,                        /* NE  */
  YYSYMBOL_NOT = 48,                       /* NOT  */
  YYSYMBOL_LIKE_T = 49,                    /* LIKE_T  */
  YYSYMBOL_IS_T = 50,                      /* IS_T  */
  YYSYMBOL_UNIQUE = 51,                    /* UNIQUE  */
  YYSYMBOL_INNER = 52,                     /* INNER  */
  YYSYMBOL_JOIN = 53,                      /* JOIN  */
  YYSYMBOL_ASC = 54,                       /* ASC  */
  YYSYMBOL_ORDER = 55,                     /* ORDER  */
  YYSYMBOL_BY = 56,                        /* BY  */
  YYSYMBOL_NULL_T = 57,                    /* NULL_T  */
  YYSYMBOL_NULLABLE = 58,                  /* NULLABLE  */
  YYSYMBOL_NUMBER = 59,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 60,                     /* FLOAT  */
  YYSYMBOL_DATE = 61,                      /* DATE  */
  YYSYMBOL_ID = 62,                        /* ID  */
  YYSYMBOL_PATH = 63,                      /* PATH  */
  YYSYMBOL_SSS = 64,                       /* SSS  */
  YYSYMBOL_STAR = 65,                      /* STAR  */
  YYSYMBOL_STRING_V = 66,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_commands = 68,                  /* commands  */
  YYSYMBOL_command = 69,                   /* command  */
  YYSYMBOL_exit = 70,                      /* exit  */
  YYSYMBOL_help = 71,                      /* help  */
  YYSYMBOL_sync = 72,                      /* sync  */
  YYSYMBOL_begin = 73,                     /* begin  */
  YYSYMBOL_commit = 74,                    /* commit  */
  YYSYMBOL_rollback = 75,                  /* rollback  */
  YYSYMBOL_drop_table = 76,                /* drop_table  */
  YYSYMBOL_show_tables = 77,               /* show_tables  */
  YYSYMBOL_desc_table = 78,                /* desc_table  */
  YYSYMBOL_create_index = 79,              /* create_index  */
  YYSYMBOL_drop_index = 80,                /* drop_index  */
  YYSYMBOL_create_table = 81,              /* create_table  */
  YYSYMBOL_attr_def_list = 82,             /* attr_def_list  */
  YYSYMBOL_attr_def = 83,                  /* attr_def  */
  YYSYMBOL_nullable = 84,                  /* nullable  */
  YYSYMBOL_number = 85,                    /* number  */
  YYSYMBOL_type = 86,                      /* type  */
  YYSYMBOL_id_list = 87,                   /* id_list  */
  YYSYMBOL_ID_get = 88,                    /* ID_get  */
  YYSYMBOL_insert = 89,                    /* insert  */
  YYSYMBOL_value_def_list = 90,            /* value_def_list  */
  YYSYMBOL_value_def = 91,                 /* value_def  */
  YYSYMBOL_value_list = 92,                /* value_list  */
  YYSYMBOL_insert_value = 93,              /* insert_value  */
  YYSYMBOL_value = 94,                     /* value  */
  YYSYMBOL_delete = 95,                    /* delete  */
  YYSYMBOL_update = 96,                    /* update  */
  YYSYMBOL_eq_define = 97,                 /* eq_define  */
  YYSYMBOL_eq_define_list = 98,            /* eq_define_list  */
  YYSYMBOL_select = 99,                    /* select  */
  YYSYMBOL_join_attr_list = 100,           /* join_attr_list  */
  YYSYMBOL_order_by = 101,                 /* order_by  */
  YYSYMBOL_order = 102,                    /* order  */
  YYSYMBOL_order_attr = 103,               /* order_attr  */
  YYSYMBOL_order_attr_lists = 104,         /* order_attr_lists  */
  YYSYMBOL_group_by = 105,                 /* group_by  */
  YYSYMBOL_group_by_list = 106,            /* group_by_list  */
  YYSYMBOL_having = 107,                   /* having  */
  YYSYMBOL_having_condition_list = 108,    /* having_condition_list  */
  YYSYMBOL_having_condition = 109,         /* having_condition  */
  YYSYMBOL_select_attr = 110,              /* select_attr  */
  YYSYMBOL_function = 111,                 /* function  */
  YYSYMBOL_function_attr = 112,            /* function_attr  */
  YYSYMBOL_function_attr_list = 113,       /* function_attr_list  */
  YYSYMBOL_attr_list = 114,                /* attr_list  */
  YYSYMBOL_rel_id = 115,                   /* rel_id  */
  YYSYMBOL_rel_list = 116,                 /* rel_list  */
  YYSYMBOL_where = 117,                    /* where  */
  YYSYMBOL_condition_list = 118,           /* condition_list  */
  YYSYMBOL_condition = 119,                /* condition  */
  YYSYMBOL_comOp = 120,                    /* comOp  */
  YYSYMBOL_load_data = 121,                /* load_data  */
  YYSYMBOL_show_index = 122                /* show_index  */
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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  291

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


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
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   167,   167,   169,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   194,   199,   204,   210,   216,   222,   228,   234,
     240,   247,   252,   260,   267,   276,   278,   282,   289,   297,
     300,   303,   307,   310,   311,   312,   313,   314,   316,   318,
     322,   332,   343,   345,   349,   352,   354,   358,   363,   367,
     371,   376,   383,   390,   400,   409,   412,   413,   418,   438,
     442,   443,   447,   450,   453,   458,   463,   469,   470,   472,
     473,   478,   485,   486,   491,   498,   499,   501,   502,   505,
     512,   520,   528,   535,   543,   554,   559,   564,   569,   574,
     580,   588,   589,   594,   599,   604,   609,   610,   615,   620,
     625,   630,   632,   637,   642,   647,   653,   657,   659,   662,
     664,   667,   669,   673,   685,   694,   705,   716,   728,   740,
     754,   755,   756,   757,   758,   759,   760,   761,   762,   763,
     767,   775
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "SELECT", "DESC", "SHOW", "SYNC",
  "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE",
  "GROUP", "HAVING", "AND", "SET", "ON", "LOAD", "DATA", "INFILE", "EQ",
  "LT", "GT", "LE", "GE", "NE", "NOT", "LIKE_T", "IS_T", "UNIQUE", "INNER",
  "JOIN", "ASC", "ORDER", "BY", "NULL_T", "NULLABLE", "NUMBER", "FLOAT",
  "DATE", "ID", "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands",
  "command", "exit", "help", "sync", "begin", "commit", "rollback",
  "drop_table", "show_tables", "desc_table", "create_index", "drop_index",
  "create_table", "attr_def_list", "attr_def", "nullable", "number",
  "type", "id_list", "ID_get", "insert", "value_def_list", "value_def",
  "value_list", "insert_value", "value", "delete", "update", "eq_define",
  "eq_define_list", "select", "join_attr_list", "order_by", "order",
  "order_attr", "order_attr_lists", "group_by", "group_by_list", "having",
  "having_condition_list", "having_condition", "select_attr", "function",
  "function_attr", "function_attr_list", "attr_list", "rel_id", "rel_list",
  "where", "condition_list", "condition", "comOp", "load_data",
  "show_index", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
#endif

#define YYPACT_NINF (-247)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -247,    18,  -247,     5,    36,   -45,   -43,    41,    32,    46,
      48,    21,    81,   102,   103,   108,   110,    72,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,    58,    61,   106,
      69,    87,    50,   141,    83,   141,   151,   161,   158,  -247,
     143,   145,   167,  -247,  -247,  -247,  -247,  -247,   168,   192,
     172,   149,   209,   210,    65,   152,    12,  -247,  -247,   153,
    -247,  -247,  -247,   154,   186,   185,   157,   156,   159,   160,
     187,  -247,  -247,  -247,  -247,  -247,  -247,    -8,  -247,   205,
     205,   207,    53,   141,   141,   141,  -247,   208,   224,   212,
     101,   226,  -247,   188,   213,   202,   111,   215,   218,   173,
      91,   174,  -247,  -247,  -247,  -247,    13,  -247,  -247,  -247,
    -247,   153,  -247,  -247,   142,   219,    52,    97,   203,  -247,
     142,   157,   185,   232,  -247,  -247,  -247,  -247,  -247,    -7,
     159,   223,   157,   225,    89,   205,   205,   205,   141,   141,
     208,   185,   227,  -247,   212,   239,   181,  -247,  -247,  -247,
    -247,  -247,  -247,   195,  -247,   198,   109,   115,   101,  -247,
    -247,   213,   244,   189,   191,   196,  -247,  -247,   215,   249,
     236,   157,   193,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
     222,   142,   240,   219,  -247,    97,  -247,  -247,  -247,  -247,
     229,  -247,   203,  -247,  -247,   256,  -247,   243,  -247,  -247,
    -247,   157,   245,   236,   205,   211,   228,   227,  -247,  -247,
     121,   199,  -247,  -247,   -32,   236,   261,   248,  -247,   204,
     127,   216,  -247,   241,  -247,  -247,  -247,  -247,  -247,   265,
      92,    43,    97,   237,    97,   220,   269,   217,  -247,   221,
     230,  -247,   231,   233,   233,   127,  -247,   136,   234,  -247,
    -247,   246,   259,    97,   258,  -247,  -247,   237,   251,  -247,
      -4,   260,   235,  -247,   233,  -247,   238,  -247,   242,  -247,
    -247,   234,     4,  -247,  -247,  -247,     4,   260,  -247,  -247,
    -247
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    20,
      19,    14,    15,    16,    17,     9,    10,    11,    12,    13,
       8,     5,     7,     6,     4,    18,    21,     0,     0,     0,
       0,     0,   111,   111,     0,   111,     0,     0,     0,    24,
       0,     0,     0,    25,    26,    27,    23,    22,     0,     0,
       0,     0,     0,     0,   101,     0,     0,    96,    95,     0,
      99,    30,    29,     0,     0,   119,     0,     0,     0,     0,
       0,    28,    33,    62,    58,    59,    61,   106,    60,   106,
     106,     0,   111,   111,   111,   111,   116,   117,     0,     0,
       0,     0,    50,     0,    66,     0,     0,    35,     0,     0,
       0,     0,   102,   104,   105,   100,     0,   112,   115,    97,
      98,     0,    69,   141,     0,    52,     0,     0,   121,    63,
       0,     0,   119,     0,    43,    44,    45,    46,    47,    39,
       0,     0,     0,     0,   106,   106,   106,   106,   111,   111,
     117,   119,    55,    57,     0,     0,     0,   130,   131,   132,
     133,   134,   135,     0,   136,   138,     0,     0,     0,   120,
      65,    66,     0,     0,     0,     0,    40,    38,    35,     0,
      48,     0,     0,   107,   109,   110,   103,   113,   114,   118,
      79,     0,     0,    52,    51,     0,   137,   139,   125,   123,
     126,   124,   121,    67,    64,     0,    42,     0,    41,    36,
      34,     0,     0,    48,   106,     0,    85,    55,    54,    53,
       0,     0,   122,   140,    39,    48,     0,     0,   108,     0,
       0,    70,    56,     0,   127,   128,    37,    49,    31,     0,
      82,     0,     0,    87,     0,     0,     0,     0,    32,     0,
       0,    80,     0,     0,     0,     0,    86,     0,     0,    68,
     129,    83,    82,     0,     0,    93,    92,    87,    90,    89,
      72,    77,     0,    81,     0,    88,     0,    73,     0,    74,
      75,     0,    72,    84,    94,    91,    72,    77,    71,    76,
      78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,   104,   144,    57,  -247,  -247,
    -201,  -138,  -247,    93,   131,    70,    98,   -63,  -247,  -247,
     163,   117,  -247,  -247,  -247,  -246,     9,    11,  -247,    29,
    -247,    34,    44,  -247,    -5,  -247,   -82,   -40,   182,   155,
    -117,   100,   138,  -125,  -247,  -247
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   141,   107,   177,   207,   139,
     212,   103,    31,   155,   125,   192,   152,   127,    32,    33,
     104,   132,    34,   151,   246,   280,   271,   282,   216,   251,
     231,   256,   243,    44,   244,    91,   112,    67,    97,   122,
     101,   169,   128,   166,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    90,   167,    68,   180,    70,   277,   113,   114,   174,
     110,    37,   227,    38,   277,   172,   175,    42,     2,    46,
      43,   111,     3,     4,   237,   278,   176,     5,     6,     7,
       8,     9,    10,    11,   190,    49,   288,    12,    13,    14,
     289,   175,    40,   213,    41,    15,    16,   146,    47,    48,
     279,   176,   117,   118,   119,   120,    39,    17,   279,    64,
      93,   153,   183,   184,   185,   186,    64,   170,    65,    64,
     220,    65,   252,   225,    94,   148,    50,    95,   149,    66,
      51,   156,   116,    52,    53,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   199,   201,    54,    55,   110,   187,   188,
     249,    56,    58,    57,    61,    69,   253,   254,   182,   257,
      59,   250,    83,    60,    84,    85,    86,    87,   153,    88,
      89,    62,   228,   134,   135,   136,   137,   138,   274,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    83,    63,
      84,    85,    86,   144,    71,    88,   145,   234,    83,    65,
      84,    85,    86,   126,    72,    88,    83,   242,    84,    85,
      86,   198,    83,    88,    84,    85,    86,   200,    83,    88,
      84,    85,    86,   233,    83,    88,    84,    85,    86,   241,
      73,    88,   242,    83,   269,    84,    85,    86,   268,    83,
      88,    84,    85,    86,    76,    74,    88,    75,    78,    77,
      79,    80,    81,    82,    92,    96,    98,    99,   100,   102,
     105,   106,   108,   110,   115,   109,   121,   123,   124,   129,
     130,   131,   133,   140,   142,   143,   147,   154,   173,   168,
     179,   181,   194,   195,   196,   191,   197,   204,   265,   266,
     206,   205,   210,   208,   211,   214,   215,   218,   221,   223,
     224,   235,   226,   230,   238,   239,   240,   229,   248,   284,
     247,   245,   259,   255,    64,   272,   258,   249,   281,   260,
     276,   236,   209,   261,   178,   193,   219,   232,   203,   217,
     287,   273,   262,   263,   171,   264,   270,   283,   290,   267,
     285,   275,   222,   150,   286,   189,   202
};

static const yytype_int16 yycheck[] =
{
       5,    64,   127,    43,   142,    45,    10,    89,    90,    16,
      18,     6,   213,     8,    10,   132,    48,    62,     0,    62,
      65,    29,     4,     5,   225,    29,    58,     9,    10,    11,
      12,    13,    14,    15,   151,     3,   282,    19,    20,    21,
     286,    48,     6,   181,     8,    27,    28,   110,     7,     8,
      54,    58,    92,    93,    94,    95,    51,    39,    54,    16,
      65,   124,   144,   145,   146,   147,    16,   130,    18,    16,
     195,    18,    29,   211,    62,    62,    30,    65,    65,    29,
      32,    29,    29,    62,     3,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    42,    43,    44,    45,    46,    47,
      48,    49,    50,   166,   167,     3,     3,    18,   148,   149,
      18,     3,    40,     3,     8,    32,   241,   242,    29,   244,
      62,    29,    57,    62,    59,    60,    61,    62,   191,    64,
      65,    62,   214,    22,    23,    24,    25,    26,   263,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    57,    62,
      59,    60,    61,    62,     3,    64,    65,   220,    57,    18,
      59,    60,    61,    62,     3,    64,    57,   230,    59,    60,
      61,    62,    57,    64,    59,    60,    61,    62,    57,    64,
      59,    60,    61,    62,    57,    64,    59,    60,    61,    62,
      32,    64,   255,    57,   257,    59,    60,    61,    62,    57,
      64,    59,    60,    61,    37,    62,    64,    62,    16,    41,
      38,    62,     3,     3,    62,    62,    62,    31,    33,    62,
      64,    62,    62,    18,    17,    38,    18,     3,    16,     3,
      42,    18,    30,    18,    16,    62,    62,    18,     6,    36,
      17,    16,     3,    62,    49,    18,    48,     3,   253,   254,
      59,    62,     3,    57,    18,    62,    34,    17,    29,     3,
      17,    62,    17,    35,     3,    17,    62,    56,     3,   274,
      29,    55,     3,    36,    16,    29,    56,    18,    18,    62,
      29,   224,   178,    62,   140,   154,   193,   217,   171,   191,
     281,   262,    62,    62,   131,    62,    62,    62,   287,   255,
      62,   267,   202,   121,    62,   150,   168
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    27,    28,    39,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    89,    95,    96,    99,   121,   122,     6,     8,    51,
       6,     8,    62,    65,   110,   111,    62,     7,     8,     3,
      30,    32,    62,     3,     3,     3,     3,     3,    40,    62,
      62,     8,    62,    62,    16,    18,    29,   114,   114,    32,
     114,     3,     3,    32,    62,    62,    37,    41,    16,    38,
      62,     3,     3,    57,    59,    60,    61,    62,    64,    65,
      94,   112,    62,   111,    62,    65,    62,   115,    62,    31,
      33,   117,    62,    88,    97,    64,    62,    83,    62,    38,
      18,    29,   113,   113,   113,    17,    29,   114,   114,   114,
     114,    18,   116,     3,    16,    91,    62,    94,   119,     3,
      42,    18,    98,    30,    22,    23,    24,    25,    26,    86,
      18,    82,    16,    62,    62,    65,    94,    62,    62,    65,
     115,   100,    93,    94,    18,    90,    29,    42,    43,    44,
      45,    46,    47,    48,    49,    50,   120,   120,    36,   118,
      94,    97,   117,     6,    16,    48,    58,    84,    83,    17,
      88,    16,    29,   113,   113,   113,   113,   114,   114,   116,
     117,    18,    92,    91,     3,    62,    49,    48,    62,    94,
      62,    94,   119,    98,     3,    62,    59,    85,    57,    82,
       3,    18,    87,    88,    62,    34,   105,    93,    17,    90,
     120,    29,   118,     3,    17,    88,    17,    87,   113,    56,
      35,   107,    92,    62,    94,    62,    84,    87,     3,    17,
      62,    62,    94,   109,   111,    55,   101,    29,     3,    18,
      29,   106,    29,   120,   120,    36,   108,   120,    56,     3,
      62,    62,    62,    62,    62,   111,   111,   109,    62,    94,
      62,   103,    29,   106,   120,   108,    29,    10,    29,    54,
     102,    18,   104,    62,   111,    62,    62,   103,   102,   102,
     104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    79,    80,    81,    82,    82,    83,    83,    84,
      84,    84,    85,    86,    86,    86,    86,    86,    87,    87,
      88,    89,    90,    90,    91,    92,    92,    93,    94,    94,
      94,    94,    94,    95,    96,    97,    98,    98,    99,   100,
     101,   101,   102,   102,   102,   103,   103,   104,   104,   105,
     105,   105,   106,   106,   106,   107,   107,   108,   108,   109,
     109,   109,   109,   109,   109,   110,   110,   110,   110,   110,
     111,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     113,   114,   114,   114,   114,   114,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   119,   119,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,    10,    11,     4,     8,     0,     3,     6,     3,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     0,     3,
       1,     7,     0,     3,     4,     0,     3,     1,     1,     1,
       1,     1,     1,     5,     7,     3,     0,     3,    11,     0,
       0,     5,     0,     1,     1,     2,     4,     0,     3,     0,
       4,     6,     0,     2,     4,     0,     3,     0,     3,     3,
       3,     5,     3,     3,     5,     2,     2,     4,     4,     2,
       4,     0,     2,     4,     2,     2,     0,     3,     5,     3,
       3,     0,     3,     5,     5,     3,     1,     0,     3,     0,
       3,     0,     3,     3,     3,     3,     3,     5,     5,     7,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       8,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (scanner, YY_("syntax error: cannot back up")); \
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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
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
                 int yyrule, void *scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
      yychar = yylex (&yylval, scanner);
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
  case 22: /* exit: EXIT SEMICOLON  */
#line 194 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1475 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 199 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1483 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 204 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1491 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 210 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1499 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 216 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1507 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 222 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1515 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 228 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1524 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 234 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1532 "yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 240 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1541 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 248 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,0);
		}
#line 1550 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 253 "yacc_sql.y"
            {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,1);
		}
#line 1559 "yacc_sql.tab.c"
    break;

  case 33: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 261 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1568 "yacc_sql.tab.c"
    break;

  case 34: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 268 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_length = 0;
		}
#line 1580 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 278 "yacc_sql.y"
                                   {    }
#line 1586 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID type LBRACE number RBRACE nullable  */
#line 283 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, (yyvsp[-5].string), (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1597 "yacc_sql.tab.c"
    break;

  case 38: /* attr_def: ID type nullable  */
#line 290 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,(yyvsp[-2].string), (yyvsp[-1].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1608 "yacc_sql.tab.c"
    break;

  case 39: /* nullable: %empty  */
#line 297 "yacc_sql.y"
               {
	    (yyval.number)=0;
	 }
#line 1616 "yacc_sql.tab.c"
    break;

  case 40: /* nullable: NULLABLE  */
#line 300 "yacc_sql.y"
             {
		(yyval.number)=1;
	 }
#line 1624 "yacc_sql.tab.c"
    break;

  case 41: /* nullable: NOT NULL_T  */
#line 303 "yacc_sql.y"
                   {
		(yyval.number)=0;
	}
#line 1632 "yacc_sql.tab.c"
    break;

  case 42: /* number: NUMBER  */
#line 307 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1638 "yacc_sql.tab.c"
    break;

  case 43: /* type: INT_T  */
#line 310 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1644 "yacc_sql.tab.c"
    break;

  case 44: /* type: STRING_T  */
#line 311 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1650 "yacc_sql.tab.c"
    break;

  case 45: /* type: FLOAT_T  */
#line 312 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1656 "yacc_sql.tab.c"
    break;

  case 46: /* type: DATE_T  */
#line 313 "yacc_sql.y"
                    { (yyval.number)=DATES;}
#line 1662 "yacc_sql.tab.c"
    break;

  case 47: /* type: TEXT_T  */
#line 314 "yacc_sql.y"
                    { (yyval.number)=TEXTS;}
#line 1668 "yacc_sql.tab.c"
    break;

  case 49: /* id_list: COMMA ID_get id_list  */
#line 318 "yacc_sql.y"
                        {
	 
   }
#line 1676 "yacc_sql.tab.c"
    break;

  case 50: /* ID_get: ID  */
#line 323 "yacc_sql.y"
        {
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", (yyvsp[0].string));
		CONTEXT->id_num++;
	}
#line 1686 "yacc_sql.tab.c"
    break;

  case 51: /* insert: INSERT INTO ID VALUES value_def value_def_list SEMICOLON  */
#line 333 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string), CONTEXT->insert_values, CONTEXT->insert_value_length,CONTEXT->insert_num);
            //临时变量清零
			for(int i=0;i<CONTEXT->insert_num;i++){
				CONTEXT->insert_value_length[i]=0;
			}
			CONTEXT->value_length=0;
			CONTEXT->insert_num=0;
         }
#line 1701 "yacc_sql.tab.c"
    break;

  case 53: /* value_def_list: COMMA value_def value_def_list  */
#line 345 "yacc_sql.y"
                                  {
  }
#line 1708 "yacc_sql.tab.c"
    break;

  case 54: /* value_def: LBRACE insert_value value_list RBRACE  */
#line 349 "yacc_sql.y"
                                       {
	CONTEXT->insert_num++;
  }
#line 1716 "yacc_sql.tab.c"
    break;

  case 56: /* value_list: COMMA insert_value value_list  */
#line 354 "yacc_sql.y"
                                     {
	  }
#line 1723 "yacc_sql.tab.c"
    break;

  case 57: /* insert_value: value  */
#line 358 "yacc_sql.y"
        {
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*(yyvsp[0].value1);
   }
#line 1731 "yacc_sql.tab.c"
    break;

  case 58: /* value: NUMBER  */
#line 363 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1740 "yacc_sql.tab.c"
    break;

  case 59: /* value: FLOAT  */
#line 367 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1749 "yacc_sql.tab.c"
    break;

  case 60: /* value: SSS  */
#line 371 "yacc_sql.y"
         {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1759 "yacc_sql.tab.c"
    break;

  case 61: /* value: DATE  */
#line 376 "yacc_sql.y"
             {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		if(value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string))<0){
		  CONTEXT->ssql->date_parse_err = -1;
		}
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 1771 "yacc_sql.tab.c"
    break;

  case 62: /* value: NULL_T  */
#line 383 "yacc_sql.y"
               {
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 1780 "yacc_sql.tab.c"
    break;

  case 63: /* delete: DELETE FROM ID where SEMICOLON  */
#line 391 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1792 "yacc_sql.tab.c"
    break;

  case 64: /* update: UPDATE ID SET eq_define eq_define_list where SEMICOLON  */
#line 401 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,(yyvsp[-5].string),CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1803 "yacc_sql.tab.c"
    break;

  case 65: /* eq_define: ID_get EQ value  */
#line 409 "yacc_sql.y"
                  {

}
#line 1811 "yacc_sql.tab.c"
    break;

  case 67: /* eq_define_list: COMMA eq_define eq_define_list  */
#line 413 "yacc_sql.y"
                                  {

   }
#line 1819 "yacc_sql.tab.c"
    break;

  case 68: /* select: SELECT select_attr FROM rel_id rel_list join_attr_list where group_by having order_by SEMICOLON  */
#line 418 "yacc_sql.y"
                                                                                                        {
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		selects_append_group_by(&CONTEXT->ssql->sstr.selection, CONTEXT->group_by_attrs, CONTEXT->group_by_attr_length);
		selects_append_having(&CONTEXT->ssql->sstr.selection, CONTEXT->having_conditions, CONTEXT->having_condition_length);
		selects_append_order(&CONTEXT->ssql->sstr.selection, CONTEXT->order_attrs, CONTEXT->order_attr_size, CONTEXT->order_flag);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";

		//临时变量清零
		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 1837 "yacc_sql.tab.c"
    break;

  case 71: /* order_by: ORDER BY order_attr order_attr_lists order  */
#line 443 "yacc_sql.y"
                                                 {
		
	}
#line 1845 "yacc_sql.tab.c"
    break;

  case 72: /* order: %empty  */
#line 447 "yacc_sql.y"
             {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
#line 1853 "yacc_sql.tab.c"
    break;

  case 73: /* order: DESC  */
#line 450 "yacc_sql.y"
           {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
#line 1861 "yacc_sql.tab.c"
    break;

  case 74: /* order: ASC  */
#line 453 "yacc_sql.y"
              {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
#line 1869 "yacc_sql.tab.c"
    break;

  case 75: /* order_attr: ID order  */
#line 458 "yacc_sql.y"
             { 
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
#line 1879 "yacc_sql.tab.c"
    break;

  case 76: /* order_attr: ID DOT ID order  */
#line 463 "yacc_sql.y"
                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
#line 1889 "yacc_sql.tab.c"
    break;

  case 80: /* group_by: GROUP BY ID group_by_list  */
#line 473 "yacc_sql.y"
                                    {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 1899 "yacc_sql.tab.c"
    break;

  case 81: /* group_by: GROUP BY ID DOT ID group_by_list  */
#line 478 "yacc_sql.y"
                                           {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 1909 "yacc_sql.tab.c"
    break;

  case 83: /* group_by_list: COMMA ID  */
#line 486 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 1919 "yacc_sql.tab.c"
    break;

  case 84: /* group_by_list: COMMA ID DOT ID  */
#line 491 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 1929 "yacc_sql.tab.c"
    break;

  case 86: /* having: HAVING having_condition having_condition_list  */
#line 499 "yacc_sql.y"
                                                        {}
#line 1935 "yacc_sql.tab.c"
    break;

  case 88: /* having_condition_list: AND having_condition having_condition_list  */
#line 502 "yacc_sql.y"
                                                     {}
#line 1941 "yacc_sql.tab.c"
    break;

  case 89: /* having_condition: function comOp value  */
#line 505 "yacc_sql.y"
                             {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 1953 "yacc_sql.tab.c"
    break;

  case 90: /* having_condition: function comOp ID  */
#line 512 "yacc_sql.y"
                            {
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 1966 "yacc_sql.tab.c"
    break;

  case 91: /* having_condition: function comOp ID DOT ID  */
#line 520 "yacc_sql.y"
                                   {
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 1979 "yacc_sql.tab.c"
    break;

  case 92: /* having_condition: value comOp function  */
#line 528 "yacc_sql.y"
                               {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 1991 "yacc_sql.tab.c"
    break;

  case 93: /* having_condition: ID comOp function  */
#line 535 "yacc_sql.y"
                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].function1));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2004 "yacc_sql.tab.c"
    break;

  case 94: /* having_condition: ID DOT ID comOp function  */
#line 543 "yacc_sql.y"
                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2017 "yacc_sql.tab.c"
    break;

  case 95: /* select_attr: STAR attr_list  */
#line 554 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 2027 "yacc_sql.tab.c"
    break;

  case 96: /* select_attr: ID attr_list  */
#line 559 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
    }
#line 2037 "yacc_sql.tab.c"
    break;

  case 97: /* select_attr: ID DOT ID attr_list  */
#line 564 "yacc_sql.y"
                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2047 "yacc_sql.tab.c"
    break;

  case 98: /* select_attr: ID DOT STAR attr_list  */
#line 569 "yacc_sql.y"
                               {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2057 "yacc_sql.tab.c"
    break;

  case 99: /* select_attr: function attr_list  */
#line 574 "yacc_sql.y"
                         {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1));
    }
#line 2065 "yacc_sql.tab.c"
    break;

  case 100: /* function: ID LBRACE function_attr RBRACE  */
#line 580 "yacc_sql.y"
                                       {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, (yyvsp[-3].string));
		CONTEXT->parameter_length = 0;
		(yyval.function1)=&CONTEXT->functions[CONTEXT->function_length-1];
	}
#line 2076 "yacc_sql.tab.c"
    break;

  case 102: /* function_attr: ID function_attr_list  */
#line 589 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2086 "yacc_sql.tab.c"
    break;

  case 103: /* function_attr: ID DOT ID function_attr_list  */
#line 594 "yacc_sql.y"
                                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2096 "yacc_sql.tab.c"
    break;

  case 104: /* function_attr: STAR function_attr_list  */
#line 599 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2106 "yacc_sql.tab.c"
    break;

  case 105: /* function_attr: value function_attr_list  */
#line 604 "yacc_sql.y"
                                   {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}
#line 2115 "yacc_sql.tab.c"
    break;

  case 107: /* function_attr_list: COMMA ID function_attr_list  */
#line 610 "yacc_sql.y"
                                      {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2125 "yacc_sql.tab.c"
    break;

  case 108: /* function_attr_list: COMMA ID DOT ID function_attr_list  */
#line 615 "yacc_sql.y"
                                             {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2135 "yacc_sql.tab.c"
    break;

  case 109: /* function_attr_list: COMMA STAR function_attr_list  */
#line 620 "yacc_sql.y"
                                        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2145 "yacc_sql.tab.c"
    break;

  case 110: /* function_attr_list: COMMA value function_attr_list  */
#line 625 "yacc_sql.y"
                                         {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}
#line 2154 "yacc_sql.tab.c"
    break;

  case 112: /* attr_list: COMMA ID attr_list  */
#line 632 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 2164 "yacc_sql.tab.c"
    break;

  case 113: /* attr_list: COMMA ID DOT ID attr_list  */
#line 637 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 2174 "yacc_sql.tab.c"
    break;

  case 114: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 642 "yacc_sql.y"
                                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2184 "yacc_sql.tab.c"
    break;

  case 115: /* attr_list: COMMA function attr_list  */
#line 647 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1));
    }
#line 2192 "yacc_sql.tab.c"
    break;

  case 116: /* rel_id: ID  */
#line 653 "yacc_sql.y"
      {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[0].string));
	}
#line 2200 "yacc_sql.tab.c"
    break;

  case 118: /* rel_list: COMMA rel_id rel_list  */
#line 659 "yacc_sql.y"
                            {	
		  }
#line 2207 "yacc_sql.tab.c"
    break;

  case 120: /* where: WHERE condition condition_list  */
#line 664 "yacc_sql.y"
                                     {	
			}
#line 2214 "yacc_sql.tab.c"
    break;

  case 122: /* condition_list: AND condition condition_list  */
#line 669 "yacc_sql.y"
                                   {
			}
#line 2221 "yacc_sql.tab.c"
    break;

  case 123: /* condition: ID comOp value  */
#line 674 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 2237 "yacc_sql.tab.c"
    break;

  case 124: /* condition: value comOp value  */
#line 686 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2250 "yacc_sql.tab.c"
    break;

  case 125: /* condition: ID comOp ID  */
#line 695 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2265 "yacc_sql.tab.c"
    break;

  case 126: /* condition: value comOp ID  */
#line 706 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
		}
#line 2280 "yacc_sql.tab.c"
    break;

  case 127: /* condition: ID DOT ID comOp value  */
#line 717 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
							
    }
#line 2296 "yacc_sql.tab.c"
    break;

  case 128: /* condition: value comOp ID DOT ID  */
#line 729 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2312 "yacc_sql.tab.c"
    break;

  case 129: /* condition: ID DOT ID comOp ID DOT ID  */
#line 741 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2327 "yacc_sql.tab.c"
    break;

  case 130: /* comOp: EQ  */
#line 754 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2333 "yacc_sql.tab.c"
    break;

  case 131: /* comOp: LT  */
#line 755 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2339 "yacc_sql.tab.c"
    break;

  case 132: /* comOp: GT  */
#line 756 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2345 "yacc_sql.tab.c"
    break;

  case 133: /* comOp: LE  */
#line 757 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2351 "yacc_sql.tab.c"
    break;

  case 134: /* comOp: GE  */
#line 758 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2357 "yacc_sql.tab.c"
    break;

  case 135: /* comOp: NE  */
#line 759 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2363 "yacc_sql.tab.c"
    break;

  case 136: /* comOp: LIKE_T  */
#line 760 "yacc_sql.y"
                 {CONTEXT->comp = LIKE;}
#line 2369 "yacc_sql.tab.c"
    break;

  case 137: /* comOp: NOT LIKE_T  */
#line 761 "yacc_sql.y"
                     {CONTEXT->comp = NOT_LIKE;}
#line 2375 "yacc_sql.tab.c"
    break;

  case 138: /* comOp: IS_T  */
#line 762 "yacc_sql.y"
               {CONTEXT->comp = IS;}
#line 2381 "yacc_sql.tab.c"
    break;

  case 139: /* comOp: IS_T NOT  */
#line 763 "yacc_sql.y"
                  {CONTEXT->comp = IS_NOT;}
#line 2387 "yacc_sql.tab.c"
    break;

  case 140: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 768 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2396 "yacc_sql.tab.c"
    break;

  case 141: /* show_index: SHOW INDEX FROM ID SEMICOLON  */
#line 776 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
		}
#line 2405 "yacc_sql.tab.c"
    break;


#line 2409 "yacc_sql.tab.c"

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
      yyerror (scanner, YY_("syntax error"));
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
                      yytoken, &yylval, scanner);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 781 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
