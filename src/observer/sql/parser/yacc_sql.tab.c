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
  RelAttr expr[MAX_NUM];
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



#line 152 "yacc_sql.tab.c"

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
#line 153 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  struct RelAttr *function1;
  struct RelAttr* expr1;
  char *string;
  int number;
  float floats;
  char *position;

#line 290 "yacc_sql.tab.c"

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
#define YYLAST   859

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  430

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
       0,   188,   188,   190,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   215,   220,   225,   231,   237,   243,   249,   255,
     261,   268,   274,   283,   290,   299,   301,   305,   312,   320,
     323,   326,   330,   333,   334,   335,   336,   337,   339,   341,
     345,   355,   366,   368,   372,   375,   377,   381,   386,   391,
     395,   399,   404,   411,   415,   433,   443,   452,   455,   456,
     461,   476,   477,   480,   483,   486,   491,   492,   495,   496,
     500,   503,   506,   511,   516,   522,   523,   525,   526,   531,
     538,   539,   544,   551,   552,   554,   555,   558,   565,   573,
     581,   588,   596,   607,   612,   617,   622,   627,   630,   635,
     640,   643,   648,   653,   656,   661,   666,   671,   676,   682,
     690,   691,   696,   701,   706,   710,   711,   716,   721,   726,
     730,   732,   737,   742,   747,   750,   755,   760,   763,   768,
     773,   776,   782,   785,   788,   793,   795,   798,   799,   802,
     803,   805,   807,   810,   812,   815,   819,   823,   827,   836,
     843,   852,   861,   869,   880,   889,   899,   910,   922,   934,
     945,   956,   963,   970,   975,   980,   988,   996,  1004,  1008,
    1012,  1018,  1024,  1028,  1032,  1036,  1040,  1044,  1049,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1073,  1081
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

