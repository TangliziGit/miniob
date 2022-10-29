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
#define YYLAST   484

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  189
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  412

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
     461,   474,   477,   480,   485,   486,   489,   490,   494,   497,
     500,   505,   510,   516,   517,   519,   520,   525,   532,   533,
     538,   545,   546,   548,   549,   552,   559,   567,   575,   582,
     590,   601,   606,   611,   616,   621,   624,   629,   634,   637,
     642,   647,   650,   655,   660,   665,   673,   681,   682,   687,
     692,   697,   702,   703,   708,   713,   718,   723,   725,   730,
     735,   740,   743,   748,   753,   756,   761,   766,   772,   775,
     778,   783,   785,   788,   789,   792,   793,   795,   797,   800,
     802,   805,   809,   813,   817,   826,   833,   842,   851,   859,
     870,   879,   889,   900,   912,   924,   935,   946,   958,   962,
     968,   974,   977,   983,   989,   995,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1018,  1026
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

#define YYPACT_NINF (-279)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -279,   328,  -279,    33,   231,   -16,   -45,    15,    57,    44,
      20,    74,    82,   126,   164,   169,   170,   112,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,   109,   119,   174,
     125,   128,     3,    22,   172,    17,   198,   210,   190,  -279,
     156,   157,   196,  -279,  -279,  -279,  -279,  -279,   199,   227,
     208,   175,   256,   259,   193,   203,   248,  -279,   149,    64,
     215,   248,  -279,   216,   236,   248,  -279,  -279,  -279,   237,
     266,   278,   242,   243,   244,   257,   288,  -279,  -279,   127,
      70,   248,  -279,   307,  -279,   312,  -279,  -279,  -279,    -1,
    -279,   312,   314,    72,    96,   248,  -279,   -24,   316,   248,
    -279,   332,   329,   116,   343,  -279,   308,   333,   322,   246,
     336,   337,   296,    87,   298,   248,  -279,   299,   248,  -279,
    -279,  -279,   -16,   162,  -279,   300,  -279,  -279,  -279,   301,
     248,  -279,   302,   248,  -279,  -279,   303,  -279,   216,   323,
    -279,  -279,   241,   356,    49,   342,   241,   315,   344,   -18,
    -279,   335,  -279,   241,   242,   278,   389,  -279,  -279,  -279,
    -279,  -279,   176,   244,   380,   242,   387,   248,   133,   248,
    -279,   248,  -279,   372,   312,    27,   312,   312,   248,  -279,
     248,  -279,  -279,   316,   353,   323,   278,   390,  -279,   329,
     404,   381,  -279,   105,   241,  -279,   339,  -279,  -279,  -279,
    -279,  -279,  -279,    59,  -279,   363,  -279,   142,   180,   116,
     116,  -279,   186,   186,   186,   186,   186,  -279,   333,   409,
     345,   346,   358,  -279,  -279,   336,   411,   399,   242,  -279,
     348,   248,  -279,  -279,  -279,   216,  -279,   349,  -279,  -279,
    -279,  -279,  -279,  -279,   350,  -279,   388,   241,   406,   356,
    -279,   351,  -279,  -279,   344,  -279,  -279,  -279,    10,   395,
    -279,    10,   396,  -279,   -18,   -18,  -279,   -34,   -34,  -279,
    -279,   217,  -279,  -279,   423,  -279,   410,  -279,  -279,  -279,
     242,   412,   399,   248,  -279,   316,   312,   -11,   371,   397,
     390,  -279,  -279,  -279,   207,  -279,   413,   360,   413,   364,
    -279,  -279,  -279,     5,   399,   430,   418,  -279,   323,  -279,
     116,   366,   400,   367,   220,   383,  -279,    10,   414,  -279,
     241,   424,  -279,   425,  -279,  -279,  -279,  -279,   437,   278,
     -18,   407,   116,   120,   275,   344,   408,   344,   391,   443,
     413,   377,   413,  -279,  -279,  -279,   388,  -279,   116,   -18,
     379,   382,  -279,   384,   385,   385,   220,  -279,   226,   386,
    -279,   433,  -279,  -279,   397,   -18,  -279,   422,   435,   344,
     441,  -279,  -279,   408,   429,  -279,    26,   442,  -279,   383,
    -279,   392,  -279,   385,  -279,   393,  -279,   394,  -279,  -279,
     386,    56,   444,  -279,  -279,  -279,    56,   442,  -279,  -279,
    -279,  -279
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
       0,     0,   127,   127,     0,   127,     0,     0,     0,    24,
       0,     0,     0,    25,    26,    27,    23,    22,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   101,   117,     0,
       0,   127,   102,     0,     0,   127,   105,    30,    29,     0,
       0,   147,     0,     0,     0,     0,     0,    28,    33,   127,
     127,   127,   113,     0,    63,   122,    59,    60,    62,   122,
      61,   122,     0,   127,   127,   127,   109,   138,   141,   127,
     111,     0,     0,     0,     0,    50,     0,    68,     0,     0,
      35,     0,     0,     0,     0,   127,   128,     0,   127,   131,
     112,    58,     0,     0,   120,     0,   118,   121,   116,     0,
     127,   104,     0,   127,   103,   106,     0,   140,     0,    74,
     108,   189,     0,    52,     0,     0,     0,   170,   168,   149,
     152,     0,    65,     0,     0,   147,     0,    43,    44,    45,
      46,    47,    39,     0,     0,     0,     0,   127,   127,   127,
     135,   127,   137,     0,   122,   122,   122,   122,   127,   114,
     127,   110,   139,   141,     0,    74,   147,    55,    57,     0,
       0,   170,   168,     0,     0,   154,     0,   176,   177,   178,
     179,   180,   181,     0,   182,   184,   186,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,    67,    68,     0,
       0,     0,     0,    40,    38,    35,     0,    48,     0,   130,
       0,   127,   129,   132,   134,     0,   125,     0,   123,   126,
     119,   115,   107,   142,     0,    75,    85,     0,     0,    52,
      51,     0,   171,   155,   169,   183,   187,   185,   143,   161,
     159,   143,   162,   160,   149,   149,   153,   174,   175,   173,
     172,   167,    69,    66,     0,    42,     0,    41,    36,    34,
       0,     0,    48,   127,   136,   141,   122,     0,     0,    91,
      55,    54,    53,   169,     0,   144,   145,     0,   145,     0,
     150,   151,   188,    39,    48,     0,     0,   133,    74,   124,
       0,     0,     0,     0,     0,    76,    56,   143,     0,   163,
     143,     0,   166,     0,   164,    37,    49,    31,     0,   147,
     149,     0,     0,    88,     0,     0,    93,     0,     0,     0,
     145,     0,   145,   156,   158,    32,    85,    71,     0,   149,
       0,     0,    86,     0,     0,     0,     0,    92,     0,     0,
      70,     0,   165,   146,    91,   149,    73,    89,    88,     0,
       0,    99,    98,    93,    96,    95,    78,    83,   157,    76,
      72,     0,    87,     0,    94,     0,    79,     0,    80,    81,
       0,    78,     0,    90,   100,    97,    78,    83,    77,    64,
      82,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,   224,   292,   153,  -279,  -279,
    -272,  -163,  -279,   209,   268,   171,   212,  -279,   -63,  -279,
    -279,   306,   245,  -279,  -279,  -193,    83,  -278,    75,    67,
     121,    98,   104,    97,   113,   352,   -64,  -279,   -90,   -42,
    -132,  -183,  -258,  -175,  -159,  -260,  -211,  -279,   261,  -120,
    -154,  -279,  -279
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   174,   120,   234,   286,   172,
     291,   116,    31,   200,   153,   258,   197,   132,   158,    32,
      33,   117,   165,    34,   195,   196,   349,   399,   387,   401,
     299,   362,   325,   367,   346,    44,    45,   102,   134,    67,
     108,   149,   306,   331,   114,   221,   159,   275,   160,   161,
     217,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    72,   255,    76,   218,   101,   229,   226,   274,   136,
     253,   137,   237,   308,   310,   311,   193,   133,   219,   131,
     316,    64,    47,    48,    92,    46,    93,   320,   135,   106,
     146,   224,   225,   110,   203,    64,   396,   256,    68,    37,
      64,    38,   336,   321,   220,   133,   147,   126,   129,   130,
      42,    69,    51,   232,    43,   397,   247,    65,   131,   322,
      49,   141,   144,   145,   233,   154,   396,   150,    94,   350,
     186,    74,   352,    66,    50,   292,    70,    96,    97,    98,
     357,   398,   100,   180,    39,    53,   182,    75,    64,   198,
      64,   202,    71,   205,   246,   248,   249,   250,   189,   376,
     227,   191,   277,   278,   279,   280,   281,    94,   265,   340,
     304,   398,   318,   295,    64,   390,    96,    97,    98,   201,
     266,   100,   262,   408,   127,   339,   139,   314,   410,    54,
     103,   359,   154,   333,   104,   239,   242,   243,   360,   244,
     128,   263,   140,    68,    52,    64,   251,   375,   252,   361,
     142,    64,    58,   177,   270,   273,   123,   178,   268,   202,
     202,   202,   202,   202,   155,    93,   143,    55,   222,   223,
     224,   225,    56,    57,    94,   371,   156,   373,    93,    59,
     356,   124,    61,    96,    97,    98,   157,   240,   100,    60,
     364,   365,   231,   368,   198,    62,   271,   125,    63,   294,
      94,    77,   154,   241,    73,   305,   319,    94,   305,    96,
      97,    98,   269,    78,   100,    95,    96,    97,    98,    99,
      94,   100,    79,   327,   232,   393,    80,    81,   184,    96,
      97,    98,   185,    82,   100,   233,    93,    40,    94,    41,
      83,   329,    93,    84,    94,    86,    85,    96,    97,    98,
     272,   317,   100,    96,    97,    98,   201,    93,   100,    87,
     347,   345,    88,    89,   305,    94,    64,   305,   167,   168,
     169,   170,   171,    91,    96,    97,    98,   328,    94,   100,
     222,   223,   224,   225,    94,   105,   107,    96,    97,    98,
     344,    68,   100,    96,    97,    98,   384,   112,   100,    94,
     381,   382,   347,   345,   363,   385,   109,   111,    96,    97,
      98,   113,   115,   100,   119,   118,   131,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   122,   121,     2,   404,
     133,   138,     3,     4,   148,   151,   216,     5,     6,     7,
       8,     9,    10,    11,   206,   152,   162,    12,    13,    14,
     163,   164,   166,   175,   173,    15,    16,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   176,    17,   179,   181,
     187,   188,   190,   192,   199,   194,   216,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   230,   216,   236,   222,   223,
     224,   225,   204,   238,   245,   216,   254,   260,   257,   264,
     261,   267,   283,   285,   289,   284,   287,   290,   293,   296,
     297,   303,   298,   301,   307,   309,   312,   313,   323,   315,
     332,   330,   324,   337,   334,   338,   341,   343,   342,   348,
     355,   353,   354,   351,   366,   358,   370,   372,   369,   377,
     388,   391,   378,   360,   379,   380,   386,    68,   395,   288,
     400,   409,   403,   405,   406,   235,   335,   259,   302,   300,
     228,   326,   402,   282,   411,   407,   392,   374,   389,   383,
     394,   276,     0,     0,   183
};

