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
  Expr expr[MAX_NUM];
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
      context->id_num=0;
	  parser_id--;
  }
  parser_id=0;
  printf("parse sql failed. error=%s", str);
}



#line 153 "yacc_sql.tab.c"

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
#define YYLAST   497

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  194
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  418

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
       0,   188,   188,   190,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   215,   220,   225,   231,   237,   243,   249,   255,
     261,   268,   274,   283,   290,   299,   301,   305,   312,   320,
     323,   326,   330,   333,   334,   335,   336,   337,   339,   341,
     345,   355,   366,   368,   372,   375,   377,   381,   386,   391,
     395,   399,   404,   411,   415,   433,   443,   452,   455,   456,
     461,   474,   475,   478,   481,   484,   489,   490,   493,   494,
     498,   501,   504,   509,   514,   520,   521,   523,   524,   529,
     536,   537,   542,   549,   550,   552,   553,   556,   563,   571,
     579,   586,   594,   605,   610,   615,   620,   625,   628,   633,
     638,   641,   646,   651,   654,   659,   664,   669,   677,   685,
     686,   691,   696,   701,   705,   706,   711,   716,   721,   725,
     727,   732,   737,   742,   745,   750,   755,   758,   763,   768,
     774,   777,   780,   785,   787,   790,   791,   794,   795,   797,
     799,   802,   804,   807,   811,   815,   819,   828,   835,   844,
     853,   861,   872,   881,   891,   902,   914,   926,   937,   948,
     957,   964,   971,   979,   983,   989,   995,   998,  1004,  1010,
    1016,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1039,  1047
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

