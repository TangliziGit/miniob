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
  struct Function *function1;
  struct _Expr* expr1;
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
#define YYLAST   439

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  374

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
     461,   474,   477,   482,   483,   486,   487,   491,   494,   497,
     502,   507,   513,   514,   516,   517,   522,   529,   530,   535,
     542,   543,   545,   546,   549,   556,   564,   572,   579,   587,
     598,   603,   608,   613,   618,   621,   626,   631,   637,   645,
     646,   651,   656,   661,   666,   667,   672,   677,   682,   687,
     689,   694,   699,   704,   710,   713,   717,   719,   722,   723,
     726,   727,   729,   731,   734,   736,   739,   743,   747,   751,
     760,   767,   776,   785,   793,   804,   813,   823,   834,   846,
     858,   869,   881,   885,   891,   897,   900,   906,   912,   918,
     926,   927,   928,   929,   930,   931,   932,   933,   934,   935,
     936,   937,   941,   949
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
  "eq_define", "eq_define_list", "select", "join_attr", "join_attr_list",
  "order_by", "order", "order_attr", "order_attr_lists", "group_by",
  "group_by_list", "having", "having_condition_list", "having_condition",
  "select_attr", "function", "function_attr", "function_attr_list",
  "attr_list", "rel_id", "rel_list", "in_value", "in_value_list", "where",
  "condition_list", "and_condition", "or_condition", "condition",
  "expression", "comOp", "load_data", "show_index", YY_NULLPTR
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