#define YYPACT_NINF (-314)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-173)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -314,   811,  -314,    21,    36,   202,   -27,    28,    55,    30,
      32,    37,    84,   123,   125,   141,   143,   114,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,    95,    96,   163,
     102,   103,    -1,  -314,   153,     7,  -314,  -314,  -314,   124,
    -314,  -314,   142,   149,   132,   183,   185,   157,  -314,   121,
     122,   156,  -314,  -314,  -314,  -314,  -314,   166,   193,   172,
     144,   210,   212,  -314,    16,   202,  -314,   484,   579,   598,
     158,   208,  -314,   605,    75,   159,   208,  -314,   160,   200,
     176,   208,  -314,   153,   153,   153,   153,  -314,   541,  -314,
    -314,   179,   219,   200,   182,   187,   203,   206,   240,  -314,
    -314,   209,   225,  -314,   229,   221,   132,   208,  -314,   271,
     272,    87,   272,   275,    60,   284,   208,  -314,   -30,   277,
     564,   255,   208,  -314,   579,   579,   667,   667,   290,   280,
     295,  -314,   258,   283,   278,   281,   291,   297,   244,  -314,
     160,    85,   245,   208,  -314,   250,   208,  -314,  -314,  -314,
     622,  -314,   251,  -314,  -314,  -314,   252,   208,  -314,   253,
     208,  -314,  -314,   254,  -314,   160,   279,   270,   402,   735,
     798,   798,    -6,  -314,   524,   276,   299,  -314,  -314,   402,
     292,  -314,   402,   182,   200,   329,  -314,  -314,  -314,  -314,
    -314,    70,   203,   319,   182,   321,   277,   208,   294,   208,
    -314,   208,  -314,   272,    88,   272,   272,   208,  -314,   208,
    -314,  -314,   277,   288,   279,  -314,   402,  -314,   286,  -314,
    -314,  -314,  -314,  -314,  -314,     4,  -314,   301,  -314,   637,
     644,   680,   564,   564,  -314,   153,   287,   687,   303,   324,
    -314,   280,   344,  -314,   283,   348,   293,   300,   304,  -314,
    -314,   291,   363,   350,   182,   279,  -314,   305,   208,  -314,
    -314,  -314,  -314,   310,  -314,  -314,  -314,  -314,  -314,  -314,
     311,  -314,  -314,   798,  -314,  -314,  -314,    -1,   336,   343,
     541,    -1,   380,   387,   421,   541,   357,  -314,  -314,    -6,
      -6,  -314,   541,    93,   758,   798,   338,   798,   325,   381,
     402,   369,   292,  -314,  -314,  -314,   384,  -314,   372,  -314,
    -314,  -314,   182,   376,   350,   200,   208,  -314,   272,   -20,
     660,   116,   383,   332,   383,   333,  -314,  -314,   337,   340,
    -314,   341,   347,   347,   687,  -314,   703,   349,  -314,   324,
    -314,  -314,  -314,    64,   350,   391,   408,   255,  -314,  -314,
     564,   356,   370,    -1,    17,   428,   541,   402,   410,   462,
     411,   469,   400,   412,   798,  -314,  -314,   338,   404,  -314,
      -3,   416,  -314,  -314,  -314,  -314,   432,   299,    -6,   399,
     564,   383,   371,  -314,   383,  -314,  -314,   374,  -314,   347,
    -314,   377,  -314,   378,  -314,  -314,   349,    18,  -314,   303,
    -314,   564,    -6,   423,   503,  -314,  -314,  -314,  -314,    18,
     416,  -314,   429,    -6,  -314,  -314,  -314,  -314,  -314,  -314
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
       0,     0,     0,    63,     0,   130,    59,    60,    62,   181,
      61,   179,    71,   178,   130,     0,     0,     0,    24,     0,
       0,     0,    25,    26,    27,    23,    22,     0,     0,     0,
       0,     0,     0,    58,   181,     0,   178,     0,   188,     0,
       0,   130,   103,   120,     0,     0,   130,   104,     0,   151,
       0,   130,   107,     0,     0,     0,     0,   118,   187,    30,
      29,     0,     0,   151,     0,     0,     0,     0,     0,    28,
      33,     0,     0,   182,   181,   178,   130,   130,   115,     0,
     125,   125,   125,     0,   130,   180,   130,   111,   142,   145,
       0,    87,   130,   113,   185,   186,   184,   183,     0,     0,
       0,    50,     0,    68,     0,     0,    35,     0,     0,   180,
       0,     0,     0,   130,   131,     0,   130,   134,   141,   114,
       0,   123,     0,   121,   124,   119,     0,   130,   106,     0,
     130,   105,   108,     0,   144,     0,    76,     0,     0,   181,
     179,   178,   153,   156,     0,     0,    93,   110,   202,     0,
      52,    65,     0,     0,   151,     0,    43,    44,    45,    46,
      47,    39,     0,     0,     0,     0,   145,   130,   180,   130,
     138,   130,   140,   125,   125,   125,   125,   130,   116,   130,
     112,   143,   145,     0,    76,    72,     0,   158,     0,   189,
     190,   191,   192,   193,   194,     0,   195,   197,   199,     0,
       0,     0,     0,     0,   152,     0,     0,     0,    78,    55,
      57,     0,     0,    67,    68,     0,     0,     0,     0,    40,
      38,    35,     0,    48,     0,    76,   133,     0,   130,   132,
     135,   137,   128,     0,   126,   129,   122,   117,   109,   146,
       0,    77,   159,   180,   196,   200,   198,   147,   181,   179,
     175,   147,   181,   179,   178,   174,     0,   171,   173,   153,
     153,   157,   177,    90,     0,     0,    95,     0,     0,     0,
       0,     0,    52,    51,    69,    66,     0,    42,     0,    41,
      36,    34,     0,     0,    48,   151,   130,   139,   125,     0,
       0,   179,   149,     0,   149,     0,   154,   155,     0,     0,
      88,     0,     0,     0,     0,    94,     0,     0,    70,    55,
      54,    53,   201,    39,    48,     0,     0,    87,   136,   127,
       0,     0,     0,   147,   181,   179,   176,   147,     0,   180,
       0,   180,    91,    90,     0,   101,   100,    95,    98,    97,
      80,    85,    56,    37,    49,    31,     0,    93,   153,     0,
       0,   149,     0,   148,   149,   160,   162,     0,    89,     0,
      96,     0,    81,     0,    82,    83,     0,    80,    32,    78,
      73,     0,   153,     0,   180,   150,    92,   102,    99,    80,
      85,    79,     0,   153,    75,   161,    84,    86,    64,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   189,   249,    99,  -314,  -314,
    -313,  -202,  -314,   146,   215,   104,   165,  -314,   -79,  -314,
    -314,   266,   213,  -314,  -314,  -314,  -210,    59,  -310,    72,
      56,   128,   108,   100,   105,   145,   413,     1,  -314,  -112,
     -32,  -127,  -175,  -288,  -296,   -98,  -280,  -241,  -314,   248,
      -5,  -168,  -314,  -314
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   203,   146,   260,   318,   201,
     323,   142,    31,   252,   190,   311,   249,    75,    51,    32,
      33,   143,   194,    34,    89,   224,   225,   309,   405,   381,
     407,   186,   340,   248,   345,   306,    52,    76,   123,   161,
      82,   129,   176,   332,   368,   131,   244,   182,   300,   183,
      98,   239,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   299,   263,   334,   122,   140,    53,   402,    73,   163,
     164,   356,   240,   241,   281,    42,   245,    87,   360,   336,
     337,    92,    97,   206,   173,    79,   403,    37,   402,    38,
     242,   265,    83,    83,   361,    56,    57,    77,   370,    78,
     174,   384,    40,    55,    41,   111,   392,   279,   222,   118,
     362,   180,   404,   284,   127,   325,   243,    43,    58,   133,
      59,    80,   324,    44,    60,   285,    46,    47,    48,    74,
      54,    50,    39,   404,   116,   391,    53,    81,    79,   394,
     115,   215,   154,   157,   158,   159,   257,    62,   134,   135,
     136,   137,   168,   171,   172,   413,   255,   421,   415,   227,
     187,   272,   274,   275,   276,   160,   160,    61,   410,   426,
     250,   338,   258,   253,   166,   330,   162,   273,   258,   388,
     354,   210,   339,   259,   212,   184,    63,  -130,    64,   259,
     167,   181,   424,  -148,  -148,   218,   342,   343,   220,   346,
      83,   124,    79,   429,    65,   125,    66,   282,    42,   412,
      79,   207,  -130,    84,    67,   208,  -130,  -130,  -130,  -130,
     289,   293,   297,   180,   180,    68,    69,    79,   305,    42,
     423,    70,    71,    72,    88,   266,   269,   270,    85,   271,
    -130,  -130,  -130,  -130,  -130,   277,    99,   278,   100,   101,
      43,   102,   103,   104,    86,    93,    94,    95,    96,    46,
      47,    48,    74,    90,    50,  -130,   399,   105,   331,   106,
     107,    43,   331,   109,   108,   110,   359,    44,    42,    91,
      46,    47,    48,    74,  -130,    50,    79,   357,   117,   126,
     128,   250,  -130,   130,   290,   295,   327,   184,   184,    79,
     302,   294,   298,   181,   181,    83,   132,    79,   307,   138,
     139,   365,   141,  -130,  -130,  -130,  -130,   150,   151,   144,
      43,  -130,  -130,  -130,  -130,   305,    44,   379,    45,    46,
      47,    48,    49,   145,    50,   155,   147,  -130,   148,   149,
      73,   180,    77,   152,   331,  -130,    77,  -130,   393,   185,
     160,   156,   165,   188,   358,   175,   189,  -130,   191,   153,
     192,   193,    79,   196,   197,   198,   199,   200,   195,   202,
     251,   180,    79,   204,   205,   209,  -130,  -130,  -130,  -130,
     211,   216,   217,   219,   221,   366,  -130,  -130,  -130,  -130,
     226,   223,   180,   246,   247,   256,   262,   264,   169,  -165,
    -130,   280,   310,   375,   376,   307,  -163,   313,   267,   286,
    -130,   315,    83,  -165,   170,   184,   283,   303,    77,   308,
    -163,   181,   319,   316,   268,   333,   321,   317,   322,  -165,
    -165,  -165,  -165,    83,   344,   326,  -163,  -163,  -163,  -163,
     328,   329,   347,  -166,   348,   184,   350,   352,  -165,   353,
    -164,   181,  -165,   355,   385,  -163,    83,  -166,  -165,  -163,
     417,   367,   369,   371,  -164,  -163,   184,   372,   390,   335,
     373,   374,   181,  -166,  -166,  -166,  -166,   296,   119,   380,
    -164,  -164,  -164,  -164,  -172,   386,   389,   395,   396,   397,
     338,  -167,  -166,   401,   406,   408,  -166,   411,  -172,  -164,
     425,   414,  -166,  -164,   416,  -167,   428,   418,   419,  -164,
     320,   261,   383,   382,  -172,  -172,  -172,  -172,   351,   254,
      43,  -167,  -167,  -167,  -167,  -170,   312,   314,   422,    46,
      47,    48,  -168,  -172,    50,   349,   427,  -172,   420,  -170,
    -167,   398,   400,  -172,  -167,   387,  -168,   409,   112,   377,
    -167,   301,     0,     0,     0,  -170,  -170,  -170,  -170,     0,
      42,   113,  -168,  -168,  -168,  -168,  -169,     0,     0,     0,
       0,     0,     0,     0,  -170,     0,     0,     0,  -170,     0,
    -169,  -168,     0,     0,  -170,  -168,     0,     0,     0,     0,
       0,  -168,     0,     0,     0,     0,  -169,  -169,  -169,  -169,
      42,     0,    43,     0,     0,     0,     0,    93,    94,    95,
      96,    46,    47,    48,    74,  -169,    50,    42,     0,  -169,
       0,     0,     0,     0,     0,  -169,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     0,     0,     0,     0,     0,
      42,     0,    43,     0,     0,   238,     0,    93,    94,    95,
      96,    46,    47,    48,    74,    42,    50,     0,     0,    43,
       0,     0,     0,     0,    93,    94,    95,    96,    46,    47,
      48,    74,   177,    50,    42,     0,     0,     0,     0,     0,
       0,   119,    43,     0,   178,     0,     0,     0,    44,     0,
       0,    46,    47,    48,   179,     0,    50,    43,   119,     0,
       0,     0,     0,     0,    95,    96,    46,    47,    48,    74,
       0,    50,     0,   287,     0,     0,    43,     0,     0,     0,
     291,     0,    44,    43,     0,    46,    47,    48,   114,     0,
      50,   120,    46,    47,    48,   121,   363,    50,     0,     0,
      43,     0,     0,    42,     0,     0,     0,     0,   213,    46,
      47,    48,   214,     0,    50,    43,   119,     0,     0,     0,
       0,    44,    43,   119,    46,    47,    48,   288,    44,    50,
       0,    46,    47,    48,   292,     0,    50,     0,    43,   119,
       0,     0,     0,     0,    44,    43,     0,    46,    47,    48,
     364,     0,    50,     0,    46,    47,    48,    74,    43,    50,
       0,     0,     0,     0,     0,    43,     0,    46,    47,    48,
     296,    83,    50,     0,    46,    47,    48,   304,     0,    50,
       0,    43,     0,     0,   228,     0,     0,     0,     0,     0,
      46,    47,    48,   378,    83,    50,     0,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   341,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,     0,     0,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,     2,     0,     0,     0,     3,     4,     0,     0,   238,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
      12,    13,    14,     0,     0,     0,     0,     0,    15,    16,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,   238
};