#define YYPACT_NINF (-349)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -349,   400,  -349,    16,    71,    61,   -46,    93,    51,    43,
      55,    22,    90,   115,   119,   121,   125,    94,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,    76,    83,   127,
      86,   103,    12,    50,   108,   126,   171,   173,   147,  -349,
     113,   116,   156,  -349,  -349,  -349,  -349,  -349,   143,   178,
     163,   135,   203,   209,   131,   152,    77,   159,   198,  -349,
     170,   198,  -349,   172,   199,   177,   198,  -349,  -349,  -349,
     181,   220,   199,   194,   193,   196,   197,   230,  -349,  -349,
     262,  -349,  -349,  -349,  -349,    11,  -349,   255,   255,   257,
      26,   136,   142,   222,   198,  -349,   198,  -349,   -23,   277,
     176,   268,   198,  -349,   301,   300,   318,  -349,   282,   317,
     310,   289,   325,   328,   278,  -349,    61,   151,   279,  -349,
    -349,  -349,  -349,    81,   280,   198,  -349,   281,   198,  -349,
     283,   198,  -349,   284,   198,  -349,  -349,  -349,   305,  -349,
     172,   294,     3,   291,   271,   312,   322,   322,     2,  -349,
     387,   320,   340,  -349,  -349,   271,   360,  -349,   271,   194,
     199,   373,  -349,  -349,  -349,  -349,  -349,   100,   196,   364,
     194,   366,   352,    14,   255,   255,   255,   276,   198,   198,
    -349,   198,  -349,   198,  -349,   198,  -349,  -349,   277,   332,
     294,  -349,   357,  -349,   166,   271,  -349,   319,  -349,  -349,
    -349,  -349,  -349,  -349,   -10,  -349,   339,  -349,   191,   211,
     217,   176,   176,  -349,   232,   232,   232,   232,   232,   329,
     239,   343,   383,  -349,   300,   399,  -349,   317,   403,   334,
     341,   358,  -349,  -349,   325,   414,   404,   194,   172,   349,
    -349,  -349,  -349,  -349,   354,   198,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,   355,  -349,   356,  -349,  -349,   322,  -349,
    -349,  -349,   120,   397,  -349,   120,    19,  -349,  -349,   422,
    -349,  -349,     2,     2,  -349,    -9,    -9,  -349,  -349,   189,
      18,   347,   322,   405,   322,   385,   437,   271,   426,   360,
    -349,  -349,  -349,   441,  -349,   428,  -349,  -349,  -349,   194,
     429,   404,   277,   255,   198,  -349,   -20,  -349,   251,  -349,
     431,   378,   431,   384,  -349,  -349,   386,   388,  -349,   389,
     391,   391,   239,  -349,   265,   392,  -349,   383,  -349,  -349,
    -349,    66,   404,   451,   439,   294,  -349,  -349,   176,   393,
     425,   120,   435,  -349,   271,   448,  -349,   449,  -349,   438,
     450,   322,  -349,  -349,   405,   440,  -349,     4,   452,  -349,
    -349,  -349,  -349,   468,   199,     2,   434,   176,   431,   406,
     431,  -349,  -349,   407,  -349,   391,  -349,   408,  -349,   409,
    -349,  -349,   392,     7,  -349,   268,  -349,   176,     2,   456,
    -349,  -349,  -349,  -349,  -349,     7,   452,  -349,   340,     2,
    -349,  -349,  -349,  -349,   343,  -349,   457,  -349
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
       0,     0,   129,   129,    71,   129,     0,     0,     0,    24,
       0,     0,     0,    25,    26,    27,    23,    22,     0,     0,
       0,     0,     0,     0,   119,     0,     0,     0,   129,   104,
       0,   129,   103,     0,   149,     0,   129,   107,    30,    29,
       0,     0,   149,     0,     0,     0,     0,     0,    28,    33,
       0,    63,    59,    60,    62,   124,    61,   124,   124,     0,
     129,   129,   129,   129,   129,   111,   129,   115,   140,   143,
       0,    87,   129,   113,     0,     0,     0,    50,     0,    68,
       0,     0,    35,     0,     0,    58,     0,     0,     0,   120,
     122,   123,   118,     0,     0,   129,   130,     0,   129,   133,
       0,   129,   105,     0,   129,   106,   108,   114,     0,   142,
       0,    76,     0,     0,     0,   175,   173,     0,   151,   154,
       0,     0,    93,   110,   194,     0,    52,    65,     0,     0,
     149,     0,    43,    44,    45,    46,    47,    39,     0,     0,
       0,     0,     0,   124,   124,   124,   124,   129,   129,   129,
     137,   129,   139,   129,   112,   129,   116,   141,   143,     0,
      76,    72,   175,   173,     0,     0,   156,     0,   181,   182,
     183,   184,   185,   186,     0,   187,   189,   191,     0,     0,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,    78,    55,    57,     0,     0,    67,    68,     0,     0,
       0,     0,    40,    38,    35,     0,    48,     0,     0,     0,
     125,   127,   128,   121,     0,   129,   131,   132,   134,   136,
     109,   117,   144,     0,    77,     0,   176,   157,   174,   188,
     192,   190,   145,   163,   161,   145,   164,   162,   171,     0,
     170,   172,   151,   151,   155,   179,   180,   178,   177,   169,
      90,     0,     0,    95,     0,     0,     0,     0,     0,    52,
      51,    69,    66,     0,    42,     0,    41,    36,    34,     0,
       0,    48,   143,   124,   129,   138,     0,   174,     0,   146,
     147,     0,   147,     0,   152,   153,     0,     0,    88,     0,
       0,     0,     0,    94,     0,     0,    70,    55,    54,    53,
     193,    39,    48,     0,     0,    76,   126,   135,     0,     0,
       0,   145,     0,   165,   145,     0,   168,     0,   166,    91,
      90,     0,   101,   100,    95,    98,    97,    80,    85,    56,
      37,    49,    31,     0,   149,   151,     0,     0,   147,     0,
     147,   158,   160,     0,    89,     0,    96,     0,    81,     0,
      82,    83,     0,    80,    32,    87,    73,     0,   151,     0,
     167,   148,    92,   102,    99,    80,    85,    79,    93,   151,
      75,   159,    84,    86,    78,    74,     0,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,   235,   302,   140,  -349,  -349,
    -290,  -172,  -349,   183,   249,   148,   187,  -349,   -62,  -349,
    -349,   321,   250,  -349,  -349,  -349,  -194,    72,  -348,    96,
      85,    97,   129,    87,   130,   161,   370,    -5,  -349,   -87,
     -18,  -141,  -185,  -249,  -302,   -81,  -267,  -216,  -349,   275,
    -115,  -153,  -349,  -349
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   179,   122,   243,   305,   177,
     310,   118,    31,   235,   166,   298,   232,   126,   156,    32,
      33,   119,   170,    34,    74,   200,   201,   296,   391,   368,
     393,   162,   328,   231,   333,   293,    44,   157,    99,   129,
      69,   109,   151,   320,   355,   111,   223,   158,   283,   159,
     160,   218,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   116,    98,   219,   220,   282,   264,   228,   246,   198,
     130,   131,   125,   262,   388,   324,   325,   388,   348,   152,
     357,   344,    37,    46,    38,    72,   322,    77,    64,   127,
      65,   148,   127,   389,   349,    64,   326,   204,   221,   269,
     128,    66,    64,   249,    65,   407,   149,   327,   323,   350,
     105,   270,   371,   107,    49,   133,   226,   412,   113,   390,
     101,    91,   390,   227,   222,   185,    67,    39,    65,    92,
      93,    94,   202,    50,    96,   311,   399,    40,   401,    41,
     134,    68,   136,   139,   142,   145,   146,    51,   147,   238,
     203,    52,   206,    53,   163,   135,   250,   251,   252,   253,
      47,    48,   378,   233,    70,   380,   236,   312,   396,   285,
     286,   287,   288,   289,   241,   318,   240,   190,    54,    71,
     192,    45,    55,   194,    56,   242,   196,   345,    57,   125,
      42,   410,   375,    43,    58,    61,    90,   342,   330,   331,
      73,   334,   415,   267,    65,    59,   102,    90,   241,   103,
     187,   374,    60,   188,    65,    62,   274,   277,   280,   242,
      65,   398,   203,   203,   203,   203,   203,    90,   292,   256,
     257,   258,    63,   259,    78,   260,    79,   261,    91,    80,
      75,   409,    81,   266,    84,    82,    92,    93,    94,    91,
     137,    96,   152,    83,    85,    76,   140,    92,    93,    94,
      95,    86,    96,    97,    87,   138,    88,   272,   385,    91,
     319,   141,    89,   319,   278,   281,    65,    92,    93,    94,
     183,   100,    96,   184,   153,   294,   346,   275,   104,   224,
     225,   226,   110,    90,    91,   233,   154,   315,   227,   106,
      65,   108,    92,    93,    94,   155,   112,    96,   152,    91,
     114,   115,   224,   225,   226,    90,   353,    92,    93,    94,
     273,   227,    96,   117,   120,   121,   123,   351,   124,    91,
     292,   125,   366,   127,   132,    91,   143,    92,    93,    94,
     276,    90,    96,    92,    93,    94,   279,    90,    96,   319,
      91,   144,   319,   395,    65,   150,   347,    91,    92,    93,
      94,   202,   161,    96,   164,    92,    93,    94,   291,    91,
      96,   172,   173,   174,   175,   176,   165,    92,    93,    94,
     352,   167,    96,    91,   168,   362,   363,   294,    64,    91,
     254,    92,    93,    94,   365,   169,    96,    92,    93,    94,
     171,   207,    96,   178,   180,   255,   199,   181,   186,   189,
     191,   205,   193,   195,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    64,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   197,   230,   329,   229,   234,   239,
     403,   245,   247,   217,   248,   263,   265,   271,   268,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   290,   295,
       2,   297,   300,   303,     3,     4,   302,   304,   217,     5,
       6,     7,     8,     9,    10,    11,   306,   308,   313,    12,
      13,    14,   309,   314,   316,   317,   321,    15,    16,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    64,    17,
     336,   332,   335,   338,   340,   341,   343,   356,   217,   354,
     224,   225,   226,   358,   372,   359,   373,   360,   361,   227,
     279,   367,   376,   377,   379,   381,   382,   383,   326,   387,
     392,   394,   397,   411,   417,   400,   402,   404,   405,   307,
     244,   370,   339,   299,   337,   369,   416,   301,   406,   384,
     237,   413,   408,   364,   386,   414,   182,   284
};