#define YYPACT_NINF (-332)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -332,   304,  -332,    10,    23,    36,   -19,    82,    52,    33,
      45,    -2,   117,   141,   143,   144,   148,   113,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,    86,    96,   149,
      97,   100,   159,    87,   150,     2,   178,   182,   168,  -332,
     121,   132,   166,  -332,  -332,  -332,  -332,  -332,   163,   196,
     175,   158,   226,   229,   170,  -332,    55,    48,   177,  -332,
     179,   184,  -332,  -332,  -332,   186,   207,   224,   188,   176,
     191,   192,   237,  -332,  -332,    12,   159,   267,  -332,   259,
    -332,  -332,  -332,    16,  -332,   259,   261,   159,     4,   159,
     225,   263,   159,   282,   270,    92,   285,  -332,   247,   272,
     262,   220,   284,   287,   235,    79,  -332,  -332,  -332,    36,
     120,  -332,   236,  -332,  -332,  -332,  -332,   240,  -332,  -332,
     241,   179,   255,  -332,  -332,   215,   303,    24,   266,   215,
     291,   320,   -15,  -332,   311,  -332,   215,   188,   224,   316,
    -332,  -332,  -332,  -332,  -332,     1,   191,   310,   188,   312,
     159,   159,   297,   259,    21,   259,   259,   159,  -332,   263,
     277,   255,   224,   324,  -332,   270,   341,   317,  -332,   109,
     215,  -332,   275,  -332,  -332,  -332,  -332,  -332,  -332,   -13,
    -332,   299,  -332,   126,   139,    92,    92,  -332,   147,   147,
     147,   147,   147,  -332,   272,   345,   279,   283,   293,  -332,
    -332,   284,   368,   355,   188,  -332,  -332,   179,  -332,   308,
    -332,  -332,  -332,  -332,  -332,   309,  -332,   346,   215,   365,
     303,  -332,   313,  -332,  -332,   320,  -332,  -332,  -332,    43,
    -332,  -332,    43,   356,  -332,   -15,   -15,  -332,    73,    73,
    -332,  -332,   157,  -332,  -332,   381,  -332,   369,  -332,  -332,
    -332,   188,   370,   355,   263,   259,   -11,   331,   354,   324,
    -332,  -332,  -332,   167,  -332,   372,   372,   321,  -332,  -332,
    -332,    89,   355,   389,   376,   255,  -332,    92,   325,   326,
     183,   338,  -332,    43,   371,  -332,   215,   380,   382,  -332,
    -332,  -332,  -332,   395,   224,   -15,   363,   125,   251,   320,
     366,   320,   347,   400,   372,   335,   372,  -332,  -332,  -332,
     346,  -332,    92,   336,   337,  -332,   339,   340,   340,   183,
    -332,   202,   342,  -332,   391,  -332,  -332,   354,   -15,   384,
     393,   320,   398,  -332,  -332,   366,   386,  -332,     9,   399,
    -332,   338,  -332,   348,  -332,   340,  -332,   349,  -332,   350,
    -332,  -332,   342,    14,   404,  -332,  -332,  -332,    14,   399,
    -332,  -332,  -332,  -332
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
       0,     0,     0,     0,     0,   100,   109,     0,     0,   101,
       0,     0,   104,    30,    29,     0,     0,   132,     0,     0,
       0,     0,     0,    28,    33,   119,   119,     0,    63,   114,
      59,    60,    62,   114,    61,   114,     0,   119,   119,   119,
     124,   126,   119,     0,     0,     0,     0,    50,     0,    68,
       0,     0,    35,     0,     0,     0,   120,   123,    58,     0,
       0,   112,     0,   110,   113,   108,   103,     0,   102,   105,
       0,     0,    73,   107,   173,     0,    52,     0,     0,     0,
     154,   152,   134,   137,     0,    65,     0,     0,   132,     0,
      43,    44,    45,    46,    47,    39,     0,     0,     0,     0,
     119,   119,     0,   114,   114,   114,   114,   119,   125,   126,
       0,    73,   132,    55,    57,     0,     0,   154,   152,     0,
       0,   139,     0,   160,   161,   162,   163,   164,   165,     0,
     166,   168,   170,     0,     0,     0,     0,   133,     0,     0,
       0,     0,     0,    67,    68,     0,     0,     0,     0,    40,
      38,    35,     0,    48,     0,   122,   121,     0,   117,     0,
     115,   118,   111,   106,   127,     0,    74,    84,     0,     0,
      52,    51,     0,   155,   140,   153,   167,   171,   169,   128,
     146,   144,   128,   147,   145,   134,   134,   138,   158,   159,
     157,   156,   151,    69,    66,     0,    42,     0,    41,    36,
      34,     0,     0,    48,   126,   114,     0,     0,    90,    55,
      54,    53,   153,     0,   129,   130,   130,     0,   135,   136,
     172,    39,    48,     0,     0,    73,   116,     0,     0,     0,
       0,    75,    56,   128,     0,   148,   128,     0,     0,   149,
      37,    49,    31,     0,   132,   134,     0,    87,     0,     0,
      92,     0,     0,     0,   130,     0,   130,   141,   143,    32,
      84,    71,     0,     0,     0,    85,     0,     0,     0,     0,
      91,     0,     0,    70,     0,   150,   131,    90,   134,    88,
      87,     0,     0,    98,    97,    92,    95,    94,    77,    82,
     142,    75,    72,     0,    86,     0,    93,     0,    78,     0,
      79,    80,     0,    77,     0,    89,    99,    96,    77,    82,
      76,    64,    81,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,   205,   268,   142,  -332,  -332,
    -238,  -152,  -332,   195,   252,   153,   198,  -332,   -63,  -332,
    -332,   281,   227,  -332,  -332,  -166,    78,  -331,    68,    63,
     114,    93,    98,    91,   108,   319,   -64,  -332,   -85,   -32,
    -119,  -160,  -196,  -241,  -146,  -231,  -188,  -332,   243,  -114,
    -140,  -332,  -332
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   157,   112,   210,   257,   155,
     262,   108,    31,   176,   136,   229,   173,   119,   178,    32,
      33,   109,   148,    34,   171,   172,   313,   361,   349,   363,
     268,   325,   291,   330,   310,    44,    45,    96,   121,    65,
     101,   132,   275,   297,   106,   197,   142,   246,   143,   144,
     193,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,   194,   205,    95,   202,   226,   213,   245,   123,   224,
     124,    69,   169,    72,   278,   279,    37,   207,    38,   358,
      64,   195,    64,   179,   358,   284,   227,   287,    66,    40,
      64,    41,   370,   118,   120,   298,   236,   372,   359,   120,
     137,   115,   141,   288,   301,   122,   276,   196,   237,   208,
     219,    46,   118,   116,   117,    49,    71,   165,   127,    87,
     209,    39,   263,    50,   360,   126,   128,   129,    52,   360,
     133,    87,   174,   334,   321,   336,   181,    51,   218,   220,
     221,   222,    88,   203,   248,   249,   250,   251,   252,    47,
      48,    90,    91,    92,   177,   273,    94,   314,   264,   305,
     316,    88,    42,    66,   285,    64,    43,   352,   137,   282,
      90,    91,    92,    88,    97,    94,    67,   234,    98,   304,
      53,    89,    90,    91,    92,    93,   233,    94,   215,   216,
     241,   244,   141,   141,   338,   223,    87,   208,   200,   201,
     138,    68,   239,   323,    54,   160,    55,    56,   209,   161,
      88,    57,   139,    58,   324,   242,    59,    61,   320,    90,
      91,    92,   140,   137,    94,   174,    60,    62,   327,   328,
      63,   331,   198,   199,   200,   201,   274,    64,    88,   274,
     286,    73,    70,   293,    88,    74,   163,    90,    91,    92,
     164,    76,    94,    90,    91,    92,   240,    88,    94,    87,
      75,   355,    77,    78,    79,    88,    90,    91,    92,   243,
     295,    94,    80,    81,    90,    91,    92,   177,    87,    94,
     198,   199,   200,   201,   141,    88,   311,   309,    82,    83,
     274,    87,    84,   274,    90,    91,    92,   294,   104,    94,
      85,    88,   150,   151,   152,   153,   154,    99,   110,   100,
      90,    91,    92,   308,   102,    94,   103,   105,   107,   141,
      88,   111,   113,   343,   344,   311,   309,    66,   347,    90,
      91,    92,   346,    88,    94,   114,   118,   120,   125,   130,
     326,   131,    90,    91,    92,   134,   135,    94,   145,   146,
     147,   366,   149,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   156,   158,     2,   159,   166,   170,     3,     4,
     167,   168,   192,     5,     6,     7,     8,     9,    10,    11,
     182,   175,   206,    12,    13,    14,   180,   212,   214,   217,
     225,    15,    16,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   228,    17,   231,   235,   232,   238,   254,   255,
     256,   258,   192,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   260,   192,   261,   198,   199,   200,   201,   265,   266,
     267,   192,   270,   272,   280,   277,   281,   283,   289,   290,
     296,   299,   302,   303,   312,   306,   307,   317,   319,   318,
     315,   322,   329,   333,   332,   335,   339,   340,   350,   341,
     342,   323,   348,   353,    66,   357,   259,   362,   365,   367,
     368,   371,   292,   300,   211,   271,   269,   230,   204,   364,
     369,   253,   373,   354,   337,   351,   356,   345,   162,   247
};

