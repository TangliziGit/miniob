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

static int parser_id;
typedef struct ParserContext {
  Query * ssql;
  size_t condition_length;
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
  size_t in_value_num;
  Value in_value[MAX_NUM];
  size_t insert_num;
  size_t insert_value_length[MAX_NUM];
  Value insert_values[MAX_NUM][MAX_NUM];
  Condition conditions[MAX_NUM];
  CompOp comp;
  OP op;
  size_t order_attr_size;
  RelAttr order_attrs[MAX_NUM];
  OrderFlag order_flag[MAX_NUM];
  size_t id_num;
  char id[MAX_NUM][MAX_NUM];
  size_t expr_num;
  RelAttr expr[MAX_NUM*4];
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

ParserContext *get_context(yyscan_t scanner)
{
  return &(((ParserContext *)yyget_extra(scanner))[parser_id]);
}

#define CONTEXT get_context(scanner)

void yyerror(yyscan_t scanner, const char *str)
{
  while(parser_id>=0){
	  ParserContext *context = CONTEXT;
      query_reset(context->ssql);
      context->ssql->flag = SCF_ERROR;
      context->condition_length = 0;
      context->value_length = 0;
      memset(context->insert_value_length,0,sizeof(context->insert_value_length));
      context->insert_num=0;
	  context->expr_num=0;
	  memset(CONTEXT->expr,0,sizeof(CONTEXT->expr));
      context->id_num=0;
	  parser_id--;
  }
  parser_id=0;
  printf("parse sql failed. error=%s", str);
}



#line 154 "yacc_sql.tab.c"

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
  YYSYMBOL_AS = 54,                        /* AS  */
  YYSYMBOL_ASC = 55,                       /* ASC  */
  YYSYMBOL_ORDER = 56,                     /* ORDER  */
  YYSYMBOL_BY = 57,                        /* BY  */
  YYSYMBOL_NULL_T = 58,                    /* NULL_T  */
  YYSYMBOL_NULLABLE = 59,                  /* NULLABLE  */
  YYSYMBOL_EXISTS_T = 60,                  /* EXISTS_T  */
  YYSYMBOL_IN_T = 61,                      /* IN_T  */
  YYSYMBOL_OR = 62,                        /* OR  */
  YYSYMBOL_ADD_T = 63,                     /* ADD_T  */
  YYSYMBOL_SUB_T = 64,                     /* SUB_T  */
  YYSYMBOL_DIV_T = 65,                     /* DIV_T  */
  YYSYMBOL_NUMBER = 66,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 67,                     /* FLOAT  */
  YYSYMBOL_DATE = 68,                      /* DATE  */
  YYSYMBOL_ID = 69,                        /* ID  */
  YYSYMBOL_PATH = 70,                      /* PATH  */
  YYSYMBOL_SSS = 71,                       /* SSS  */
  YYSYMBOL_STAR = 72,                      /* STAR  */
  YYSYMBOL_STRING_V = 73,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_commands = 75,                  /* commands  */
  YYSYMBOL_command = 76,                   /* command  */
  YYSYMBOL_exit = 77,                      /* exit  */
  YYSYMBOL_help = 78,                      /* help  */
  YYSYMBOL_sync = 79,                      /* sync  */
  YYSYMBOL_begin = 80,                     /* begin  */
  YYSYMBOL_commit = 81,                    /* commit  */
  YYSYMBOL_rollback = 82,                  /* rollback  */
  YYSYMBOL_drop_table = 83,                /* drop_table  */
  YYSYMBOL_show_tables = 84,               /* show_tables  */
  YYSYMBOL_desc_table = 85,                /* desc_table  */
  YYSYMBOL_create_index = 86,              /* create_index  */
  YYSYMBOL_drop_index = 87,                /* drop_index  */
  YYSYMBOL_create_table = 88,              /* create_table  */
  YYSYMBOL_attr_def_list = 89,             /* attr_def_list  */
  YYSYMBOL_attr_def = 90,                  /* attr_def  */
  YYSYMBOL_nullable = 91,                  /* nullable  */
  YYSYMBOL_number = 92,                    /* number  */
  YYSYMBOL_type = 93,                      /* type  */
  YYSYMBOL_id_list = 94,                   /* id_list  */
  YYSYMBOL_ID_get = 95,                    /* ID_get  */
  YYSYMBOL_insert = 96,                    /* insert  */
  YYSYMBOL_value_def_list = 97,            /* value_def_list  */
  YYSYMBOL_value_def = 98,                 /* value_def  */
  YYSYMBOL_value_list = 99,                /* value_list  */
  YYSYMBOL_insert_value = 100,             /* insert_value  */
  YYSYMBOL_get_select = 101,               /* get_select  */
  YYSYMBOL_value = 102,                    /* value  */
  YYSYMBOL_delete = 103,                   /* delete  */
  YYSYMBOL_update = 104,                   /* update  */
  YYSYMBOL_eq_define = 105,                /* eq_define  */
  YYSYMBOL_eq_define_list = 106,           /* eq_define_list  */
  YYSYMBOL_select = 107,                   /* select  */
  YYSYMBOL_from = 108,                     /* from  */
  YYSYMBOL_join_attr = 109,                /* join_attr  */
  YYSYMBOL_join_attr_list = 110,           /* join_attr_list  */
  YYSYMBOL_order_by = 111,                 /* order_by  */
  YYSYMBOL_order = 112,                    /* order  */
  YYSYMBOL_order_attr = 113,               /* order_attr  */
  YYSYMBOL_order_attr_lists = 114,         /* order_attr_lists  */
  YYSYMBOL_group_by = 115,                 /* group_by  */
  YYSYMBOL_group_by_list = 116,            /* group_by_list  */
  YYSYMBOL_having = 117,                   /* having  */
  YYSYMBOL_having_condition_list = 118,    /* having_condition_list  */
  YYSYMBOL_having_condition = 119,         /* having_condition  */
  YYSYMBOL_select_attr = 120,              /* select_attr  */
  YYSYMBOL_function = 121,                 /* function  */
  YYSYMBOL_function_attr = 122,            /* function_attr  */
  YYSYMBOL_function_attr_list = 123,       /* function_attr_list  */
  YYSYMBOL_attr_list = 124,                /* attr_list  */
  YYSYMBOL_rel_id = 125,                   /* rel_id  */
  YYSYMBOL_rel_list = 126,                 /* rel_list  */
  YYSYMBOL_in_value = 127,                 /* in_value  */
  YYSYMBOL_in_value_list = 128,            /* in_value_list  */
  YYSYMBOL_where = 129,                    /* where  */
  YYSYMBOL_condition_list = 130,           /* condition_list  */
  YYSYMBOL_and_condition = 131,            /* and_condition  */
  YYSYMBOL_or_condition = 132,             /* or_condition  */
  YYSYMBOL_condition = 133,                /* condition  */
  YYSYMBOL_expression = 134,               /* expression  */
  YYSYMBOL_comOp = 135,                    /* comOp  */
  YYSYMBOL_load_data = 136,                /* load_data  */
  YYSYMBOL_show_index = 137                /* show_index  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   872

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  434

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   189,   189,   191,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   216,   221,   226,   232,   238,   244,   250,   256,
     262,   269,   275,   284,   291,   300,   302,   306,   313,   321,
     324,   327,   331,   334,   335,   336,   337,   338,   340,   342,
     346,   356,   367,   369,   373,   376,   378,   382,   387,   392,
     396,   400,   405,   412,   416,   434,   444,   453,   456,   457,
     462,   479,   480,   483,   486,   489,   494,   495,   498,   499,
     503,   506,   509,   514,   519,   525,   526,   528,   529,   534,
     541,   542,   547,   554,   555,   557,   558,   561,   568,   576,
     584,   591,   599,   610,   615,   620,   625,   630,   633,   638,
     643,   646,   651,   656,   659,   664,   669,   674,   679,   685,
     693,   694,   699,   704,   709,   713,   714,   719,   724,   729,
     733,   735,   740,   745,   750,   753,   758,   763,   766,   771,
     776,   779,   785,   788,   791,   796,   798,   801,   802,   805,
     806,   808,   810,   813,   815,   818,   822,   826,   830,   839,
     846,   855,   864,   872,   883,   892,   902,   913,   925,   937,
     948,   959,   966,   973,   978,   983,   988,   996,  1004,  1012,
    1020,  1028,  1032,  1036,  1042,  1048,  1052,  1056,  1060,  1064,
    1068,  1073,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1097,  1105
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
  "JOIN", "AS", "ASC", "ORDER", "BY", "NULL_T", "NULLABLE", "EXISTS_T",
  "IN_T", "OR", "ADD_T", "SUB_T", "DIV_T", "NUMBER", "FLOAT", "DATE", "ID",
  "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands", "command",
  "exit", "help", "sync", "begin", "commit", "rollback", "drop_table",
  "show_tables", "desc_table", "create_index", "drop_index",
  "create_table", "attr_def_list", "attr_def", "nullable", "number",
  "type", "id_list", "ID_get", "insert", "value_def_list", "value_def",
  "value_list", "insert_value", "get_select", "value", "delete", "update",
  "eq_define", "eq_define_list", "select", "from", "join_attr",
  "join_attr_list", "order_by", "order", "order_attr", "order_attr_lists",
  "group_by", "group_by_list", "having", "having_condition_list",
  "having_condition", "select_attr", "function", "function_attr",
  "function_attr_list", "attr_list", "rel_id", "rel_list", "in_value",
  "in_value_list", "where", "condition_list", "and_condition",
  "or_condition", "condition", "expression", "comOp", "load_data",
  "show_index", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-327)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-180)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -327,   824,  -327,    15,   155,   151,   -40,   158,    35,    13,
      21,    45,   121,   125,   134,   149,   181,   114,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,   117,   118,   183,
     126,   129,   139,  -327,   244,  -327,  -327,  -327,    17,  -327,
     -10,  -327,   168,    23,   591,   199,   201,   179,  -327,   143,
     144,   190,  -327,  -327,  -327,  -327,  -327,   175,   216,   195,
     176,   248,   254,  -327,    49,   151,  -327,   610,   310,   364,
     387,    72,   178,   240,  -327,   192,   240,  -327,   193,   226,
     200,   240,  -327,   244,   244,   244,   244,  -327,   629,  -327,
    -327,   202,   233,   226,   203,   197,   204,   205,   232,  -327,
    -327,   207,   247,  -327,   271,    76,   266,   266,   268,   124,
     196,   591,   221,    -7,   240,  -327,   240,  -327,   -35,   269,
     667,   255,   240,  -327,   310,   310,   690,   690,   285,   275,
     293,  -327,   256,   281,   273,   146,   283,   289,   261,  -327,
     193,   645,   262,  -327,  -327,  -327,  -327,    78,   263,   240,
    -327,   265,   240,  -327,  -327,   267,   240,  -327,   274,   240,
    -327,  -327,  -327,   276,  -327,   193,   272,   282,   251,   749,
     811,   811,    46,  -327,   575,   278,   288,  -327,  -327,   251,
     307,  -327,   251,   203,   226,   344,  -327,  -327,  -327,  -327,
    -327,   103,   204,   327,   203,   335,   269,    84,   266,   266,
     266,   260,   240,   240,  -327,   240,  -327,   240,  -327,   240,
    -327,  -327,   269,   299,   272,  -327,   251,  -327,   284,  -327,
    -327,  -327,  -327,  -327,  -327,   -13,  -327,   309,  -327,   428,
     469,   702,   667,   667,  -327,   510,   290,   708,   306,   345,
    -327,   275,   362,  -327,   281,   366,   301,   317,   326,  -327,
    -327,   283,   382,   368,   203,   272,   318,  -327,  -327,  -327,
    -327,   322,   240,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
     323,  -327,  -327,   811,  -327,  -327,  -327,   139,   304,   390,
     629,   139,   338,   426,   431,   629,   380,  -327,  -327,    46,
      46,  -327,   385,   467,   629,    93,   771,   811,   361,   811,
     341,   396,   251,   388,   307,  -327,  -327,  -327,   403,  -327,
     391,  -327,  -327,  -327,   203,   392,   368,   226,   266,   240,
    -327,    66,   683,   165,   393,   343,   393,   346,  -327,  -327,
     348,   358,   359,  -327,   369,   370,   370,   708,  -327,   714,
     371,  -327,   345,  -327,  -327,  -327,    90,   368,   410,   432,
     255,  -327,  -327,   667,   381,   419,   139,    58,   472,   629,
     251,   446,   508,   451,   513,   549,   440,   453,   811,  -327,
    -327,   361,   443,  -327,    -1,   455,  -327,  -327,  -327,  -327,
     471,   288,    46,   438,   667,   393,   408,  -327,   393,  -327,
    -327,   411,  -327,   370,  -327,   412,  -327,   421,  -327,  -327,
     371,    12,  -327,   306,  -327,   667,    46,   462,   554,  -327,
    -327,  -327,  -327,    12,   455,  -327,   474,    46,  -327,  -327,
    -327,  -327,  -327,  -327
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
       0,     0,     0,    63,     0,    59,    60,    62,   184,    61,
     130,   182,    71,   181,   130,     0,     0,     0,    24,     0,
       0,     0,    25,    26,    27,    23,    22,     0,     0,     0,
       0,     0,     0,    58,   184,     0,   181,     0,   191,   120,
       0,     0,     0,   130,   104,     0,   130,   103,     0,   151,
       0,   130,   107,     0,     0,     0,     0,   118,   190,    30,
      29,     0,     0,   151,     0,     0,     0,     0,     0,    28,
      33,     0,     0,   185,     0,   125,   125,   125,     0,   184,
     181,   130,   183,   130,   130,   111,   130,   115,   142,   145,
       0,    87,   130,   113,   188,   189,   187,   186,     0,     0,
       0,    50,     0,    68,     0,     0,    35,     0,     0,   183,
       0,     0,     0,   121,   123,   124,   119,     0,     0,   130,
     131,     0,   130,   134,   141,     0,   130,   105,     0,   130,
     106,   108,   114,     0,   144,     0,    76,     0,     0,   184,
     182,   181,   153,   156,     0,     0,    93,   110,   205,     0,
      52,    65,     0,     0,   151,     0,    43,    44,    45,    46,
      47,    39,     0,     0,     0,     0,   145,   125,   125,   125,
     125,   183,   130,   130,   138,   130,   140,   130,   112,   130,
     116,   143,   145,     0,    76,    72,     0,   158,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   200,   202,     0,
       0,     0,     0,     0,   152,     0,     0,     0,    78,    55,
      57,     0,     0,    67,    68,     0,     0,     0,     0,    40,
      38,    35,     0,    48,     0,    76,     0,   126,   128,   129,
     122,     0,   130,   132,   133,   135,   137,   109,   117,   146,
       0,    77,   159,   183,   199,   203,   201,   147,   184,   182,
     176,   147,   184,   182,   181,   174,     0,   171,   173,   153,
     153,   157,   184,   182,   180,    90,     0,     0,    95,     0,
       0,     0,     0,     0,    52,    51,    69,    66,     0,    42,
       0,    41,    36,    34,     0,     0,    48,   151,   125,   130,
     139,     0,     0,   182,   149,     0,   149,     0,   154,   155,
       0,     0,     0,    88,     0,     0,     0,     0,    94,     0,
       0,    70,    55,    54,    53,   204,    39,    48,     0,     0,
      87,   127,   136,     0,     0,     0,   147,   184,   182,   178,
     147,     0,   183,     0,   183,   183,    91,    90,     0,   101,
     100,    95,    98,    97,    80,    85,    56,    37,    49,    31,
       0,    93,   153,     0,     0,   149,     0,   148,   149,   160,
     162,     0,    89,     0,    96,     0,    81,     0,    82,    83,
       0,    80,    32,    78,    73,     0,   153,     0,   183,   150,
      92,   102,    99,    80,    85,    79,     0,   153,    75,   161,
      84,    86,    64,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,   237,   302,   153,  -327,  -327,
    -312,  -203,  -327,   198,   259,   161,   206,  -327,   -66,  -327,
    -327,   321,   277,  -327,  -327,  -327,  -182,   102,  -316,   107,
      96,   162,   173,   130,   164,   185,   464,     1,  -327,   -92,
     -23,  -135,  -190,  -286,  -326,  -101,  -282,  -230,  -327,   308,
      -5,  -177,  -327,  -327
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   203,   146,   260,   320,   201,
     325,   142,    31,   252,   190,   313,   249,    75,    51,    32,
      33,   143,   194,    34,    89,   224,   225,   311,   409,   385,
     411,   186,   343,   248,   348,   308,    52,    76,   118,   153,
      84,   129,   176,   334,   371,   131,   244,   182,   300,   183,
      98,   239,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   263,   140,   240,   241,   336,    53,   245,    80,   406,
     373,    80,   299,   117,   359,   206,   265,   338,   339,   173,
    -130,    37,   406,    38,   154,   155,  -130,    87,   407,    55,
      92,    97,   279,    79,   174,    80,   284,    77,    58,    78,
     222,    80,   281,    59,    85,   388,    81,   168,   285,  -130,
    -130,  -130,  -130,    60,   408,  -130,  -130,  -130,  -130,    86,
     125,   326,   169,   127,   180,    79,    39,   408,   133,   417,
      54,    82,   419,  -130,    79,   121,    53,    90,   111,  -130,
     395,   120,   242,   327,   398,   209,    83,   396,   134,   135,
     136,   137,    91,   255,   151,   425,   160,   163,   164,   167,
     170,   171,   151,   172,   363,   152,   332,   430,   243,   187,
     414,   341,   227,   266,    61,   267,   268,   269,   270,   257,
     364,   357,   342,   250,    62,   184,   253,  -130,    63,   345,
     346,   181,   349,   392,   428,   365,   214,    64,   258,   216,
      79,   122,    80,   218,   123,   433,   220,   211,    73,   259,
     212,   258,    65,   157,    67,    42,  -130,  -130,  -130,  -130,
     282,    40,   259,    41,   416,    56,    57,    42,   196,   197,
     198,   199,   200,   289,   293,   297,   180,   180,   158,   303,
    -130,   307,  -148,  -148,    66,   427,    68,    69,   273,   274,
     275,    70,   276,   159,   277,    71,   278,    43,    72,  -130,
      88,   403,    99,    44,   100,    45,    46,    47,    74,    43,
      49,   101,   102,   103,    80,    44,   105,    45,    46,    47,
      48,   333,    49,    50,  -130,   333,   360,   104,  -130,  -130,
    -130,  -130,   106,   107,   290,   295,   361,   184,   184,    80,
     304,   294,   298,   181,   181,   108,   250,   124,   309,   330,
     161,   109,  -130,  -130,  -130,  -130,  -130,   110,    80,   130,
      42,   126,   128,  -130,   139,   162,   368,   114,   144,   132,
     148,   138,   141,   145,   147,   165,   149,  -130,    80,   150,
      73,   307,    77,   383,   151,   156,    77,   175,   188,   185,
     166,   189,  -130,  -130,  -130,  -130,   191,   180,   192,   193,
     333,   202,    43,   195,   397,   204,   362,  -165,    44,    43,
      45,    46,    47,    74,   271,    49,  -130,    45,    46,    47,
      79,  -165,    49,   247,   223,   251,    42,   369,   180,   272,
     205,   210,   213,   335,   215,   246,   217,  -165,  -165,  -165,
    -165,  -166,   226,   219,   262,   221,   379,   380,   309,   180,
     256,   264,   280,   283,    79,  -166,  -165,   286,   184,   305,
    -165,    77,   310,   312,   181,   315,  -165,   337,    43,   317,
     318,  -166,  -166,  -166,  -166,    95,    45,    46,    47,    74,
     114,    49,    96,   319,   321,   323,   324,   328,  -177,   184,
    -166,   329,   331,  -163,  -166,   181,    79,   347,   350,   351,
    -166,    79,  -177,    42,   421,   353,   355,  -163,   356,   358,
     184,   370,   372,   389,   340,   374,   181,   375,  -177,  -177,
    -177,  -177,    43,  -163,  -163,  -163,  -163,   376,   377,  -164,
      45,    46,    47,   115,  -172,    49,   116,  -177,   378,   296,
     384,  -177,  -163,  -164,   287,    43,  -163,  -177,  -172,   390,
     393,    44,  -163,    45,    46,    47,   119,   394,    49,  -164,
    -164,  -164,  -164,   399,  -172,  -172,  -172,  -172,   400,   401,
    -175,   341,   405,   410,   412,  -167,   415,   418,  -164,   429,
     420,   422,  -164,  -172,  -175,   291,    43,  -172,  -164,  -167,
     423,   432,    44,  -172,    45,    46,    47,   288,   322,    49,
    -175,  -175,  -175,  -175,   261,  -167,  -167,  -167,  -167,   387,
     314,  -170,   354,   386,   254,   426,  -168,   424,   352,  -175,
     431,   413,   391,  -175,  -167,  -170,    42,    43,  -167,  -175,
    -168,   316,   381,    44,  -167,    45,    46,    47,   292,   112,
      49,  -170,  -170,  -170,  -170,   404,  -168,  -168,  -168,  -168,
     402,   301,  -179,     0,     0,     0,     0,  -169,     0,     0,
    -170,     0,     0,     0,  -170,  -168,  -179,     0,    43,  -168,
    -170,  -169,     0,     0,    44,  -168,    45,    46,    47,   302,
       0,    49,  -179,  -179,  -179,  -179,     0,  -169,  -169,  -169,
    -169,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -179,     0,     0,     0,  -179,  -169,    42,     0,    80,
    -169,  -179,     0,     0,     0,     0,  -169,   229,   230,   231,
     232,   233,   234,   235,   236,   237,    42,   113,     0,     0,
       0,     0,     0,    43,     0,     0,   238,     0,    93,    94,
      95,    45,    46,    47,    74,    42,    49,    96,     0,    43,
       0,     0,     0,     0,    93,    94,    95,    45,    46,    47,
      74,   114,    49,    96,     0,     0,     0,     0,    43,     0,
       0,     0,     0,    93,    94,    95,    45,    46,    47,    74,
       0,    49,    96,    42,     0,     0,     0,    43,     0,     0,
       0,     0,    93,    94,    95,    45,    46,    47,    74,   366,
      49,    96,     0,    43,     0,     0,    42,     0,     0,     0,
       0,    45,    46,    47,   207,   177,    49,   208,   114,     0,
       0,     0,     0,     0,   114,    43,     0,   178,     0,     0,
     114,    44,     0,    45,    46,    47,   179,     0,    49,     0,
       0,    43,     0,     0,     0,     0,     0,    44,    43,    45,
      46,    47,   367,     0,    49,     0,    45,    46,    47,    74,
      43,    49,     0,     0,     0,    79,    43,     0,    45,    46,
      47,   296,    43,    49,    45,    46,    47,   306,   228,    49,
      45,    46,    47,   382,     0,    49,     0,    79,     0,     0,
       0,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     344,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,     0,     2,     0,     0,     0,     3,     4,
       0,     0,   238,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,    12,    13,    14,     0,     0,     0,     0,
       0,    15,    16,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,   238
};

static const yytype_int16 yycheck[] =
{
       5,   204,   103,   180,   181,   291,     5,   184,    18,    10,
     336,    18,   242,    79,   326,   150,   206,   299,   300,    54,
       3,     6,    10,     8,   116,   117,     3,    50,    29,    69,
      53,    54,   222,    16,    69,    18,    49,    42,     3,    44,
     175,    18,   224,    30,    54,   357,    29,    54,    61,    32,
      33,    34,    35,    32,    55,    32,    33,    34,    35,    69,
      83,   264,    69,    86,   130,    16,    51,    55,    91,   395,
      75,    54,   398,    56,    16,    80,    75,    54,    29,    56,
     366,    80,    36,   265,   370,   151,    69,    29,    93,    94,
      95,    96,    69,   194,    18,   411,   119,   120,   121,   122,
     123,   124,    18,   126,    38,    29,   283,   423,    62,   132,
     392,    18,   178,    29,    69,   207,   208,   209,   210,    16,
      54,   324,    29,   189,     3,   130,   192,     3,     3,   306,
     307,   130,   309,   363,   416,    69,   159,     3,    48,   162,
      16,    69,    18,   166,    72,   427,   169,    69,     9,    59,
      72,    48,     3,    29,    40,    16,    32,    33,    34,    35,
     226,     6,    59,     8,   394,     7,     8,    16,    22,    23,
      24,    25,    26,   239,   240,   241,   242,   243,    54,   245,
      56,   247,    17,    18,     3,   415,    69,    69,   211,   212,
     213,     8,   215,    69,   217,    69,   219,    58,    69,     3,
      32,   378,     3,    64,     3,    66,    67,    68,    69,    58,
      71,    32,    69,    69,    18,    64,    41,    66,    67,    68,
      69,   287,    71,    72,     3,   291,   327,    37,    32,    33,
      34,    35,    16,    38,   239,   240,   328,   242,   243,    18,
     245,   240,   241,   242,   243,    69,   312,    69,   247,   272,
      54,     3,    56,    32,    33,    34,    35,     3,    18,    33,
      16,    69,    69,     3,    31,    69,   332,    16,    71,    69,
      38,    69,    69,    69,    69,    54,    69,    56,    18,    32,
       9,   347,   287,   349,    18,    17,   291,    18,     3,    34,
      69,    16,    32,    33,    34,    35,     3,   363,    42,    18,
     366,    18,    58,    30,   370,    16,   329,     3,    64,    58,
      66,    67,    68,    69,    54,    71,    56,    66,    67,    68,
      16,    17,    71,    35,    52,    18,    16,   332,   394,    69,
      69,    69,    69,    29,    69,    57,    69,    33,    34,    35,
      36,     3,    60,    69,    17,    69,   345,   346,   347,   415,
       6,    16,    53,    69,    16,    17,    52,    48,   363,    69,
      56,   366,    56,    18,   363,     3,    62,    29,    58,     3,
      69,    33,    34,    35,    36,    65,    66,    67,    68,    69,
      16,    71,    72,    66,    58,     3,    18,    69,     3,   394,
      52,    69,    69,     3,    56,   394,    16,    36,    57,     3,
      62,    16,    17,    16,   403,    17,     3,    17,    17,    17,
     415,    18,    69,     3,    29,    69,   415,    69,    33,    34,
      35,    36,    58,    33,    34,    35,    36,    69,    69,     3,
      66,    67,    68,    69,     3,    71,    72,    52,    69,    69,
      69,    56,    52,    17,    16,    58,    56,    62,    17,    17,
      69,    64,    62,    66,    67,    68,    69,    38,    71,    33,
      34,    35,    36,    17,    33,    34,    35,    36,    17,    29,
       3,    18,    29,    18,     3,     3,    38,    69,    52,    17,
      69,    69,    56,    52,    17,    16,    58,    56,    62,    17,
      69,    17,    64,    62,    66,    67,    68,    69,   261,    71,
      33,    34,    35,    36,   202,    33,    34,    35,    36,   356,
     251,     3,   314,   352,   193,   413,     3,   410,   312,    52,
     424,   391,   360,    56,    52,    17,    16,    58,    56,    62,
      17,   254,   347,    64,    62,    66,    67,    68,    69,    75,
      71,    33,    34,    35,    36,   381,    33,    34,    35,    36,
     377,   243,     3,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      52,    -1,    -1,    -1,    56,    52,    17,    -1,    58,    56,
      62,    17,    -1,    -1,    64,    62,    66,    67,    68,    69,
      -1,    71,    33,    34,    35,    36,    -1,    33,    34,    35,
      36,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    56,    52,    16,    -1,    18,
      56,    62,    -1,    -1,    -1,    -1,    62,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    16,    17,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    63,    64,
      65,    66,    67,    68,    69,    16,    71,    72,    -1,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    16,    71,    72,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    16,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    16,
      71,    72,    -1,    58,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    48,    71,    72,    16,    -1,
      -1,    -1,    -1,    -1,    16,    58,    -1,    60,    -1,    -1,
      16,    64,    -1,    66,    67,    68,    69,    -1,    71,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    64,    58,    66,
      67,    68,    69,    -1,    71,    -1,    66,    67,    68,    69,
      58,    71,    -1,    -1,    -1,    16,    58,    -1,    66,    67,
      68,    69,    58,    71,    66,    67,    68,    69,    29,    71,
      66,    67,    68,    69,    -1,    71,    -1,    16,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,     0,    -1,    -1,    -1,     4,     5,
      -1,    -1,    61,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    27,    28,    39,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    96,   103,   104,   107,   136,   137,     6,     8,    51,
       6,     8,    16,    58,    64,    66,    67,    68,    69,    71,
      72,   102,   120,   121,   134,    69,     7,     8,     3,    30,
      32,    69,     3,     3,     3,     3,     3,    40,    69,    69,
       8,    69,    69,     9,    69,   101,   121,   134,   134,    16,
      18,    29,    54,    69,   124,    54,    69,   124,    32,   108,
      54,    69,   124,    63,    64,    65,    72,   124,   134,     3,
       3,    32,    69,    69,    37,    41,    16,    38,    69,     3,
       3,    29,   120,    17,    16,    69,    72,   102,   122,    69,
     121,   134,    69,    72,    69,   124,    69,   124,    69,   125,
      33,   129,    69,   124,   134,   134,   134,   134,    69,    31,
     129,    69,    95,   105,    71,    69,    90,    69,    38,    69,
      32,    18,    29,   123,   123,   123,    17,    29,    54,    69,
     124,    54,    69,   124,   124,    54,    69,   124,    54,    69,
     124,   124,   124,    54,    69,    18,   126,    48,    60,    69,
     102,   121,   131,   133,   134,    34,   115,   124,     3,    16,
      98,     3,    42,    18,   106,    30,    22,    23,    24,    25,
      26,    93,    18,    89,    16,    69,   125,    69,    72,   102,
      69,    69,    72,    69,   124,    69,   124,    69,   124,    69,
     124,    69,   125,    52,   109,   110,    60,   102,    29,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    61,   135,
     135,   135,    36,    62,   130,   135,    57,    35,   117,   100,
     102,    18,    97,   102,   105,   129,     6,    16,    48,    59,
      91,    90,    17,    95,    16,   126,    29,   123,   123,   123,
     123,    54,    69,   124,   124,   124,   124,   124,   124,   126,
      53,   110,   102,    69,    49,    61,    48,    16,    69,   102,
     134,    16,    69,   102,   121,   134,    69,   102,   121,   131,
     132,   133,    69,   102,   134,    69,    69,   102,   119,   121,
      56,   111,    18,    99,    98,     3,   106,     3,    69,    66,
      92,    58,    89,     3,    18,    94,    95,   110,    69,    69,
     124,    69,   135,   102,   127,    29,   127,    29,   130,   130,
      29,    18,    29,   116,    29,   135,   135,    36,   118,   135,
      57,     3,   100,    17,    97,     3,    17,    95,    17,    94,
     129,   123,   124,    38,    54,    69,    16,    69,   102,   134,
      18,   128,    69,   128,    69,    69,    69,    69,    69,   121,
     121,   119,    69,   102,    69,   113,    99,    91,    94,     3,
      17,   115,   131,    69,    38,   127,    29,   102,   127,    17,
      17,    29,   116,   135,   118,    29,    10,    29,    55,   112,
      18,   114,     3,   117,   130,    38,   131,   128,    69,   128,
      69,   121,    69,    69,   113,   112,   111,   131,   130,    17,
     112,   114,    17,   130
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    86,    87,    88,    89,    89,    90,    90,    91,
      91,    91,    92,    93,    93,    93,    93,    93,    94,    94,
      95,    96,    97,    97,    98,    99,    99,   100,   101,   102,
     102,   102,   102,   102,   102,   103,   104,   105,   106,   106,
     107,   108,   108,   109,   109,   109,   110,   110,   111,   111,
     112,   112,   112,   113,   113,   114,   114,   115,   115,   115,
     116,   116,   116,   117,   117,   118,   118,   119,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     122,   122,   122,   122,   122,   123,   123,   123,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   130,   131,   132,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   136,   137
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,    10,    11,     4,     8,     0,     3,     6,     3,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     0,     3,
       1,     7,     0,     3,     4,     0,     3,     1,     1,     1,
       1,     1,     1,     1,    12,     5,     7,     3,     0,     3,
       8,     0,     4,     6,     8,     7,     0,     2,     0,     5,
       0,     1,     1,     2,     4,     0,     3,     0,     4,     6,
       0,     2,     4,     0,     3,     0,     3,     3,     3,     5,
       3,     3,     5,     2,     2,     4,     4,     2,     4,     6,
       4,     3,     5,     3,     4,     3,     5,     6,     2,     4,
       0,     2,     4,     2,     2,     0,     3,     5,     3,     3,
       0,     3,     5,     5,     3,     5,     7,     5,     4,     6,
       4,     3,     1,     3,     2,     0,     3,     0,     1,     0,
       3,     0,     3,     0,     3,     3,     1,     1,     2,     3,
       6,     8,     6,     3,     3,     3,     3,     5,     5,     7,
       5,     3,     3,     3,     3,     3,     3,     3,     5,     5,
       3,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     2,     8,     5
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
  YY_USE (yyoutput);
  YY_USE (scanner);
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
  YY_USE (yyvaluep);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
#line 216 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1677 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 221 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1685 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 226 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1693 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 232 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1701 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 238 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1709 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 244 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1717 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 250 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1726 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 256 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1734 "yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 262 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1743 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 270 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,0);
			CONTEXT->id_num=0;
		}
#line 1753 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 276 "yacc_sql.y"
            {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,1);
			CONTEXT->id_num=0;
		}
#line 1763 "yacc_sql.tab.c"
    break;

  case 33: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 285 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1772 "yacc_sql.tab.c"
    break;

  case 34: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 292 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_length = 0;
		}
#line 1784 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 302 "yacc_sql.y"
                                   {    }
#line 1790 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID type LBRACE number RBRACE nullable  */
#line 307 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, (yyvsp[-5].string), (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1801 "yacc_sql.tab.c"
    break;

  case 38: /* attr_def: ID type nullable  */
#line 314 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,(yyvsp[-2].string), (yyvsp[-1].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1812 "yacc_sql.tab.c"
    break;

  case 39: /* nullable: %empty  */
#line 321 "yacc_sql.y"
               {
	    (yyval.number)=0;
	 }
#line 1820 "yacc_sql.tab.c"
    break;

  case 40: /* nullable: NULLABLE  */
#line 324 "yacc_sql.y"
             {
		(yyval.number)=1;
	 }
#line 1828 "yacc_sql.tab.c"
    break;

  case 41: /* nullable: NOT NULL_T  */
#line 327 "yacc_sql.y"
                   {
		(yyval.number)=0;
	}
#line 1836 "yacc_sql.tab.c"
    break;

  case 42: /* number: NUMBER  */
#line 331 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1842 "yacc_sql.tab.c"
    break;

  case 43: /* type: INT_T  */
#line 334 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1848 "yacc_sql.tab.c"
    break;

  case 44: /* type: STRING_T  */
#line 335 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1854 "yacc_sql.tab.c"
    break;

  case 45: /* type: FLOAT_T  */
#line 336 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1860 "yacc_sql.tab.c"
    break;

  case 46: /* type: DATE_T  */
#line 337 "yacc_sql.y"
                    { (yyval.number)=DATES;}
#line 1866 "yacc_sql.tab.c"
    break;

  case 47: /* type: TEXT_T  */
#line 338 "yacc_sql.y"
                    { (yyval.number)=TEXTS;}
#line 1872 "yacc_sql.tab.c"
    break;

  case 49: /* id_list: COMMA ID_get id_list  */
#line 342 "yacc_sql.y"
                        {
	 
   }
#line 1880 "yacc_sql.tab.c"
    break;

  case 50: /* ID_get: ID  */
#line 347 "yacc_sql.y"
        {
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", (yyvsp[0].string));
		CONTEXT->id_num++;
	}
#line 1890 "yacc_sql.tab.c"
    break;

  case 51: /* insert: INSERT INTO ID VALUES value_def value_def_list SEMICOLON  */
#line 357 "yacc_sql.y"
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
#line 1905 "yacc_sql.tab.c"
    break;

  case 53: /* value_def_list: COMMA value_def value_def_list  */
#line 369 "yacc_sql.y"
                                  {
  }
#line 1912 "yacc_sql.tab.c"
    break;

  case 54: /* value_def: LBRACE insert_value value_list RBRACE  */
#line 373 "yacc_sql.y"
                                       {
	CONTEXT->insert_num++;
  }
#line 1920 "yacc_sql.tab.c"
    break;

  case 56: /* value_list: COMMA insert_value value_list  */
#line 378 "yacc_sql.y"
                                     {
	  }
#line 1927 "yacc_sql.tab.c"
    break;

  case 57: /* insert_value: value  */
#line 382 "yacc_sql.y"
        {
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*(yyvsp[0].value1);
   }
#line 1935 "yacc_sql.tab.c"
    break;

  case 58: /* get_select: SELECT  */
#line 387 "yacc_sql.y"
         {
	parser_id++;
	CONTEXT->ssql=query_create();
}
#line 1944 "yacc_sql.tab.c"
    break;

  case 59: /* value: NUMBER  */
#line 392 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1953 "yacc_sql.tab.c"
    break;

  case 60: /* value: FLOAT  */
#line 396 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1962 "yacc_sql.tab.c"
    break;

  case 61: /* value: SSS  */
#line 400 "yacc_sql.y"
         {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1972 "yacc_sql.tab.c"
    break;

  case 62: /* value: DATE  */
#line 405 "yacc_sql.y"
             {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		if(value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string))<0){
		  CONTEXT->ssql->date_parse_err = -1;
		}
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 1984 "yacc_sql.tab.c"
    break;

  case 63: /* value: NULL_T  */
#line 412 "yacc_sql.y"
               {
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 1993 "yacc_sql.tab.c"
    break;

  case 64: /* value: LBRACE get_select select_attr FROM rel_id rel_list join_attr_list where group_by having order_by RBRACE  */
#line 416 "yacc_sql.y"
                                                                                                                {

		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		selects_append_group_by(&CONTEXT->ssql->sstr.selection, CONTEXT->group_by_attrs, CONTEXT->group_by_attr_length);
		selects_append_having(&CONTEXT->ssql->sstr.selection, CONTEXT->having_conditions, CONTEXT->having_condition_length);
		selects_append_order(&CONTEXT->ssql->sstr.selection, CONTEXT->order_attrs, CONTEXT->order_attr_size, CONTEXT->order_flag);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		Query * query = CONTEXT->ssql;
		//临时变量清零
		CONTEXT->condition_length=0;
		CONTEXT->value_length = 0;
		parser_id--;
		value_init_select(&CONTEXT->values[CONTEXT->value_length++],query);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 2013 "yacc_sql.tab.c"
    break;

  case 65: /* delete: DELETE FROM ID where SEMICOLON  */
#line 435 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2025 "yacc_sql.tab.c"
    break;

  case 66: /* update: UPDATE ID SET eq_define eq_define_list where SEMICOLON  */
#line 445 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,(yyvsp[-5].string),CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2036 "yacc_sql.tab.c"
    break;

  case 67: /* eq_define: ID_get EQ value  */
#line 453 "yacc_sql.y"
                  {

}
#line 2044 "yacc_sql.tab.c"
    break;

  case 69: /* eq_define_list: COMMA eq_define eq_define_list  */
#line 457 "yacc_sql.y"
                                  {

   }
#line 2052 "yacc_sql.tab.c"
    break;

  case 70: /* select: SELECT select_attr from where group_by having order_by SEMICOLON  */
#line 462 "yacc_sql.y"
                                                                         {
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		selects_append_group_by(&CONTEXT->ssql->sstr.selection, CONTEXT->group_by_attrs, CONTEXT->group_by_attr_length);
		selects_append_having(&CONTEXT->ssql->sstr.selection, CONTEXT->having_conditions, CONTEXT->having_condition_length);
		selects_append_order(&CONTEXT->ssql->sstr.selection, CONTEXT->order_attrs, CONTEXT->order_attr_size, CONTEXT->order_flag);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";

		//临时变量清零
		CONTEXT->condition_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->expr_num = 0;
		memset(CONTEXT->values,0,sizeof(CONTEXT->values));
		memset(CONTEXT->expr,0,sizeof(CONTEXT->expr));
		memset(CONTEXT->conditions,0,sizeof(CONTEXT->conditions));
	}
#line 2072 "yacc_sql.tab.c"
    break;

  case 72: /* from: FROM rel_id rel_list join_attr_list  */
#line 480 "yacc_sql.y"
                                              {}
#line 2078 "yacc_sql.tab.c"
    break;

  case 73: /* join_attr: INNER JOIN ID ON and_condition condition_list  */
#line 483 "yacc_sql.y"
                                                     {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string), NULL);
   	}
#line 2086 "yacc_sql.tab.c"
    break;

  case 74: /* join_attr: INNER JOIN ID AS ID ON and_condition condition_list  */
#line 486 "yacc_sql.y"
                                                             {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string), (yyvsp[-3].string));
   	}