static const yytype_int16 yycheck[] =
{
       5,    82,    64,   156,   157,   221,   200,   160,   180,   150,
      97,    98,     9,   198,    10,   282,   283,    10,    38,    16,
     322,   311,     6,    69,     8,    43,   275,    45,    16,    18,
      18,    54,    18,    29,    54,    16,    18,   152,    36,    49,
      29,    29,    16,    29,    18,   393,    69,    29,    29,    69,
      68,    61,   342,    71,     3,    29,    65,   405,    76,    55,
      65,    58,    55,    72,    62,   127,    54,    51,    18,    66,
      67,    68,    69,    30,    71,   247,   378,     6,   380,     8,
      54,    69,   100,   101,   102,   103,   104,    32,   106,   170,
     152,    69,   154,     3,   112,    69,   183,   184,   185,   186,
       7,     8,   351,   165,    54,   354,   168,   248,   375,   224,
     225,   226,   227,   228,    48,   268,    16,   135,     3,    69,
     138,   126,     3,   141,     3,    59,   144,   312,     3,     9,
      69,   398,   348,    72,    40,     8,    16,   309,   291,   292,
      32,   294,   409,   205,    18,    69,    69,    16,    48,    72,
      69,   345,    69,    72,    18,    69,   218,   219,   220,    59,
      18,   377,   224,   225,   226,   227,   228,    16,   230,   187,
     188,   189,    69,   191,     3,   193,     3,   195,    58,    32,
      54,   397,    69,    17,    41,    69,    66,    67,    68,    58,
      54,    71,    16,    37,    16,    69,    54,    66,    67,    68,
      69,    38,    71,    72,    69,    69,     3,    16,   361,    58,
     272,    69,     3,   275,   219,   220,    18,    66,    67,    68,
      69,    69,    71,    72,    48,   230,   313,    16,    69,    63,
      64,    65,    33,    16,    58,   297,    60,   255,    72,    69,
      18,    69,    66,    67,    68,    69,    69,    71,    16,    58,
      69,    31,    63,    64,    65,    16,   318,    66,    67,    68,
      69,    72,    71,    69,    71,    69,    69,    16,    38,    58,
     332,     9,   334,    18,    17,    58,    54,    66,    67,    68,
      69,    16,    71,    66,    67,    68,    69,    16,    71,   351,
      58,    69,   354,   374,    18,    18,   314,    58,    66,    67,
      68,    69,    34,    71,     3,    66,    67,    68,    69,    58,
      71,    22,    23,    24,    25,    26,    16,    66,    67,    68,
      69,     3,    71,    58,    42,   330,   331,   332,    16,    58,
      54,    66,    67,    68,    69,    18,    71,    66,    67,    68,
      30,    29,    71,    18,    16,    69,    52,    69,    69,    69,
      69,    60,    69,    69,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    16,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    61,    69,    35,    29,    57,    18,     6,
     385,    17,    16,    61,    32,    53,    29,    48,    69,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    69,    56,
       0,    18,     3,    69,     4,     5,     3,    66,    61,     9,
      10,    11,    12,    13,    14,    15,    58,     3,    69,    19,
      20,    21,    18,    69,    69,    69,    29,    27,    28,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    16,    39,
       3,    36,    57,    17,     3,    17,    17,    69,    61,    18,
      63,    64,    65,    69,     3,    69,    17,    69,    69,    72,
      69,    69,    69,    38,    29,    17,    17,    29,    18,    29,
      18,     3,    38,    17,    17,    69,    69,    69,    69,   244,
     178,   341,   299,   234,   297,   337,   414,   237,   392,   360,
     169,   406,   395,   332,   364,   408,   126,   222
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    27,    28,    39,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    96,   103,   104,   107,   136,   137,     6,     8,    51,
       6,     8,    69,    72,   120,   121,    69,     7,     8,     3,
      30,    32,    69,     3,     3,     3,     3,     3,    40,    69,
      69,     8,    69,    69,    16,    18,    29,    54,    69,   124,
      54,    69,   124,    32,   108,    54,    69,   124,     3,     3,
      32,    69,    69,    37,    41,    16,    38,    69,     3,     3,
      16,    58,    66,    67,    68,    69,    71,    72,   102,   122,
      69,   121,    69,    72,    69,   124,    69,   124,    69,   125,
      33,   129,    69,   124,    69,    31,   129,    69,    95,   105,
      71,    69,    90,    69,    38,     9,   101,    18,    29,   123,
     123,   123,    17,    29,    54,    69,   124,    54,    69,   124,
      54,    69,   124,    54,    69,   124,   124,   124,    54,    69,
      18,   126,    16,    48,    60,    69,   102,   121,   131,   133,
     134,    34,   115,   124,     3,    16,    98,     3,    42,    18,
     106,    30,    22,    23,    24,    25,    26,    93,    18,    89,
      16,    69,   120,    69,    72,   102,    69,    69,    72,    69,
     124,    69,   124,    69,   124,    69,   124,    69,   125,    52,
     109,   110,    69,   102,   134,    60,   102,    29,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    61,   135,   135,
     135,    36,    62,   130,    63,    64,    65,    72,   135,    57,
      35,   117,   100,   102,    18,    97,   102,   105,   129,     6,
      16,    48,    59,    91,    90,    17,    95,    16,    32,    29,
     123,   123,   123,   123,    54,    69,   124,   124,   124,   124,
     124,   124,   126,    53,   110,    29,    17,   102,    69,    49,
      61,    48,    16,    69,   102,    16,    69,   102,   121,    69,
     102,   121,   131,   132,   133,   134,   134,   134,   134,   134,
      69,    69,   102,   119,   121,    56,   111,    18,    99,    98,
       3,   106,     3,    69,    66,    92,    58,    89,     3,    18,
      94,    95,   125,    69,    69,   124,    69,    69,   135,   102,
     127,    29,   127,    29,   130,   130,    18,    29,   116,    29,
     135,   135,    36,   118,   135,    57,     3,   100,    17,    97,
       3,    17,    95,    17,    94,   126,   123,   124,    38,    54,
      69,    16,    69,   102,    18,   128,    69,   128,    69,    69,
      69,    69,   121,   121,   119,    69,   102,    69,   113,    99,
      91,    94,     3,    17,   110,   131,    69,    38,   127,    29,
     127,    17,    17,    29,   116,   135,   118,    29,    10,    29,
      55,   112,    18,   114,     3,   129,   130,    38,   131,   128,
      69,   128,    69,   121,    69,    69,   113,   112,   115,   131,
     130,    17,   112,   114,   117,   130,   111,    17
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
     120,   120,   120,   120,   120,   120,   120,   120,   121,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   131,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   136,   137
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
       4,     3,     5,     3,     4,     3,     5,     6,     4,     0,
       2,     4,     2,     2,     0,     3,     5,     3,     3,     0,
       3,     5,     5,     3,     5,     7,     5,     4,     6,     4,
       1,     3,     2,     0,     3,     0,     1,     0,     3,     0,
       3,     0,     3,     3,     1,     1,     2,     3,     6,     8,
       6,     3,     3,     3,     3,     5,     5,     7,     5,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     2,     8,     5
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
#line 215 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1591 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 220 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1599 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 225 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1607 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 231 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1615 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 237 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1623 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 243 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1631 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 249 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1640 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 255 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1648 "yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 261 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1657 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 269 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,0);
			CONTEXT->id_num=0;
		}