static const yytype_int16 yycheck[] =
{
      64,   141,   148,    66,   144,   171,   158,   195,    93,   169,
      95,    43,   131,    45,   245,   246,     6,    16,     8,    10,
      18,    36,    18,   137,    10,   263,   172,    38,    16,     6,
      18,     8,   363,     9,    18,   276,    49,   368,    29,    18,
      16,    29,   105,    54,   282,    29,   242,    62,    61,    48,
      29,    70,     9,    85,    86,     3,    54,   120,    54,    16,
      59,    51,   214,    30,    55,    97,    98,    99,    70,    55,
     102,    16,   135,   314,   305,   316,   139,    32,   163,   164,
     165,   166,    58,   146,   198,   199,   200,   201,   202,     7,
       8,    67,    68,    69,    70,   235,    72,   293,   217,   287,
     296,    58,    66,    16,   264,    18,    70,   338,    16,   261,
      67,    68,    69,    58,    66,    72,    29,   180,    70,   285,
       3,    66,    67,    68,    69,    70,    17,    72,   160,   161,
     193,   194,   195,   196,   322,   167,    16,    48,    65,    66,
      48,    54,    16,    18,     3,    66,     3,     3,    59,    70,
      58,     3,    60,    40,    29,    16,    70,     8,   304,    67,
      68,    69,    70,    16,    72,   228,    70,    70,   308,   309,
      70,   311,    63,    64,    65,    66,   239,    18,    58,   242,
     265,     3,    32,    16,    58,     3,    66,    67,    68,    69,
      70,    70,    72,    67,    68,    69,    70,    58,    72,    16,
      32,   341,    70,    37,    41,    58,    67,    68,    69,    70,
     273,    72,    16,    38,    67,    68,    69,    70,    16,    72,
      63,    64,    65,    66,   287,    58,   290,   290,    70,     3,
     293,    16,     3,   296,    67,    68,    69,    70,    31,    72,
      70,    58,    22,    23,    24,    25,    26,    70,    72,    70,
      67,    68,    69,    70,    70,    72,    70,    33,    70,   322,
      58,    70,    70,   327,   328,   329,   329,    16,   331,    67,
      68,    69,    70,    58,    72,    38,     9,    18,    17,    54,
      29,    18,    67,    68,    69,     3,    16,    72,     3,    42,
      18,   355,    30,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    18,    16,     0,    70,    70,    52,     4,     5,
      70,    70,    61,     9,    10,    11,    12,    13,    14,    15,
      29,    18,     6,    19,    20,    21,    60,    17,    16,    32,
      53,    27,    28,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    18,    39,     3,    70,    29,    48,     3,    70,
      67,    58,    61,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     3,    61,    18,    63,    64,    65,    66,    70,    70,
      34,    61,    17,    70,     3,    29,    17,    17,    57,    35,
      18,    70,     3,    17,    56,    70,    70,    17,     3,    17,
      29,    38,    36,     3,    57,    70,    70,    70,    17,    70,
      70,    18,    70,    29,    16,    29,   211,    18,    70,    70,
      70,    17,   269,   281,   156,   230,   228,   175,   147,   351,
     362,   204,   369,   340,   320,   337,   345,   329,   119,   196
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    27,    28,    39,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    96,   103,   104,   107,   135,   136,     6,     8,    51,
       6,     8,    66,    70,   119,   120,    70,     7,     8,     3,
      30,    32,    70,     3,     3,     3,     3,     3,    40,    70,
      70,     8,    70,    70,    18,   123,    16,    29,    54,   123,
      32,    54,   123,     3,     3,    32,    70,    70,    37,    41,
      16,    38,    70,     3,     3,    70,   120,    16,    58,    66,
      67,    68,    69,    70,    72,   102,   121,    66,    70,    70,
      70,   124,    70,    70,    31,    33,   128,    70,    95,   105,
      72,    70,    90,    70,    38,    29,   123,   123,     9,   101,
      18,   122,    29,   122,   122,    17,   123,    54,   123,   123,
      54,    18,   125,   123,     3,    16,    98,    16,    48,    60,
      70,   102,   130,   132,   133,     3,    42,    18,   106,    30,
      22,    23,    24,    25,    26,    93,    18,    89,    16,    70,
      66,    70,   119,    66,    70,   102,    70,    70,    70,   124,
      52,   108,   109,   100,   102,    18,    97,    70,   102,   133,
      60,   102,    29,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    61,   134,   134,    36,    62,   129,    63,    64,
      65,    66,   134,   102,   105,   128,     6,    16,    48,    59,
      91,    90,    17,    95,    16,   123,   123,    32,   122,    29,
     122,   122,   122,   123,   125,    53,   109,   128,    18,    99,
      98,     3,    29,    17,   102,    70,    49,    61,    48,    16,
      70,   102,    16,    70,   102,   130,   131,   132,   133,   133,
     133,   133,   133,   106,     3,    70,    67,    92,    58,    89,
       3,    18,    94,    95,   124,    70,    70,    34,   114,   100,
      17,    97,    70,   134,   102,   126,   126,    29,   129,   129,
       3,    17,    95,    17,    94,   125,   122,    38,    54,    57,
      35,   116,    99,    16,    70,   102,    18,   127,   127,    70,
      91,    94,     3,    17,   109,   130,    70,    70,    70,   102,
     118,   120,    56,   110,   126,    29,   126,    17,    17,     3,
     128,   129,    38,    18,    29,   115,    29,   134,   134,    36,
     117,   134,    57,     3,   127,    70,   127,   114,   130,    70,
      70,    70,    70,   120,   120,   118,    70,   102,    70,   112,
      17,   116,   129,    29,   115,   134,   117,    29,    10,    29,
      55,   111,    18,   113,   110,    70,   120,    70,    70,   112,
     111,    17,   111,   113
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
     107,   108,   108,   109,   109,   110,   110,   111,   111,   111,
     112,   112,   113,   113,   114,   114,   114,   115,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   121,
     121,   121,   121,   121,   122,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   129,   130,   131,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   135,   136
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
      11,     6,     8,     0,     2,     0,     5,     0,     1,     1,
       2,     4,     0,     3,     0,     4,     6,     0,     2,     4,
       0,     3,     0,     3,     3,     3,     5,     3,     3,     5,
       2,     2,     4,     4,     2,     4,     6,     4,     4,     0,
       2,     4,     2,     2,     0,     3,     5,     3,     3,     0,
       3,     5,     5,     3,     1,     3,     0,     3,     0,     1,
       0,     3,     0,     3,     0,     3,     3,     1,     1,     2,
       3,     6,     8,     6,     3,     3,     3,     3,     5,     5,
       7,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     2,     8,     5
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
#line 1753 "yacc_sql.tab.c"
    break;

  case 23:
#line 220 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1761 "yacc_sql.tab.c"
    break;

  case 24:
#line 225 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1769 "yacc_sql.tab.c"
    break;

  case 25:
#line 231 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1777 "yacc_sql.tab.c"
    break;

  case 26:
#line 237 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1785 "yacc_sql.tab.c"
    break;

  case 27:
#line 243 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1793 "yacc_sql.tab.c"
    break;

  case 28:
#line 249 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1802 "yacc_sql.tab.c"
    break;

  case 29:
#line 255 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1810 "yacc_sql.tab.c"
    break;

  case 30:
#line 261 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1819 "yacc_sql.tab.c"
    break;

  case 31:
#line 269 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,0);
			CONTEXT->id_num=0;
		}
