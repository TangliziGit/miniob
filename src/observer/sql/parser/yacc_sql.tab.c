/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_YACC_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    CREATE = 259,
    DROP = 260,
    TABLE = 261,
    TABLES = 262,
    INDEX = 263,
    SELECT = 264,
    DESC = 265,
    SHOW = 266,
    SYNC = 267,
    INSERT = 268,
    DELETE = 269,
    UPDATE = 270,
    LBRACE = 271,
    RBRACE = 272,
    COMMA = 273,
    TRX_BEGIN = 274,
    TRX_COMMIT = 275,
    TRX_ROLLBACK = 276,
    INT_T = 277,
    STRING_T = 278,
    FLOAT_T = 279,
    DATE_T = 280,
    TEXT_T = 281,
    HELP = 282,
    EXIT = 283,
    DOT = 284,
    INTO = 285,
    VALUES = 286,
    FROM = 287,
    WHERE = 288,
    GROUP = 289,
    HAVING = 290,
    AND = 291,
    SET = 292,
    ON = 293,
    LOAD = 294,
    DATA = 295,
    INFILE = 296,
    EQ = 297,
    LT = 298,
    GT = 299,
    LE = 300,
    GE = 301,
    NE = 302,
    NOT = 303,
    LIKE_T = 304,
    IS_T = 305,
    UNIQUE = 306,
    INNER = 307,
    JOIN = 308,
    AS = 309,
    ASC = 310,
    ORDER = 311,
    BY = 312,
    NULL_T = 313,
    NULLABLE = 314,
    EXISTS_T = 315,
    IN_T = 316,
    OR = 317,
    ADD_T = 318,
    SUB_T = 319,
    DIV_T = 320,
    STAR = 321,
    NUMBER = 322,
    FLOAT = 323,
    DATE = 324,
    ID = 325,
    PATH = 326,
    SSS = 327,
    STRING_V = 328
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 154 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  struct RelAttr *function1;
  struct RelAttr* expr1;
  char *string;
  int number;
  float floats;
  char *position;

#line 291 "yacc_sql.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */



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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   964

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  434

#define YYUNDEFTOK  2
#define YYMAXUTOK   328


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "CREATE", "DROP", "TABLE",
  "TABLES", "INDEX", "SELECT", "DESC", "SHOW", "SYNC", "INSERT", "DELETE",
  "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "TEXT_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "GROUP",
  "HAVING", "AND", "SET", "ON", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT",
  "LE", "GE", "NE", "NOT", "LIKE_T", "IS_T", "UNIQUE", "INNER", "JOIN",
  "AS", "ASC", "ORDER", "BY", "NULL_T", "NULLABLE", "EXISTS_T", "IN_T",
  "OR", "ADD_T", "SUB_T", "DIV_T", "STAR", "NUMBER", "FLOAT", "DATE", "ID",
  "PATH", "SSS", "STRING_V", "$accept", "commands", "command", "exit",
  "help", "sync", "begin", "commit", "rollback", "drop_table",
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
#endif

# ifdef YYPRINT
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
};
# endif