#line 1667 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 275 "yacc_sql.y"
            {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,1);
			CONTEXT->id_num=0;
		}
#line 1677 "yacc_sql.tab.c"
    break;

  case 33: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 284 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1686 "yacc_sql.tab.c"
    break;

  case 34: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 291 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_length = 0;
		}
#line 1698 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 301 "yacc_sql.y"
                                   {    }
#line 1704 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID type LBRACE number RBRACE nullable  */
#line 306 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, (yyvsp[-5].string), (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1715 "yacc_sql.tab.c"
    break;

  case 38: /* attr_def: ID type nullable  */
#line 313 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,(yyvsp[-2].string), (yyvsp[-1].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1726 "yacc_sql.tab.c"
    break;

  case 39: /* nullable: %empty  */
#line 320 "yacc_sql.y"
               {
	    (yyval.number)=0;
	 }
#line 1734 "yacc_sql.tab.c"
    break;

  case 40: /* nullable: NULLABLE  */
#line 323 "yacc_sql.y"
             {
		(yyval.number)=1;
	 }
#line 1742 "yacc_sql.tab.c"
    break;

  case 41: /* nullable: NOT NULL_T  */
#line 326 "yacc_sql.y"
                   {
		(yyval.number)=0;
	}
#line 1750 "yacc_sql.tab.c"
    break;

  case 42: /* number: NUMBER  */
#line 330 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1756 "yacc_sql.tab.c"
    break;

  case 43: /* type: INT_T  */
#line 333 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1762 "yacc_sql.tab.c"
    break;

  case 44: /* type: STRING_T  */
#line 334 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1768 "yacc_sql.tab.c"
    break;

  case 45: /* type: FLOAT_T  */
#line 335 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1774 "yacc_sql.tab.c"
    break;

  case 46: /* type: DATE_T  */
#line 336 "yacc_sql.y"
                    { (yyval.number)=DATES;}
#line 1780 "yacc_sql.tab.c"
    break;

  case 47: /* type: TEXT_T  */
#line 337 "yacc_sql.y"
                    { (yyval.number)=TEXTS;}
#line 1786 "yacc_sql.tab.c"
    break;

  case 49: /* id_list: COMMA ID_get id_list  */
#line 341 "yacc_sql.y"
                        {
	 
   }
