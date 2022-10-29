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
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  413

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
     960,   964,   970,   976,   979,   985,   991,   997,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1020,  1028
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

#define YYPACT_NINF (-348)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -348,   349,  -348,    12,   202,   -13,   -44,    23,    43,    21,
      42,    -9,   101,   119,   128,   129,   136,   107,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,    92,    93,   163,
     114,   124,     8,    31,   148,    32,   194,   206,   179,  -348,
     153,   162,   176,  -348,  -348,  -348,  -348,  -348,   191,   218,
     197,   168,   245,   247,   118,   182,    54,   183,   235,  -348,
     186,   235,  -348,   188,   225,   193,   235,  -348,  -348,  -348,
     195,   232,   225,   198,   208,   200,   214,   228,  -348,  -348,
     276,  -348,  -348,  -348,  -348,    26,  -348,   268,   268,   274,
      18,    75,    79,   103,   235,  -348,   235,  -348,   -26,   278,
     158,   270,   235,  -348,   302,   294,   311,  -348,   275,   298,
     288,   277,   312,   304,   262,  -348,   -13,   133,   264,  -348,
    -348,  -348,  -348,   126,   265,   235,  -348,   266,   235,  -348,
     267,   235,  -348,   279,   235,  -348,  -348,  -348,   281,  -348,
     188,   285,    13,   287,   261,   336,   365,   -17,  -348,   356,
     295,   316,  -348,  -348,   261,   337,  -348,   261,   198,   225,
     350,  -348,  -348,  -348,  -348,  -348,    94,   200,   354,   198,
     351,   334,    99,   268,   268,   268,   127,   235,   235,  -348,
     235,  -348,   235,  -348,   235,  -348,  -348,   278,   319,   285,
    -348,   344,  -348,   156,   261,  -348,   305,  -348,  -348,  -348,
    -348,  -348,  -348,   -22,  -348,   327,  -348,   172,   178,   158,
     158,  -348,   207,   207,   207,   207,   207,   318,   226,   333,
     372,  -348,   294,   388,  -348,   298,   389,   324,   328,   338,
    -348,  -348,   312,   392,   398,   198,   188,   353,  -348,  -348,
    -348,  -348,   355,   235,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,   358,  -348,   360,  -348,  -348,   365,  -348,  -348,  -348,
     111,   394,  -348,   111,   396,  -348,   -17,   -17,  -348,   -11,
     -11,  -348,  -348,   217,   106,   296,   365,   382,   365,   373,
     428,   261,   415,   337,  -348,  -348,  -348,   430,  -348,   417,
    -348,  -348,  -348,   198,   418,   398,   278,   268,   235,  -348,
     -21,  -348,   240,  -348,   419,   367,   419,   369,  -348,  -348,
     370,   371,  -348,   374,   375,   375,   226,  -348,   255,   376,
    -348,   372,  -348,  -348,  -348,   144,   398,   438,   425,   285,
    -348,  -348,   158,   377,   409,   111,   420,  -348,   261,   431,
    -348,   433,  -348,   422,   434,   365,   437,  -348,  -348,   382,
     426,  -348,    28,   436,  -348,  -348,  -348,  -348,   453,   225,
     -17,   421,   158,   419,   391,   419,  -348,  -348,   393,  -348,
     375,  -348,   395,  -348,   397,  -348,  -348,   376,    48,  -348,
     270,  -348,   158,   -17,   440,  -348,  -348,  -348,  -348,  -348,
      48,   436,  -348,   316,   -17,  -348,  -348,  -348,  -348,   333,
    -348,   441,  -348
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
       0,    76,     0,     0,     0,   172,   170,   151,   154,     0,
       0,    93,   110,   191,     0,    52,    65,     0,     0,   149,
       0,    43,    44,    45,    46,    47,    39,     0,     0,     0,
       0,     0,   124,   124,   124,   124,   129,   129,   129,   137,
     129,   139,   129,   112,   129,   116,   141,   143,     0,    76,
      72,   172,   170,     0,     0,   156,     0,   178,   179,   180,
     181,   182,   183,     0,   184,   186,   188,     0,     0,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,    78,
      55,    57,     0,     0,    67,    68,     0,     0,     0,     0,
      40,    38,    35,     0,    48,     0,     0,     0,   125,   127,
     128,   121,     0,   129,   131,   132,   134,   136,   109,   117,
     144,     0,    77,     0,   173,   157,   171,   185,   189,   187,
     145,   163,   161,   145,   164,   162,   151,   151,   155,   176,
     177,   175,   174,   169,    90,     0,     0,    95,     0,     0,
       0,     0,     0,    52,    51,    69,    66,     0,    42,     0,
      41,    36,    34,     0,     0,    48,   143,   124,   129,   138,
       0,   171,     0,   146,   147,     0,   147,     0,   152,   153,
       0,     0,    88,     0,     0,     0,     0,    94,     0,     0,
      70,    55,    54,    53,   190,    39,    48,     0,     0,    76,
     126,   135,     0,     0,     0,   145,     0,   165,   145,     0,
     168,     0,   166,    91,    90,     0,     0,   101,   100,    95,
      98,    97,    80,    85,    56,    37,    49,    31,     0,   149,
     151,     0,     0,   147,     0,   147,   158,   160,     0,    89,
       0,    96,     0,    81,     0,    82,    83,     0,    80,    32,
      87,    73,     0,   151,     0,   167,   148,    92,   102,    99,
      80,    85,    79,    93,   151,    75,   159,    84,    86,    78,
      74,     0,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,   219,   286,   130,  -348,  -348,
    -284,  -167,  -348,   174,   236,   138,   180,  -348,   -58,  -348,
    -348,   306,   237,  -348,  -348,  -348,  -196,    61,  -347,    86,
      74,    87,   122,    76,   121,   152,   357,   -65,  -348,   -93,
     -36,  -135,  -187,  -250,  -300,   -81,  -263,  -217,  -348,   269,
    -110,  -148,  -348,  -348
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   178,   122,   241,   299,   176,
     304,   118,    31,   233,   165,   292,   230,   126,   156,    32,
      33,   119,   169,    34,    74,   199,   200,   290,   386,   363,
     388,   161,   322,   229,   327,   287,    44,    45,    99,   129,
      69,   109,   151,   314,   349,   111,   221,   157,   277,   158,
     159,   217,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   116,   276,   262,   130,   131,    98,    72,   218,    77,
     260,   226,   244,   318,   319,   197,   351,   342,    37,   219,
      38,   338,   125,   316,    64,    46,    65,   267,   148,   152,
      47,    48,   105,   343,    64,   107,    65,    66,   383,   268,
     113,   402,   203,   149,   127,   220,    49,   133,   344,    65,
      65,    50,   366,   407,   224,   128,    42,   384,   383,    43,
      52,   225,    67,    39,   136,   139,   142,   145,   146,   184,
     147,    91,   134,   394,    51,   396,   162,    68,   305,    92,
      93,    94,   201,   385,    96,    70,    75,   135,   236,   248,
     249,   250,   251,    65,   202,   373,   205,    65,   375,   189,
      71,    76,   191,   385,    53,   193,   231,   391,   195,   234,
     238,   306,   279,   280,   281,   282,   283,   127,   312,   339,
     125,    65,    54,   102,   320,   370,   103,    90,   247,   137,
     405,    55,    56,   140,    90,   321,   336,   324,   325,    57,
     328,   410,   239,   369,   138,    65,   265,    58,   141,    90,
     254,   255,   256,   240,   257,   393,   258,   143,   259,   272,
     275,    59,    60,   288,   202,   202,   202,   202,   202,    91,
     286,    61,   144,   264,   152,   404,    91,    92,    93,    94,
      73,   252,    96,    62,    92,    93,    94,    95,   270,    96,
      97,    91,   239,    63,   273,   186,   253,    78,   187,    92,
      93,    94,   182,   240,    96,   183,   153,   380,    40,    79,
      41,    80,   313,    83,   340,   313,    91,   309,   154,   222,
     223,   224,    81,   152,    92,    93,    94,   155,   225,    96,
      91,    82,    84,   231,    85,    86,    91,    87,    92,    93,
      94,   271,    90,    96,    92,    93,    94,   274,    88,    96,
      89,   100,   104,    65,   347,   106,   345,   108,   110,   357,
     358,   288,   112,   115,   114,    91,   124,   117,   286,   121,
     361,    90,   341,    92,    93,    94,   201,    90,    96,   120,
     222,   223,   224,   123,    91,   125,   127,   313,   390,   225,
     313,   132,    92,    93,    94,   285,   150,    96,    91,   171,
     172,   173,   174,   175,   160,   163,    92,    93,    94,   346,
     164,    96,    64,    91,   166,   398,   168,   167,   170,    91,
     179,    92,    93,    94,   360,   323,    96,    92,    93,    94,
     177,   180,    96,   185,   188,   190,   192,   198,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   204,   194,     2,
     196,   228,   227,     3,     4,   232,   237,   216,     5,     6,
       7,     8,     9,    10,    11,   206,   246,   245,    12,    13,
      14,   243,   261,   263,   266,   269,    15,    16,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   284,    17,   289,
     291,   294,   296,   297,   298,   302,   300,   216,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   303,   216,   326,   222,
     223,   224,   307,   315,   308,   317,   216,   310,   225,   311,
     329,   330,   332,   334,   335,   337,   350,   348,   352,   353,
     354,   367,   368,   355,   356,   362,   371,   372,   376,   374,
     377,   378,   320,    64,   387,   382,   389,   406,   412,   392,
     395,   301,   397,   242,   399,   365,   400,   333,   293,   364,
     411,   331,   295,   401,   235,   408,   379,   403,   359,   409,
     381,     0,     0,   181,     0,     0,     0,     0,     0,   278
};