static const yytype_int16 yycheck[] =
{
      64,    43,   195,    45,   158,    68,   165,   161,   219,    99,
     193,   101,   175,   271,   274,   275,   148,    18,    36,     9,
     292,    18,     7,     8,    66,    70,    16,    38,    29,    71,
      54,    65,    66,    75,   154,    18,    10,   196,    16,     6,
      18,     8,   314,    54,    62,    18,    70,    89,    90,    91,
      66,    29,    32,    48,    70,    29,    29,    54,     9,    70,
       3,   103,   104,   105,    59,    16,    10,   109,    58,   327,
     133,    54,   330,    70,    30,   238,    54,    67,    68,    69,
     340,    55,    72,   125,    51,     3,   128,    70,    18,   152,
      18,   154,    70,   156,   184,   185,   186,   187,   140,   359,
     163,   143,   222,   223,   224,   225,   226,    58,    49,   320,
     264,    55,   295,   245,    18,   375,    67,    68,    69,    70,
      61,    72,    17,   401,    54,   318,    54,   290,   406,     3,
      66,   342,    16,   308,    70,   177,   178,   179,    18,   181,
      70,   204,    70,    16,    70,    18,   188,   358,   190,    29,
      54,    18,    40,    66,   217,   218,    29,    70,    16,   222,
     223,   224,   225,   226,    48,    16,    70,     3,    63,    64,
      65,    66,     3,     3,    58,   350,    60,   352,    16,    70,
     339,    54,     8,    67,    68,    69,    70,    54,    72,    70,
     344,   345,    16,   347,   257,    70,    16,    70,    70,   241,
      58,     3,    16,    70,    32,   268,   296,    58,   271,    67,
      68,    69,    70,     3,    72,    66,    67,    68,    69,    70,
      58,    72,    32,    16,    48,   379,    70,    70,    66,    67,
      68,    69,    70,    37,    72,    59,    16,     6,    58,     8,
      41,   304,    16,    16,    58,    70,    38,    67,    68,    69,
      70,   293,    72,    67,    68,    69,    70,    16,    72,     3,
     324,   324,     3,    70,   327,    58,    18,   330,    22,    23,
      24,    25,    26,    70,    67,    68,    69,    70,    58,    72,
      63,    64,    65,    66,    58,    70,    70,    67,    68,    69,
      70,    16,    72,    67,    68,    69,    70,    31,    72,    58,
     364,   365,   366,   366,    29,   368,    70,    70,    67,    68,
      69,    33,    70,    72,    70,    72,     9,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    38,    70,     0,   393,
      18,    17,     4,     5,    18,     3,    61,     9,    10,    11,
      12,    13,    14,    15,    29,    16,     3,    19,    20,    21,
      42,    18,    30,    16,    18,    27,    28,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    70,    39,    70,    70,
      70,    70,    70,    70,    18,    52,    61,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     6,    61,    17,    63,    64,
      65,    66,    60,    16,    32,    61,    53,     3,    18,    70,
      29,    48,     3,    67,     3,    70,    58,    18,    70,    70,
      70,    70,    34,    17,    29,    29,     3,    17,    57,    17,
      70,    18,    35,     3,    70,    17,    70,    70,    38,    56,
       3,    17,    17,    29,    36,    38,     3,    70,    57,    70,
      17,    29,    70,    18,    70,    70,    70,    16,    29,   235,
      18,    17,    70,    70,    70,   173,   313,   199,   259,   257,
     164,   300,   389,   228,   407,   400,   378,   356,   374,   366,
     383,   220,    -1,    -1,   132
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
      70,     8,    70,    70,    18,    54,    70,   123,    16,    29,
      54,    70,   123,    32,    54,    70,   123,     3,     3,    32,
      70,    70,    37,    41,    16,    38,    70,     3,     3,    70,
     120,    70,   123,    16,    58,    66,    67,    68,    69,    70,
      72,   102,   121,    66,    70,    70,   123,    70,   124,    70,
     123,    70,    31,    33,   128,    70,    95,   105,    72,    70,
      90,    70,    38,    29,    54,    70,   123,    54,    70,   123,
     123,     9,   101,    18,   122,    29,   122,   122,    17,    54,
      70,   123,    54,    70,   123,   123,    54,    70,    18,   125,
     123,     3,    16,    98,    16,    48,    60,    70,   102,   130,
     132,   133,     3,    42,    18,   106,    30,    22,    23,    24,
      25,    26,    93,    18,    89,    16,    70,    66,    70,    70,
     123,    70,   123,   119,    66,    70,   102,    70,    70,   123,
      70,   123,    70,   124,    52,   108,   109,   100,   102,    18,
      97,    70,   102,   133,    60,   102,    29,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    61,   134,   134,    36,
      62,   129,    63,    64,    65,    66,   134,   102,   105,   128,
       6,    16,    48,    59,    91,    90,    17,    95,    16,   123,
      54,    70,   123,   123,   123,    32,   122,    29,   122,   122,
     122,   123,   123,   125,    53,   109,   128,    18,    99,    98,
       3,    29,    17,   102,    70,    49,    61,    48,    16,    70,
     102,    16,    70,   102,   130,   131,   132,   133,   133,   133,
     133,   133,   106,     3,    70,    67,    92,    58,    89,     3,
      18,    94,    95,    70,   123,   124,    70,    70,    34,   114,
     100,    17,    97,    70,   134,   102,   126,    29,   126,    29,
     129,   129,     3,    17,    95,    17,    94,   123,   125,   122,
      38,    54,    70,    57,    35,   116,    99,    16,    70,   102,
      18,   127,    70,   127,    70,    91,    94,     3,    17,   109,
     130,    70,    38,    70,    70,   102,   118,   120,    56,   110,
     126,    29,   126,    17,    17,     3,   128,   129,    38,   130,
      18,    29,   115,    29,   134,   134,    36,   117,   134,    57,
       3,   127,    70,   127,   114,   130,   129,    70,    70,    70,
      70,   120,   120,   118,    70,   102,    70,   112,    17,   116,
     129,    29,   115,   134,   117,    29,    10,    29,    55,   111,
      18,   113,   110,    70,   120,    70,    70,   112,   111,    17,
     111,   113
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
     107,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   115,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   120,   121,   121,   121,
     121,   121,   122,   122,   122,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   129,   130,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   133,   133,
     133,   133,   133,   133,   133,   133,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   135,   136
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
      11,     6,     8,     7,     0,     2,     0,     5,     0,     1,
       1,     2,     4,     0,     3,     0,     4,     6,     0,     2,
       4,     0,     3,     0,     3,     3,     3,     5,     3,     3,
       5,     2,     2,     4,     4,     2,     4,     6,     4,     3,
       5,     3,     4,     3,     5,     6,     4,     0,     2,     4,
       2,     2,     0,     3,     5,     3,     3,     0,     3,     5,
       5,     3,     5,     7,     5,     4,     6,     4,     1,     3,
       2,     0,     3,     0,     1,     0,     3,     0,     3,     0,
       3,     3,     1,     1,     2,     3,     6,     8,     6,     3,
       3,     3,     3,     5,     5,     7,     5,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     2,     8,     5
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
#line 1778 "yacc_sql.tab.c"
    break;

  case 23:
#line 220 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1786 "yacc_sql.tab.c"
    break;

  case 24:
#line 225 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1794 "yacc_sql.tab.c"
    break;

  case 25:
#line 231 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1802 "yacc_sql.tab.c"
    break;

  case 26:
#line 237 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1810 "yacc_sql.tab.c"
    break;

  case 27:
#line 243 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1818 "yacc_sql.tab.c"
    break;

  case 28:
#line 249 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1827 "yacc_sql.tab.c"
    break;

  case 29:
#line 255 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1835 "yacc_sql.tab.c"
    break;

  case 30:
#line 261 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1844 "yacc_sql.tab.c"
    break;

  case 31:
#line 269 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,0);
			CONTEXT->id_num=0;
		}