static const yytype_int16 yycheck[] =
{
       5,   242,   204,   291,    83,   103,     5,    10,     9,   121,
     122,   324,   180,   181,   224,    16,   184,    49,    38,   299,
     300,    53,    54,   150,    54,    18,    29,     6,    10,     8,
      36,   206,    16,    16,    54,     7,     8,    42,   334,    44,
      70,   354,     6,    70,     8,    29,    29,   222,   175,    81,
      70,   130,    55,    49,    86,   265,    62,    58,     3,    91,
      30,    54,   264,    64,    32,    61,    67,    68,    69,    70,
      75,    72,    51,    55,    79,   363,    75,    70,    18,   367,
      79,   160,   114,   115,   116,   117,    16,     3,    93,    94,
      95,    96,   124,   125,   126,   391,   194,   407,   394,   178,
     132,   213,   214,   215,   216,    18,    18,    70,   388,   419,
     189,    18,    48,   192,    54,   283,    29,    29,    48,   360,
     322,   153,    29,    59,   156,   130,     3,     3,     3,    59,
      70,   130,   412,    17,    18,   167,   304,   305,   170,   307,
      16,    66,    18,   423,     3,    70,     3,   226,    16,   390,
      18,    66,     3,    29,    40,    70,    32,    33,    34,    35,
     239,   240,   241,   242,   243,    70,    70,    18,   247,    16,
     411,     8,    70,    70,    32,   207,   208,   209,    54,   211,
      56,    32,    33,    34,    35,   217,     3,   219,     3,    32,
      58,    70,    70,    37,    70,    63,    64,    65,    66,    67,
      68,    69,    70,    54,    72,    56,   374,    41,   287,    16,
      38,    58,   291,     3,    70,     3,   328,    64,    16,    70,
      67,    68,    69,    70,     3,    72,    18,   325,    70,    70,
      70,   310,     3,    33,   239,   240,   268,   242,   243,    18,
     245,   240,   241,   242,   243,    16,    70,    18,   247,    70,
      31,   330,    70,    32,    33,    34,    35,    32,    29,    72,
      58,    32,    33,    34,    35,   344,    64,   346,    66,    67,
      68,    69,    70,    70,    72,    54,    70,    56,    38,    70,
       9,   360,   287,    54,   363,    56,   291,     3,   367,    34,
      18,    70,    17,     3,   326,    18,    16,     3,     3,    70,
      42,    18,    18,    22,    23,    24,    25,    26,    30,    18,
      18,   390,    18,    16,    70,    70,    32,    33,    34,    35,
      70,    70,    70,    70,    70,   330,    32,    33,    34,    35,
      60,    52,   411,    57,    35,     6,    17,    16,    54,     3,
      56,    53,    18,   342,   343,   344,     3,     3,    54,    48,
      56,     3,    16,    17,    70,   360,    70,    70,   363,    56,
      17,   360,    58,    70,    70,    29,     3,    67,    18,    33,
      34,    35,    36,    16,    36,    70,    33,    34,    35,    36,
      70,    70,    57,     3,     3,   390,    17,     3,    52,    17,
       3,   390,    56,    17,     3,    52,    16,    17,    62,    56,
     399,    18,    70,    70,    17,    62,   411,    70,    38,    29,
      70,    70,   411,    33,    34,    35,    36,    70,    16,    70,
      33,    34,    35,    36,     3,    17,    70,    17,    17,    29,
      18,     3,    52,    29,    18,     3,    56,    38,    17,    52,
      17,    70,    62,    56,    70,    17,    17,    70,    70,    62,
     261,   202,   353,   349,    33,    34,    35,    36,   312,   193,
      58,    33,    34,    35,    36,     3,   251,   254,   409,    67,
      68,    69,     3,    52,    72,   310,   420,    56,   406,    17,
      52,   373,   377,    62,    56,   357,    17,   387,    75,   344,
      62,   243,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      16,    17,    33,    34,    35,    36,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    56,    -1,
      17,    52,    -1,    -1,    62,    56,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      16,    -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    52,    72,    16,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    62,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    58,    -1,    -1,    61,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    16,    72,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    48,    72,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    58,    -1,    60,    -1,    -1,    -1,    64,    -1,
      -1,    67,    68,    69,    70,    -1,    72,    58,    16,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    -1,    16,    -1,    -1,    58,    -1,    -1,    -1,
      16,    -1,    64,    58,    -1,    67,    68,    69,    70,    -1,
      72,    66,    67,    68,    69,    70,    16,    72,    -1,    -1,
      58,    -1,    -1,    16,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    -1,    72,    58,    16,    -1,    -1,    -1,
      -1,    64,    58,    16,    67,    68,    69,    70,    64,    72,
      -1,    67,    68,    69,    70,    -1,    72,    -1,    58,    16,
      -1,    -1,    -1,    -1,    64,    58,    -1,    67,    68,    69,
      70,    -1,    72,    -1,    67,    68,    69,    70,    58,    72,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    67,    68,    69,
      70,    16,    72,    -1,    67,    68,    69,    70,    -1,    72,
      -1,    58,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    16,    72,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,     0,    -1,    -1,    -1,     4,     5,    -1,    -1,    61,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61
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
     132,   133,   134,    70,    70,   102,   119,   121,    56,   111,
      18,    99,    98,     3,   106,     3,    70,    67,    92,    58,
      89,     3,    18,    94,    95,   110,    70,   124,    70,    70,
     135,   102,   127,    29,   127,    29,   130,   130,    18,    29,
     116,    29,   135,   135,    36,   118,   135,    57,     3,   100,
      17,    97,     3,    17,    95,    17,    94,   129,   124,   123,
      38,    54,    70,    16,    70,   102,   134,    18,   128,    70,
     128,    70,    70,    70,    70,   121,   121,   119,    70,   102,
      70,   113,    99,    91,    94,     3,    17,   115,   131,    70,
      38,   127,    29,   102,   127,    17,    17,    29,   116,   135,
     118,    29,    10,    29,    55,   112,    18,   114,     3,   117,
     130,    38,   131,   128,    70,   128,    70,   121,    70,    70,
     113,   112,   111,   131,   130,    17,   112,   114,    17,   130
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
     133,   133,   133,   133,   133,   133,   133,   133,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   136,   137
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
       5,     3,     3,     3,     3,     3,     5,     3,     1,     1,
       3,     1,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       2,     8,     5
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
#line 215 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1862 "yacc_sql.tab.c"
    break;

  case 23:
#line 220 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1870 "yacc_sql.tab.c"
    break;

  case 24:
#line 225 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1878 "yacc_sql.tab.c"
    break;

  case 25:
#line 231 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1886 "yacc_sql.tab.c"
    break;

  case 26:
#line 237 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1894 "yacc_sql.tab.c"
    break;

  case 27:
#line 243 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1902 "yacc_sql.tab.c"
    break;

  case 28:
#line 249 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1911 "yacc_sql.tab.c"
    break;

  case 29:
#line 255 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1919 "yacc_sql.tab.c"
    break;

  case 30:
#line 261 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1928 "yacc_sql.tab.c"
    break;

  case 31:
#line 269 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,0);
			CONTEXT->id_num=0;
		}