static const yytype_int16 yycheck[] =
{
      65,    82,   219,   199,    97,    98,    64,    43,   156,    45,
     197,   159,   179,   276,   277,   150,   316,    38,     6,    36,
       8,   305,     9,   273,    16,    69,    18,    49,    54,    16,
       7,     8,    68,    54,    16,    71,    18,    29,    10,    61,
      76,   388,   152,    69,    18,    62,     3,    29,    69,    18,
      18,    30,   336,   400,    65,    29,    69,    29,    10,    72,
      69,    72,    54,    51,   100,   101,   102,   103,   104,   127,
     106,    58,    54,   373,    32,   375,   112,    69,   245,    66,
      67,    68,    69,    55,    71,    54,    54,    69,   169,   182,
     183,   184,   185,    18,   152,   345,   154,    18,   348,   135,
      69,    69,   138,    55,     3,   141,   164,   370,   144,   167,
      16,   246,   222,   223,   224,   225,   226,    18,   266,   306,
       9,    18,     3,    69,    18,   342,    72,    16,    29,    54,
     393,     3,     3,    54,    16,    29,   303,   285,   286,     3,
     288,   404,    48,   339,    69,    18,   204,    40,    69,    16,
     186,   187,   188,    59,   190,   372,   192,    54,   194,   217,
     218,    69,    69,   228,   222,   223,   224,   225,   226,    58,
     228,     8,    69,    17,    16,   392,    58,    66,    67,    68,
      32,    54,    71,    69,    66,    67,    68,    69,    16,    71,
      72,    58,    48,    69,    16,    69,    69,     3,    72,    66,
      67,    68,    69,    59,    71,    72,    48,   355,     6,     3,
       8,    32,   270,    37,   307,   273,    58,   253,    60,    63,
      64,    65,    69,    16,    66,    67,    68,    69,    72,    71,
      58,    69,    41,   291,    16,    38,    58,    69,    66,    67,
      68,    69,    16,    71,    66,    67,    68,    69,     3,    71,
       3,    69,    69,    18,   312,    69,    16,    69,    33,   324,
     325,   326,    69,    31,    69,    58,    38,    69,   326,    69,
     328,    16,   308,    66,    67,    68,    69,    16,    71,    71,
      63,    64,    65,    69,    58,     9,    18,   345,   369,    72,
     348,    17,    66,    67,    68,    69,    18,    71,    58,    22,
      23,    24,    25,    26,    34,     3,    66,    67,    68,    69,
      16,    71,    16,    58,     3,   380,    18,    42,    30,    58,
      16,    66,    67,    68,    69,    29,    71,    66,    67,    68,
      18,    69,    71,    69,    69,    69,    69,    52,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    60,    69,     0,
      69,    35,    57,     4,     5,    18,     6,    61,     9,    10,
      11,    12,    13,    14,    15,    29,    32,    16,    19,    20,
      21,    17,    53,    29,    69,    48,    27,    28,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    69,    39,    56,
      18,     3,     3,    69,    66,     3,    58,    61,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    18,    61,    36,    63,
      64,    65,    69,    29,    69,    29,    61,    69,    72,    69,
      57,     3,    17,     3,    17,    17,    69,    18,    69,    69,
      69,     3,    17,    69,    69,    69,    69,    38,    17,    29,
      17,    29,    18,    16,    18,    29,     3,    17,    17,    38,
      69,   242,    69,   177,    69,   335,    69,   293,   232,   331,
     409,   291,   235,   387,   168,   401,   354,   390,   326,   403,
     359,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,   220
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
      18,   126,    16,    48,    60,    69,   102,   131,   133,   134,
      34,   115,   124,     3,    16,    98,     3,    42,    18,   106,
      30,    22,    23,    24,    25,    26,    93,    18,    89,    16,
      69,   120,    69,    72,   102,    69,    69,    72,    69,   124,
      69,   124,    69,   124,    69,   124,    69,   125,    52,   109,
     110,    69,   102,   134,    60,   102,    29,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    61,   135,   135,    36,
      62,   130,    63,    64,    65,    72,   135,    57,    35,   117,
     100,   102,    18,    97,   102,   105,   129,     6,    16,    48,
      59,    91,    90,    17,    95,    16,    32,    29,   123,   123,
     123,   123,    54,    69,   124,   124,   124,   124,   124,   124,
     126,    53,   110,    29,    17,   102,    69,    49,    61,    48,
      16,    69,   102,    16,    69,   102,   131,   132,   133,   134,
     134,   134,   134,   134,    69,    69,   102,   119,   121,    56,
     111,    18,    99,    98,     3,   106,     3,    69,    66,    92,
      58,    89,     3,    18,    94,    95,   125,    69,    69,   124,
      69,    69,   135,   102,   127,    29,   127,    29,   130,   130,
      18,    29,   116,    29,   135,   135,    36,   118,   135,    57,
       3,   100,    17,    97,     3,    17,    95,    17,    94,   126,
     123,   124,    38,    54,    69,    16,    69,   102,    18,   128,
      69,   128,    69,    69,    69,    69,    69,   121,   121,   119,
      69,   102,    69,   113,    99,    91,    94,     3,    17,   110,
     131,    69,    38,   127,    29,   127,    17,    17,    29,   116,
     135,   118,    29,    10,    29,    55,   112,    18,   114,     3,
     129,   130,    38,   131,   128,    69,   128,    69,   121,    69,
      69,   113,   112,   115,   131,   130,    17,   112,   114,   117,
     130,   111,    17
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
     134,   134,   134,   134,   134,   134,   134,   134,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   137
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
       1,     3,     1,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       8,     5
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
#line 1589 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 220 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1597 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 225 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1605 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 231 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1613 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 237 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1621 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 243 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1629 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 249 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1638 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 255 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1646 "yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 261 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1655 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 269 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,0);
			CONTEXT->id_num=0;
		}