#line 2094 "yacc_sql.tab.c"
    break;

  case 75: /* join_attr: INNER JOIN ID ID ON and_condition condition_list  */
#line 489 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string), (yyvsp[-3].string));
   	}
#line 2102 "yacc_sql.tab.c"
    break;

  case 77: /* join_attr_list: join_attr join_attr_list  */
#line 495 "yacc_sql.y"
                              {
   }
#line 2109 "yacc_sql.tab.c"
    break;

  case 79: /* order_by: ORDER BY order_attr order_attr_lists order  */
#line 499 "yacc_sql.y"
                                                 {
		
	}
#line 2117 "yacc_sql.tab.c"
    break;

  case 80: /* order: %empty  */
#line 503 "yacc_sql.y"
             {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
#line 2125 "yacc_sql.tab.c"
    break;

  case 81: /* order: DESC  */
#line 506 "yacc_sql.y"
           {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
#line 2133 "yacc_sql.tab.c"
    break;

  case 82: /* order: ASC  */
#line 509 "yacc_sql.y"
              {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
#line 2141 "yacc_sql.tab.c"
    break;

  case 83: /* order_attr: ID order  */
#line 514 "yacc_sql.y"
             { 
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
#line 2151 "yacc_sql.tab.c"
    break;

  case 84: /* order_attr: ID DOT ID order  */
#line 519 "yacc_sql.y"
                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
#line 2161 "yacc_sql.tab.c"
    break;

  case 88: /* group_by: GROUP BY ID group_by_list  */
#line 529 "yacc_sql.y"
                                    {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2171 "yacc_sql.tab.c"
    break;

  case 89: /* group_by: GROUP BY ID DOT ID group_by_list  */
#line 534 "yacc_sql.y"
                                           {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2181 "yacc_sql.tab.c"
    break;

  case 91: /* group_by_list: COMMA ID  */
#line 542 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2191 "yacc_sql.tab.c"
    break;

  case 92: /* group_by_list: COMMA ID DOT ID  */
#line 547 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2201 "yacc_sql.tab.c"
    break;

  case 94: /* having: HAVING having_condition having_condition_list  */
#line 555 "yacc_sql.y"
                                                        {}
#line 2207 "yacc_sql.tab.c"
    break;

  case 96: /* having_condition_list: AND having_condition having_condition_list  */
#line 558 "yacc_sql.y"
                                                     {}
#line 2213 "yacc_sql.tab.c"
    break;

  case 97: /* having_condition: function comOp value  */
#line 561 "yacc_sql.y"
                         {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2225 "yacc_sql.tab.c"
    break;

  case 98: /* having_condition: function comOp ID  */
#line 568 "yacc_sql.y"
                            {
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2238 "yacc_sql.tab.c"
    break;

  case 99: /* having_condition: function comOp ID DOT ID  */
#line 576 "yacc_sql.y"
                                   {
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2251 "yacc_sql.tab.c"
    break;

  case 100: /* having_condition: value comOp function  */
#line 584 "yacc_sql.y"
                               {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2263 "yacc_sql.tab.c"
    break;

  case 101: /* having_condition: ID comOp function  */
#line 591 "yacc_sql.y"
                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].function1));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2276 "yacc_sql.tab.c"
    break;

  case 102: /* having_condition: ID DOT ID comOp function  */
#line 599 "yacc_sql.y"
                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2289 "yacc_sql.tab.c"
    break;

  case 103: /* select_attr: STAR attr_list  */
#line 610 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2299 "yacc_sql.tab.c"
    break;

  case 104: /* select_attr: ID attr_list  */
#line 615 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2309 "yacc_sql.tab.c"
    break;

  case 105: /* select_attr: ID DOT ID attr_list  */
#line 620 "yacc_sql.y"
                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2319 "yacc_sql.tab.c"
    break;

  case 106: /* select_attr: ID DOT STAR attr_list  */
#line 625 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2329 "yacc_sql.tab.c"
    break;

  case 107: /* select_attr: function attr_list  */
#line 630 "yacc_sql.y"
                         {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2337 "yacc_sql.tab.c"
    break;

  case 108: /* select_attr: ID AS ID attr_list  */
#line 633 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2347 "yacc_sql.tab.c"
    break;

  case 109: /* select_attr: ID DOT ID AS ID attr_list  */
#line 638 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2357 "yacc_sql.tab.c"
    break;

  case 110: /* select_attr: function AS ID attr_list  */
#line 643 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2365 "yacc_sql.tab.c"
    break;

  case 111: /* select_attr: ID ID attr_list  */
#line 646 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2375 "yacc_sql.tab.c"
    break;

  case 112: /* select_attr: ID DOT ID ID attr_list  */
#line 651 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2385 "yacc_sql.tab.c"
    break;

  case 113: /* select_attr: function ID attr_list  */
#line 656 "yacc_sql.y"
                            {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2393 "yacc_sql.tab.c"
    break;

  case 114: /* select_attr: STAR AS ID attr_list  */
#line 659 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2403 "yacc_sql.tab.c"
    break;

  case 115: /* select_attr: STAR ID attr_list  */
#line 664 "yacc_sql.y"
                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2413 "yacc_sql.tab.c"
    break;

  case 116: /* select_attr: ID DOT STAR ID attr_list  */
#line 669 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2423 "yacc_sql.tab.c"
    break;

  case 117: /* select_attr: ID DOT STAR AS ID attr_list  */
#line 674 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2433 "yacc_sql.tab.c"
    break;

  case 118: /* select_attr: expression attr_list  */
#line 679 "yacc_sql.y"
                              {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1), NULL);
	}
#line 2441 "yacc_sql.tab.c"
    break;

  case 119: /* function: ID LBRACE function_attr RBRACE  */
#line 685 "yacc_sql.y"
                                       {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, (yyvsp[-3].string));
		CONTEXT->parameter_length = 0;
		(yyval.function1)=&CONTEXT->functions[CONTEXT->function_length-1];
	}
#line 2452 "yacc_sql.tab.c"
    break;

  case 121: /* function_attr: ID function_attr_list  */
#line 694 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2462 "yacc_sql.tab.c"
    break;

  case 122: /* function_attr: ID DOT ID function_attr_list  */
#line 699 "yacc_sql.y"
                                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2472 "yacc_sql.tab.c"
    break;

  case 123: /* function_attr: STAR function_attr_list  */
#line 704 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2482 "yacc_sql.tab.c"
    break;

  case 124: /* function_attr: value function_attr_list  */
#line 709 "yacc_sql.y"
                                   {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2490 "yacc_sql.tab.c"
    break;

  case 126: /* function_attr_list: COMMA ID function_attr_list  */
#line 714 "yacc_sql.y"
                                      {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2500 "yacc_sql.tab.c"
    break;

  case 127: /* function_attr_list: COMMA ID DOT ID function_attr_list  */
#line 719 "yacc_sql.y"
                                             {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2510 "yacc_sql.tab.c"
    break;

  case 128: /* function_attr_list: COMMA STAR function_attr_list  */
#line 724 "yacc_sql.y"
                                        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2520 "yacc_sql.tab.c"
    break;

  case 129: /* function_attr_list: COMMA value function_attr_list  */
#line 729 "yacc_sql.y"
                                         {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2528 "yacc_sql.tab.c"
    break;

  case 131: /* attr_list: COMMA ID attr_list  */
#line 735 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2538 "yacc_sql.tab.c"
    break;

  case 132: /* attr_list: COMMA ID DOT ID attr_list  */
#line 740 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2548 "yacc_sql.tab.c"
    break;

  case 133: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 745 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2558 "yacc_sql.tab.c"
    break;

  case 134: /* attr_list: COMMA function attr_list  */
#line 750 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2566 "yacc_sql.tab.c"
    break;

  case 135: /* attr_list: COMMA ID AS ID attr_list  */
#line 753 "yacc_sql.y"
                               {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2576 "yacc_sql.tab.c"
    break;

  case 136: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 758 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2586 "yacc_sql.tab.c"
    break;

  case 137: /* attr_list: COMMA function AS ID attr_list  */
#line 763 "yacc_sql.y"
                                     {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2594 "yacc_sql.tab.c"
    break;

  case 138: /* attr_list: COMMA ID ID attr_list  */
#line 766 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2604 "yacc_sql.tab.c"
    break;

  case 139: /* attr_list: COMMA ID DOT ID ID attr_list  */
#line 771 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2614 "yacc_sql.tab.c"
    break;

  case 140: /* attr_list: COMMA function ID attr_list  */
#line 776 "yacc_sql.y"
                                  {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2622 "yacc_sql.tab.c"
    break;

  case 141: /* attr_list: COMMA expression attr_list  */
#line 779 "yacc_sql.y"
                                    {
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1), NULL);
	}
#line 2630 "yacc_sql.tab.c"
    break;

  case 142: /* rel_id: ID  */
#line 785 "yacc_sql.y"
      {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[0].string), NULL);
    }
#line 2638 "yacc_sql.tab.c"
    break;

  case 143: /* rel_id: ID AS ID  */
#line 788 "yacc_sql.y"
               {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string), (yyvsp[0].string));
    }
#line 2646 "yacc_sql.tab.c"
    break;

  case 144: /* rel_id: ID ID  */
#line 791 "yacc_sql.y"
            {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string), (yyvsp[0].string));
    }
#line 2654 "yacc_sql.tab.c"
    break;

  case 146: /* rel_list: COMMA rel_id rel_list  */
#line 798 "yacc_sql.y"
                            {	
		  }
#line 2661 "yacc_sql.tab.c"
    break;

  case 148: /* in_value: value  */
#line 802 "yacc_sql.y"
          {
	CONTEXT->in_value[CONTEXT->in_value_num++] = *(yyvsp[0].value1);
   }
#line 2669 "yacc_sql.tab.c"
    break;

  case 150: /* in_value_list: COMMA in_value in_value_list  */
#line 806 "yacc_sql.y"
                                 {
   }
#line 2676 "yacc_sql.tab.c"
    break;

  case 152: /* where: WHERE and_condition condition_list  */
#line 810 "yacc_sql.y"
                                         {	
			}
#line 2683 "yacc_sql.tab.c"
    break;

  case 154: /* condition_list: AND and_condition condition_list  */
#line 815 "yacc_sql.y"
                                       {

	}
#line 2691 "yacc_sql.tab.c"
    break;

  case 155: /* condition_list: OR or_condition condition_list  */
#line 818 "yacc_sql.y"
                                          {
	}
#line 2698 "yacc_sql.tab.c"
    break;

  case 156: /* and_condition: condition  */
#line 822 "yacc_sql.y"
            {
	CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 0;
}
#line 2706 "yacc_sql.tab.c"
    break;

  case 157: /* or_condition: condition  */
#line 826 "yacc_sql.y"
            {
     CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 1;
}
#line 2714 "yacc_sql.tab.c"
    break;

  case 158: /* condition: EXISTS_T value  */
#line 830 "yacc_sql.y"
                      {
		CONTEXT->comp = EXISTS;

		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2728 "yacc_sql.tab.c"
    break;

  case 159: /* condition: NOT EXISTS_T value  */
#line 839 "yacc_sql.y"
                            {
		CONTEXT->comp = NOT_EXISTS;
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2740 "yacc_sql.tab.c"
    break;

  case 160: /* condition: ID comOp LBRACE in_value in_value_list RBRACE  */
#line 846 "yacc_sql.y"
                                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2754 "yacc_sql.tab.c"
    break;

  case 161: /* condition: ID DOT ID comOp LBRACE in_value in_value_list RBRACE  */
#line 855 "yacc_sql.y"
                                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr,(yyvsp[-7].string), (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2768 "yacc_sql.tab.c"
    break;

  case 162: /* condition: value comOp LBRACE in_value in_value_list RBRACE  */
#line 864 "yacc_sql.y"
                                                           {
		Value *left_value = (yyvsp[-5].value1);

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 0, NULL, left_value,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2781 "yacc_sql.tab.c"
    break;

  case 163: /* condition: ID comOp value  */
#line 872 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;

	}
#line 2797 "yacc_sql.tab.c"
    break;

  case 164: /* condition: value comOp value  */
#line 884 "yacc_sql.y"
        {
		Value *left_value = (yyvsp[-2].value1);
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2810 "yacc_sql.tab.c"
    break;

  case 165: /* condition: ID comOp ID  */
#line 892 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2825 "yacc_sql.tab.c"
    break;

  case 166: /* condition: value comOp ID  */
#line 903 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-2].value1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
		}
#line 2840 "yacc_sql.tab.c"
    break;

  case 167: /* condition: ID DOT ID comOp value  */
#line 914 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = (yyvsp[0].value1);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
							
    }
#line 2856 "yacc_sql.tab.c"
    break;

  case 168: /* condition: value comOp ID DOT ID  */
#line 926 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-4].value1);

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2872 "yacc_sql.tab.c"
    break;

  case 169: /* condition: ID DOT ID comOp ID DOT ID  */
#line 938 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2887 "yacc_sql.tab.c"
    break;

  case 170: /* condition: ID comOp ID DOT ID  */
#line 949 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2902 "yacc_sql.tab.c"
    break;

  case 171: /* condition: function comOp value  */
#line 959 "yacc_sql.y"
                           {
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2914 "yacc_sql.tab.c"
    break;

  case 172: /* condition: value comOp function  */
#line 966 "yacc_sql.y"
                           {
	Value *left_value = (yyvsp[-2].value1);

	Condition condition;
	condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
	CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2926 "yacc_sql.tab.c"
    break;

  case 173: /* condition: function comOp function  */
#line 973 "yacc_sql.y"
                              {
	Condition condition;
	condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, (yyvsp[0].function1), NULL);
	CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2936 "yacc_sql.tab.c"
    break;

  case 174: /* condition: value comOp expression  */
#line 978 "yacc_sql.y"
                                {
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, (yyvsp[-2].value1), 1, (yyvsp[0].expr1), NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2946 "yacc_sql.tab.c"
    break;

  case 175: /* condition: expression comOp value  */
#line 983 "yacc_sql.y"
                                {
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1,(yyvsp[-2].expr1), NULL, 0,NULL,(yyvsp[0].value1));
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2956 "yacc_sql.tab.c"
    break;

  case 176: /* condition: ID comOp expression  */
#line 988 "yacc_sql.y"
                             {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].expr1), NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2969 "yacc_sql.tab.c"
    break;

  case 177: /* condition: expression comOp ID  */
#line 996 "yacc_sql.y"
                              {
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].expr1), NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2982 "yacc_sql.tab.c"
    break;

  case 178: /* condition: ID DOT ID comOp expression  */
#line 1004 "yacc_sql.y"
                                    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].expr1), NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2995 "yacc_sql.tab.c"
    break;

  case 179: /* condition: expression comOp ID DOT ID  */
#line 1012 "yacc_sql.y"
                                    {
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].expr1), NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3008 "yacc_sql.tab.c"
    break;

  case 180: /* condition: expression comOp expression  */
#line 1020 "yacc_sql.y"
                                     {
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].expr1), NULL, 1,(yyvsp[0].expr1), NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3018 "yacc_sql.tab.c"
    break;

  case 181: /* expression: function  */
#line 1028 "yacc_sql.y"
              {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,(yyvsp[0].function1),NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3027 "yacc_sql.tab.c"
    break;

  case 182: /* expression: value  */
#line 1032 "yacc_sql.y"
                {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],0,NULL,(yyvsp[0].value1));
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3036 "yacc_sql.tab.c"
    break;

  case 183: /* expression: ID DOT ID  */
#line 1036 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr,(yyvsp[-2].string),(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3047 "yacc_sql.tab.c"
    break;

  case 184: /* expression: ID  */
#line 1042 "yacc_sql.y"
              {
		RelAttr attr;
		relation_attr_init(&attr,NULL,(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3058 "yacc_sql.tab.c"
    break;

  case 185: /* expression: LBRACE expression RBRACE  */
#line 1048 "yacc_sql.y"
                                   {
		append_brace((yyvsp[-1].expr1));
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 3067 "yacc_sql.tab.c"
    break;

  case 186: /* expression: expression STAR expression  */
#line 1052 "yacc_sql.y"
                                     {
		append_expression((yyvsp[-2].expr1),MUL,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3076 "yacc_sql.tab.c"
    break;

  case 187: /* expression: expression DIV_T expression  */
#line 1056 "yacc_sql.y"
                                      {
		append_expression((yyvsp[-2].expr1),DIV,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3085 "yacc_sql.tab.c"
    break;

  case 188: /* expression: expression ADD_T expression  */
#line 1060 "yacc_sql.y"
                                      {
		append_expression((yyvsp[-2].expr1),ADD,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3094 "yacc_sql.tab.c"
    break;

  case 189: /* expression: expression SUB_T expression  */
#line 1064 "yacc_sql.y"
                                      {
		append_expression((yyvsp[-2].expr1),SUB,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3103 "yacc_sql.tab.c"
    break;

  case 190: /* expression: expression expression  */
#line 1068 "yacc_sql.y"
                                {
		// 减数字,当作加负数
		append_expression((yyvsp[-1].expr1),ADD_NEG,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 3113 "yacc_sql.tab.c"
    break;

  case 191: /* expression: SUB_T expression  */
#line 1073 "yacc_sql.y"
                           {
		append_neg((yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[0].expr1);
	 }
#line 3122 "yacc_sql.tab.c"
    break;

  case 192: /* comOp: EQ  */
#line 1082 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3128 "yacc_sql.tab.c"
    break;

  case 193: /* comOp: LT  */
#line 1083 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3134 "yacc_sql.tab.c"
    break;

  case 194: /* comOp: GT  */
#line 1084 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3140 "yacc_sql.tab.c"
    break;

  case 195: /* comOp: LE  */
#line 1085 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3146 "yacc_sql.tab.c"
    break;

  case 196: /* comOp: GE  */
#line 1086 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3152 "yacc_sql.tab.c"
    break;

  case 197: /* comOp: NE  */
#line 1087 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3158 "yacc_sql.tab.c"
    break;

  case 198: /* comOp: LIKE_T  */
#line 1088 "yacc_sql.y"
                 {CONTEXT->comp = LIKE;}
#line 3164 "yacc_sql.tab.c"
    break;

  case 199: /* comOp: NOT LIKE_T  */
#line 1089 "yacc_sql.y"
                     {CONTEXT->comp = NOT_LIKE;}
#line 3170 "yacc_sql.tab.c"
    break;

  case 200: /* comOp: IS_T  */
#line 1090 "yacc_sql.y"
               {CONTEXT->comp = IS;}
#line 3176 "yacc_sql.tab.c"
    break;

  case 201: /* comOp: IS_T NOT  */
#line 1091 "yacc_sql.y"
                  {CONTEXT->comp = IS_NOT;}
#line 3182 "yacc_sql.tab.c"
    break;

  case 202: /* comOp: IN_T  */
#line 1092 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 3188 "yacc_sql.tab.c"
    break;

  case 203: /* comOp: NOT IN_T  */
#line 1093 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 3194 "yacc_sql.tab.c"
    break;

  case 204: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1098 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3203 "yacc_sql.tab.c"
    break;

  case 205: /* show_index: SHOW INDEX FROM ID SEMICOLON  */
#line 1106 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
		}
#line 3212 "yacc_sql.tab.c"
    break;


#line 3216 "yacc_sql.tab.c"

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
  yyerror (scanner, YY_("memory exhausted"));
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

#line 1111 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context[MAX_NUM];
	memset(&context, 0, sizeof(context));
	parser_id = 0;

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context[parser_id].ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