#line 1938 "yacc_sql.tab.c"
    break;

  case 32:
#line 275 "yacc_sql.y"
            {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,1);
			CONTEXT->id_num=0;
		}
#line 1948 "yacc_sql.tab.c"
    break;

  case 33:
#line 284 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1957 "yacc_sql.tab.c"
    break;

  case 34:
#line 291 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零
			CONTEXT->value_length = 0;
		}
#line 1969 "yacc_sql.tab.c"
    break;

  case 36:
#line 301 "yacc_sql.y"
                                   {    }
#line 1975 "yacc_sql.tab.c"
    break;

  case 37:
#line 306 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, (yyvsp[-5].string), (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1986 "yacc_sql.tab.c"
    break;

  case 38:
#line 313 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,(yyvsp[-2].string), (yyvsp[-1].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1997 "yacc_sql.tab.c"
    break;

  case 39:
#line 320 "yacc_sql.y"
               {
	    (yyval.number)=0;
	 }
#line 2005 "yacc_sql.tab.c"
    break;

  case 40:
#line 323 "yacc_sql.y"
             {
		(yyval.number)=1;
	 }
#line 2013 "yacc_sql.tab.c"
    break;

  case 41:
#line 326 "yacc_sql.y"
                   {
		(yyval.number)=0;
	}