#line 1665 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 275 "yacc_sql.y"
            {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,1);
			CONTEXT->id_num=0;
		}
#line 1675 "yacc_sql.tab.c"
    break;

  case 33: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 284 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1684 "yacc_sql.tab.c"
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
#line 1696 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 301 "yacc_sql.y"
                                   {    }
#line 1702 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID type LBRACE number RBRACE nullable  */
#line 306 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, (yyvsp[-5].string), (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1713 "yacc_sql.tab.c"
    break;

  case 38: /* attr_def: ID type nullable  */
#line 313 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,(yyvsp[-2].string), (yyvsp[-1].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1724 "yacc_sql.tab.c"
    break;

  case 39: /* nullable: %empty  */
#line 320 "yacc_sql.y"
               {
	    (yyval.number)=0;
	 }
#line 1732 "yacc_sql.tab.c"
    break;

  case 40: /* nullable: NULLABLE  */
#line 323 "yacc_sql.y"
             {
		(yyval.number)=1;
	 }
#line 1740 "yacc_sql.tab.c"
    break;

  case 41: /* nullable: NOT NULL_T  */
#line 326 "yacc_sql.y"
                   {
		(yyval.number)=0;
	}
#line 1748 "yacc_sql.tab.c"
    break;

  case 42: /* number: NUMBER  */