#define YYPACT_NINF (-366)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-180)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -366,   916,  -366,     5,   105,   667,   -37,   166,    33,    21,
      43,    38,   117,   120,   139,   143,   159,   124,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,   101,   108,   172,
     114,   118,   250,  -366,   699,    17,  -366,  -366,  -366,     9,
    -366,  -366,   135,   163,   590,   187,   188,   160,  -366,   123,
     129,   157,  -366,  -366,  -366,  -366,  -366,   161,   184,   168,
     131,   200,   201,  -366,    44,   667,  -366,   609,   686,   712,
     137,   190,  -366,   725,     2,   140,   190,  -366,   144,   180,
     145,   190,  -366,   699,   699,   699,   699,  -366,   629,  -366,
    -366,   146,   195,   180,   175,   155,   176,   179,   191,  -366,
    -366,   181,   199,  -366,   116,   221,   590,   190,  -366,   243,
     239,    11,   239,   241,    27,   229,   190,  -366,   -23,   242,
     652,   234,   190,  -366,   686,   686,   153,   153,   266,   254,
     268,  -366,   231,   256,   246,   130,   260,   263,   210,  -366,
     144,    63,   220,   190,  -366,   222,   190,  -366,  -366,  -366,
     732,  -366,   223,  -366,  -366,  -366,   224,   190,  -366,   225,
     190,  -366,  -366,   227,  -366,   144,   248,   238,   381,   839,
     903,   903,   -12,  -366,   574,   249,   270,  -366,  -366,   381,
     289,  -366,   381,   175,   180,   303,  -366,  -366,  -366,  -366,
    -366,     7,   176,   293,   175,   295,   242,   190,   269,   190,
    -366,   190,  -366,   239,    97,   239,   239,   190,  -366,   190,
    -366,  -366,   242,   262,   248,  -366,   381,  -366,   251,  -366,
    -366,  -366,  -366,  -366,  -366,    57,  -366,   265,  -366,   745,
     758,   273,   652,   652,  -366,   771,   258,   802,   274,   298,
    -366,   254,   323,  -366,   256,   326,   264,   277,   278,  -366,
    -366,   260,   329,   317,   175,   248,  -366,   281,   190,  -366,
    -366,  -366,  -366,   282,  -366,  -366,  -366,  -366,  -366,  -366,
     283,  -366,  -366,   903,  -366,  -366,  -366,   250,   321,   389,
     629,   250,   346,   425,   430,   629,   343,  -366,  -366,   -12,
     -12,  -366,   384,   466,   629,    98,   863,   903,   324,   903,
     308,   363,   381,   350,   289,  -366,  -366,  -366,   365,  -366,
     352,  -366,  -366,  -366,   175,   353,   317,   180,   190,  -366,
     239,    60,   789,   165,   354,   301,   354,   304,  -366,  -366,
     306,   314,   315,  -366,   316,   318,   318,   802,  -366,   808,
     320,  -366,   298,  -366,  -366,  -366,    80,   317,   375,   374,
     234,  -366,  -366,   652,   333,   355,   250,    70,   471,   629,
     381,   377,   507,   379,   512,   548,   370,   387,   903,  -366,
    -366,   324,   378,  -366,    -3,   391,  -366,  -366,  -366,  -366,
     408,   270,   -12,   376,   652,   354,   342,  -366,   354,  -366,
    -366,   345,  -366,   318,  -366,   351,  -366,   356,  -366,  -366,
     320,    -2,  -366,   274,  -366,   652,   -12,   410,   553,  -366,
    -366,  -366,  -366,    -2,   391,  -366,   412,   -12,  -366,  -366,
    -366,  -366,  -366,  -366
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
       0,     0,     0,    63,     0,   130,    59,    60,    62,   184,
      61,   182,    71,   181,   130,     0,     0,     0,    24,     0,
       0,     0,    25,    26,    27,    23,    22,     0,     0,     0,
       0,     0,     0,    58,   184,     0,   181,     0,   191,     0,
       0,   130,   103,   120,     0,     0,   130,   104,     0,   151,
       0,   130,   107,     0,     0,     0,     0,   118,   190,    30,
      29,     0,     0,   151,     0,     0,     0,     0,     0,    28,
      33,     0,     0,   185,   184,   181,   130,   130,   115,     0,
     125,   125,   125,     0,   130,   183,   130,   111,   142,   145,
       0,    87,   130,   113,   188,   189,   187,   186,     0,     0,
       0,    50,     0,    68,     0,     0,    35,     0,     0,   183,
       0,     0,     0,   130,   131,     0,   130,   134,   141,   114,
       0,   123,     0,   121,   124,   119,     0,   130,   106,     0,
     130,   105,   108,     0,   144,     0,    76,     0,     0,   184,
     182,   181,   153,   156,     0,     0,    93,   110,   205,     0,
      52,    65,     0,     0,   151,     0,    43,    44,    45,    46,
      47,    39,     0,     0,     0,     0,   145,   130,   183,   130,
     138,   130,   140,   125,   125,   125,   125,   130,   116,   130,
     112,   143,   145,     0,    76,    72,     0,   158,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   200,   202,     0,
       0,     0,     0,     0,   152,     0,     0,     0,    78,    55,
      57,     0,     0,    67,    68,     0,     0,     0,     0,    40,
      38,    35,     0,    48,     0,    76,   133,     0,   130,   132,
     135,   137,   128,     0,   126,   129,   122,   117,   109,   146,
       0,    77,   159,   183,   199,   203,   201,   147,   184,   182,
     176,   147,   184,   182,   181,   174,     0,   171,   173,   153,
     153,   157,   184,   182,   180,    90,     0,     0,    95,     0,
       0,     0,     0,     0,    52,    51,    69,    66,     0,    42,
       0,    41,    36,    34,     0,     0,    48,   151,   130,   139,
     125,     0,     0,   182,   149,     0,   149,     0,   154,   155,
       0,     0,     0,    88,     0,     0,     0,     0,    94,     0,
       0,    70,    55,    54,    53,   204,    39,    48,     0,     0,
      87,   136,   127,     0,     0,     0,   147,   184,   182,   178,
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
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,   169,   230,    75,  -366,  -366,
    -323,  -202,  -366,   121,   183,    85,   126,  -366,   -82,  -366,
    -366,   259,   189,  -366,  -366,  -366,  -196,    31,  -365,    45,
      30,    96,    90,    66,    81,   125,   393,     1,  -366,  -112,
     -32,  -118,  -145,  -261,  -331,   -99,  -280,  -226,  -366,   228,
      -5,  -166,  -366,  -366
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   203,   146,   260,   320,   201,
     325,   142,    31,   252,   190,   313,   249,    75,    51,    32,
      33,   143,   194,    34,    89,   224,   225,   311,   409,   385,
     411,   186,   343,   248,   348,   308,    52,    76,   123,   161,
      82,   129,   176,   334,   371,   131,   244,   182,   300,   183,
      98,   239,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   122,   263,   359,   140,   373,    53,   406,   406,   163,
     164,    37,  -130,    38,   240,   241,   299,    87,   245,   338,
     339,    92,    97,   257,   242,    83,   407,    79,   281,   160,
     336,   173,   206,    55,   388,    79,    58,    77,    84,    78,
     162,  -130,  -130,  -130,  -130,    79,   425,   174,   180,   118,
     243,    59,   408,   408,   127,   258,    39,   222,   430,   133,
      83,   265,   326,    85,   417,  -130,   259,   419,   124,   327,
      54,    80,   125,   111,   116,    60,    53,   279,   215,    86,
     115,   166,   154,   157,   158,   159,    83,    81,   134,   135,
     136,   137,   168,   171,   172,   255,   227,   167,   363,   396,
     187,   272,   274,   275,   276,   395,   284,   250,    61,   398,
     253,    40,   414,    41,   364,   160,   341,   332,   285,  -130,
      62,   210,   357,    63,   212,   184,   273,   342,   258,   207,
     365,   181,    83,   208,    79,   218,   428,   392,   220,   259,
     345,   346,    64,   349,   282,   151,    65,   433,  -130,  -130,
    -130,  -130,   196,   197,   198,   199,   200,   289,   293,   297,
     180,   180,    66,   303,    67,   307,  -130,    88,   416,    42,
     152,    68,  -130,    56,    57,   266,   269,   270,    69,   271,
      70,    79,  -148,  -148,    71,   277,   153,   278,    72,   427,
      99,   100,   101,   102,   104,  -130,  -130,  -130,  -130,   103,
     106,   108,   105,   109,   110,   333,   107,   117,    79,   333,
     126,    43,   403,   130,   128,   132,   138,    90,   362,  -130,
      46,    47,    48,    74,  -130,    50,   139,   144,   360,   148,
     250,   150,  -130,    91,   290,   295,   329,   184,   184,    79,
     304,   294,   298,   181,   181,   141,   145,    79,   309,   147,
     368,   149,    73,  -130,  -130,  -130,  -130,   160,   165,    73,
     175,  -130,  -130,  -130,  -130,   307,    42,   383,   185,   188,
     189,   191,  -130,   192,   193,   155,   195,  -130,   202,   204,
     205,   180,    77,   169,   333,  -130,    77,    79,   397,   119,
     209,   156,   211,   216,   217,   219,   361,   221,   226,   170,
     223,  -130,  -130,  -130,  -130,   247,   246,   251,    43,   256,
     262,   264,   180,   286,    44,   280,   312,    46,    47,    48,
      74,   283,    50,   267,  -165,  -130,   315,   369,   305,   317,
     310,    43,   323,   180,   318,   324,   321,    83,  -165,   268,
      46,    47,    48,   296,   319,    50,   379,   380,   309,  -166,
     335,   328,   330,   331,  -165,  -165,  -165,  -165,   184,    83,
     347,    77,    83,  -166,   181,   350,   351,   353,   355,   356,
     358,   372,   370,  -165,   374,   337,   375,  -165,   389,  -166,
    -166,  -166,  -166,  -165,   376,   377,   378,  -177,   296,   184,
     384,   390,  -163,   394,   399,   181,   400,   119,  -166,   401,
      83,  -177,  -166,   393,   421,   341,  -163,   405,  -166,   410,
     184,   412,   418,   340,   415,   420,   181,  -177,  -177,  -177,
    -177,   422,  -163,  -163,  -163,  -163,   423,   429,  -164,   432,
     322,   387,   261,  -172,   314,   354,  -177,   386,   352,    43,
    -177,  -163,  -164,   316,   426,  -163,  -177,  -172,    46,    47,
      48,  -163,   254,    50,   431,   424,   391,   413,  -164,  -164,
    -164,  -164,   404,  -172,  -172,  -172,  -172,   402,   112,  -175,
       0,   301,   381,     0,  -167,     0,     0,  -164,     0,     0,
       0,  -164,  -172,  -175,     0,     0,  -172,  -164,  -167,     0,
       0,     0,  -172,     0,     0,     0,     0,     0,     0,  -175,
    -175,  -175,  -175,     0,  -167,  -167,  -167,  -167,     0,     0,
    -170,     0,     0,     0,     0,  -168,     0,     0,  -175,     0,
       0,     0,  -175,  -167,  -170,     0,     0,  -167,  -175,  -168,
       0,     0,     0,  -167,     0,     0,     0,     0,     0,     0,
    -170,  -170,  -170,  -170,     0,  -168,  -168,  -168,  -168,     0,
       0,  -179,     0,     0,     0,     0,  -169,     0,     0,  -170,
       0,     0,     0,  -170,  -168,  -179,     0,     0,  -168,  -170,
    -169,     0,     0,     0,  -168,     0,     0,     0,     0,     0,
       0,  -179,  -179,  -179,  -179,     0,  -169,  -169,  -169,  -169,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -179,     0,     0,     0,  -179,  -169,    42,     0,    79,  -169,
    -179,     0,     0,     0,     0,  -169,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    42,   113,     0,     0,     0,
       0,     0,    43,     0,     0,   238,     0,    93,    94,    95,
      96,    46,    47,    48,    74,    42,    50,     0,    43,     0,
       0,     0,     0,    93,    94,    95,    96,    46,    47,    48,
      74,     0,    50,     0,     0,     0,     0,    43,    42,     0,
       0,     0,    93,    94,    95,    96,    46,    47,    48,    74,
       0,    50,     0,    42,     0,     0,     0,    43,     0,     0,
       0,     0,    93,    94,    95,    96,    46,    47,    48,    74,
     177,    50,    42,     0,     0,     0,     0,     0,     0,     0,
      43,     0,   178,     0,     0,    42,    44,     0,     0,    46,
      47,    48,   179,     0,    50,    43,     0,     0,    42,     0,
       0,    44,     0,    45,    46,    47,    48,    49,     0,    50,
       0,   119,     0,     0,    43,     0,     0,     0,   119,     0,
       0,    95,    96,    46,    47,    48,    74,    43,    50,     0,
       0,   287,     0,    44,     0,     0,    46,    47,    48,    74,
      43,    50,     0,     0,   291,     0,    44,     0,     0,    46,
      47,    48,   114,    43,    50,     0,     0,    42,     0,     0,
      43,   120,    46,    47,    48,   121,     0,    50,   213,    46,
      47,    48,   214,    43,    50,   366,     0,     0,     0,    44,
       0,     0,    46,    47,    48,   288,    43,    50,   119,     0,
       0,     0,    44,     0,   119,    46,    47,    48,   292,    43,
      50,     0,     0,     0,     0,    44,     0,     0,    46,    47,
      48,   302,     0,    50,     0,     0,     0,    43,     0,     0,
       0,     0,     0,    44,     0,    83,    46,    47,    48,   367,
      43,    50,     0,     0,     0,     0,    43,     0,   228,    46,
      47,    48,   306,     0,    50,    46,    47,    48,   382,    83,
      50,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,     0,   344,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,     0,     0,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,     0,     2,     0,     0,     0,
       3,     4,     0,     0,   238,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     0,    12,    13,    14,     0,     0,
       0,     0,     0,    15,    16,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,   238
};

