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
      context->id_num=0;
	  parser_id--;
  }
  parser_id=0;
  printf("parse sql failed. error=%s", str);
}



#line 149 "yacc_sql.tab.c"

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
  YYSYMBOL_NUMBER = 63,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 64,                     /* FLOAT  */
  YYSYMBOL_DATE = 65,                      /* DATE  */
  YYSYMBOL_ID = 66,                        /* ID  */
  YYSYMBOL_PATH = 67,                      /* PATH  */
  YYSYMBOL_SSS = 68,                       /* SSS  */
  YYSYMBOL_STAR = 69,                      /* STAR  */
  YYSYMBOL_STRING_V = 70,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_commands = 72,                  /* commands  */
  YYSYMBOL_command = 73,                   /* command  */
  YYSYMBOL_exit = 74,                      /* exit  */
  YYSYMBOL_help = 75,                      /* help  */
  YYSYMBOL_sync = 76,                      /* sync  */
  YYSYMBOL_begin = 77,                     /* begin  */
  YYSYMBOL_commit = 78,                    /* commit  */
  YYSYMBOL_rollback = 79,                  /* rollback  */
  YYSYMBOL_drop_table = 80,                /* drop_table  */
  YYSYMBOL_show_tables = 81,               /* show_tables  */
  YYSYMBOL_desc_table = 82,                /* desc_table  */
  YYSYMBOL_create_index = 83,              /* create_index  */
  YYSYMBOL_drop_index = 84,                /* drop_index  */
  YYSYMBOL_create_table = 85,              /* create_table  */
  YYSYMBOL_attr_def_list = 86,             /* attr_def_list  */
  YYSYMBOL_attr_def = 87,                  /* attr_def  */
  YYSYMBOL_nullable = 88,                  /* nullable  */
  YYSYMBOL_number = 89,                    /* number  */
  YYSYMBOL_type = 90,                      /* type  */
  YYSYMBOL_id_list = 91,                   /* id_list  */
  YYSYMBOL_ID_get = 92,                    /* ID_get  */
  YYSYMBOL_insert = 93,                    /* insert  */
  YYSYMBOL_value_def_list = 94,            /* value_def_list  */
  YYSYMBOL_value_def = 95,                 /* value_def  */
  YYSYMBOL_value_list = 96,                /* value_list  */
  YYSYMBOL_insert_value = 97,              /* insert_value  */
  YYSYMBOL_get_select = 98,                /* get_select  */
  YYSYMBOL_value = 99,                     /* value  */
  YYSYMBOL_delete = 100,                   /* delete  */
  YYSYMBOL_update = 101,                   /* update  */
  YYSYMBOL_eq_define = 102,                /* eq_define  */
  YYSYMBOL_eq_define_list = 103,           /* eq_define_list  */
  YYSYMBOL_select = 104,                   /* select  */
  YYSYMBOL_join_attr = 105,                /* join_attr  */
  YYSYMBOL_join_attr_list = 106,           /* join_attr_list  */
  YYSYMBOL_order_by = 107,                 /* order_by  */
  YYSYMBOL_order = 108,                    /* order  */
  YYSYMBOL_order_attr = 109,               /* order_attr  */
  YYSYMBOL_order_attr_lists = 110,         /* order_attr_lists  */
  YYSYMBOL_group_by = 111,                 /* group_by  */
  YYSYMBOL_group_by_list = 112,            /* group_by_list  */
  YYSYMBOL_having = 113,                   /* having  */
  YYSYMBOL_having_condition_list = 114,    /* having_condition_list  */
  YYSYMBOL_having_condition = 115,         /* having_condition  */
  YYSYMBOL_select_attr = 116,              /* select_attr  */
  YYSYMBOL_function = 117,                 /* function  */
  YYSYMBOL_function_attr = 118,            /* function_attr  */
  YYSYMBOL_function_attr_list = 119,       /* function_attr_list  */
  YYSYMBOL_attr_list = 120,                /* attr_list  */
  YYSYMBOL_rel_id = 121,                   /* rel_id  */
  YYSYMBOL_rel_list = 122,                 /* rel_list  */
  YYSYMBOL_in_value = 123,                 /* in_value  */
  YYSYMBOL_in_value_list = 124,            /* in_value_list  */
  YYSYMBOL_where = 125,                    /* where  */
  YYSYMBOL_condition_list = 126,           /* condition_list  */
  YYSYMBOL_and_condition = 127,            /* and_condition  */
  YYSYMBOL_or_condition = 128,             /* or_condition  */
  YYSYMBOL_condition = 129,                /* condition  */
  YYSYMBOL_comOp = 130,                    /* comOp  */
  YYSYMBOL_load_data = 131,                /* load_data  */
  YYSYMBOL_show_index = 132                /* show_index  */
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
#define YYLAST   387

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   175,   175,   177,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   202,   207,   212,   218,   224,   230,   236,   242,
     248,   255,   260,   268,   275,   284,   286,   290,   297,   305,
     308,   311,   315,   318,   319,   320,   321,   322,   324,   326,
     330,   340,   351,   353,   357,   360,   362,   366,   371,   376,
     380,   384,   389,   396,   400,   418,   428,   437,   440,   441,
     446,   459,   462,   467,   468,   471,   472,   476,   479,   482,
     487,   492,   498,   499,   501,   502,   507,   514,   515,   520,
     527,   528,   530,   531,   534,   541,   549,   557,   564,   572,
     583,   588,   593,   598,   603,   606,   611,   616,   622,   630,
     631,   636,   641,   646,   651,   652,   657,   662,   667,   672,
     674,   679,   684,   689,   695,   698,   702,   704,   707,   708,
     711,   712,   714,   716,   719,   721,   724,   728,   732,   736,
     745,   752,   761,   770,   778,   789,   798,   808,   819,   831,
     843,   857,   858,   859,   860,   861,   862,   863,   864,   865,
     866,   867,   868,   872,   880
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
  "IN_T", "OR", "NUMBER", "FLOAT", "DATE", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "drop_index", "create_table", "attr_def_list",
  "attr_def", "nullable", "number", "type", "id_list", "ID_get", "insert",
  "value_def_list", "value_def", "value_list", "insert_value",
  "get_select", "value", "delete", "update", "eq_define", "eq_define_list",
  "select", "join_attr", "join_attr_list", "order_by", "order",
  "order_attr", "order_attr_lists", "group_by", "group_by_list", "having",
  "having_condition_list", "having_condition", "select_attr", "function",
  "function_attr", "function_attr_list", "attr_list", "rel_id", "rel_list",
  "in_value", "in_value_list", "where", "condition_list", "and_condition",
  "or_condition", "condition", "comOp", "load_data", "show_index", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-239)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -239,   255,  -239,    10,    33,   -37,   -33,   143,    70,    63,
      90,    58,   127,   154,   158,   159,   160,    88,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,  -239,   100,   102,   162,
     107,   112,     5,   164,   148,    20,   181,   182,   155,  -239,
     129,   130,   161,  -239,  -239,  -239,  -239,  -239,   167,   187,
     168,   144,   194,   208,    41,   147,    48,   150,  -239,  -239,
     151,   152,  -239,  -239,  -239,   166,   195,   192,   173,   172,
     175,   176,   205,  -239,  -239,   218,  -239,  -239,  -239,  -239,
       7,  -239,   231,   231,   234,    82,   164,    38,   164,   164,
     202,   240,   164,   258,   246,   111,   260,  -239,   235,   261,
     243,   212,   263,   264,   227,  -239,   -37,    71,   229,  -239,
    -239,  -239,  -239,    54,  -239,  -239,   230,  -239,  -239,  -239,
     232,   151,   226,  -239,  -239,   189,   279,   239,   189,   242,
     262,    -9,  -239,  -239,   189,   173,   192,   294,  -239,  -239,
    -239,  -239,  -239,    99,   175,   284,   173,   286,   281,    84,
     231,   231,   231,   164,   164,   164,  -239,   240,   265,   226,
     192,   296,  -239,   246,   312,   189,  -239,   250,  -239,  -239,
    -239,  -239,  -239,  -239,   -30,  -239,   269,  -239,    80,   125,
     111,   111,  -239,  -239,   261,   316,   254,   259,   266,  -239,
    -239,   263,   318,   307,   173,   151,   267,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,   268,  -239,   292,   189,   310,
     279,  -239,  -239,   262,  -239,  -239,  -239,    26,  -239,  -239,
      26,   299,  -239,    -9,    -9,  -239,  -239,  -239,   326,  -239,
     313,  -239,  -239,  -239,   173,   314,   307,   240,   231,   -26,
     275,   300,   296,  -239,  -239,   136,  -239,   319,   319,   270,
    -239,  -239,  -239,    60,   307,   335,   322,   226,  -239,   111,
     274,   276,   156,   285,  -239,    26,   315,  -239,   189,   328,
     329,  -239,  -239,  -239,  -239,   340,   192,    -9,   309,   131,
       1,   262,   317,   262,   291,   346,   319,   288,   319,  -239,
    -239,  -239,   292,  -239,   111,   289,   290,  -239,   293,   295,
     295,   156,  -239,   165,   297,  -239,   333,  -239,  -239,   300,
      -9,   323,   339,   262,   342,  -239,  -239,   317,   331,  -239,
      42,   344,  -239,   285,  -239,   298,  -239,   295,  -239,   301,
    -239,   302,  -239,  -239,   297,    14,   334,  -239,  -239,  -239,
      14,   344,  -239,  -239,  -239,  -239
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
       0,     0,   119,   119,     0,   119,     0,     0,     0,    24,
       0,     0,     0,    25,    26,    27,    23,    22,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,   101,   100,
       0,     0,   104,    30,    29,     0,     0,   132,     0,     0,
       0,     0,     0,    28,    33,     0,    63,    59,    60,    62,
     114,    61,   114,   114,     0,   119,   119,   119,   119,   119,
     124,   126,   119,     0,     0,     0,     0,    50,     0,    68,
       0,     0,    35,     0,     0,    58,     0,     0,     0,   110,
     112,   113,   108,     0,   120,   123,     0,   102,   103,   105,
       0,     0,    73,   107,   164,     0,    52,     0,     0,     0,
       0,   134,   137,    65,     0,     0,   132,     0,    43,    44,
      45,    46,    47,    39,     0,     0,     0,     0,     0,   114,
     114,   114,   114,   119,   119,   119,   125,   126,     0,    73,
     132,    55,    57,     0,     0,     0,   139,     0,   151,   152,
     153,   154,   155,   156,     0,   157,   159,   161,     0,     0,
       0,     0,   133,    67,    68,     0,     0,     0,     0,    40,
      38,    35,     0,    48,     0,     0,     0,   115,   117,   118,
     111,   121,   122,   106,   127,     0,    74,    84,     0,     0,
      52,    51,   140,     0,   158,   162,   160,   128,   146,   144,
     128,   147,   145,   134,   134,   138,    69,    66,     0,    42,
       0,    41,    36,    34,     0,     0,    48,   126,   114,     0,
       0,    90,    55,    54,    53,     0,   129,   130,   130,     0,
     135,   136,   163,    39,    48,     0,     0,    73,   116,     0,
       0,     0,     0,    75,    56,   128,     0,   148,   128,     0,
       0,   149,    37,    49,    31,     0,   132,   134,     0,    87,
       0,     0,    92,     0,     0,     0,   130,     0,   130,   141,
     143,    32,    84,    71,     0,     0,     0,    85,     0,     0,
       0,     0,    91,     0,     0,    70,     0,   150,   131,    90,
     134,    88,    87,     0,     0,    98,    97,    92,    95,    94,
      77,    82,   142,    75,    72,     0,    86,     0,    93,     0,
      78,     0,    79,    80,     0,    77,     0,    89,    99,    96,
      77,    82,    76,    64,    81,    83
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,   169,   211,   103,  -239,  -239,
    -224,  -149,  -239,   149,   198,   120,   157,  -239,   -63,  -239,
    -239,   228,   180,  -239,  -239,  -164,    43,  -229,    34,    28,
      75,    59,    61,    55,    72,   271,   -65,  -239,   -83,   -32,
    -125,  -159,  -193,  -238,  -144,  -219,  -186,  -239,   193,  -137,
    -239,  -239
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   155,   112,   200,   240,   153,
     245,   108,    31,   174,   136,   219,   171,   116,   140,    32,
      33,   109,   146,    34,   169,   170,   295,   343,   331,   345,
     251,   307,   273,   312,   292,    44,    45,    94,   119,    68,
     101,   132,   257,   279,   106,   192,   141,   234,   142,   188,
      35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,    93,   195,   189,   233,   216,   167,   203,   214,   120,
     121,    69,   269,    72,   260,   261,    37,    64,    38,   224,
     280,    64,   266,    65,   340,   117,   217,   190,   270,    42,
     308,   225,    43,    46,    66,   115,   118,   258,    65,    40,
     283,    41,    85,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   340,   191,   161,   246,    65,    85,   316,    67,
     318,    39,   187,   124,   125,   127,   128,   129,   303,   342,
     133,   341,   172,    49,    71,   176,   207,   208,   209,   210,
     247,   193,   296,   287,    86,   298,   255,    85,   267,    87,
      88,    89,   126,    50,    91,   264,   227,   342,    64,    86,
      65,   334,   117,   286,    87,    88,    89,    90,   198,    91,
      92,   123,   222,   206,    97,   197,   352,    98,   320,   199,
     163,   354,    51,   164,    52,   229,   232,    85,    58,    86,
      53,   211,   212,   213,    87,    88,    89,   159,    86,    91,
     160,   230,   302,    87,    88,    89,   228,   198,    91,   305,
      47,    48,   275,   309,   310,   172,   313,    54,   199,   137,
     306,    55,    56,    57,   256,   268,    59,   256,    60,    86,
      61,   138,    85,    62,    87,    88,    89,   139,    63,    91,
      70,    85,    65,    86,    73,    74,   337,    75,    87,    88,
      89,   231,   277,    91,    86,    76,    77,    83,    78,    87,
      88,    89,   276,    80,    91,    85,    81,   293,    79,   291,
      82,    84,   256,    95,    86,   256,    99,   100,   102,    87,
      88,    89,   290,    86,    91,   105,   104,   115,    87,    88,
      89,   328,   103,    91,   148,   149,   150,   151,   152,   107,
     110,   111,   113,   114,   325,   326,   293,    86,   291,   117,
     329,   122,    87,    88,    89,     2,   130,    91,   131,     3,
       4,   134,   135,   143,     5,     6,     7,     8,     9,    10,
      11,   177,   348,   147,    12,    13,    14,   144,   168,   145,
     156,   154,    15,    16,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   157,    17,   162,   165,   173,   166,   175,
     196,   202,   204,   187,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   205,   218,   221,   223,   226,   215,   237,
     238,   243,   239,   187,   241,   244,   250,   253,   259,   262,
     263,   265,   271,   248,   249,   272,   281,   278,   284,   285,
     288,   294,   289,   301,   297,   299,   300,   304,   314,   315,
     332,   353,   335,   311,   317,   321,   322,   305,    64,   323,
     339,   324,   344,   330,   347,   201,   282,   349,   350,   254,
     242,   220,   274,   194,   236,   252,   346,   319,   351,   355,
     333,   336,   338,   327,   235,     0,     0,   158
};