#line 1829 "yacc_sql.tab.c"
    break;

  case 32:
#line 275 "yacc_sql.y"
            {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,1);
			CONTEXT->id_num=0;
		}
#line 1839 "yacc_sql.tab.c"
    break;

  case 33:
#line 284 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1848 "yacc_sql.tab.c"
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
#line 1860 "yacc_sql.tab.c"
    break;

  case 36:
#line 301 "yacc_sql.y"
                                   {    }
#line 1866 "yacc_sql.tab.c"
    break;

  case 37:
#line 306 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, (yyvsp[-5].string), (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1877 "yacc_sql.tab.c"
    break;

  case 38:
#line 313 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,(yyvsp[-2].string), (yyvsp[-1].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1888 "yacc_sql.tab.c"
    break;

  case 39:
#line 320 "yacc_sql.y"
               {
	    (yyval.number)=0;
	 }
#line 1896 "yacc_sql.tab.c"
    break;

  case 40:
#line 323 "yacc_sql.y"
             {
		(yyval.number)=1;
	 }
#line 1904 "yacc_sql.tab.c"
    break;

  case 41:
#line 326 "yacc_sql.y"
                   {
		(yyval.number)=0;
	}
#line 1912 "yacc_sql.tab.c"
    break;

  case 42:
#line 330 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1918 "yacc_sql.tab.c"
    break;

  case 43:
#line 333 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1924 "yacc_sql.tab.c"
    break;

  case 44:
#line 334 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1930 "yacc_sql.tab.c"
    break;

  case 45:
#line 335 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1936 "yacc_sql.tab.c"
    break;

  case 46:
#line 336 "yacc_sql.y"
                    { (yyval.number)=DATES;}
#line 1942 "yacc_sql.tab.c"
    break;

  case 47:
#line 337 "yacc_sql.y"
                    { (yyval.number)=TEXTS;}
#line 1948 "yacc_sql.tab.c"
    break;

  case 49:
#line 341 "yacc_sql.y"
                        {
	 
   }
#line 1956 "yacc_sql.tab.c"
    break;

  case 50:
#line 346 "yacc_sql.y"
        {
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", (yyvsp[0].string));
		CONTEXT->id_num++;
	}
#line 1966 "yacc_sql.tab.c"
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
#line 1981 "yacc_sql.tab.c"
    break;

  case 53:
#line 368 "yacc_sql.y"
                                  {
  }
#line 1988 "yacc_sql.tab.c"
    break;

  case 54:
#line 372 "yacc_sql.y"
                                       {
	CONTEXT->insert_num++;
  }
#line 1996 "yacc_sql.tab.c"
    break;

  case 56:
#line 377 "yacc_sql.y"
                                     {
	  }