static const yytype_int16 yycheck[] =
{
       5,    83,   204,   326,   103,   336,     5,    10,    10,   121,
     122,     6,     3,     8,   180,   181,   242,    49,   184,   299,
     300,    53,    54,    16,    36,    16,    29,    18,   224,    18,
     291,    54,   150,    70,   357,    18,     3,    42,    29,    44,
      29,    32,    33,    34,    35,    18,   411,    70,   130,    81,
      62,    30,    55,    55,    86,    48,    51,   175,   423,    91,
      16,   206,   264,    54,   395,    56,    59,   398,    66,   265,
      75,    54,    70,    29,    79,    32,    75,   222,   160,    70,
      79,    54,   114,   115,   116,   117,    16,    70,    93,    94,
      95,    96,   124,   125,   126,   194,   178,    70,    38,    29,
     132,   213,   214,   215,   216,   366,    49,   189,    70,   370,
     192,     6,   392,     8,    54,    18,    18,   283,    61,     3,
       3,   153,   324,     3,   156,   130,    29,    29,    48,    66,
      70,   130,    16,    70,    18,   167,   416,   363,   170,    59,
     306,   307,     3,   309,   226,    29,     3,   427,    32,    33,
      34,    35,    22,    23,    24,    25,    26,   239,   240,   241,
     242,   243,     3,   245,    40,   247,     3,    32,   394,    16,
      54,    70,    56,     7,     8,   207,   208,   209,    70,   211,
       8,    18,    17,    18,    70,   217,    70,   219,    70,   415,
       3,     3,    32,    70,    37,    32,    33,    34,    35,    70,
      16,    70,    41,     3,     3,   287,    38,    70,    18,   291,
      70,    58,   378,    33,    70,    70,    70,    54,   330,    56,
      67,    68,    69,    70,     3,    72,    31,    72,   327,    38,
     312,    32,     3,    70,   239,   240,   268,   242,   243,    18,
     245,   240,   241,   242,   243,    70,    70,    18,   247,    70,
     332,    70,     9,    32,    33,    34,    35,    18,    17,     9,
      18,    32,    33,    34,    35,   347,    16,   349,    34,     3,
      16,     3,     3,    42,    18,    54,    30,    56,    18,    16,
      70,   363,   287,    54,   366,    56,   291,    18,   370,    16,
      70,    70,    70,    70,    70,    70,   328,    70,    60,    70,
      52,    32,    33,    34,    35,    35,    57,    18,    58,     6,
      17,    16,   394,    48,    64,    53,    18,    67,    68,    69,
      70,    70,    72,    54,     3,    56,     3,   332,    70,     3,
      56,    58,     3,   415,    70,    18,    58,    16,    17,    70,
      67,    68,    69,    70,    67,    72,   345,   346,   347,     3,
      29,    70,    70,    70,    33,    34,    35,    36,   363,    16,
      36,   366,    16,    17,   363,    57,     3,    17,     3,    17,
      17,    70,    18,    52,    70,    29,    70,    56,     3,    33,
      34,    35,    36,    62,    70,    70,    70,     3,    70,   394,
      70,    17,     3,    38,    17,   394,    17,    16,    52,    29,
      16,    17,    56,    70,   403,    18,    17,    29,    62,    18,
     415,     3,    70,    29,    38,    70,   415,    33,    34,    35,
      36,    70,    33,    34,    35,    36,    70,    17,     3,    17,
     261,   356,   202,     3,   251,   314,    52,   352,   312,    58,
      56,    52,    17,   254,   413,    56,    62,    17,    67,    68,
      69,    62,   193,    72,   424,   410,   360,   391,    33,    34,
      35,    36,   381,    33,    34,    35,    36,   377,    75,     3,
      -1,   243,   347,    -1,     3,    -1,    -1,    52,    -1,    -1,
      -1,    56,    52,    17,    -1,    -1,    56,    62,    17,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    33,    34,    35,    36,    -1,    -1,
       3,    -1,    -1,    -1,    -1,     3,    -1,    -1,    52,    -1,
      -1,    -1,    56,    52,    17,    -1,    -1,    56,    62,    17,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    33,    34,    35,    36,    -1,
      -1,     3,    -1,    -1,    -1,    -1,     3,    -1,    -1,    52,
      -1,    -1,    -1,    56,    52,    17,    -1,    -1,    56,    62,
      17,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    -1,    33,    34,    35,    36,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    56,    52,    16,    -1,    18,    56,
      62,    -1,    -1,    -1,    -1,    62,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    17,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    16,    72,    -1,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    72,    -1,    -1,    -1,    -1,    58,    16,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    72,    -1,    16,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      48,    72,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    60,    -1,    -1,    16,    64,    -1,    -1,    67,
      68,    69,    70,    -1,    72,    58,    -1,    -1,    16,    -1,
      -1,    64,    -1,    66,    67,    68,    69,    70,    -1,    72,
      -1,    16,    -1,    -1,    58,    -1,    -1,    -1,    16,    -1,
      -1,    65,    66,    67,    68,    69,    70,    58,    72,    -1,
      -1,    16,    -1,    64,    -1,    -1,    67,    68,    69,    70,
      58,    72,    -1,    -1,    16,    -1,    64,    -1,    -1,    67,
      68,    69,    70,    58,    72,    -1,    -1,    16,    -1,    -1,
      58,    66,    67,    68,    69,    70,    -1,    72,    66,    67,
      68,    69,    70,    58,    72,    16,    -1,    -1,    -1,    64,
      -1,    -1,    67,    68,    69,    70,    58,    72,    16,    -1,
      -1,    -1,    64,    -1,    16,    67,    68,    69,    70,    58,
      72,    -1,    -1,    -1,    -1,    64,    -1,    -1,    67,    68,
      69,    70,    -1,    72,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    16,    67,    68,    69,    70,
      58,    72,    -1,    -1,    -1,    -1,    58,    -1,    29,    67,
      68,    69,    70,    -1,    72,    67,    68,    69,    70,    16,
      72,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,     0,    -1,    -1,    -1,
       4,     5,    -1,    -1,    61,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    27,    28,    39,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    96,   103,   104,   107,   136,   137,     6,     8,    51,
       6,     8,    16,    58,    64,    66,    67,    68,    69,    70,
      72,   102,   120,   121,   134,    70,     7,     8,     3,    30,
      32,    70,     3,     3,     3,     3,     3,    40,    70,    70,
       8,    70,    70,     9,    70,   101,   121,   134,   134,    18,
      54,    70,   124,    16,    29,    54,    70,   124,    32,   108,
      54,    70,   124,    63,    64,    65,    66,   124,   134,     3,
       3,    32,    70,    70,    37,    41,    16,    38,    70,     3,
       3,    29,   120,    17,    70,   121,   134,    70,   124,    16,
      66,    70,   102,   122,    66,    70,    70,   124,    70,   125,
      33,   129,    70,   124,   134,   134,   134,   134,    70,    31,
     129,    70,    95,   105,    72,    70,    90,    70,    38,    70,
      32,    29,    54,    70,   124,    54,    70,   124,   124,   124,
      18,   123,    29,   123,   123,    17,    54,    70,   124,    54,
      70,   124,   124,    54,    70,    18,   126,    48,    60,    70,
     102,   121,   131,   133,   134,    34,   115,   124,     3,    16,
      98,     3,    42,    18,   106,    30,    22,    23,    24,    25,
      26,    93,    18,    89,    16,    70,   125,    66,    70,    70,
     124,    70,   124,    66,    70,   102,    70,    70,   124,    70,
     124,    70,   125,    52,   109,   110,    60,   102,    29,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    61,   135,
     135,   135,    36,    62,   130,   135,    57,    35,   117,   100,
     102,    18,    97,   102,   105,   129,     6,    16,    48,    59,
      91,    90,    17,    95,    16,   126,   124,    54,    70,   124,
     124,   124,   123,    29,   123,   123,   123,   124,   124,   126,
      53,   110,   102,    70,    49,    61,    48,    16,    70,   102,
     134,    16,    70,   102,   121,   134,    70,   102,   121,   131,
     132,   133,    70,   102,   134,    70,    70,   102,   119,   121,
      56,   111,    18,    99,    98,     3,   106,     3,    70,    67,
      92,    58,    89,     3,    18,    94,    95,   110,    70,   124,
      70,    70,   135,   102,   127,    29,   127,    29,   130,   130,
      29,    18,    29,   116,    29,   135,   135,    36,   118,   135,
      57,     3,   100,    17,    97,     3,    17,    95,    17,    94,
     129,   124,   123,    38,    54,    70,    16,    70,   102,   134,
      18,   128,    70,   128,    70,    70,    70,    70,    70,   121,
     121,   119,    70,   102,    70,   113,    99,    91,    94,     3,
      17,   115,   131,    70,    38,   127,    29,   102,   127,    17,
      17,    29,   116,   135,   118,    29,    10,    29,    55,   112,
      18,   114,     3,   117,   130,    38,   131,   128,    70,   128,
      70,   121,    70,    70,   113,   112,   111,   131,   130,    17,
     112,   114,    17,   130
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, void *scanner)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , scanner);
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 22:
#line 216 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1888 "yacc_sql.tab.c"
    break;

  case 23:
#line 221 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1896 "yacc_sql.tab.c"
    break;

  case 24:
#line 226 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1904 "yacc_sql.tab.c"
    break;

  case 25:
#line 232 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1912 "yacc_sql.tab.c"
    break;

  case 26:
#line 238 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1920 "yacc_sql.tab.c"
    break;

  case 27:
#line 244 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1928 "yacc_sql.tab.c"
    break;

  case 28:
#line 250 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1937 "yacc_sql.tab.c"
    break;

  case 29:
#line 256 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1945 "yacc_sql.tab.c"
    break;

  case 30:
#line 262 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1954 "yacc_sql.tab.c"
    break;

  case 31:
#line 270 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,0);
			CONTEXT->id_num=0;
		}
#line 1964 "yacc_sql.tab.c"
    break;

  case 32:
#line 276 "yacc_sql.y"
            {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,1);
			CONTEXT->id_num=0;
		}
#line 1974 "yacc_sql.tab.c"
    break;

  case 33:
#line 285 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1983 "yacc_sql.tab.c"
    break;

  case 34:
#line 292 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_length = 0;
		}
#line 1995 "yacc_sql.tab.c"
    break;

  case 36:
#line 302 "yacc_sql.y"
                                   {    }
#line 2001 "yacc_sql.tab.c"
    break;

  case 37:
#line 307 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, (yyvsp[-5].string), (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 2012 "yacc_sql.tab.c"
    break;

  case 38:
#line 314 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,(yyvsp[-2].string), (yyvsp[-1].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 2023 "yacc_sql.tab.c"
    break;

  case 39:
#line 321 "yacc_sql.y"
               {
	    (yyval.number)=0;
	 }
#line 2031 "yacc_sql.tab.c"
    break;

  case 40:
#line 324 "yacc_sql.y"
             {
		(yyval.number)=1;
	 }
#line 2039 "yacc_sql.tab.c"
    break;

  case 41:
#line 327 "yacc_sql.y"
                   {
		(yyval.number)=0;
	}
#line 2047 "yacc_sql.tab.c"
    break;

  case 42:
#line 331 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 2053 "yacc_sql.tab.c"
    break;

  case 43:
#line 334 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 2059 "yacc_sql.tab.c"
    break;

  case 44:
#line 335 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 2065 "yacc_sql.tab.c"
    break;

  case 45:
#line 336 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 2071 "yacc_sql.tab.c"
    break;

  case 46:
#line 337 "yacc_sql.y"
                    { (yyval.number)=DATES;}
#line 2077 "yacc_sql.tab.c"
    break;

  case 47:
#line 338 "yacc_sql.y"
                    { (yyval.number)=TEXTS;}
#line 2083 "yacc_sql.tab.c"
    break;

  case 49:
#line 342 "yacc_sql.y"
                        {
	 
   }
#line 2091 "yacc_sql.tab.c"
    break;

  case 50:
#line 347 "yacc_sql.y"
        {
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", (yyvsp[0].string));
		CONTEXT->id_num++;
	}
#line 2101 "yacc_sql.tab.c"
    break;

  case 51:
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
#line 2116 "yacc_sql.tab.c"
    break;

  case 53:
#line 369 "yacc_sql.y"
                                  {
  }
#line 2123 "yacc_sql.tab.c"
    break;

  case 54:
#line 373 "yacc_sql.y"
                                       {
	CONTEXT->insert_num++;
  }
#line 2131 "yacc_sql.tab.c"
    break;

  case 56:
#line 378 "yacc_sql.y"
                                     {
	  }
#line 2138 "yacc_sql.tab.c"
    break;

  case 57:
#line 382 "yacc_sql.y"
        {
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*(yyvsp[0].value1);
   }
#line 2146 "yacc_sql.tab.c"
    break;

  case 58:
#line 387 "yacc_sql.y"
         {
	parser_id++;
	CONTEXT->ssql=query_create();
}
#line 2155 "yacc_sql.tab.c"
    break;

  case 59:
#line 392 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2164 "yacc_sql.tab.c"
    break;

  case 60:
#line 396 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2173 "yacc_sql.tab.c"
    break;

  case 61:
#line 400 "yacc_sql.y"
         {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2183 "yacc_sql.tab.c"
    break;

  case 62:
#line 405 "yacc_sql.y"
             {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		if(value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string))<0){
		  CONTEXT->ssql->date_parse_err = -1;
		}
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 2195 "yacc_sql.tab.c"
    break;

  case 63:
#line 412 "yacc_sql.y"
               {
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 2204 "yacc_sql.tab.c"
    break;

  case 64:
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
#line 2224 "yacc_sql.tab.c"
    break;

  case 65:
#line 435 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2236 "yacc_sql.tab.c"
    break;

  case 66:
#line 445 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,(yyvsp[-5].string),CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2247 "yacc_sql.tab.c"
    break;

  case 67:
#line 453 "yacc_sql.y"
                  {

}
#line 2255 "yacc_sql.tab.c"
    break;

  case 69:
#line 457 "yacc_sql.y"
                                  {

   }
#line 2263 "yacc_sql.tab.c"
    break;

  case 70:
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
#line 2283 "yacc_sql.tab.c"
    break;

  case 72:
#line 480 "yacc_sql.y"
                                              {}
#line 2289 "yacc_sql.tab.c"
    break;

  case 73:
#line 483 "yacc_sql.y"
                                                     {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string), NULL);
   	}
#line 2297 "yacc_sql.tab.c"
    break;

  case 74:
#line 486 "yacc_sql.y"
                                                             {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string), (yyvsp[-3].string));
   	}
#line 2305 "yacc_sql.tab.c"
    break;

  case 75:
#line 489 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string), (yyvsp[-3].string));
   	}
#line 2313 "yacc_sql.tab.c"
    break;

  case 77:
#line 495 "yacc_sql.y"
                              {
   }
#line 2320 "yacc_sql.tab.c"
    break;

  case 79:
#line 499 "yacc_sql.y"
                                                 {
		
	}
#line 2328 "yacc_sql.tab.c"
    break;

  case 80:
#line 503 "yacc_sql.y"
             {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
#line 2336 "yacc_sql.tab.c"
    break;

  case 81:
#line 506 "yacc_sql.y"
           {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
#line 2344 "yacc_sql.tab.c"
    break;

  case 82:
#line 509 "yacc_sql.y"
              {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
#line 2352 "yacc_sql.tab.c"
    break;

  case 83:
#line 514 "yacc_sql.y"
             { 
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
#line 2362 "yacc_sql.tab.c"
    break;

  case 84:
#line 519 "yacc_sql.y"
                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
#line 2372 "yacc_sql.tab.c"
    break;

  case 88:
#line 529 "yacc_sql.y"
                                    {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2382 "yacc_sql.tab.c"
    break;

  case 89:
#line 534 "yacc_sql.y"
                                           {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2392 "yacc_sql.tab.c"
    break;

  case 91:
#line 542 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2402 "yacc_sql.tab.c"
    break;

  case 92:
#line 547 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2412 "yacc_sql.tab.c"
    break;

  case 94:
#line 555 "yacc_sql.y"
                                                        {}
#line 2418 "yacc_sql.tab.c"
    break;

  case 96:
#line 558 "yacc_sql.y"
                                                     {}
#line 2424 "yacc_sql.tab.c"
    break;

  case 97:
#line 561 "yacc_sql.y"
                         {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2436 "yacc_sql.tab.c"
    break;

  case 98:
#line 568 "yacc_sql.y"
                            {
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2449 "yacc_sql.tab.c"
    break;

  case 99:
#line 576 "yacc_sql.y"
                                   {
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2462 "yacc_sql.tab.c"
    break;

  case 100:
#line 584 "yacc_sql.y"
                               {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2474 "yacc_sql.tab.c"
    break;

  case 101:
#line 591 "yacc_sql.y"
                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].function1));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2487 "yacc_sql.tab.c"
    break;

  case 102:
#line 599 "yacc_sql.y"
                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2500 "yacc_sql.tab.c"
    break;

  case 103:
#line 610 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2510 "yacc_sql.tab.c"
    break;

  case 104:
#line 615 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2520 "yacc_sql.tab.c"
    break;

  case 105:
#line 620 "yacc_sql.y"
                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2530 "yacc_sql.tab.c"
    break;

  case 106:
#line 625 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2540 "yacc_sql.tab.c"
    break;

  case 107:
#line 630 "yacc_sql.y"
                         {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2548 "yacc_sql.tab.c"
    break;

  case 108:
#line 633 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2558 "yacc_sql.tab.c"
    break;

  case 109:
#line 638 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2568 "yacc_sql.tab.c"
    break;

  case 110:
#line 643 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2576 "yacc_sql.tab.c"
    break;

  case 111:
#line 646 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2586 "yacc_sql.tab.c"
    break;

  case 112:
#line 651 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2596 "yacc_sql.tab.c"
    break;

  case 113:
#line 656 "yacc_sql.y"
                            {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2604 "yacc_sql.tab.c"
    break;

  case 114:
#line 659 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2614 "yacc_sql.tab.c"
    break;

  case 115:
#line 664 "yacc_sql.y"
                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2624 "yacc_sql.tab.c"
    break;

  case 116:
#line 669 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2634 "yacc_sql.tab.c"
    break;

  case 117:
#line 674 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2644 "yacc_sql.tab.c"
    break;

  case 118:
#line 679 "yacc_sql.y"
                              {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1), NULL);
	}
#line 2652 "yacc_sql.tab.c"
    break;

  case 119:
#line 685 "yacc_sql.y"
                                       {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, (yyvsp[-3].string));
		CONTEXT->parameter_length = 0;
		(yyval.function1)=&CONTEXT->functions[CONTEXT->function_length-1];
	}
#line 2663 "yacc_sql.tab.c"
    break;

  case 121:
#line 694 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2673 "yacc_sql.tab.c"
    break;

  case 122:
#line 699 "yacc_sql.y"
                                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2683 "yacc_sql.tab.c"
    break;

  case 123:
#line 704 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2693 "yacc_sql.tab.c"
    break;

  case 124:
#line 709 "yacc_sql.y"
                                   {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2701 "yacc_sql.tab.c"
    break;

  case 126:
#line 714 "yacc_sql.y"
                                      {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2711 "yacc_sql.tab.c"
    break;

  case 127:
#line 719 "yacc_sql.y"
                                             {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2721 "yacc_sql.tab.c"
    break;

  case 128:
#line 724 "yacc_sql.y"
                                        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2731 "yacc_sql.tab.c"
    break;

  case 129:
#line 729 "yacc_sql.y"
                                         {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2739 "yacc_sql.tab.c"
    break;

  case 131:
#line 735 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2749 "yacc_sql.tab.c"
    break;

  case 132:
#line 740 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2759 "yacc_sql.tab.c"
    break;

  case 133:
#line 745 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2769 "yacc_sql.tab.c"
    break;

  case 134:
#line 750 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2777 "yacc_sql.tab.c"
    break;

  case 135:
#line 753 "yacc_sql.y"
                               {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2787 "yacc_sql.tab.c"
    break;

  case 136:
#line 758 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2797 "yacc_sql.tab.c"
    break;

  case 137:
#line 763 "yacc_sql.y"
                                     {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2805 "yacc_sql.tab.c"
    break;

  case 138:
#line 766 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2815 "yacc_sql.tab.c"
    break;

  case 139:
#line 771 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2825 "yacc_sql.tab.c"
    break;

  case 140:
#line 776 "yacc_sql.y"
                                  {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2833 "yacc_sql.tab.c"
    break;

  case 141:
#line 779 "yacc_sql.y"
                                    {
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1), NULL);
	}
#line 2841 "yacc_sql.tab.c"
    break;

  case 142:
#line 785 "yacc_sql.y"
      {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[0].string), NULL);
    }
#line 2849 "yacc_sql.tab.c"
    break;

  case 143:
#line 788 "yacc_sql.y"
               {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string), (yyvsp[0].string));
    }
#line 2857 "yacc_sql.tab.c"
    break;

  case 144:
#line 791 "yacc_sql.y"
            {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string), (yyvsp[0].string));
    }
#line 2865 "yacc_sql.tab.c"
    break;

  case 146:
#line 798 "yacc_sql.y"
                            {	
		  }
#line 2872 "yacc_sql.tab.c"
    break;

  case 148:
#line 802 "yacc_sql.y"
          {
	CONTEXT->in_value[CONTEXT->in_value_num++] = *(yyvsp[0].value1);
   }
#line 2880 "yacc_sql.tab.c"
    break;

  case 150:
#line 806 "yacc_sql.y"
                                 {
   }
#line 2887 "yacc_sql.tab.c"
    break;

  case 152:
#line 810 "yacc_sql.y"
                                         {	
			}
#line 2894 "yacc_sql.tab.c"
    break;

  case 154:
#line 815 "yacc_sql.y"
                                       {

	}
#line 2902 "yacc_sql.tab.c"
    break;

  case 155:
#line 818 "yacc_sql.y"
                                          {
	}
#line 2909 "yacc_sql.tab.c"
    break;

  case 156:
#line 822 "yacc_sql.y"
            {
	CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 0;
}
#line 2917 "yacc_sql.tab.c"
    break;

  case 157:
#line 826 "yacc_sql.y"
            {
     CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 1;
}
#line 2925 "yacc_sql.tab.c"
    break;

  case 158:
#line 830 "yacc_sql.y"
                      {
		CONTEXT->comp = EXISTS;

		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2939 "yacc_sql.tab.c"
    break;

  case 159:
#line 839 "yacc_sql.y"
                            {
		CONTEXT->comp = NOT_EXISTS;
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2951 "yacc_sql.tab.c"
    break;

  case 160:
#line 846 "yacc_sql.y"
                                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2965 "yacc_sql.tab.c"
    break;

  case 161:
#line 855 "yacc_sql.y"
                                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr,(yyvsp[-7].string), (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2979 "yacc_sql.tab.c"
    break;

  case 162:
#line 864 "yacc_sql.y"
                                                           {
		Value *left_value = (yyvsp[-5].value1);

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 0, NULL, left_value,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2992 "yacc_sql.tab.c"
    break;

  case 163:
#line 872 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;

	}
#line 3008 "yacc_sql.tab.c"
    break;

  case 164:
#line 884 "yacc_sql.y"
        {
		Value *left_value = (yyvsp[-2].value1);
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3021 "yacc_sql.tab.c"
    break;

  case 165:
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
#line 3036 "yacc_sql.tab.c"
    break;

  case 166:
#line 903 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-2].value1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
		}
#line 3051 "yacc_sql.tab.c"
    break;

  case 167:
#line 914 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = (yyvsp[0].value1);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
							
    }
#line 3067 "yacc_sql.tab.c"
    break;

  case 168:
#line 926 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-4].value1);

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 3083 "yacc_sql.tab.c"
    break;

  case 169:
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
#line 3098 "yacc_sql.tab.c"
    break;

  case 170:
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
#line 3113 "yacc_sql.tab.c"
    break;

  case 171:
#line 959 "yacc_sql.y"
                           {
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3125 "yacc_sql.tab.c"
    break;

  case 172:
#line 966 "yacc_sql.y"
                           {
	Value *left_value = (yyvsp[-2].value1);

	Condition condition;
	condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
	CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3137 "yacc_sql.tab.c"
    break;

  case 173:
#line 973 "yacc_sql.y"
                              {
	Condition condition;
	condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, (yyvsp[0].function1), NULL);
	CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3147 "yacc_sql.tab.c"
    break;

  case 174:
#line 978 "yacc_sql.y"
                                {
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, (yyvsp[-2].value1), 1, (yyvsp[0].expr1), NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3157 "yacc_sql.tab.c"
    break;

  case 175:
#line 983 "yacc_sql.y"
                                {
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1,(yyvsp[-2].expr1), NULL, 0,NULL,(yyvsp[0].value1));
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3167 "yacc_sql.tab.c"
    break;

  case 176:
#line 988 "yacc_sql.y"
                             {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].expr1), NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3180 "yacc_sql.tab.c"
    break;

  case 177:
#line 996 "yacc_sql.y"
                              {
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].expr1), NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3193 "yacc_sql.tab.c"
    break;

  case 178:
#line 1004 "yacc_sql.y"
                                    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].expr1), NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3206 "yacc_sql.tab.c"
    break;

  case 179:
#line 1012 "yacc_sql.y"
                                    {
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].expr1), NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3219 "yacc_sql.tab.c"
    break;

  case 180:
#line 1020 "yacc_sql.y"
                                     {
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].expr1), NULL, 1,(yyvsp[0].expr1), NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3229 "yacc_sql.tab.c"
    break;

  case 181:
#line 1028 "yacc_sql.y"
              {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,(yyvsp[0].function1),NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3238 "yacc_sql.tab.c"
    break;

  case 182:
#line 1032 "yacc_sql.y"
                {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],0,NULL,(yyvsp[0].value1));
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3247 "yacc_sql.tab.c"
    break;

  case 183:
#line 1036 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr,(yyvsp[-2].string),(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3258 "yacc_sql.tab.c"
    break;

  case 184:
#line 1042 "yacc_sql.y"
              {
		RelAttr attr;
		relation_attr_init(&attr,NULL,(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3269 "yacc_sql.tab.c"
    break;

  case 185:
#line 1048 "yacc_sql.y"
                                   {
		append_brace((yyvsp[-1].expr1));
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 3278 "yacc_sql.tab.c"
    break;

  case 186:
#line 1052 "yacc_sql.y"
                                     {
		append_expression((yyvsp[-2].expr1),MUL,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3287 "yacc_sql.tab.c"
    break;

  case 187:
#line 1056 "yacc_sql.y"
                                      {
		append_expression((yyvsp[-2].expr1),DIV,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3296 "yacc_sql.tab.c"
    break;

  case 188:
#line 1060 "yacc_sql.y"
                                      {
		append_expression((yyvsp[-2].expr1),ADD,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3305 "yacc_sql.tab.c"
    break;

  case 189:
#line 1064 "yacc_sql.y"
                                      {
		append_expression((yyvsp[-2].expr1),SUB,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3314 "yacc_sql.tab.c"
    break;

  case 190:
#line 1068 "yacc_sql.y"
                                {
		// 减数字,当作加负数
		append_expression((yyvsp[-1].expr1),ADD,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 3324 "yacc_sql.tab.c"
    break;

  case 191:
#line 1073 "yacc_sql.y"
                           {
		append_neg((yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[0].expr1);
	 }
#line 3333 "yacc_sql.tab.c"
    break;

  case 192:
#line 1082 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3339 "yacc_sql.tab.c"
    break;

  case 193:
#line 1083 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3345 "yacc_sql.tab.c"
    break;

  case 194:
#line 1084 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3351 "yacc_sql.tab.c"
    break;

  case 195:
#line 1085 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3357 "yacc_sql.tab.c"
    break;

  case 196:
#line 1086 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3363 "yacc_sql.tab.c"
    break;

  case 197:
#line 1087 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3369 "yacc_sql.tab.c"
    break;

  case 198:
#line 1088 "yacc_sql.y"
                 {CONTEXT->comp = LIKE;}
#line 3375 "yacc_sql.tab.c"
    break;

  case 199:
#line 1089 "yacc_sql.y"
                     {CONTEXT->comp = NOT_LIKE;}
#line 3381 "yacc_sql.tab.c"
    break;

  case 200:
#line 1090 "yacc_sql.y"
               {CONTEXT->comp = IS;}
#line 3387 "yacc_sql.tab.c"
    break;

  case 201:
#line 1091 "yacc_sql.y"
                  {CONTEXT->comp = IS_NOT;}
#line 3393 "yacc_sql.tab.c"
    break;

  case 202:
#line 1092 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 3399 "yacc_sql.tab.c"
    break;

  case 203:
#line 1093 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 3405 "yacc_sql.tab.c"
    break;

  case 204:
#line 1098 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3414 "yacc_sql.tab.c"
    break;

  case 205:
#line 1106 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
		}
#line 3423 "yacc_sql.tab.c"
    break;


#line 3427 "yacc_sql.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
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