static const yytype_int16 yycheck[] =
{
      65,    64,   146,   140,   190,   169,   131,   156,   167,    92,
      93,    43,    38,    45,   233,   234,     6,    16,     8,    49,
     258,    16,   246,    18,    10,    18,   170,    36,    54,    66,
      29,    61,    69,    66,    29,     9,    29,   230,    18,     6,
     264,     8,    16,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    10,    62,   117,   204,    18,    16,   296,    54,
     298,    51,    61,    95,    96,    97,    98,    99,   287,    55,
     102,    29,   135,     3,    54,   138,   159,   160,   161,   162,
     205,   144,   275,   269,    58,   278,   223,    16,   247,    63,
      64,    65,    54,    30,    68,   244,    16,    55,    16,    58,
      18,   320,    18,   267,    63,    64,    65,    66,    48,    68,
      69,    29,   175,    29,    66,    16,   345,    69,   304,    59,
      66,   350,    32,    69,    66,   188,   189,    16,    40,    58,
       3,   163,   164,   165,    63,    64,    65,    66,    58,    68,
      69,    16,   286,    63,    64,    65,    66,    48,    68,    18,
       7,     8,    16,   290,   291,   218,   293,     3,    59,    48,
      29,     3,     3,     3,   227,   248,    66,   230,    66,    58,
       8,    60,    16,    66,    63,    64,    65,    66,    66,    68,
      32,    16,    18,    58,     3,     3,   323,    32,    63,    64,
      65,    66,   255,    68,    58,    66,    66,     3,    37,    63,
      64,    65,    66,    16,    68,    16,    38,   272,    41,   272,
      66,     3,   275,    66,    58,   278,    66,    66,    66,    63,
      64,    65,    66,    58,    68,    33,    31,     9,    63,    64,
      65,    66,    66,    68,    22,    23,    24,    25,    26,    66,
      68,    66,    66,    38,   309,   310,   311,    58,   311,    18,
     313,    17,    63,    64,    65,     0,    54,    68,    18,     4,
       5,     3,    16,     3,     9,    10,    11,    12,    13,    14,
      15,    29,   337,    30,    19,    20,    21,    42,    52,    18,
      16,    18,    27,    28,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    66,    39,    66,    66,    18,    66,    60,
       6,    17,    16,    61,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    32,    18,     3,    66,    48,    53,     3,
      66,     3,    63,    61,    58,    18,    34,    17,    29,     3,
      17,    17,    57,    66,    66,    35,    66,    18,     3,    17,
      66,    56,    66,     3,    29,    17,    17,    38,    57,     3,
      17,    17,    29,    36,    66,    66,    66,    18,    16,    66,
      29,    66,    18,    66,    66,   154,   263,    66,    66,   220,
     201,   173,   252,   145,   194,   218,   333,   302,   344,   351,
     319,   322,   327,   311,   191,    -1,    -1,   116
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    27,    28,    39,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    93,   100,   101,   104,   131,   132,     6,     8,    51,
       6,     8,    66,    69,   116,   117,    66,     7,     8,     3,
      30,    32,    66,     3,     3,     3,     3,     3,    40,    66,
      66,     8,    66,    66,    16,    18,    29,    54,   120,   120,
      32,    54,   120,     3,     3,    32,    66,    66,    37,    41,
      16,    38,    66,     3,     3,    16,    58,    63,    64,    65,
      66,    68,    69,    99,   118,    66,   117,    66,    69,    66,
      66,   121,    66,    66,    31,    33,   125,    66,    92,   102,
      68,    66,    87,    66,    38,     9,    98,    18,    29,   119,
     119,   119,    17,    29,   120,   120,    54,   120,   120,   120,
      54,    18,   122,   120,     3,    16,    95,    48,    60,    66,
      99,   127,   129,     3,    42,    18,   103,    30,    22,    23,
      24,    25,    26,    90,    18,    86,    16,    66,   116,    66,
      69,    99,    66,    66,    69,    66,    66,   121,    52,   105,
     106,    97,    99,    18,    94,    60,    99,    29,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    61,   130,   130,
      36,    62,   126,    99,   102,   125,     6,    16,    48,    59,
      88,    87,    17,    92,    16,    32,    29,   119,   119,   119,
     119,   120,   120,   120,   122,    53,   106,   125,    18,    96,
      95,     3,    99,    66,    49,    61,    48,    16,    66,    99,
      16,    66,    99,   127,   128,   129,   103,     3,    66,    63,
      89,    58,    86,     3,    18,    91,    92,   121,    66,    66,
      34,   111,    97,    17,    94,   130,    99,   123,   123,    29,
     126,   126,     3,    17,    92,    17,    91,   122,   119,    38,
      54,    57,    35,   113,    96,    16,    66,    99,    18,   124,
     124,    66,    88,    91,     3,    17,   106,   127,    66,    66,
      66,    99,   115,   117,    56,   107,   123,    29,   123,    17,
      17,     3,   125,   126,    38,    18,    29,   112,    29,   130,
     130,    36,   114,   130,    57,     3,   124,    66,   124,   111,
     127,    66,    66,    66,    66,   117,   117,   115,    66,    99,
      66,   109,    17,   113,   126,    29,   112,   130,   114,    29,
      10,    29,    55,   108,    18,   110,   107,    66,   117,    66,
      66,   109,   108,    17,   108,   110
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    83,    84,    85,    86,    86,    87,    87,    88,
      88,    88,    89,    90,    90,    90,    90,    90,    91,    91,
      92,    93,    94,    94,    95,    96,    96,    97,    98,    99,
      99,    99,    99,    99,    99,   100,   101,   102,   103,   103,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   112,   112,   112,
     113,   113,   114,   114,   115,   115,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   120,
     120,   120,   120,   120,   121,   121,   122,   122,   123,   123,
     124,   124,   125,   125,   126,   126,   126,   127,   128,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   131,   132
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
      11,     6,     8,     0,     2,     0,     5,     0,     1,     1,
       2,     4,     0,     3,     0,     4,     6,     0,     2,     4,
       0,     3,     0,     3,     3,     3,     5,     3,     3,     5,
       2,     2,     4,     4,     2,     4,     6,     4,     4,     0,
       2,     4,     2,     2,     0,     3,     5,     3,     3,     0,
       3,     5,     5,     3,     1,     3,     0,     3,     0,     1,
       0,     3,     0,     3,     0,     3,     3,     1,     1,     2,
       3,     6,     8,     6,     3,     3,     3,     3,     5,     5,
       7,     1,     1,     1,     1,     1,     1,     1,     2,     1,
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
#line 202 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1531 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 207 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1539 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 212 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1547 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 218 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1555 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 224 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1563 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 230 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1571 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 236 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1580 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 242 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1588 "yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 248 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1597 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 256 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,0);
		}