#line 1854 "yacc_sql.tab.c"
    break;

  case 32:
#line 275 "yacc_sql.y"
            {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), CONTEXT->id_num,CONTEXT->id,1);
			CONTEXT->id_num=0;
		}
#line 1864 "yacc_sql.tab.c"
    break;

  case 33:
#line 284 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1873 "yacc_sql.tab.c"
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
#line 1885 "yacc_sql.tab.c"
    break;

  case 36:
#line 301 "yacc_sql.y"
                                   {    }
#line 1891 "yacc_sql.tab.c"
    break;

  case 37:
#line 306 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, (yyvsp[-5].string), (yyvsp[-4].number), (yyvsp[-2].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1902 "yacc_sql.tab.c"
    break;

  case 38:
#line 313 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,(yyvsp[-2].string), (yyvsp[-1].number),(yyvsp[0].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1913 "yacc_sql.tab.c"
    break;

  case 39:
#line 320 "yacc_sql.y"
               {
	    (yyval.number)=0;
	 }
#line 1921 "yacc_sql.tab.c"
    break;

  case 40:
#line 323 "yacc_sql.y"
             {
		(yyval.number)=1;
	 }
#line 1929 "yacc_sql.tab.c"
    break;

  case 41:
#line 326 "yacc_sql.y"
                   {
		(yyval.number)=0;
	}