#line 1794 "yacc_sql.tab.c"
    break;

  case 50: /* ID_get: ID  */
#line 346 "yacc_sql.y"
        {
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", (yyvsp[0].string));
		CONTEXT->id_num++;
	}
#line 1804 "yacc_sql.tab.c"
    break;

  case 51: /* insert: INSERT INTO ID VALUES value_def value_def_list SEMICOLON  */
#line 356 "yacc_sql.y"
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
#line 1819 "yacc_sql.tab.c"
    break;

  case 53: /* value_def_list: COMMA value_def value_def_list  */
#line 368 "yacc_sql.y"
                                  {
  }
#line 1826 "yacc_sql.tab.c"
    break;

  case 54: /* value_def: LBRACE insert_value value_list RBRACE  */
#line 372 "yacc_sql.y"
                                       {
	CONTEXT->insert_num++;
  }
#line 1834 "yacc_sql.tab.c"
    break;

  case 56: /* value_list: COMMA insert_value value_list  */
#line 377 "yacc_sql.y"
                                     {
	  }
#line 1841 "yacc_sql.tab.c"
    break;

  case 57: /* insert_value: value  */
#line 381 "yacc_sql.y"
        {
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*(yyvsp[0].value1);
   }
#line 1849 "yacc_sql.tab.c"
    break;

  case 58: /* get_select: SELECT  */
#line 386 "yacc_sql.y"
         {
	parser_id++;
	CONTEXT->ssql=query_create();
}
#line 1858 "yacc_sql.tab.c"
    break;

  case 59: /* value: NUMBER  */
#line 391 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1867 "yacc_sql.tab.c"
    break;

  case 60: /* value: FLOAT  */
#line 395 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1876 "yacc_sql.tab.c"
    break;

  case 61: /* value: SSS  */
#line 399 "yacc_sql.y"
         {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1886 "yacc_sql.tab.c"
    break;

  case 62: /* value: DATE  */
#line 404 "yacc_sql.y"
             {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		if(value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string))<0){
		  CONTEXT->ssql->date_parse_err = -1;
		}
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 1898 "yacc_sql.tab.c"
    break;

  case 63: /* value: NULL_T  */
#line 411 "yacc_sql.y"
               {
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 1907 "yacc_sql.tab.c"
    break;

  case 64: /* value: LBRACE get_select select_attr FROM rel_id rel_list join_attr_list where group_by having order_by RBRACE  */
#line 415 "yacc_sql.y"
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
#line 1927 "yacc_sql.tab.c"
    break;

  case 65: /* delete: DELETE FROM ID where SEMICOLON  */
#line 434 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1939 "yacc_sql.tab.c"
    break;

  case 66: /* update: UPDATE ID SET eq_define eq_define_list where SEMICOLON  */
#line 444 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,(yyvsp[-5].string),CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1950 "yacc_sql.tab.c"
    break;

  case 67: /* eq_define: ID_get EQ value  */
#line 452 "yacc_sql.y"
                  {

}
#line 1958 "yacc_sql.tab.c"
    break;

  case 69: /* eq_define_list: COMMA eq_define eq_define_list  */
#line 456 "yacc_sql.y"
                                  {

   }
#line 1966 "yacc_sql.tab.c"
    break;

  case 70: /* select: SELECT select_attr from where group_by having order_by SEMICOLON  */
#line 461 "yacc_sql.y"
                                                                         {
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		selects_append_group_by(&CONTEXT->ssql->sstr.selection, CONTEXT->group_by_attrs, CONTEXT->group_by_attr_length);
		selects_append_having(&CONTEXT->ssql->sstr.selection, CONTEXT->having_conditions, CONTEXT->having_condition_length);
		selects_append_order(&CONTEXT->ssql->sstr.selection, CONTEXT->order_attrs, CONTEXT->order_attr_size, CONTEXT->order_flag);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";

		//临时变量清零
		CONTEXT->condition_length=0;
		CONTEXT->value_length = 0;
	}
#line 1982 "yacc_sql.tab.c"
    break;

  case 72: /* from: FROM rel_id rel_list join_attr_list  */
#line 475 "yacc_sql.y"
                                              {}
#line 1988 "yacc_sql.tab.c"
    break;

  case 73: /* join_attr: INNER JOIN ID ON and_condition condition_list  */
#line 478 "yacc_sql.y"
                                                     {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string), NULL);
   	}
#line 1996 "yacc_sql.tab.c"
    break;

  case 74: /* join_attr: INNER JOIN ID AS ID ON and_condition condition_list  */
#line 481 "yacc_sql.y"
                                                             {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string), (yyvsp[-3].string));
   	}
#line 2004 "yacc_sql.tab.c"
    break;

  case 75: /* join_attr: INNER JOIN ID ID ON and_condition condition_list  */
#line 484 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string), (yyvsp[-3].string));
   	}
#line 2012 "yacc_sql.tab.c"
    break;

  case 77: /* join_attr_list: join_attr join_attr_list  */
#line 490 "yacc_sql.y"
                              {
   }
#line 2019 "yacc_sql.tab.c"
    break;

  case 79: /* order_by: ORDER BY order_attr order_attr_lists order  */
#line 494 "yacc_sql.y"
                                                 {
		
	}
#line 2027 "yacc_sql.tab.c"
    break;

  case 80: /* order: %empty  */