#line 1606 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON  */
#line 261 "yacc_sql.y"
            {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,1);
		}
#line 1615 "yacc_sql.tab.c"
    break;

  case 33: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 269 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1624 "yacc_sql.tab.c"
    break;

  case 34: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 276 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_length = 0;
		}
#line 1636 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 286 "yacc_sql.y"
                                   {    }
#line 1642 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID type LBRACE number RBRACE nullable  */
#line 291 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, (yyvsp[-5].string), (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1653 "yacc_sql.tab.c"
    break;

  case 38: /* attr_def: ID type nullable  */
#line 298 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,(yyvsp[-2].string), (yyvsp[-1].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1664 "yacc_sql.tab.c"
    break;

  case 39: /* nullable: %empty  */
#line 305 "yacc_sql.y"
               {
	    (yyval.number)=0;
	 }
#line 1672 "yacc_sql.tab.c"
    break;

  case 40: /* nullable: NULLABLE  */
#line 308 "yacc_sql.y"
             {
		(yyval.number)=1;
	 }
#line 1680 "yacc_sql.tab.c"
    break;

  case 41: /* nullable: NOT NULL_T  */
#line 311 "yacc_sql.y"
                   {
		(yyval.number)=0;
	}
#line 1688 "yacc_sql.tab.c"
    break;

  case 42: /* number: NUMBER  */