#line 330 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1754 "yacc_sql.tab.c"
    break;

  case 43: /* type: INT_T  */
#line 333 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1760 "yacc_sql.tab.c"
    break;

  case 44: /* type: STRING_T  */
#line 334 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1766 "yacc_sql.tab.c"
    break;

  case 45: /* type: FLOAT_T  */
#line 335 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1772 "yacc_sql.tab.c"
    break;

  case 46: /* type: DATE_T  */
#line 336 "yacc_sql.y"
                    { (yyval.number)=DATES;}
#line 1778 "yacc_sql.tab.c"
    break;

  case 47: /* type: TEXT_T  */
#line 337 "yacc_sql.y"
                    { (yyval.number)=TEXTS;}
#line 1784 "yacc_sql.tab.c"
    break;

  case 49: /* id_list: COMMA ID_get id_list  */
#line 341 "yacc_sql.y"
                        {
	 
   }
#line 1792 "yacc_sql.tab.c"
    break;

  case 50: /* ID_get: ID  */
#line 346 "yacc_sql.y"
        {
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", (yyvsp[0].string));
		CONTEXT->id_num++;
	}
#line 1802 "yacc_sql.tab.c"
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
#line 1817 "yacc_sql.tab.c"
    break;

  case 53: /* value_def_list: COMMA value_def value_def_list  */