#line 2021 "yacc_sql.tab.c"
    break;

  case 42:
#line 330 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 2027 "yacc_sql.tab.c"
    break;

  case 43:
#line 333 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 2033 "yacc_sql.tab.c"
    break;

  case 44:
#line 334 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 2039 "yacc_sql.tab.c"
    break;

  case 45:
#line 335 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 2045 "yacc_sql.tab.c"
    break;

  case 46:
#line 336 "yacc_sql.y"
                    { (yyval.number)=DATES;}
#line 2051 "yacc_sql.tab.c"
    break;

  case 47:
#line 337 "yacc_sql.y"
                    { (yyval.number)=TEXTS;}
#line 2057 "yacc_sql.tab.c"
    break;

  case 49:
#line 341 "yacc_sql.y"
                        {
	 
   }
#line 2065 "yacc_sql.tab.c"
    break;

  case 50:
#line 346 "yacc_sql.y"
        {
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", (yyvsp[0].string));
		CONTEXT->id_num++;
	}
#line 2075 "yacc_sql.tab.c"
    break;

  case 51:
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
#line 2090 "yacc_sql.tab.c"
    break;

  case 53:
#line 368 "yacc_sql.y"
                                  {
  }
#line 2097 "yacc_sql.tab.c"
    break;

  case 54:
#line 372 "yacc_sql.y"
                                       {
	CONTEXT->insert_num++;
  }
#line 2105 "yacc_sql.tab.c"
    break;

  case 56:
#line 377 "yacc_sql.y"
                                     {
	  }
#line 2112 "yacc_sql.tab.c"
    break;

  case 57:
#line 381 "yacc_sql.y"
        {
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*(yyvsp[0].value1);
   }
#line 2120 "yacc_sql.tab.c"
    break;

  case 58:
#line 386 "yacc_sql.y"
         {
	parser_id++;
	CONTEXT->ssql=query_create();
}
#line 2129 "yacc_sql.tab.c"
    break;

  case 59:
#line 391 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2138 "yacc_sql.tab.c"
    break;

  case 60:
#line 395 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2147 "yacc_sql.tab.c"
    break;

  case 61:
#line 399 "yacc_sql.y"
         {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2157 "yacc_sql.tab.c"
    break;

  case 62:
#line 404 "yacc_sql.y"
             {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
		if(value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string))<0){
		  CONTEXT->ssql->date_parse_err = -1;
		}
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 2169 "yacc_sql.tab.c"
    break;

  case 63:
#line 411 "yacc_sql.y"
               {
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 2178 "yacc_sql.tab.c"
    break;

  case 64:
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
#line 2198 "yacc_sql.tab.c"
    break;

  case 65:
#line 434 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2210 "yacc_sql.tab.c"
    break;

  case 66:
#line 444 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,(yyvsp[-5].string),CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2221 "yacc_sql.tab.c"
    break;

  case 67:
#line 452 "yacc_sql.y"
                  {

}
#line 2229 "yacc_sql.tab.c"
    break;

  case 69:
#line 456 "yacc_sql.y"
                                  {

   }
#line 2237 "yacc_sql.tab.c"
    break;

  case 70:
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
		memset(CONTEXT->expr,0,sizeof(CONTEXT->expr));
		CONTEXT->expr_num = 0;
	}
#line 2255 "yacc_sql.tab.c"
    break;

  case 72:
#line 477 "yacc_sql.y"
                                              {}
#line 2261 "yacc_sql.tab.c"
    break;

  case 73:
#line 480 "yacc_sql.y"
                                                     {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string), NULL);
   	}
#line 2269 "yacc_sql.tab.c"
    break;

  case 74:
#line 483 "yacc_sql.y"
                                                             {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string), (yyvsp[-3].string));
   	}
#line 2277 "yacc_sql.tab.c"
    break;

  case 75:
#line 486 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string), (yyvsp[-3].string));
   	}
#line 2285 "yacc_sql.tab.c"
    break;

  case 77:
#line 492 "yacc_sql.y"
                              {
   }
#line 2292 "yacc_sql.tab.c"
    break;

  case 79:
#line 496 "yacc_sql.y"
                                                 {
		
	}
#line 2300 "yacc_sql.tab.c"
    break;

  case 80:
#line 500 "yacc_sql.y"
             {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
#line 2308 "yacc_sql.tab.c"
    break;

  case 81:
#line 503 "yacc_sql.y"
           {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
#line 2316 "yacc_sql.tab.c"
    break;

  case 82:
#line 506 "yacc_sql.y"
              {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
#line 2324 "yacc_sql.tab.c"
    break;

  case 83:
#line 511 "yacc_sql.y"
             { 
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
#line 2334 "yacc_sql.tab.c"
    break;

  case 84:
#line 516 "yacc_sql.y"
                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
#line 2344 "yacc_sql.tab.c"
    break;

  case 88:
#line 526 "yacc_sql.y"
                                    {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2354 "yacc_sql.tab.c"
    break;

  case 89:
#line 531 "yacc_sql.y"
                                           {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2364 "yacc_sql.tab.c"
    break;

  case 91:
#line 539 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2374 "yacc_sql.tab.c"
    break;

  case 92:
#line 544 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2384 "yacc_sql.tab.c"
    break;

  case 94:
#line 552 "yacc_sql.y"
                                                        {}
#line 2390 "yacc_sql.tab.c"
    break;

  case 96:
#line 555 "yacc_sql.y"
                                                     {}
#line 2396 "yacc_sql.tab.c"
    break;

  case 97:
#line 558 "yacc_sql.y"
                         {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2408 "yacc_sql.tab.c"
    break;

  case 98:
#line 565 "yacc_sql.y"
                            {
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2421 "yacc_sql.tab.c"
    break;

  case 99:
#line 573 "yacc_sql.y"
                                   {
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2434 "yacc_sql.tab.c"
    break;

  case 100:
#line 581 "yacc_sql.y"
                               {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2446 "yacc_sql.tab.c"
    break;

  case 101:
#line 588 "yacc_sql.y"
                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].function1));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2459 "yacc_sql.tab.c"
    break;

  case 102:
#line 596 "yacc_sql.y"
                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2472 "yacc_sql.tab.c"
    break;

  case 103:
#line 607 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2482 "yacc_sql.tab.c"
    break;

  case 104:
#line 612 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2492 "yacc_sql.tab.c"
    break;

  case 105:
#line 617 "yacc_sql.y"
                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2502 "yacc_sql.tab.c"
    break;

  case 106:
#line 622 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2512 "yacc_sql.tab.c"
    break;

  case 107:
#line 627 "yacc_sql.y"
                         {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2520 "yacc_sql.tab.c"
    break;

  case 108:
#line 630 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2530 "yacc_sql.tab.c"
    break;

  case 109:
#line 635 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2540 "yacc_sql.tab.c"
    break;

  case 110:
#line 640 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2548 "yacc_sql.tab.c"
    break;

  case 111:
#line 643 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2558 "yacc_sql.tab.c"
    break;

  case 112:
#line 648 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2568 "yacc_sql.tab.c"
    break;

  case 113:
#line 653 "yacc_sql.y"
                            {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2576 "yacc_sql.tab.c"
    break;

  case 114:
#line 656 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2586 "yacc_sql.tab.c"
    break;

  case 115:
#line 661 "yacc_sql.y"
                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2596 "yacc_sql.tab.c"
    break;

  case 116:
#line 666 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2606 "yacc_sql.tab.c"
    break;

  case 117:
#line 671 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2616 "yacc_sql.tab.c"
    break;

  case 118:
#line 676 "yacc_sql.y"
                              {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1), NULL);
	}
#line 2624 "yacc_sql.tab.c"
    break;

  case 119:
#line 682 "yacc_sql.y"
                                       {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, (yyvsp[-3].string));
		CONTEXT->parameter_length = 0;
		(yyval.function1)=&CONTEXT->functions[CONTEXT->function_length-1];
	}
#line 2635 "yacc_sql.tab.c"
    break;

  case 121:
#line 691 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2645 "yacc_sql.tab.c"
    break;

  case 122:
#line 696 "yacc_sql.y"
                                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2655 "yacc_sql.tab.c"
    break;

  case 123:
#line 701 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2665 "yacc_sql.tab.c"
    break;

  case 124:
#line 706 "yacc_sql.y"
                                   {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2673 "yacc_sql.tab.c"
    break;

  case 126:
#line 711 "yacc_sql.y"
                                      {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2683 "yacc_sql.tab.c"
    break;

  case 127:
#line 716 "yacc_sql.y"
                                             {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2693 "yacc_sql.tab.c"
    break;

  case 128:
#line 721 "yacc_sql.y"
                                        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2703 "yacc_sql.tab.c"
    break;

  case 129:
#line 726 "yacc_sql.y"
                                         {
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], (yyvsp[-1].value1));
	}
#line 2711 "yacc_sql.tab.c"
    break;

  case 131:
#line 732 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2721 "yacc_sql.tab.c"
    break;

  case 132:
#line 737 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2731 "yacc_sql.tab.c"
    break;

  case 133:
#line 742 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2741 "yacc_sql.tab.c"
    break;

  case 134:
#line 747 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2749 "yacc_sql.tab.c"
    break;

  case 135:
#line 750 "yacc_sql.y"
                               {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2759 "yacc_sql.tab.c"
    break;

  case 136:
#line 755 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2769 "yacc_sql.tab.c"
    break;

  case 137:
#line 760 "yacc_sql.y"
                                     {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2777 "yacc_sql.tab.c"
    break;

  case 138:
#line 763 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2787 "yacc_sql.tab.c"
    break;

  case 139:
#line 768 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2797 "yacc_sql.tab.c"
    break;

  case 140:
#line 773 "yacc_sql.y"
                                  {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2805 "yacc_sql.tab.c"
    break;

  case 141:
#line 776 "yacc_sql.y"
                                    {
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1), NULL);
	}
#line 2813 "yacc_sql.tab.c"
    break;

  case 142:
#line 782 "yacc_sql.y"
      {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[0].string), NULL);
    }
#line 2821 "yacc_sql.tab.c"
    break;

  case 143:
#line 785 "yacc_sql.y"
               {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string), (yyvsp[0].string));
    }
#line 2829 "yacc_sql.tab.c"
    break;

  case 144:
#line 788 "yacc_sql.y"
            {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string), (yyvsp[0].string));
    }
#line 2837 "yacc_sql.tab.c"
    break;

  case 146:
#line 795 "yacc_sql.y"
                            {	
		  }
#line 2844 "yacc_sql.tab.c"
    break;

  case 148:
#line 799 "yacc_sql.y"
          {
	CONTEXT->in_value[CONTEXT->in_value_num++] = *(yyvsp[0].value1);
   }
#line 2852 "yacc_sql.tab.c"
    break;

  case 150:
#line 803 "yacc_sql.y"
                                 {
   }
#line 2859 "yacc_sql.tab.c"
    break;

  case 152:
#line 807 "yacc_sql.y"
                                         {	
			}
#line 2866 "yacc_sql.tab.c"
    break;

  case 154:
#line 812 "yacc_sql.y"
                                       {

	}
#line 2874 "yacc_sql.tab.c"
    break;

  case 155:
#line 815 "yacc_sql.y"
                                          {
	}
#line 2881 "yacc_sql.tab.c"
    break;

  case 156:
#line 819 "yacc_sql.y"
            {
	CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 0;
}
#line 2889 "yacc_sql.tab.c"
    break;

  case 157:
#line 823 "yacc_sql.y"
            {
     CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 1;
}
#line 2897 "yacc_sql.tab.c"
    break;

  case 158:
#line 827 "yacc_sql.y"
                      {
		CONTEXT->comp = EXISTS;

		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2911 "yacc_sql.tab.c"
    break;

  case 159:
#line 836 "yacc_sql.y"
                            {
		CONTEXT->comp = NOT_EXISTS;
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2923 "yacc_sql.tab.c"
    break;

  case 160:
#line 843 "yacc_sql.y"
                                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2937 "yacc_sql.tab.c"
    break;

  case 161:
#line 852 "yacc_sql.y"
                                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr,(yyvsp[-7].string), (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2951 "yacc_sql.tab.c"
    break;

  case 162:
#line 861 "yacc_sql.y"
                                                           {
		Value *left_value = (yyvsp[-5].value1);

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 0, NULL, left_value,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2964 "yacc_sql.tab.c"
    break;

  case 163:
#line 869 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;

	}
#line 2980 "yacc_sql.tab.c"
    break;

  case 164:
#line 881 "yacc_sql.y"
        {
		Value *left_value = (yyvsp[-2].value1);
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2993 "yacc_sql.tab.c"
    break;

  case 165:
#line 889 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3008 "yacc_sql.tab.c"
    break;

  case 166:
#line 900 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-2].value1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
		}
#line 3023 "yacc_sql.tab.c"
    break;

  case 167:
#line 911 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = (yyvsp[0].value1);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
							
    }
#line 3039 "yacc_sql.tab.c"
    break;

  case 168:
#line 923 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-4].value1);

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 3055 "yacc_sql.tab.c"
    break;

  case 169:
#line 935 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3070 "yacc_sql.tab.c"
    break;

  case 170:
#line 946 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3085 "yacc_sql.tab.c"
    break;

  case 171:
#line 956 "yacc_sql.y"
                           {
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3097 "yacc_sql.tab.c"
    break;

  case 172:
#line 963 "yacc_sql.y"
                           {
	Value *left_value = (yyvsp[-2].value1);

	Condition condition;
	condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
	CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3109 "yacc_sql.tab.c"
    break;

  case 173:
#line 970 "yacc_sql.y"
                              {
	Condition condition;
	condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, (yyvsp[0].function1), NULL);
	CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3119 "yacc_sql.tab.c"
    break;

  case 174:
#line 975 "yacc_sql.y"
                                {
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, (yyvsp[-2].value1), 1, (yyvsp[0].expr1), NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3129 "yacc_sql.tab.c"
    break;

  case 175:
#line 980 "yacc_sql.y"
                             {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].expr1), NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3142 "yacc_sql.tab.c"
    break;

  case 176:
#line 988 "yacc_sql.y"
                                    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].expr1), NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3155 "yacc_sql.tab.c"
    break;

  case 177:
#line 996 "yacc_sql.y"
                                     {
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].expr1), NULL, 1,(yyvsp[0].expr1), NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3165 "yacc_sql.tab.c"
    break;

  case 178:
#line 1004 "yacc_sql.y"
              {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,(yyvsp[0].function1),NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3174 "yacc_sql.tab.c"
    break;

  case 179:
#line 1008 "yacc_sql.y"
                {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],0,NULL,(yyvsp[0].value1));
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3183 "yacc_sql.tab.c"
    break;

  case 180:
#line 1012 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr,(yyvsp[-2].string),(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3194 "yacc_sql.tab.c"
    break;

  case 181:
#line 1018 "yacc_sql.y"
              {
		RelAttr attr;
		relation_attr_init(&attr,NULL,(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3205 "yacc_sql.tab.c"
    break;

  case 182:
#line 1024 "yacc_sql.y"
                                   {
		append_brace((yyvsp[-1].expr1));
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 3214 "yacc_sql.tab.c"
    break;

  case 183:
#line 1028 "yacc_sql.y"
                                     {
		append_expression((yyvsp[-2].expr1),MUL,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3223 "yacc_sql.tab.c"
    break;

  case 184:
#line 1032 "yacc_sql.y"
                                      {
		append_expression((yyvsp[-2].expr1),DIV,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3232 "yacc_sql.tab.c"
    break;

  case 185:
#line 1036 "yacc_sql.y"
                                      {
		append_expression((yyvsp[-2].expr1),ADD,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3241 "yacc_sql.tab.c"
    break;

  case 186:
#line 1040 "yacc_sql.y"
                                      {
		append_expression((yyvsp[-2].expr1),SUB,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-2].expr1);
	 }
#line 3250 "yacc_sql.tab.c"
    break;

  case 187:
#line 1044 "yacc_sql.y"
                                {
		// 减数字,当作加负数
		append_expression((yyvsp[-1].expr1),ADD,(yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 3260 "yacc_sql.tab.c"
    break;

  case 188:
#line 1049 "yacc_sql.y"
                           {
		append_neg((yyvsp[0].expr1));
		(yyval.expr1)=(yyvsp[0].expr1);
	 }
#line 3269 "yacc_sql.tab.c"
    break;

  case 189:
#line 1058 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3275 "yacc_sql.tab.c"
    break;

  case 190:
#line 1059 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3281 "yacc_sql.tab.c"
    break;

  case 191:
#line 1060 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3287 "yacc_sql.tab.c"
    break;

  case 192:
#line 1061 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3293 "yacc_sql.tab.c"
    break;

  case 193:
#line 1062 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3299 "yacc_sql.tab.c"
    break;

  case 194:
#line 1063 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3305 "yacc_sql.tab.c"
    break;

  case 195:
#line 1064 "yacc_sql.y"
                 {CONTEXT->comp = LIKE;}
#line 3311 "yacc_sql.tab.c"
    break;

  case 196:
#line 1065 "yacc_sql.y"
                     {CONTEXT->comp = NOT_LIKE;}
#line 3317 "yacc_sql.tab.c"
    break;

  case 197:
#line 1066 "yacc_sql.y"
               {CONTEXT->comp = IS;}
#line 3323 "yacc_sql.tab.c"
    break;

  case 198:
#line 1067 "yacc_sql.y"
                  {CONTEXT->comp = IS_NOT;}
#line 3329 "yacc_sql.tab.c"
    break;

  case 199:
#line 1068 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 3335 "yacc_sql.tab.c"
    break;

  case 200:
#line 1069 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 3341 "yacc_sql.tab.c"
    break;

  case 201:
#line 1074 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3350 "yacc_sql.tab.c"
    break;

  case 202:
#line 1082 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
		}
#line 3359 "yacc_sql.tab.c"
    break;


#line 3363 "yacc_sql.tab.c"

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
#line 1087 "yacc_sql.y"

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