#line 1937 "yacc_sql.tab.c"
    break;

  case 42:
#line 330 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1943 "yacc_sql.tab.c"
    break;

  case 43:
#line 333 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1949 "yacc_sql.tab.c"
    break;

  case 44:
#line 334 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1955 "yacc_sql.tab.c"
    break;

  case 45:
#line 335 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1961 "yacc_sql.tab.c"
    break;

  case 46:
#line 336 "yacc_sql.y"
                    { (yyval.number)=DATES;}
#line 1967 "yacc_sql.tab.c"
    break;

  case 47:
#line 337 "yacc_sql.y"
                    { (yyval.number)=TEXTS;}
#line 1973 "yacc_sql.tab.c"
    break;

  case 49:
#line 341 "yacc_sql.y"
                        {
	 
   }
#line 1981 "yacc_sql.tab.c"
    break;

  case 50:
#line 346 "yacc_sql.y"
        {
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", (yyvsp[0].string));
		CONTEXT->id_num++;
	}
#line 1991 "yacc_sql.tab.c"
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
#line 2006 "yacc_sql.tab.c"
    break;

  case 53:
#line 368 "yacc_sql.y"
                                  {
  }
#line 2013 "yacc_sql.tab.c"
    break;

  case 54:
#line 372 "yacc_sql.y"
                                       {
	CONTEXT->insert_num++;
  }