#line 368 "yacc_sql.y"
                                  {
  }
#line 1824 "yacc_sql.tab.c"
    break;

  case 54: /* value_def: LBRACE insert_value value_list RBRACE  */
#line 372 "yacc_sql.y"
                                       {
	CONTEXT->insert_num++;
  }
#line 1832 "yacc_sql.tab.c"
    break;

  case 56: /* value_list: COMMA insert_value value_list  */
#line 377 "yacc_sql.y"
                                     {
	  }
#line 1839 "yacc_sql.tab.c"
    break;

  case 57: /* insert_value: value  */
#line 381 "yacc_sql.y"
        {
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*(yyvsp[0].value1);
   }
#line 1847 "yacc_sql.tab.c"
    break;

  case 58: /* get_select: SELECT  */
#line 386 "yacc_sql.y"
         {
	parser_id++;
	CONTEXT->ssql=query_create();
}
#line 1856 "yacc_sql.tab.c"
    break;

  case 59: /* value: NUMBER  */
#line 391 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1865 "yacc_sql.tab.c"
    break;

  case 60: /* value: FLOAT  */
#line 395 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1874 "yacc_sql.tab.c"
    break;

  case 61: /* value: SSS  */
#line 399 "yacc_sql.y"
         {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1884 "yacc_sql.tab.c"
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
#line 1896 "yacc_sql.tab.c"
    break;

  case 63: /* value: NULL_T  */
#line 411 "yacc_sql.y"
               {
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 1905 "yacc_sql.tab.c"
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
#line 1925 "yacc_sql.tab.c"
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
#line 1937 "yacc_sql.tab.c"
    break;

  case 66: /* update: UPDATE ID SET eq_define eq_define_list where SEMICOLON  */
#line 444 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,(yyvsp[-5].string),CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1948 "yacc_sql.tab.c"
    break;

  case 67: /* eq_define: ID_get EQ value  */
#line 452 "yacc_sql.y"
                  {

}
#line 1956 "yacc_sql.tab.c"
    break;

  case 69: /* eq_define_list: COMMA eq_define eq_define_list  */
#line 456 "yacc_sql.y"
                                  {

   }
#line 1964 "yacc_sql.tab.c"
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
#line 1980 "yacc_sql.tab.c"
    break;

  case 72: /* from: FROM rel_id rel_list join_attr_list  */
#line 475 "yacc_sql.y"
                                              {}
#line 1986 "yacc_sql.tab.c"
    break;

  case 73: /* join_attr: INNER JOIN ID ON and_condition condition_list  */
#line 478 "yacc_sql.y"
                                                     {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string), NULL);
   	}
#line 1994 "yacc_sql.tab.c"
    break;

  case 74: /* join_attr: INNER JOIN ID AS ID ON and_condition condition_list  */
#line 481 "yacc_sql.y"
                                                             {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string), (yyvsp[-3].string));
   	}
#line 2002 "yacc_sql.tab.c"
    break;

  case 75: /* join_attr: INNER JOIN ID ID ON and_condition condition_list  */
#line 484 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string), (yyvsp[-3].string));
   	}
#line 2010 "yacc_sql.tab.c"
    break;

  case 77: /* join_attr_list: join_attr join_attr_list  */
#line 490 "yacc_sql.y"
                              {
   }
#line 2017 "yacc_sql.tab.c"
    break;

  case 79: /* order_by: ORDER BY order_attr order_attr_lists order  */
#line 494 "yacc_sql.y"
                                                 {
		
	}
#line 2025 "yacc_sql.tab.c"
    break;

  case 80: /* order: %empty  */