#line 2003 "yacc_sql.tab.c"
    break;

  case 57:
#line 381 "yacc_sql.y"
        {
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*(yyvsp[0].value1);
   }
#line 2011 "yacc_sql.tab.c"
    break;

  case 58:
#line 386 "yacc_sql.y"
         {
	parser_id++;
	CONTEXT->ssql=query_create();
}
#line 2020 "yacc_sql.tab.c"
    break;

  case 59:
#line 391 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2029 "yacc_sql.tab.c"
    break;

  case 60:
#line 395 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2038 "yacc_sql.tab.c"
    break;

  case 61:
#line 399 "yacc_sql.y"
         {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2048 "yacc_sql.tab.c"
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
#line 2060 "yacc_sql.tab.c"
    break;

  case 63:
#line 411 "yacc_sql.y"
               {
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 2069 "yacc_sql.tab.c"
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
#line 2089 "yacc_sql.tab.c"
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
#line 2101 "yacc_sql.tab.c"
    break;

  case 66:
#line 444 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,(yyvsp[-5].string),CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2112 "yacc_sql.tab.c"
    break;

  case 67:
#line 452 "yacc_sql.y"
                  {

}
#line 2120 "yacc_sql.tab.c"
    break;

  case 69:
#line 456 "yacc_sql.y"
                                  {

   }
#line 2128 "yacc_sql.tab.c"
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
	}
#line 2144 "yacc_sql.tab.c"
    break;

  case 71:
#line 474 "yacc_sql.y"
                                                     {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string), NULL);
   	}
#line 2152 "yacc_sql.tab.c"
    break;

  case 72:
#line 477 "yacc_sql.y"
                                                             {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string), (yyvsp[-3].string));
   	}
#line 2160 "yacc_sql.tab.c"
    break;

  case 74:
#line 483 "yacc_sql.y"
                              {
   }
#line 2167 "yacc_sql.tab.c"
    break;

  case 76:
#line 487 "yacc_sql.y"
                                                 {
		
	}
#line 2175 "yacc_sql.tab.c"
    break;

  case 77:
#line 491 "yacc_sql.y"
             {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
#line 2183 "yacc_sql.tab.c"
    break;

  case 78:
#line 494 "yacc_sql.y"
           {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
#line 2191 "yacc_sql.tab.c"
    break;

  case 79:
#line 497 "yacc_sql.y"
              {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
#line 2199 "yacc_sql.tab.c"
    break;

  case 80:
#line 502 "yacc_sql.y"
             { 
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
#line 2209 "yacc_sql.tab.c"
    break;

  case 81:
#line 507 "yacc_sql.y"
                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
#line 2219 "yacc_sql.tab.c"
    break;

  case 85:
#line 517 "yacc_sql.y"
                                    {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2229 "yacc_sql.tab.c"
    break;

  case 86:
#line 522 "yacc_sql.y"
                                           {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2239 "yacc_sql.tab.c"
    break;

  case 88:
#line 530 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2249 "yacc_sql.tab.c"
    break;

  case 89:
#line 535 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2259 "yacc_sql.tab.c"
    break;

  case 91:
#line 543 "yacc_sql.y"
                                                        {}
#line 2265 "yacc_sql.tab.c"
    break;

  case 93:
#line 546 "yacc_sql.y"
                                                     {}
#line 2271 "yacc_sql.tab.c"
    break;

  case 94:
#line 549 "yacc_sql.y"
                         {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2283 "yacc_sql.tab.c"
    break;

  case 95:
#line 556 "yacc_sql.y"
                            {
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2296 "yacc_sql.tab.c"
    break;

  case 96:
#line 564 "yacc_sql.y"
                                   {
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2309 "yacc_sql.tab.c"
    break;

  case 97:
#line 572 "yacc_sql.y"
                               {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2321 "yacc_sql.tab.c"
    break;

  case 98:
#line 579 "yacc_sql.y"
                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].function1));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2334 "yacc_sql.tab.c"
    break;

  case 99:
#line 587 "yacc_sql.y"
                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2347 "yacc_sql.tab.c"
    break;

  case 100:
#line 598 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2357 "yacc_sql.tab.c"
    break;

  case 101:
#line 603 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2367 "yacc_sql.tab.c"
    break;

  case 102:
#line 608 "yacc_sql.y"
                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2377 "yacc_sql.tab.c"
    break;

  case 103:
#line 613 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2387 "yacc_sql.tab.c"
    break;

  case 104:
#line 618 "yacc_sql.y"
                         {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2395 "yacc_sql.tab.c"
    break;

  case 105:
#line 621 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2405 "yacc_sql.tab.c"
    break;

  case 106:
#line 626 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2415 "yacc_sql.tab.c"
    break;

  case 107:
#line 631 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2423 "yacc_sql.tab.c"
    break;

  case 108:
#line 637 "yacc_sql.y"
                                       {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, (yyvsp[-3].string));
		CONTEXT->parameter_length = 0;
		(yyval.function1)=&CONTEXT->functions[CONTEXT->function_length-1];
	}
#line 2434 "yacc_sql.tab.c"
    break;

  case 110:
#line 646 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2444 "yacc_sql.tab.c"
    break;

  case 111:
#line 651 "yacc_sql.y"
                                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2454 "yacc_sql.tab.c"
    break;

  case 112:
#line 656 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2464 "yacc_sql.tab.c"
    break;

  case 113:
#line 661 "yacc_sql.y"
                                   {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}
#line 2473 "yacc_sql.tab.c"
    break;

  case 115:
#line 667 "yacc_sql.y"
                                      {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2483 "yacc_sql.tab.c"
    break;

  case 116:
#line 672 "yacc_sql.y"
                                             {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2493 "yacc_sql.tab.c"
    break;

  case 117:
#line 677 "yacc_sql.y"
                                        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2503 "yacc_sql.tab.c"
    break;

  case 118:
#line 682 "yacc_sql.y"
                                         {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}
#line 2512 "yacc_sql.tab.c"
    break;

  case 120:
#line 689 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
      }
#line 2522 "yacc_sql.tab.c"
    break;

  case 121:
#line 694 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
  	  }
#line 2532 "yacc_sql.tab.c"
    break;

  case 122:
#line 699 "yacc_sql.y"
                                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
	}
#line 2542 "yacc_sql.tab.c"
    break;

  case 123:
#line 704 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2550 "yacc_sql.tab.c"
    break;

  case 124:
#line 710 "yacc_sql.y"
      {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[0].string), NULL);
    }
#line 2558 "yacc_sql.tab.c"
    break;

  case 125:
#line 713 "yacc_sql.y"
              {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string), (yyvsp[0].string));
    }
#line 2566 "yacc_sql.tab.c"
    break;

  case 127:
#line 719 "yacc_sql.y"
                            {	
		  }
#line 2573 "yacc_sql.tab.c"
    break;

  case 129:
#line 723 "yacc_sql.y"
          {
	CONTEXT->in_value[CONTEXT->in_value_num++] = *(yyvsp[0].value1);
   }
#line 2581 "yacc_sql.tab.c"
    break;

  case 131:
#line 727 "yacc_sql.y"
                                 {
   }
#line 2588 "yacc_sql.tab.c"
    break;

  case 133:
#line 731 "yacc_sql.y"
                                         {	
			}
#line 2595 "yacc_sql.tab.c"
    break;

  case 135:
#line 736 "yacc_sql.y"
                                       {

	}
#line 2603 "yacc_sql.tab.c"
    break;

  case 136:
#line 739 "yacc_sql.y"
                                          {
	}
#line 2610 "yacc_sql.tab.c"
    break;

  case 137:
#line 743 "yacc_sql.y"
            {
	CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 0;
}
#line 2618 "yacc_sql.tab.c"
    break;

  case 138:
#line 747 "yacc_sql.y"
            {
     CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 1;
}
#line 2626 "yacc_sql.tab.c"
    break;

  case 139:
#line 751 "yacc_sql.y"
                      {
		CONTEXT->comp = EXISTS;

		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2640 "yacc_sql.tab.c"
    break;

  case 140:
#line 760 "yacc_sql.y"
                            {
		CONTEXT->comp = NOT_EXISTS;
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2652 "yacc_sql.tab.c"
    break;

  case 141:
#line 767 "yacc_sql.y"
                                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2666 "yacc_sql.tab.c"
    break;

  case 142:
#line 776 "yacc_sql.y"
                                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr,(yyvsp[-7].string), (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2680 "yacc_sql.tab.c"
    break;

  case 143:
#line 785 "yacc_sql.y"
                                                           {
		Value *left_value = (yyvsp[-5].value1);

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 0, NULL, left_value,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2693 "yacc_sql.tab.c"
    break;

  case 144:
#line 793 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;

	}
#line 2709 "yacc_sql.tab.c"
    break;

  case 145:
#line 805 "yacc_sql.y"
        {
		Value *left_value = (yyvsp[-2].value1);
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2722 "yacc_sql.tab.c"
    break;

  case 146:
#line 813 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2737 "yacc_sql.tab.c"
    break;

  case 147:
#line 824 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-2].value1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
		}
#line 2752 "yacc_sql.tab.c"
    break;

  case 148:
#line 835 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = (yyvsp[0].value1);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
							
    }
#line 2768 "yacc_sql.tab.c"
    break;

  case 149:
#line 847 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-4].value1);

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2784 "yacc_sql.tab.c"
    break;

  case 150:
#line 859 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2799 "yacc_sql.tab.c"
    break;

  case 151:
#line 869 "yacc_sql.y"
                                     {
		Value left_value;
		value_init_expression(&left_value,(yyvsp[-2].expr1));
		Value right_value;
		value_init_expression(&right_value,(yyvsp[0].expr1));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, &right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2813 "yacc_sql.tab.c"
    break;

  case 152:
#line 881 "yacc_sql.y"
               {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],0,NULL,(yyvsp[0].value1));
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 2822 "yacc_sql.tab.c"
    break;

  case 153:
#line 885 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr,(yyvsp[-2].string),(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 2833 "yacc_sql.tab.c"
    break;

  case 154:
#line 891 "yacc_sql.y"
              {
		RelAttr attr;
		relation_attr_init(&attr,NULL,(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 2844 "yacc_sql.tab.c"
    break;

  case 155:
#line 897 "yacc_sql.y"
                                   {
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 2852 "yacc_sql.tab.c"
    break;

  case 156:
#line 900 "yacc_sql.y"
                                     {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,MUL,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2863 "yacc_sql.tab.c"
    break;

  case 157:
#line 906 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,DIV,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2874 "yacc_sql.tab.c"
    break;

  case 158:
#line 912 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,ADD,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2885 "yacc_sql.tab.c"
    break;

  case 159:
#line 918 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,SUB,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 2896 "yacc_sql.tab.c"
    break;

  case 160:
#line 926 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2902 "yacc_sql.tab.c"
    break;

  case 161:
#line 927 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2908 "yacc_sql.tab.c"
    break;

  case 162:
#line 928 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2914 "yacc_sql.tab.c"
    break;

  case 163:
#line 929 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2920 "yacc_sql.tab.c"
    break;

  case 164:
#line 930 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2926 "yacc_sql.tab.c"
    break;

  case 165:
#line 931 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2932 "yacc_sql.tab.c"
    break;

  case 166:
#line 932 "yacc_sql.y"
                 {CONTEXT->comp = LIKE;}
#line 2938 "yacc_sql.tab.c"
    break;

  case 167:
#line 933 "yacc_sql.y"
                     {CONTEXT->comp = NOT_LIKE;}
#line 2944 "yacc_sql.tab.c"
    break;

  case 168:
#line 934 "yacc_sql.y"
               {CONTEXT->comp = IS;}
#line 2950 "yacc_sql.tab.c"
    break;

  case 169:
#line 935 "yacc_sql.y"
                  {CONTEXT->comp = IS_NOT;}
#line 2956 "yacc_sql.tab.c"
    break;

  case 170:
#line 936 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 2962 "yacc_sql.tab.c"
    break;

  case 171:
#line 937 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 2968 "yacc_sql.tab.c"
    break;

  case 172:
#line 942 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2977 "yacc_sql.tab.c"
    break;

  case 173:
#line 950 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
		}
#line 2986 "yacc_sql.tab.c"
    break;


#line 2990 "yacc_sql.tab.c"

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
#line 955 "yacc_sql.y"

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