#line 2021 "yacc_sql.tab.c"
    break;

  case 56:
#line 377 "yacc_sql.y"
                                     {
	  }
#line 2028 "yacc_sql.tab.c"
    break;

  case 57:
#line 381 "yacc_sql.y"
        {
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*(yyvsp[0].value1);
   }
#line 2036 "yacc_sql.tab.c"
    break;

  case 58:
#line 386 "yacc_sql.y"
         {
	parser_id++;
	CONTEXT->ssql=query_create();
}
#line 2045 "yacc_sql.tab.c"
    break;

  case 59:
#line 391 "yacc_sql.y"
          {
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2054 "yacc_sql.tab.c"
    break;

  case 60:
#line 395 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2063 "yacc_sql.tab.c"
    break;

  case 61:
#line 399 "yacc_sql.y"
         {
		(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
		}
#line 2073 "yacc_sql.tab.c"
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
#line 2085 "yacc_sql.tab.c"
    break;

  case 63:
#line 411 "yacc_sql.y"
               {
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		(yyval.value1)=&CONTEXT->values[CONTEXT->value_length-1];
	}
#line 2094 "yacc_sql.tab.c"
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
#line 2114 "yacc_sql.tab.c"
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
#line 2126 "yacc_sql.tab.c"
    break;

  case 66:
#line 444 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,(yyvsp[-5].string),CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2137 "yacc_sql.tab.c"
    break;

  case 67:
#line 452 "yacc_sql.y"
                  {

}
#line 2145 "yacc_sql.tab.c"
    break;

  case 69:
#line 456 "yacc_sql.y"
                                  {

   }
#line 2153 "yacc_sql.tab.c"
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
#line 2169 "yacc_sql.tab.c"
    break;

  case 71:
#line 474 "yacc_sql.y"
                                                     {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string), NULL);
   	}