#line 315 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1694 "yacc_sql.tab.c"
    break;

  case 43: /* type: INT_T  */
#line 318 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1700 "yacc_sql.tab.c"
    break;

  case 44: /* type: STRING_T  */
#line 319 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1706 "yacc_sql.tab.c"
    break;

  case 45: /* type: FLOAT_T  */
#line 320 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1712 "yacc_sql.tab.c"
    break;

  case 46: /* type: DATE_T  */
#line 321 "yacc_sql.y"
                    { (yyval.number)=DATES;}
#line 1718 "yacc_sql.tab.c"
    break;

  case 47: /* type: TEXT_T  */
#line 322 "yacc_sql.y"
                    { (yyval.number)=TEXTS;}
#line 1724 "yacc_sql.tab.c"
    break;

  case 49: /* id_list: COMMA ID_get id_list  */
#line 326 "yacc_sql.y"
                        {
	 
   }
#line 1732 "yacc_sql.tab.c"
    break;

  case 50: /* ID_get: ID  */
#line 331 "yacc_sql.y"
        {
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", (yyvsp[0].string));
		CONTEXT->id_num++;
	}
#line 1742 "yacc_sql.tab.c"
    break;

  case 51: /* insert: INSERT INTO ID VALUES value_def value_def_list SEMICOLON  */