#line 498 "yacc_sql.y"
             {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
#line 2035 "yacc_sql.tab.c"
    break;

  case 81: /* order: DESC  */
#line 501 "yacc_sql.y"
           {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
#line 2043 "yacc_sql.tab.c"
    break;

  case 82: /* order: ASC  */
#line 504 "yacc_sql.y"
              {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
#line 2051 "yacc_sql.tab.c"
    break;

  case 83: /* order_attr: ID order  */
#line 509 "yacc_sql.y"
             { 
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
#line 2061 "yacc_sql.tab.c"
    break;

  case 84: /* order_attr: ID DOT ID order  */
#line 514 "yacc_sql.y"
                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
#line 2071 "yacc_sql.tab.c"
    break;

  case 88: /* group_by: GROUP BY ID group_by_list  */
#line 524 "yacc_sql.y"
                                    {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2081 "yacc_sql.tab.c"
    break;

  case 89: /* group_by: GROUP BY ID DOT ID group_by_list  */
#line 529 "yacc_sql.y"
                                           {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2091 "yacc_sql.tab.c"
    break;

  case 91: /* group_by_list: COMMA ID  */
#line 537 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2101 "yacc_sql.tab.c"
    break;

  case 92: /* group_by_list: COMMA ID DOT ID  */
#line 542 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2111 "yacc_sql.tab.c"
    break;

  case 94: /* having: HAVING having_condition having_condition_list  */
#line 550 "yacc_sql.y"
                                                        {}
#line 2117 "yacc_sql.tab.c"
    break;

  case 96: /* having_condition_list: AND having_condition having_condition_list  */
#line 553 "yacc_sql.y"
                                                     {}
#line 2123 "yacc_sql.tab.c"
    break;

  case 97: /* having_condition: function comOp value  */
#line 556 "yacc_sql.y"
                         {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2135 "yacc_sql.tab.c"
    break;

  case 98: /* having_condition: function comOp ID  */
#line 563 "yacc_sql.y"
                            {
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2148 "yacc_sql.tab.c"
    break;

  case 99: /* having_condition: function comOp ID DOT ID  */
#line 571 "yacc_sql.y"
                                   {
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2161 "yacc_sql.tab.c"
    break;

  case 100: /* having_condition: value comOp function  */
#line 579 "yacc_sql.y"
                               {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2173 "yacc_sql.tab.c"
    break;

  case 101: /* having_condition: ID comOp function  */
#line 586 "yacc_sql.y"
                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].function1));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2186 "yacc_sql.tab.c"
    break;

  case 102: /* having_condition: ID DOT ID comOp function  */
#line 594 "yacc_sql.y"
                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2199 "yacc_sql.tab.c"
    break;

  case 103: /* select_attr: STAR attr_list  */
#line 605 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2209 "yacc_sql.tab.c"
    break;

  case 104: /* select_attr: ID attr_list  */
#line 610 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2219 "yacc_sql.tab.c"
    break;

  case 105: /* select_attr: ID DOT ID attr_list  */
#line 615 "yacc_sql.y"
                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2229 "yacc_sql.tab.c"
    break;

  case 106: /* select_attr: ID DOT STAR attr_list  */
#line 620 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2239 "yacc_sql.tab.c"
    break;

  case 107: /* select_attr: function attr_list  */
#line 625 "yacc_sql.y"
                         {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2247 "yacc_sql.tab.c"
    break;

  case 108: /* select_attr: ID AS ID attr_list  */
#line 628 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2257 "yacc_sql.tab.c"
    break;

  case 109: /* select_attr: ID DOT ID AS ID attr_list  */
#line 633 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2267 "yacc_sql.tab.c"
    break;

  case 110: /* select_attr: function AS ID attr_list  */
#line 638 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2275 "yacc_sql.tab.c"
    break;

  case 111: /* select_attr: ID ID attr_list  */
#line 641 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2285 "yacc_sql.tab.c"
    break;

  case 112: /* select_attr: ID DOT ID ID attr_list  */
#line 646 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2295 "yacc_sql.tab.c"
    break;

  case 113: /* select_attr: function ID attr_list  */
#line 651 "yacc_sql.y"
                            {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2303 "yacc_sql.tab.c"
    break;

  case 114: /* select_attr: STAR AS ID attr_list  */
#line 654 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2313 "yacc_sql.tab.c"
    break;

  case 115: /* select_attr: STAR ID attr_list  */
#line 659 "yacc_sql.y"
                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2323 "yacc_sql.tab.c"
    break;

  case 116: /* select_attr: ID DOT STAR ID attr_list  */
#line 664 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2333 "yacc_sql.tab.c"
    break;

  case 117: /* select_attr: ID DOT STAR AS ID attr_list  */
#line 669 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2343 "yacc_sql.tab.c"
    break;

  case 118: /* function: ID LBRACE function_attr RBRACE  */
#line 677 "yacc_sql.y"
                                       {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, (yyvsp[-3].string));
		CONTEXT->parameter_length = 0;
		(yyval.function1)=&CONTEXT->functions[CONTEXT->function_length-1];
	}
#line 2354 "yacc_sql.tab.c"
    break;

  case 120: /* function_attr: ID function_attr_list  */
#line 686 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2364 "yacc_sql.tab.c"
    break;

  case 121: /* function_attr: ID DOT ID function_attr_list  */
#line 691 "yacc_sql.y"
                                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2374 "yacc_sql.tab.c"
    break;

  case 122: /* function_attr: STAR function_attr_list  */
#line 696 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2384 "yacc_sql.tab.c"
    break;

  case 123: /* function_attr: value function_attr_list  */
#line 701 "yacc_sql.y"
                                   {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2392 "yacc_sql.tab.c"
    break;

  case 125: /* function_attr_list: COMMA ID function_attr_list  */
#line 706 "yacc_sql.y"
                                      {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2402 "yacc_sql.tab.c"
    break;

  case 126: /* function_attr_list: COMMA ID DOT ID function_attr_list  */
#line 711 "yacc_sql.y"
                                             {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2412 "yacc_sql.tab.c"
    break;

  case 127: /* function_attr_list: COMMA STAR function_attr_list  */
#line 716 "yacc_sql.y"
                                        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2422 "yacc_sql.tab.c"
    break;

  case 128: /* function_attr_list: COMMA value function_attr_list  */
#line 721 "yacc_sql.y"
                                         {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2430 "yacc_sql.tab.c"
    break;

  case 130: /* attr_list: COMMA ID attr_list  */
#line 727 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2440 "yacc_sql.tab.c"
    break;

  case 131: /* attr_list: COMMA ID DOT ID attr_list  */
#line 732 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2450 "yacc_sql.tab.c"
    break;

  case 132: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 737 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2460 "yacc_sql.tab.c"
    break;

  case 133: /* attr_list: COMMA function attr_list  */
#line 742 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2468 "yacc_sql.tab.c"
    break;

  case 134: /* attr_list: COMMA ID AS ID attr_list  */
#line 745 "yacc_sql.y"
                               {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2478 "yacc_sql.tab.c"
    break;

  case 135: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 750 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2488 "yacc_sql.tab.c"
    break;

  case 136: /* attr_list: COMMA function AS ID attr_list  */
#line 755 "yacc_sql.y"
                                     {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2496 "yacc_sql.tab.c"
    break;

  case 137: /* attr_list: COMMA ID ID attr_list  */
#line 758 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2506 "yacc_sql.tab.c"
    break;

  case 138: /* attr_list: COMMA ID DOT ID ID attr_list  */
#line 763 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2516 "yacc_sql.tab.c"
    break;

  case 139: /* attr_list: COMMA function ID attr_list  */
#line 768 "yacc_sql.y"
                                  {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2524 "yacc_sql.tab.c"
    break;

  case 140: /* rel_id: ID  */
#line 774 "yacc_sql.y"
      {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[0].string), NULL);
    }
#line 2532 "yacc_sql.tab.c"
    break;

  case 141: /* rel_id: ID AS ID  */
#line 777 "yacc_sql.y"
               {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string), (yyvsp[0].string));
    }
#line 2540 "yacc_sql.tab.c"
    break;

  case 142: /* rel_id: ID ID  */
#line 780 "yacc_sql.y"
            {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string), (yyvsp[0].string));
    }
#line 2548 "yacc_sql.tab.c"
    break;

  case 144: /* rel_list: COMMA rel_id rel_list  */
#line 787 "yacc_sql.y"
                            {	
		  }
#line 2555 "yacc_sql.tab.c"
    break;

  case 146: /* in_value: value  */
#line 791 "yacc_sql.y"
          {
	CONTEXT->in_value[CONTEXT->in_value_num++] = *(yyvsp[0].value1);
   }
#line 2563 "yacc_sql.tab.c"
    break;

  case 148: /* in_value_list: COMMA in_value in_value_list  */
#line 795 "yacc_sql.y"
                                 {
   }
#line 2570 "yacc_sql.tab.c"
    break;

  case 150: /* where: WHERE and_condition condition_list  */
#line 799 "yacc_sql.y"
                                         {	
			}
#line 2577 "yacc_sql.tab.c"
    break;

  case 152: /* condition_list: AND and_condition condition_list  */
#line 804 "yacc_sql.y"
                                       {

	}
#line 2585 "yacc_sql.tab.c"
    break;

  case 153: /* condition_list: OR or_condition condition_list  */
#line 807 "yacc_sql.y"
                                          {
	}
#line 2592 "yacc_sql.tab.c"
    break;

  case 154: /* and_condition: condition  */
#line 811 "yacc_sql.y"
            {
	CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 0;
}
#line 2600 "yacc_sql.tab.c"
    break;

  case 155: /* or_condition: condition  */
#line 815 "yacc_sql.y"
            {
     CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 1;
}
#line 2608 "yacc_sql.tab.c"
    break;

  case 156: /* condition: EXISTS_T value  */
#line 819 "yacc_sql.y"
                      {
		CONTEXT->comp = EXISTS;

		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2622 "yacc_sql.tab.c"
    break;

  case 157: /* condition: NOT EXISTS_T value  */
#line 828 "yacc_sql.y"
                            {
		CONTEXT->comp = NOT_EXISTS;
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2634 "yacc_sql.tab.c"
    break;

  case 158: /* condition: ID comOp LBRACE in_value in_value_list RBRACE  */
#line 835 "yacc_sql.y"
                                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2648 "yacc_sql.tab.c"
    break;

  case 159: /* condition: ID DOT ID comOp LBRACE in_value in_value_list RBRACE  */
#line 844 "yacc_sql.y"
                                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr,(yyvsp[-7].string), (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2662 "yacc_sql.tab.c"
    break;

  case 160: /* condition: value comOp LBRACE in_value in_value_list RBRACE  */
#line 853 "yacc_sql.y"
                                                           {
		Value *left_value = (yyvsp[-5].value1);

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 0, NULL, left_value,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2675 "yacc_sql.tab.c"
    break;

  case 161: /* condition: ID comOp value  */
#line 861 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;

	}
#line 2691 "yacc_sql.tab.c"
    break;

  case 162: /* condition: value comOp value  */
#line 873 "yacc_sql.y"
        {
		Value *left_value = (yyvsp[-2].value1);
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2704 "yacc_sql.tab.c"
    break;

  case 163: /* condition: ID comOp ID  */
#line 881 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2719 "yacc_sql.tab.c"
    break;

  case 164: /* condition: value comOp ID  */
#line 892 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-2].value1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
		}
#line 2734 "yacc_sql.tab.c"
    break;

  case 165: /* condition: ID DOT ID comOp value  */
#line 903 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = (yyvsp[0].value1);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
							
    }
#line 2750 "yacc_sql.tab.c"
    break;

  case 166: /* condition: value comOp ID DOT ID  */
#line 915 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-4].value1);

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2766 "yacc_sql.tab.c"
    break;

  case 167: /* condition: ID DOT ID comOp ID DOT ID  */
#line 927 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2781 "yacc_sql.tab.c"
    break;

  case 168: /* condition: ID comOp ID DOT ID  */
#line 938 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2796 "yacc_sql.tab.c"
    break;

  case 169: /* condition: expression comOp expression  */
#line 948 "yacc_sql.y"
                                     {
		Value left_value;
		value_init_expression(&left_value,(yyvsp[-2].expr1));
		Value right_value;
		value_init_expression(&right_value,(yyvsp[0].expr1));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, &right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2810 "yacc_sql.tab.c"
    break;

  case 170: /* condition: function comOp value  */
#line 957 "yacc_sql.y"
                           {
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2822 "yacc_sql.tab.c"
    break;

  case 171: /* condition: value comOp function  */
#line 964 "yacc_sql.y"
                           {
	Value *left_value = (yyvsp[-2].value1);

	Condition condition;
	condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
	CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2834 "yacc_sql.tab.c"
    break;

  case 172: /* condition: function comOp function  */
#line 971 "yacc_sql.y"
                              {
	Condition condition;
	condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, (yyvsp[0].function1), NULL);
	CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2844 "yacc_sql.tab.c"
    break;

  case 173: /* expression: value  */
#line 979 "yacc_sql.y"
               {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],0,NULL,(yyvsp[0].value1));
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 2853 "yacc_sql.tab.c"
    break;

  case 174: /* expression: ID DOT ID  */
#line 983 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr,(yyvsp[-2].string),(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 2864 "yacc_sql.tab.c"
    break;

  case 175: /* expression: ID  */
#line 989 "yacc_sql.y"
              {
		RelAttr attr;
		relation_attr_init(&attr,NULL,(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 2875 "yacc_sql.tab.c"
    break;

  case 176: /* expression: LBRACE expression RBRACE  */
#line 995 "yacc_sql.y"
                                   {
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 2883 "yacc_sql.tab.c"
    break;

  case 177: /* expression: expression STAR expression  */
#line 998 "yacc_sql.y"
                                     {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,MUL,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2894 "yacc_sql.tab.c"
    break;

  case 178: /* expression: expression DIV_T expression  */
#line 1004 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,DIV,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2905 "yacc_sql.tab.c"
    break;

  case 179: /* expression: expression ADD_T expression  */
#line 1010 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,ADD,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2916 "yacc_sql.tab.c"
    break;

  case 180: /* expression: expression SUB_T expression  */
#line 1016 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,SUB,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2927 "yacc_sql.tab.c"
    break;

  case 181: /* comOp: EQ  */
#line 1024 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2933 "yacc_sql.tab.c"
    break;

  case 182: /* comOp: LT  */
#line 1025 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2939 "yacc_sql.tab.c"
    break;

  case 183: /* comOp: GT  */
#line 1026 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2945 "yacc_sql.tab.c"
    break;

  case 184: /* comOp: LE  */
#line 1027 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2951 "yacc_sql.tab.c"
    break;

  case 185: /* comOp: GE  */
#line 1028 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2957 "yacc_sql.tab.c"
    break;

  case 186: /* comOp: NE  */
#line 1029 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2963 "yacc_sql.tab.c"
    break;

  case 187: /* comOp: LIKE_T  */
#line 1030 "yacc_sql.y"
                 {CONTEXT->comp = LIKE;}
#line 2969 "yacc_sql.tab.c"
    break;

  case 188: /* comOp: NOT LIKE_T  */
#line 1031 "yacc_sql.y"
                     {CONTEXT->comp = NOT_LIKE;}
#line 2975 "yacc_sql.tab.c"
    break;

  case 189: /* comOp: IS_T  */
#line 1032 "yacc_sql.y"
               {CONTEXT->comp = IS;}
#line 2981 "yacc_sql.tab.c"
    break;

  case 190: /* comOp: IS_T NOT  */
#line 1033 "yacc_sql.y"
                  {CONTEXT->comp = IS_NOT;}
#line 2987 "yacc_sql.tab.c"
    break;

  case 191: /* comOp: IN_T  */
#line 1034 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 2993 "yacc_sql.tab.c"
    break;

  case 192: /* comOp: NOT IN_T  */
#line 1035 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 2999 "yacc_sql.tab.c"
    break;

  case 193: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1040 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3008 "yacc_sql.tab.c"
    break;

  case 194: /* show_index: SHOW INDEX FROM ID SEMICOLON  */
#line 1048 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
		}
#line 3017 "yacc_sql.tab.c"
    break;


#line 3021 "yacc_sql.tab.c"

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

#line 1053 "yacc_sql.y"

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