#line 2177 "yacc_sql.tab.c"
    break;

  case 72:
#line 477 "yacc_sql.y"
                                                             {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string), (yyvsp[-3].string));
   	}
#line 2185 "yacc_sql.tab.c"
    break;

  case 73:
#line 480 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string), (yyvsp[-3].string));
   	}
#line 2193 "yacc_sql.tab.c"
    break;

  case 75:
#line 486 "yacc_sql.y"
                              {
   }
#line 2200 "yacc_sql.tab.c"
    break;

  case 77:
#line 490 "yacc_sql.y"
                                                 {
		
	}
#line 2208 "yacc_sql.tab.c"
    break;

  case 78:
#line 494 "yacc_sql.y"
             {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
#line 2216 "yacc_sql.tab.c"
    break;

  case 79:
#line 497 "yacc_sql.y"
           {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
#line 2224 "yacc_sql.tab.c"
    break;

  case 80:
#line 500 "yacc_sql.y"
              {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
#line 2232 "yacc_sql.tab.c"
    break;

  case 81:
#line 505 "yacc_sql.y"
             { 
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
#line 2242 "yacc_sql.tab.c"
    break;

  case 82:
#line 510 "yacc_sql.y"
                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
#line 2252 "yacc_sql.tab.c"
    break;

  case 86:
#line 520 "yacc_sql.y"
                                    {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2262 "yacc_sql.tab.c"
    break;

  case 87:
#line 525 "yacc_sql.y"
                                           {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2272 "yacc_sql.tab.c"
    break;

  case 89:
#line 533 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2282 "yacc_sql.tab.c"
    break;

  case 90:
#line 538 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
#line 2292 "yacc_sql.tab.c"
    break;

  case 92:
#line 546 "yacc_sql.y"
                                                        {}
#line 2298 "yacc_sql.tab.c"
    break;

  case 94:
#line 549 "yacc_sql.y"
                                                     {}
#line 2304 "yacc_sql.tab.c"
    break;

  case 95:
#line 552 "yacc_sql.y"
                         {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2316 "yacc_sql.tab.c"
    break;

  case 96:
#line 559 "yacc_sql.y"
                            {
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-2].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2329 "yacc_sql.tab.c"
    break;

  case 97:
#line 567 "yacc_sql.y"
                                   {
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, (yyvsp[-4].function1), NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2342 "yacc_sql.tab.c"
    break;

  case 98:
#line 575 "yacc_sql.y"
                               {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2354 "yacc_sql.tab.c"
    break;

  case 99:
#line 582 "yacc_sql.y"
                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].function1));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2367 "yacc_sql.tab.c"
    break;

  case 100:
#line 590 "yacc_sql.y"
                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, (yyvsp[0].function1), NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
#line 2380 "yacc_sql.tab.c"
    break;

  case 101:
#line 601 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2390 "yacc_sql.tab.c"
    break;

  case 102:
#line 606 "yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2400 "yacc_sql.tab.c"
    break;

  case 103:
#line 611 "yacc_sql.y"
                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2410 "yacc_sql.tab.c"
    break;

  case 104:
#line 616 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2420 "yacc_sql.tab.c"
    break;

  case 105:
#line 621 "yacc_sql.y"
                         {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2428 "yacc_sql.tab.c"
    break;

  case 106:
#line 624 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2438 "yacc_sql.tab.c"
    break;

  case 107:
#line 629 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2448 "yacc_sql.tab.c"
    break;

  case 108:
#line 634 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2456 "yacc_sql.tab.c"
    break;

  case 109:
#line 637 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2466 "yacc_sql.tab.c"
    break;

  case 110:
#line 642 "yacc_sql.y"
                             {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2476 "yacc_sql.tab.c"
    break;

  case 111:
#line 647 "yacc_sql.y"
                            {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2484 "yacc_sql.tab.c"
    break;

  case 112:
#line 650 "yacc_sql.y"
                           {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2494 "yacc_sql.tab.c"
    break;

  case 113:
#line 655 "yacc_sql.y"
                        {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2504 "yacc_sql.tab.c"
    break;

  case 114:
#line 660 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2514 "yacc_sql.tab.c"
    break;

  case 115:
#line 665 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2524 "yacc_sql.tab.c"
    break;

  case 116:
#line 673 "yacc_sql.y"
                                       {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, (yyvsp[-3].string));
		CONTEXT->parameter_length = 0;
		(yyval.function1)=&CONTEXT->functions[CONTEXT->function_length-1];
	}
#line 2535 "yacc_sql.tab.c"
    break;

  case 118:
#line 682 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2545 "yacc_sql.tab.c"
    break;

  case 119:
#line 687 "yacc_sql.y"
                                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2555 "yacc_sql.tab.c"
    break;

  case 120:
#line 692 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2565 "yacc_sql.tab.c"
    break;

  case 121:
#line 697 "yacc_sql.y"
                                   {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}
#line 2574 "yacc_sql.tab.c"
    break;

  case 123:
#line 703 "yacc_sql.y"
                                      {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2584 "yacc_sql.tab.c"
    break;

  case 124:
#line 708 "yacc_sql.y"
                                             {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2594 "yacc_sql.tab.c"
    break;

  case 125:
#line 713 "yacc_sql.y"
                                        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
#line 2604 "yacc_sql.tab.c"
    break;

  case 126:
#line 718 "yacc_sql.y"
                                         {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}
#line 2613 "yacc_sql.tab.c"
    break;

  case 128:
#line 725 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2623 "yacc_sql.tab.c"
    break;

  case 129:
#line 730 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2633 "yacc_sql.tab.c"
    break;

  case 130:
#line 735 "yacc_sql.y"
                                 {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
#line 2643 "yacc_sql.tab.c"
    break;

  case 131:
#line 740 "yacc_sql.y"
                               {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].function1), NULL);
    }
#line 2651 "yacc_sql.tab.c"
    break;

  case 132:
#line 743 "yacc_sql.y"
                               {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2661 "yacc_sql.tab.c"
    break;

  case 133:
#line 748 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2671 "yacc_sql.tab.c"
    break;

  case 134:
#line 753 "yacc_sql.y"
                                     {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].function1), (yyvsp[-1].string));
    }
#line 2679 "yacc_sql.tab.c"
    break;

  case 135:
#line 756 "yacc_sql.y"
                            {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2689 "yacc_sql.tab.c"
    break;

  case 136:
#line 761 "yacc_sql.y"
                                   {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, (yyvsp[-1].string));
    }
#line 2699 "yacc_sql.tab.c"
    break;

  case 137:
#line 766 "yacc_sql.y"
                                  {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].function1), (yyvsp[-1].string));
    }
#line 2707 "yacc_sql.tab.c"
    break;

  case 138:
#line 772 "yacc_sql.y"
      {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[0].string), NULL);
    }
#line 2715 "yacc_sql.tab.c"
    break;

  case 139:
#line 775 "yacc_sql.y"
               {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string), (yyvsp[0].string));
    }
#line 2723 "yacc_sql.tab.c"
    break;

  case 140:
#line 778 "yacc_sql.y"
            {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string), (yyvsp[0].string));
    }