#line 498 "yacc_sql.y"
             {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
#line 2033 "yacc_sql.tab.c"
    break;

  case 81: /* order: DESC  */
#line 501 "yacc_sql.y"
           {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
#line 2041 "yacc_sql.tab.c"
    break;

  case 82: /* order: ASC  */
#line 504 "yacc_sql.y"
              {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
#line 2049 "yacc_sql.tab.c"
    break;

  case 83: /* order_attr: ID order  */
#line 509 "yacc_sql.y"
             { 
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
#line 2059 "yacc_sql.tab.c"
    break;

  case 84: /* order_attr: ID DOT ID order  */
#line 514 "yacc_sql.y"
                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
#line 2069 "yacc_sql.tab.c"
    break;

  case 88: /* group_by: GROUP BY ID group_by_list  */
#line 524 "yacc_sql.y"
                                    {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2079 "yacc_sql.tab.c"
    break;

  case 89: /* group_by: GROUP BY ID DOT ID group_by_list  */
#line 529 "yacc_sql.y"
                                           {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2089 "yacc_sql.tab.c"
    break;

  case 91: /* group_by_list: COMMA ID  */
#line 537 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2099 "yacc_sql.tab.c"
    break;

  case 92: /* group_by_list: COMMA ID DOT ID  */
#line 542 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2109 "yacc_sql.tab.c"
    break;

  case 94: /* having: HAVING having_condition having_condition_list  */
#line 550 "yacc_sql.y"
                                                        {}
#line 2115 "yacc_sql.tab.c"
    break;

  case 96: /* having_condition_list: AND having_condition having_condition_list  */
#line 553 "yacc_sql.y"
                                                     {}
#line 2121 "yacc_sql.tab.c"
    break;

  case 97: /* having_condition: function comOp value  */
#line 556 "yacc_sql.y"
                         {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2133 "yacc_sql.tab.c"
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
#line 2146 "yacc_sql.tab.c"
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
#line 2159 "yacc_sql.tab.c"
    break;

  case 100: /* having_condition: value comOp function  */
#line 579 "yacc_sql.y"
                               {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2171 "yacc_sql.tab.c"
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
#line 2184 "yacc_sql.tab.c"
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
#line 2197 "yacc_sql.tab.c"
    break;

  case 103: /* select_attr: STAR attr_list  */
#line 605 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2207 "yacc_sql.tab.c"
    break;

  case 104: /* select_attr: ID attr_list  */
#line 610 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2217 "yacc_sql.tab.c"
    break;

  case 105: /* select_attr: ID DOT ID attr_list  */
#line 615 "yacc_sql.y"
                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2227 "yacc_sql.tab.c"
    break;

  case 106: /* select_attr: ID DOT STAR attr_list  */
#line 620 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2237 "yacc_sql.tab.c"
    break;

  case 107: /* select_attr: function attr_list  */
#line 625 "yacc_sql.y"
                         {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2245 "yacc_sql.tab.c"
    break;

  case 108: /* select_attr: ID AS ID attr_list  */
#line 628 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2255 "yacc_sql.tab.c"
    break;

  case 109: /* select_attr: ID DOT ID AS ID attr_list  */
#line 633 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2265 "yacc_sql.tab.c"
    break;

  case 110: /* select_attr: function AS ID attr_list  */
#line 638 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2273 "yacc_sql.tab.c"
    break;

  case 111: /* select_attr: ID ID attr_list  */
#line 641 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2283 "yacc_sql.tab.c"
    break;

  case 112: /* select_attr: ID DOT ID ID attr_list  */
#line 646 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2293 "yacc_sql.tab.c"
    break;

  case 113: /* select_attr: function ID attr_list  */
#line 651 "yacc_sql.y"
                            {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2301 "yacc_sql.tab.c"
    break;

  case 114: /* select_attr: STAR AS ID attr_list  */
#line 654 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2311 "yacc_sql.tab.c"
    break;

  case 115: /* select_attr: STAR ID attr_list  */
#line 659 "yacc_sql.y"
                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2321 "yacc_sql.tab.c"
    break;

  case 116: /* select_attr: ID DOT STAR ID attr_list  */
#line 664 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2331 "yacc_sql.tab.c"
    break;

  case 117: /* select_attr: ID DOT STAR AS ID attr_list  */
#line 669 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2341 "yacc_sql.tab.c"
    break;

  case 118: /* function: ID LBRACE function_attr RBRACE  */
#line 677 "yacc_sql.y"
                                       {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, (yyvsp[-3].string));
		CONTEXT->parameter_length = 0;
		(yyval.function1)=&CONTEXT->functions[CONTEXT->function_length-1];
	}
#line 2352 "yacc_sql.tab.c"
    break;

  case 120: /* function_attr: ID function_attr_list  */
#line 686 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2362 "yacc_sql.tab.c"
    break;

  case 121: /* function_attr: ID DOT ID function_attr_list  */
#line 691 "yacc_sql.y"
                                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2372 "yacc_sql.tab.c"
    break;

  case 122: /* function_attr: STAR function_attr_list  */
#line 696 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2382 "yacc_sql.tab.c"
    break;

  case 123: /* function_attr: value function_attr_list  */
#line 701 "yacc_sql.y"
                                   {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2390 "yacc_sql.tab.c"
    break;

  case 125: /* function_attr_list: COMMA ID function_attr_list  */
#line 706 "yacc_sql.y"
                                      {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2400 "yacc_sql.tab.c"
    break;

  case 126: /* function_attr_list: COMMA ID DOT ID function_attr_list  */
#line 711 "yacc_sql.y"
                                             {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2410 "yacc_sql.tab.c"
    break;

  case 127: /* function_attr_list: COMMA STAR function_attr_list  */
#line 716 "yacc_sql.y"
                                        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2420 "yacc_sql.tab.c"
    break;

  case 128: /* function_attr_list: COMMA value function_attr_list  */
#line 721 "yacc_sql.y"
                                         {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2428 "yacc_sql.tab.c"
    break;

  case 130: /* attr_list: COMMA ID attr_list  */
#line 727 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2438 "yacc_sql.tab.c"
    break;

  case 131: /* attr_list: COMMA ID DOT ID attr_list  */
#line 732 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2448 "yacc_sql.tab.c"
    break;

  case 132: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 737 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2458 "yacc_sql.tab.c"
    break;

  case 133: /* attr_list: COMMA function attr_list  */
#line 742 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2466 "yacc_sql.tab.c"
    break;

  case 134: /* attr_list: COMMA ID AS ID attr_list  */
#line 745 "yacc_sql.y"
                               {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2476 "yacc_sql.tab.c"
    break;

  case 135: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 750 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2486 "yacc_sql.tab.c"
    break;

  case 136: /* attr_list: COMMA function AS ID attr_list  */
#line 755 "yacc_sql.y"
                                     {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2494 "yacc_sql.tab.c"
    break;

  case 137: /* attr_list: COMMA ID ID attr_list  */
#line 758 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2504 "yacc_sql.tab.c"
    break;

  case 138: /* attr_list: COMMA ID DOT ID ID attr_list  */
#line 763 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2514 "yacc_sql.tab.c"
    break;

  case 139: /* attr_list: COMMA function ID attr_list  */
#line 768 "yacc_sql.y"
                                  {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2522 "yacc_sql.tab.c"
    break;

  case 140: /* rel_id: ID  */
#line 774 "yacc_sql.y"
      {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[0].string), NULL);
    }
#line 2530 "yacc_sql.tab.c"
    break;

  case 141: /* rel_id: ID AS ID  */
#line 777 "yacc_sql.y"
               {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string), (yyvsp[0].string));
    }
#line 2538 "yacc_sql.tab.c"
    break;

  case 142: /* rel_id: ID ID  */
#line 780 "yacc_sql.y"
            {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string), (yyvsp[0].string));
    }
#line 2546 "yacc_sql.tab.c"
    break;

  case 144: /* rel_list: COMMA rel_id rel_list  */
#line 787 "yacc_sql.y"
                            {	
		  }
#line 2553 "yacc_sql.tab.c"
    break;

  case 146: /* in_value: value  */
#line 791 "yacc_sql.y"
          {
	CONTEXT->in_value[CONTEXT->in_value_num++] = *(yyvsp[0].value1);
   }
#line 2561 "yacc_sql.tab.c"
    break;

  case 148: /* in_value_list: COMMA in_value in_value_list  */
#line 795 "yacc_sql.y"
                                 {
   }
#line 2568 "yacc_sql.tab.c"
    break;

  case 150: /* where: WHERE and_condition condition_list  */
#line 799 "yacc_sql.y"
                                         {	
			}
#line 2575 "yacc_sql.tab.c"
    break;

  case 152: /* condition_list: AND and_condition condition_list  */
#line 804 "yacc_sql.y"
                                       {

	}
#line 2583 "yacc_sql.tab.c"
    break;

  case 153: /* condition_list: OR or_condition condition_list  */
#line 807 "yacc_sql.y"
                                          {
	}
#line 2590 "yacc_sql.tab.c"
    break;

  case 154: /* and_condition: condition  */
#line 811 "yacc_sql.y"
            {
	CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 0;
}
#line 2598 "yacc_sql.tab.c"
    break;

  case 155: /* or_condition: condition  */
#line 815 "yacc_sql.y"
            {
     CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 1;
}
#line 2606 "yacc_sql.tab.c"
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
#line 2620 "yacc_sql.tab.c"
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
#line 2632 "yacc_sql.tab.c"
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
#line 2646 "yacc_sql.tab.c"
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
#line 2660 "yacc_sql.tab.c"
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
#line 2673 "yacc_sql.tab.c"
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
#line 2689 "yacc_sql.tab.c"
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
#line 2702 "yacc_sql.tab.c"
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
#line 2717 "yacc_sql.tab.c"
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
#line 2732 "yacc_sql.tab.c"
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
#line 2748 "yacc_sql.tab.c"
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
#line 2764 "yacc_sql.tab.c"
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
#line 2779 "yacc_sql.tab.c"
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
#line 2794 "yacc_sql.tab.c"
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
#line 2808 "yacc_sql.tab.c"
    break;

  case 170: /* expression: value  */
#line 960 "yacc_sql.y"
               {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],0,NULL,(yyvsp[0].value1));
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 2817 "yacc_sql.tab.c"
    break;

  case 171: /* expression: ID DOT ID  */
#line 964 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr,(yyvsp[-2].string),(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 2828 "yacc_sql.tab.c"
    break;

  case 172: /* expression: ID  */
#line 970 "yacc_sql.y"
              {
		RelAttr attr;
		relation_attr_init(&attr,NULL,(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 2839 "yacc_sql.tab.c"
    break;

  case 173: /* expression: LBRACE expression RBRACE  */
#line 976 "yacc_sql.y"
                                   {
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 2847 "yacc_sql.tab.c"
    break;

  case 174: /* expression: expression STAR expression  */
#line 979 "yacc_sql.y"
                                     {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,MUL,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2858 "yacc_sql.tab.c"
    break;

  case 175: /* expression: expression DIV_T expression  */
#line 985 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,DIV,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2869 "yacc_sql.tab.c"
    break;

  case 176: /* expression: expression ADD_T expression  */
#line 991 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,ADD,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2880 "yacc_sql.tab.c"
    break;

  case 177: /* expression: expression SUB_T expression  */
#line 997 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,SUB,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2891 "yacc_sql.tab.c"
    break;

  case 178: /* comOp: EQ  */
#line 1005 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2897 "yacc_sql.tab.c"
    break;

  case 179: /* comOp: LT  */
#line 1006 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2903 "yacc_sql.tab.c"
    break;

  case 180: /* comOp: GT  */
#line 1007 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2909 "yacc_sql.tab.c"
    break;

  case 181: /* comOp: LE  */
#line 1008 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2915 "yacc_sql.tab.c"
    break;

  case 182: /* comOp: GE  */
#line 1009 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2921 "yacc_sql.tab.c"
    break;

  case 183: /* comOp: NE  */
#line 1010 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2927 "yacc_sql.tab.c"
    break;

  case 184: /* comOp: LIKE_T  */
#line 1011 "yacc_sql.y"
                 {CONTEXT->comp = LIKE;}
#line 2933 "yacc_sql.tab.c"
    break;

  case 185: /* comOp: NOT LIKE_T  */
#line 1012 "yacc_sql.y"
                     {CONTEXT->comp = NOT_LIKE;}
#line 2939 "yacc_sql.tab.c"
    break;

  case 186: /* comOp: IS_T  */
#line 1013 "yacc_sql.y"
               {CONTEXT->comp = IS;}
#line 2945 "yacc_sql.tab.c"
    break;

  case 187: /* comOp: IS_T NOT  */
#line 1014 "yacc_sql.y"
                  {CONTEXT->comp = IS_NOT;}
#line 2951 "yacc_sql.tab.c"
    break;

  case 188: /* comOp: IN_T  */
#line 1015 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 2957 "yacc_sql.tab.c"
    break;

  case 189: /* comOp: NOT IN_T  */
#line 1016 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 2963 "yacc_sql.tab.c"
    break;

  case 190: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1021 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2972 "yacc_sql.tab.c"
    break;

  case 191: /* show_index: SHOW INDEX FROM ID SEMICOLON  */
#line 1029 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
		}
#line 2981 "yacc_sql.tab.c"
    break;


#line 2985 "yacc_sql.tab.c"

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

#line 1034 "yacc_sql.y"

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