#line 341 "yacc_sql.y"
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
#line 1757 "yacc_sql.tab.c"
    break;

  case 53: /* value_def_list: COMMA value_def value_def_list  */
#line 353 "yacc_sql.y"
                                  {
  }
#line 1764 "yacc_sql.tab.c"
    break;

  case 54: /* value_def: LBRACE insert_value value_list RBRACE  */
#line 357 "yacc_sql.y"
                                       {
	CONTEXT->insert_num++;
  }
#line 1772 "yacc_sql.tab.c"
    break;

  case 56: /* value_list: COMMA insert_value value_list  */
#line 362 "yacc_sql.y"
                                     {
	  }
#line 1779 "yacc_sql.tab.c"
    break;

  case 57: /* insert_value: value  */
#line 366 "yacc_sql.y"
        {
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*(yyvsp[0].value1);
   }
#line 1787 "yacc_sql.tab.c"
    break;

  case 58: /* get_select: SELECT  */
#line 371 "yacc_sql.y"
         {
	parser_id++;
	CONTEXT->ssql=query_create();
}
#line 1796 "yacc_sql.tab.c"
    break;

  case 59: /* value: NUMBER  */
#line 376 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1805 "yacc_sql.tab.c"
    break;

  case 60: /* value: FLOAT  */