#line 2731 "yacc_sql.tab.c"
    break;

  case 142:
#line 785 "yacc_sql.y"
                            {	
		  }
#line 2738 "yacc_sql.tab.c"
    break;

  case 144:
#line 789 "yacc_sql.y"
          {
	CONTEXT->in_value[CONTEXT->in_value_num++] = *(yyvsp[0].value1);
   }
#line 2746 "yacc_sql.tab.c"
    break;

  case 146:
#line 793 "yacc_sql.y"
                                 {
   }
#line 2753 "yacc_sql.tab.c"
    break;

  case 148:
#line 797 "yacc_sql.y"
                                         {	
			}
#line 2760 "yacc_sql.tab.c"
    break;

  case 150:
#line 802 "yacc_sql.y"
                                       {

	}
#line 2768 "yacc_sql.tab.c"
    break;

  case 151:
#line 805 "yacc_sql.y"
                                          {
	}
#line 2775 "yacc_sql.tab.c"
    break;

  case 152:
#line 809 "yacc_sql.y"
            {
	CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 0;
}
#line 2783 "yacc_sql.tab.c"
    break;

  case 153:
#line 813 "yacc_sql.y"
            {
     CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 1;
}
#line 2791 "yacc_sql.tab.c"
    break;

  case 154:
#line 817 "yacc_sql.y"
                      {
		CONTEXT->comp = EXISTS;

		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2805 "yacc_sql.tab.c"
    break;

  case 155:
#line 826 "yacc_sql.y"
                            {
		CONTEXT->comp = NOT_EXISTS;
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2817 "yacc_sql.tab.c"
    break;

  case 156:
#line 833 "yacc_sql.y"
                                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2831 "yacc_sql.tab.c"
    break;

  case 157:
#line 842 "yacc_sql.y"
                                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr,(yyvsp[-7].string), (yyvsp[-5].string));

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2845 "yacc_sql.tab.c"
    break;

  case 158:
#line 851 "yacc_sql.y"
                                                           {
		Value *left_value = (yyvsp[-5].value1);

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 0, NULL, left_value,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
#line 2858 "yacc_sql.tab.c"
    break;

  case 159:
#line 859 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;

	}
#line 2874 "yacc_sql.tab.c"
    break;

  case 160:
#line 871 "yacc_sql.y"
        {
		Value *left_value = (yyvsp[-2].value1);
		Value *right_value = (yyvsp[0].value1);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2887 "yacc_sql.tab.c"
    break;

  case 161:
#line 879 "yacc_sql.y"
                     {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2902 "yacc_sql.tab.c"
    break;

  case 162:
#line 890 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-2].value1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
		}
#line 2917 "yacc_sql.tab.c"
    break;

  case 163:
#line 901 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = (yyvsp[0].value1);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
							
    }
#line 2933 "yacc_sql.tab.c"
    break;

  case 164:
#line 913 "yacc_sql.y"
                {
			Value *left_value = (yyvsp[-4].value1);

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2949 "yacc_sql.tab.c"
    break;

  case 165:
#line 925 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2964 "yacc_sql.tab.c"
    break;

  case 166:
#line 936 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2979 "yacc_sql.tab.c"
    break;

  case 167:
#line 946 "yacc_sql.y"
                                     {
		Value left_value;
		value_init_expression(&left_value,(yyvsp[-2].expr1));
		Value right_value;
		value_init_expression(&right_value,(yyvsp[0].expr1));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, &right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2993 "yacc_sql.tab.c"
    break;

  case 168:
#line 958 "yacc_sql.y"
               {
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],0,NULL,(yyvsp[0].value1));
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3002 "yacc_sql.tab.c"
    break;

  case 169:
#line 962 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr,(yyvsp[-2].string),(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3013 "yacc_sql.tab.c"
    break;

  case 170:
#line 968 "yacc_sql.y"
              {
		RelAttr attr;
		relation_attr_init(&attr,NULL,(yyvsp[0].string));
		init_expression(&CONTEXT->expr[CONTEXT->expr_num++],1,&attr,NULL);
		(yyval.expr1)=&CONTEXT->expr[CONTEXT->expr_num-1];
	 }
#line 3024 "yacc_sql.tab.c"
    break;

  case 171:
#line 974 "yacc_sql.y"
                                   {
		(yyval.expr1)=(yyvsp[-1].expr1);
	 }
#line 3032 "yacc_sql.tab.c"
    break;

  case 172:
#line 977 "yacc_sql.y"
                                     {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,MUL,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 3043 "yacc_sql.tab.c"
    break;

  case 173:
#line 983 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,DIV,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 3054 "yacc_sql.tab.c"
    break;

  case 174:
#line 989 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,ADD,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 3065 "yacc_sql.tab.c"
    break;

  case 175:
#line 995 "yacc_sql.y"
                                      {
        Expr* left_expr = (yyvsp[-2].expr1);
		Expr* right_expr = (yyvsp[0].expr1);
		append_expression(left_expr,SUB,right_expr);
		(yyval.expr1)=left_expr;
	 }
#line 3076 "yacc_sql.tab.c"
    break;

  case 176:
#line 1003 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3082 "yacc_sql.tab.c"
    break;

  case 177:
#line 1004 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3088 "yacc_sql.tab.c"
    break;

  case 178:
#line 1005 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3094 "yacc_sql.tab.c"
    break;

  case 179:
#line 1006 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3100 "yacc_sql.tab.c"
    break;

  case 180:
#line 1007 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3106 "yacc_sql.tab.c"
    break;

  case 181:
#line 1008 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3112 "yacc_sql.tab.c"
    break;

  case 182:
#line 1009 "yacc_sql.y"
                 {CONTEXT->comp = LIKE;}
#line 3118 "yacc_sql.tab.c"
    break;

  case 183:
#line 1010 "yacc_sql.y"
                     {CONTEXT->comp = NOT_LIKE;}
#line 3124 "yacc_sql.tab.c"
    break;

  case 184:
#line 1011 "yacc_sql.y"
               {CONTEXT->comp = IS;}
#line 3130 "yacc_sql.tab.c"
    break;

  case 185:
#line 1012 "yacc_sql.y"
                  {CONTEXT->comp = IS_NOT;}
#line 3136 "yacc_sql.tab.c"
    break;

  case 186:
#line 1013 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 3142 "yacc_sql.tab.c"
    break;

  case 187:
#line 1014 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 3148 "yacc_sql.tab.c"
    break;

  case 188:
#line 1019 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3157 "yacc_sql.tab.c"
    break;

  case 189:
#line 1027 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
		}
#line 3166 "yacc_sql.tab.c"
    break;


#line 3170 "yacc_sql.tab.c"

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
#line 1032 "yacc_sql.y"

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