#line 380 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1814 "yacc_sql.tab.c"
    break;

  case 61: /* value: SSS  */
#line 384 "yacc_sql.y"
         {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 1824 "yacc_sql.tab.c"
    break;

  case 62: /* value: DATE  */
#line 389 "yacc_sql.y"
             {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		if(value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string))<0){
		  CONTEXT->ssql->date_parse_err = -1;
		}
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 1836 "yacc_sql.tab.c"
    break;

  case 63: /* value: NULL_T  */
#line 396 "yacc_sql.y"
               {
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 1845 "yacc_sql.tab.c"
    break;

  case 64: /* value: LBRACE get_select select_attr FROM rel_id rel_list join_attr_list where group_by having order_by RBRACE  */
#line 400 "yacc_sql.y"
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
#line 1865 "yacc_sql.tab.c"
    break;

  case 65: /* delete: DELETE FROM ID where SEMICOLON  */
#line 419 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1877 "yacc_sql.tab.c"
    break;

  case 66: /* update: UPDATE ID SET eq_define eq_define_list where SEMICOLON  */
#line 429 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,(yyvsp[-5].string),CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1888 "yacc_sql.tab.c"
    break;

  case 67: /* eq_define: ID_get EQ value  */
#line 437 "yacc_sql.y"
                  {

}
#line 1896 "yacc_sql.tab.c"
    break;

  case 69: /* eq_define_list: COMMA eq_define eq_define_list  */
#line 441 "yacc_sql.y"
                                  {

   }
#line 1904 "yacc_sql.tab.c"
    break;

  case 70: /* select: SELECT select_attr FROM rel_id rel_list join_attr_list where group_by having order_by SEMICOLON  */
#line 446 "yacc_sql.y"
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
#line 1920 "yacc_sql.tab.c"
    break;

  case 71: /* join_attr: INNER JOIN ID ON and_condition condition_list  */
#line 459 "yacc_sql.y"
                                                     {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string), NULL);
   	}
#line 1928 "yacc_sql.tab.c"
    break;

  case 72: /* join_attr: INNER JOIN ID AS ID ON and_condition condition_list  */
#line 462 "yacc_sql.y"
                                                             {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string), (yyvsp[-3].string));
   	}
#line 1936 "yacc_sql.tab.c"
    break;

  case 74: /* join_attr_list: join_attr join_attr_list  */
#line 468 "yacc_sql.y"
                              {
   }
#line 1943 "yacc_sql.tab.c"
    break;

  case 76: /* order_by: ORDER BY order_attr order_attr_lists order  */
#line 472 "yacc_sql.y"
                                                 {
		
	}
#line 1951 "yacc_sql.tab.c"
    break;

  case 77: /* order: %empty  */
#line 476 "yacc_sql.y"
             {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
#line 1959 "yacc_sql.tab.c"
    break;

  case 78: /* order: DESC  */
#line 479 "yacc_sql.y"
           {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
#line 1967 "yacc_sql.tab.c"
    break;

  case 79: /* order: ASC  */
#line 482 "yacc_sql.y"
              {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
#line 1975 "yacc_sql.tab.c"
    break;

  case 80: /* order_attr: ID order  */
#line 487 "yacc_sql.y"
             { 
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
#line 1985 "yacc_sql.tab.c"
    break;

  case 81: /* order_attr: ID DOT ID order  */
#line 492 "yacc_sql.y"
                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
#line 1995 "yacc_sql.tab.c"
    break;

  case 85: /* group_by: GROUP BY ID group_by_list  */
#line 502 "yacc_sql.y"
                                    {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2005 "yacc_sql.tab.c"
    break;

  case 86: /* group_by: GROUP BY ID DOT ID group_by_list  */
#line 507 "yacc_sql.y"
                                           {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2015 "yacc_sql.tab.c"
    break;

  case 88: /* group_by_list: COMMA ID  */
#line 515 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2025 "yacc_sql.tab.c"
    break;

  case 89: /* group_by_list: COMMA ID DOT ID  */
#line 520 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2035 "yacc_sql.tab.c"
    break;

  case 91: /* having: HAVING having_condition having_condition_list  */
#line 528 "yacc_sql.y"
                                                        {}
#line 2041 "yacc_sql.tab.c"
    break;

  case 93: /* having_condition_list: AND having_condition having_condition_list  */
#line 531 "yacc_sql.y"
                                                     {}
#line 2047 "yacc_sql.tab.c"
    break;

  case 94: /* having_condition: function comOp value  */
#line 534 "yacc_sql.y"
                         {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2059 "yacc_sql.tab.c"
    break;

  case 95: /* having_condition: function comOp ID  */
#line 541 "yacc_sql.y"
                            {
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2072 "yacc_sql.tab.c"
    break;

  case 96: /* having_condition: function comOp ID DOT ID  */
#line 549 "yacc_sql.y"
                                   {
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2085 "yacc_sql.tab.c"
    break;

  case 97: /* having_condition: value comOp function  */
#line 557 "yacc_sql.y"
                               {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2097 "yacc_sql.tab.c"
    break;

  case 98: /* having_condition: ID comOp function  */
#line 564 "yacc_sql.y"
                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].function1));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2110 "yacc_sql.tab.c"
    break;

  case 99: /* having_condition: ID DOT ID comOp function  */
#line 572 "yacc_sql.y"
                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2123 "yacc_sql.tab.c"
    break;

  case 100: /* select_attr: STAR attr_list  */
#line 583 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2133 "yacc_sql.tab.c"
    break;

  case 101: /* select_attr: ID attr_list  */
#line 588 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2143 "yacc_sql.tab.c"
    break;

  case 102: /* select_attr: ID DOT ID attr_list  */
#line 593 "yacc_sql.y"
                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2153 "yacc_sql.tab.c"
    break;

  case 103: /* select_attr: ID DOT STAR attr_list  */
#line 598 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2163 "yacc_sql.tab.c"
    break;

  case 104: /* select_attr: function attr_list  */
#line 603 "yacc_sql.y"
                         {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2171 "yacc_sql.tab.c"
    break;

  case 105: /* select_attr: ID AS ID attr_list  */
#line 606 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2181 "yacc_sql.tab.c"
    break;

  case 106: /* select_attr: ID DOT ID AS ID attr_list  */
#line 611 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2191 "yacc_sql.tab.c"
    break;

  case 107: /* select_attr: function AS ID attr_list  */
#line 616 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2199 "yacc_sql.tab.c"
    break;

  case 108: /* function: ID LBRACE function_attr RBRACE  */
#line 622 "yacc_sql.y"
                                       {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, (yyvsp[-3].string));
		CONTEXT->parameter_length = 0;
		(yyval.function1)=&CONTEXT->functions[CONTEXT->function_length-1];
	}
#line 2210 "yacc_sql.tab.c"
    break;

  case 110: /* function_attr: ID function_attr_list  */
#line 631 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2220 "yacc_sql.tab.c"
    break;

  case 111: /* function_attr: ID DOT ID function_attr_list  */
#line 636 "yacc_sql.y"
                                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2230 "yacc_sql.tab.c"
    break;

  case 112: /* function_attr: STAR function_attr_list  */
#line 641 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2240 "yacc_sql.tab.c"
    break;

  case 113: /* function_attr: value function_attr_list  */
#line 646 "yacc_sql.y"
                                   {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}
#line 2249 "yacc_sql.tab.c"
    break;

  case 115: /* function_attr_list: COMMA ID function_attr_list  */
#line 652 "yacc_sql.y"
                                      {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2259 "yacc_sql.tab.c"
    break;

  case 116: /* function_attr_list: COMMA ID DOT ID function_attr_list  */
#line 657 "yacc_sql.y"
                                             {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2269 "yacc_sql.tab.c"
    break;

  case 117: /* function_attr_list: COMMA STAR function_attr_list  */
#line 662 "yacc_sql.y"
                                        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2279 "yacc_sql.tab.c"
    break;

  case 118: /* function_attr_list: COMMA value function_attr_list  */
#line 667 "yacc_sql.y"
                                         {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}
#line 2288 "yacc_sql.tab.c"
    break;

  case 120: /* attr_list: COMMA ID attr_list  */
#line 674 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
      }
#line 2298 "yacc_sql.tab.c"
    break;

  case 121: /* attr_list: COMMA ID DOT ID attr_list  */
#line 679 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
  	  }
#line 2308 "yacc_sql.tab.c"
    break;

  case 122: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 684 "yacc_sql.y"
                                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
	}
#line 2318 "yacc_sql.tab.c"
    break;

  case 123: /* attr_list: COMMA function attr_list  */
#line 689 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2326 "yacc_sql.tab.c"
    break;

  case 124: /* rel_id: ID  */
#line 695 "yacc_sql.y"
      {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[0].string), NULL);
    }
#line 2334 "yacc_sql.tab.c"
    break;

  case 125: /* rel_id: ID AS ID  */
#line 698 "yacc_sql.y"
              {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string), (yyvsp[0].string));
    }
#line 2342 "yacc_sql.tab.c"
    break;

  case 127: /* rel_list: COMMA rel_id rel_list  */
#line 704 "yacc_sql.y"
                            {	
		  }
#line 2349 "yacc_sql.tab.c"
    break;

  case 129: /* in_value: value  */
#line 708 "yacc_sql.y"
          {
	CONTEXT->in_value[CONTEXT->in_value_num++] = *(yyvsp[0].value1);
   }
#line 2357 "yacc_sql.tab.c"
    break;

  case 131: /* in_value_list: COMMA in_value in_value_list  */
#line 712 "yacc_sql.y"
                                 {
   }
#line 2364 "yacc_sql.tab.c"
    break;

  case 133: /* where: WHERE and_condition condition_list  */
#line 716 "yacc_sql.y"
                                         {	
			}
#line 2371 "yacc_sql.tab.c"
    break;

  case 135: /* condition_list: AND and_condition condition_list  */
#line 721 "yacc_sql.y"
                                       {

	}
#line 2379 "yacc_sql.tab.c"
    break;

  case 136: /* condition_list: OR or_condition condition_list  */
#line 724 "yacc_sql.y"
                                          {
	}
#line 2386 "yacc_sql.tab.c"
    break;

  case 137: /* and_condition: condition  */
#line 728 "yacc_sql.y"
            {
	CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 0;
}
#line 2394 "yacc_sql.tab.c"
    break;

  case 138: /* or_condition: condition  */
#line 732 "yacc_sql.y"
            {
     CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 1;
}
#line 2402 "yacc_sql.tab.c"
    break;

  case 139: /* condition: EXISTS_T value  */
#line 736 "yacc_sql.y"
                      {
		CONTEXT->comp = EXISTS;

		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2416 "yacc_sql.tab.c"
    break;

  case 140: /* condition: NOT EXISTS_T value  */
#line 745 "yacc_sql.y"
                            {
		CONTEXT->comp = NOT_EXISTS;
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2428 "yacc_sql.tab.c"
    break;

  case 141: /* condition: ID comOp LBRACE in_value in_value_list RBRACE  */
#line 752 "yacc_sql.y"
                                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2442 "yacc_sql.tab.c"
    break;

  case 142: /* condition: ID DOT ID comOp LBRACE in_value in_value_list RBRACE  */
#line 761 "yacc_sql.y"
                                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr,(yyvsp[-7].string), (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2456 "yacc_sql.tab.c"
    break;

  case 143: /* condition: value comOp LBRACE in_value in_value_list RBRACE  */
#line 770 "yacc_sql.y"
                                                           {
		Value *left_value = (yyvsp[-5].value1);

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 0, NULL, left_value,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2469 "yacc_sql.tab.c"
    break;

  case 144: /* condition: ID comOp value  */
#line 778 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;

	}
#line 2485 "yacc_sql.tab.c"
    break;

  case 145: /* condition: value comOp value  */
#line 790 "yacc_sql.y"
        {
		Value *left_value = (yyvsp[-2].value1);
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2498 "yacc_sql.tab.c"
    break;

  case 146: /* condition: ID comOp ID  */
#line 798 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2513 "yacc_sql.tab.c"
    break;

  case 147: /* condition: value comOp ID  */
#line 809 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-2].value1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
		}
#line 2528 "yacc_sql.tab.c"
    break;

  case 148: /* condition: ID DOT ID comOp value  */
#line 820 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = (yyvsp[0].value1);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
							
    }
#line 2544 "yacc_sql.tab.c"
    break;

  case 149: /* condition: value comOp ID DOT ID  */
#line 832 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-4].value1);

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2560 "yacc_sql.tab.c"
    break;

  case 150: /* condition: ID DOT ID comOp ID DOT ID  */
#line 844 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2575 "yacc_sql.tab.c"
    break;

  case 151: /* comOp: EQ  */
#line 857 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2581 "yacc_sql.tab.c"
    break;

  case 152: /* comOp: LT  */
#line 858 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2587 "yacc_sql.tab.c"
    break;

  case 153: /* comOp: GT  */
#line 859 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2593 "yacc_sql.tab.c"
    break;

  case 154: /* comOp: LE  */
#line 860 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2599 "yacc_sql.tab.c"
    break;

  case 155: /* comOp: GE  */
#line 861 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2605 "yacc_sql.tab.c"
    break;

  case 156: /* comOp: NE  */
#line 862 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2611 "yacc_sql.tab.c"
    break;

  case 157: /* comOp: LIKE_T  */
#line 863 "yacc_sql.y"
                 {CONTEXT->comp = LIKE;}
#line 2617 "yacc_sql.tab.c"
    break;

  case 158: /* comOp: NOT LIKE_T  */
#line 864 "yacc_sql.y"
                     {CONTEXT->comp = NOT_LIKE;}
#line 2623 "yacc_sql.tab.c"
    break;

  case 159: /* comOp: IS_T  */
#line 865 "yacc_sql.y"
               {CONTEXT->comp = IS;}
#line 2629 "yacc_sql.tab.c"
    break;

  case 160: /* comOp: IS_T NOT  */
#line 866 "yacc_sql.y"
                  {CONTEXT->comp = IS_NOT;}
#line 2635 "yacc_sql.tab.c"
    break;

  case 161: /* comOp: IN_T  */
#line 867 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 2641 "yacc_sql.tab.c"
    break;

  case 162: /* comOp: NOT IN_T  */
#line 868 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 2647 "yacc_sql.tab.c"
    break;

  case 163: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 873 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2656 "yacc_sql.tab.c"
    break;

  case 164: /* show_index: SHOW INDEX FROM ID SEMICOLON  */
#line 881 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
		}
#line 2665 "yacc_sql.tab.c"
    break;


#line 2669 "yacc_sql.tab.c"

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

#line 886 "yacc_sql.y"

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
