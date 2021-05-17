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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "proyecto.y"

#include <stdio.h>    
#include <string.h>
extern FILE  *yyin;

int yylex (void);
int yyerror(char *msg);

void showLine(int line);
void printOnError(char *err);
void dibujoArbol(int caso);

char *derivaciones[30];
int i = 0, ntries = 0; //ntries cuenta que ejemplo de entrada es.
int nlines = 0; //Este cuenta las lineas dentro de un ejemplo, para dar un mejor error
/*Las siguientes constantes sirven para saber que mostrar en el arbol*/
int confSecParag=0; //Sirve para saber si mostrar el conf-sec-paragraphs en el arbol de derivacion
char *envDivCont[10];
char *showInTree[5]; //Este es el que se corre en la funcion de mostrar arbol
int j = 0; //me sirve para poder ir acomodando los items en el array de showInTree

//Estos dos son para servir hacer toggle a mostrar las derivaciones
int env = 0, dat = 0; 

short int errorC = 0;

short int proneToShow = 1; /*Permite que no salte muchas veces un mensaje en errores reiterados
(como si fuera el yyerror que solo se llama una vez)*/

#line 100 "proyecto.tab.c"

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
#ifndef YY_YY_PROYECTO_TAB_H_INCLUDED
# define YY_YY_PROYECTO_TAB_H_INCLUDED
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
    ID = 258,
    TAB = 259,
    NL = 260,
    DOT = 261,
    ENVIROMENT = 262,
    DIVISION = 263,
    DATA = 264,
    SECTION = 265,
    CONFIGURATION = 266,
    FILEM = 267,
    CONTROL = 268,
    SOURCE = 269,
    COMPUTER = 270,
    OBJECT = 271,
    DESCRIPTION = 272,
    FD = 273
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "proyecto.y"

    int digitos;
    char *letras;

#line 176 "proyecto.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROYECTO_TAB_H_INCLUDED  */



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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

#define YYUNDEFTOK  2
#define YYMAXUTOK   273


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
      15,    16,    17,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    46,    48,    49,    80,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   121,   122,
     128,   136,   141,   142,   143,   144,   147,   148,   152,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   166,   167,
     173,   174,   175,   176,   179,   183,   184,   187,   191,   192,
     193,   194,   197,   200,   201,   202
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TAB", "NL", "DOT", "ENVIROMENT",
  "DIVISION", "DATA", "SECTION", "CONFIGURATION", "FILEM", "CONTROL",
  "SOURCE", "COMPUTER", "OBJECT", "DESCRIPTION", "FD", "$accept",
  "mi_axioma", "cobol-source-program", "enviroment-division-content",
  "configuration-section", "configuration-section-paragraphs",
  "data-division-content", "file-description-entry",
  "input-output-section", "file-control-entry", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273
};
# endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-39)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,    19,   -77,    37,    62,   104,   -77,    31,    51,     4,
      71,    75,   -77,   -77,    84,     6,    93,   102,   103,   112,
      38,   113,   -77,   102,   -77,    47,   114,   102,   102,   123,
     123,   123,    87,   115,    60,   -77,   -77,   -77,   140,    52,
       2,    19,   -77,   -77,   -77,    73,   -77,   -77,   -77,   148,
      54,    19,   -77,   142,    74,   154,   155,   157,    85,   158,
     124,   148,   159,   160,   125,   161,   162,   143,   164,   165,
     166,    78,   167,   168,   141,   169,   170,   171,   144,   172,
     173,   174,   175,   174,   174,   174,    30,   -77,   175,   175,
     175,    48,   -77,   176,   176,   176,   176,     8,   -77,   177,
     178,   -77,   -77,   -77,   -77,   -77,   147,    27,    35,   -77,
     -77,   -77,   179,   131,   -77,   -77,   -77,   -77,   181,    65,
      16,     5,   180,   182,   134,   183,   135,   185,   186,   146,
     -77,   -77,   187,     1,    94,   184,   190,   191,   153,   192,
     193,   156,   -77,   -77,   -77,   -77,   -77,   194,   195,   196,
     197,   137,   198,   199,   200,   138,   -77,   -77,   -77,   -77,
     -77,   174,   -77,   -77,   -77,   -77,   174,   -77,   -77
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     4,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     1,     3,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,    11,     8,     0,     0,
       0,    16,     5,    19,    20,     0,    12,    13,    14,    15,
       0,    17,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,    39,     0,
       0,    22,    48,    23,    24,    25,     0,     0,     0,    49,
      50,    51,     0,     0,    40,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    52,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,     0,    27,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,    -4,   106,   -77,   -71,    72,   -76,   -77,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,    26,    27,   101,    33,   114,    28,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,    13,    98,    59,   130,    16,   134,    22,   113,   118,
      17,    23,   103,   104,   105,    60,   122,   133,   115,   116,
     117,   -26,    42,   119,   115,    92,   119,     7,   123,    52,
     107,   106,   108,   102,   119,   -26,   125,    14,     8,    31,
     110,   111,   124,    32,   107,     9,   108,   -18,    38,   112,
     126,   113,   -18,    57,   -18,    63,   -18,    15,    39,    40,
     -18,    53,    58,    10,    64,   -18,   131,   -18,   132,   -18,
      11,    39,    54,   -38,    61,    66,    19,    18,   -38,    85,
     -38,    20,   -38,    86,    64,    50,    70,    60,    49,    21,
     167,    71,   -38,    36,   -38,   168,   -38,   130,    24,    50,
     127,    46,    47,    48,    12,     1,     1,    25,    29,     2,
       2,     3,     3,     4,     4,    41,    51,    30,    34,     2,
       2,     3,     3,     4,     4,    73,    77,    35,    45,    37,
      74,    78,   128,    43,    44,   137,   140,   129,   160,   165,
     138,   141,    90,   161,   166,    96,    91,   144,    81,    97,
      55,   145,    65,    56,   150,    56,   151,   154,    62,   155,
      67,    68,   122,    69,    72,    75,    76,    79,    80,    82,
      83,    84,    88,    89,    93,    94,    95,    99,   100,    86,
      91,    97,   120,   121,   130,   127,   135,   147,   136,   139,
     142,   143,   146,   148,   149,   152,   153,     0,     0,     0,
     156,   157,   158,   159,   162,   163,   164
};

static const yytype_int16 yycheck[] =
{
      71,     5,    78,     1,     3,     1,     1,     1,     3,     1,
       6,     5,    83,    84,    85,    13,    15,     1,    94,    95,
      96,     5,    26,    18,   100,    74,    18,     8,     1,    33,
      14,     1,    16,    82,    18,     5,     1,     6,     1,     1,
      89,    90,    15,     5,    14,     8,    16,     0,     1,     1,
      15,     3,     5,     1,     7,     1,     9,     6,    11,    12,
       0,     1,    10,     1,    10,     5,     1,     7,     3,     9,
       8,    11,    12,     0,     1,     1,     1,     6,     5,     1,
       7,     6,     9,     5,    10,    12,     1,    13,     1,     5,
     161,     6,     5,    21,     7,   166,     9,     3,     5,    12,
       6,    29,    30,    31,     0,     1,     1,     5,     5,     5,
       5,     7,     7,     9,     9,     1,     1,     5,     5,     5,
       5,     7,     7,     9,     9,     1,     1,    21,     5,    23,
       6,     6,     1,    27,    28,     1,     1,     6,     1,     1,
       6,     6,     1,     6,     6,     1,     5,     1,     5,     5,
      10,     5,    10,    13,     1,    13,     3,     1,    10,     3,
       6,     6,    15,     6,     6,     6,     6,     6,     6,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     3,     6,     6,     3,     6,     6,
       5,     5,     5,     3,     3,     3,     3,    -1,    -1,    -1,
       6,     6,     6,     6,     6,     6,     6
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,     7,     9,    20,    21,     8,     1,     8,
       1,     8,     0,    21,     6,     6,     1,     6,     6,     1,
       6,     5,     1,     5,     5,     5,    22,    23,    27,     5,
       5,     1,     5,    25,     5,    22,    25,    22,     1,    11,
      12,     1,    21,    22,    22,     5,    25,    25,    25,     1,
      12,     1,    21,     1,    12,    10,    13,     1,    10,     1,
      13,     1,    10,     1,    10,    10,     1,     6,     6,     6,
       1,     6,     6,     1,     6,     6,     6,     1,     6,     6,
       6,     5,     5,     5,     5,     1,     5,    24,     5,     5,
       1,     5,    28,     5,     5,     5,     1,     5,    26,     5,
       5,    24,    28,    24,    24,    24,     1,    14,    16,    28,
      28,    28,     1,     3,    26,    26,    26,    26,     1,    18,
       5,     5,    15,     1,    15,     1,    15,     6,     1,     6,
       3,     1,     3,     1,     1,     6,     6,     1,     6,     6,
       1,     6,     5,     5,     1,     5,     5,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     6,     6,     6,     6,
       1,     6,     6,     6,     6,     1,     6,    24,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    19,    20,    20,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    22,    22,
      22,    23,    23,    23,    23,    23,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    25,    25,
      25,    25,    25,    25,    26,    26,    26,    27,    27,    27,
      27,    27,    28,    28,    28,    28
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     5,     5,     5,     5,     4,
       4,     5,     5,     5,     5,     5,     5,     5,     1,     2,
       2,     5,     6,     6,     6,     6,     1,     7,     7,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     1,     5,
       6,     6,     6,     6,     4,     3,     3,     5,     6,     6,
       6,     6,     4,     4,     4,     4
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
      yychar = yylex ();
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
  case 4:
#line 48 "proyecto.y"
                        {derivaciones[i]="<cobol-source-program> ==> ' ' \n"; i++; env++; dat++;}
#line 1449 "proyecto.tab.c"
    break;

  case 5:
#line 49 "proyecto.y"
                                                                                               {     //Lo cargo fuera del if para hacerlo sin importar recursion
                                                                                derivaciones[i] = "\n<cobol-source-program> ==>  ENVIROMENT DIVISION DOT NL <enviroment-division-content> <cobol-source-program>\n";
                                                                                showInTree[j] = "\n\t ENVIROMENT DIVISION DOT NL <enviroment-division-content>";
                                                                                ++j;
                                                                                ++i;
                                                                                
                                                                                
                                                                                if( env >= 1 && errorC == 0){
                                                                                //Esto corre al final, por lo tanto lo pone al ultimo
                                                                                showInTree[j] = "\n\t <cobol-source-program>";
                                                                                printf("\n\n________________________\nDERIVACION EJEMPLO: %d   ESTADO: LINEA ACEPTADA\n",++ntries);
                                                                                /*Decrementa, porque esto se corre al final*/
                                                                                for(i; i>=0; i--){
                                                                                    printf("%s", derivaciones[i]);
                                                                                }
                                                                                
                                                                                
                                                                                /*Limpio los array para el proximo ejemplo*/
                                                                                for (i=0;i<30;i++){
                                                                                  derivaciones[i]="";
                                                                                }
                                                                                //Reseteo para el proximo ejemplo.
                                                                                nlines = 0;
                                                                                dibujoArbol(1);
                                                                                printf("\n________________________\n");
                                                                                printf("\n Nuevo itento: \n");
                                                                                env = 0;
                                                                                dat = 0;
                                                                                errorC = 0;
                                                                            }
                                                                           }
#line 1485 "proyecto.tab.c"
    break;

  case 6:
#line 80 "proyecto.y"
                                                                                   {
                                                                                //Lo cargo afuera, para que se cargue siempre (sin importar recursion)
                                                                                derivaciones[i] = "\n<cobol-source-program> ==>  DATA DIVISION DOT NL <data-division-content> <cobol-source-program>\n";
                                                                                showInTree[j] = "\n\t DATA DIVISION DOT NL <data-division-content>";
                                                                                ++j;
                                                                                i++;
                                                                                
                                                                                
                                                                                if( dat >= 1 && errorC == 0 ){
                                                                                //Esto corre al final, por lo tanto lo pone al ultimo
                                                                                showInTree[j] = "<cobol-source-program>";
                                                                                printf("\n\n________________________\nDERIVACION EJEMPLO: %d   ESTADO: LINEA ACEPTADA\n",++ntries);
                                                                                /*Decrementa, porque esto se corre al final*/
                                                                                for(i; i>=0; i--){
                                                                                    printf("%s", derivaciones[i]);
                                                                                }   
                                                                                
                                                                                /*Limpio los array para el proximo ejemplo*/
                                                                                for (i=0;i<30;i++){
                                                                                  derivaciones[i]="";
                                                                                }
                                                                                dibujoArbol(2);
                                                                                printf("\n________________________\n");
                                                                                printf("\n Nuevo itento: \n");
                                                                                dat = 0;
                                                                                env = 0;
                                                                                errorC = 0;
                                                                             }
                                                                            }
#line 1519 "proyecto.tab.c"
    break;

  case 7:
#line 109 "proyecto.y"
                                                                        {printOnError("Se esperaba 'ENVIROMENT' al iniciar la frase\n "); /*Si contemplo asi el error, no se para*/ errorC = 1;}
#line 1525 "proyecto.tab.c"
    break;

  case 8:
#line 110 "proyecto.y"
                                                                          {printOnError("Se esperaba 'DIVISION' en segundo lugar\n "); errorC = 1;}
#line 1531 "proyecto.tab.c"
    break;

  case 9:
#line 111 "proyecto.y"
                                                   {printOnError("Al definir el titular de env division content. Se esperaba un punto ( . ) en tercer lugar\n "); errorC = 1;}
#line 1537 "proyecto.tab.c"
    break;

  case 10:
#line 112 "proyecto.y"
                                                 {printOnError("Se esperaba un salto de linea para entrar poder contemplar el input de enviroment-division-content\n "); errorC = 1;}
#line 1543 "proyecto.tab.c"
    break;

  case 11:
#line 113 "proyecto.y"
                                                                  {printOnError("Se esperaba 'DATA' al iniciar la oracion \n"); errorC = 1;}
#line 1549 "proyecto.tab.c"
    break;

  case 12:
#line 114 "proyecto.y"
                                                              {printOnError("Se esperaba DIVISION en segundo lugar \n"); errorC = 1;}
#line 1555 "proyecto.tab.c"
    break;

  case 13:
#line 115 "proyecto.y"
                                                                   {printOnError("Al definir el titular de data division content. Se esperaba un punto ( . ) en tercer lugar\n"); errorC = 1;}
#line 1561 "proyecto.tab.c"
    break;

  case 14:
#line 116 "proyecto.y"
                                                                    {printOnError("Se esperaba un salto de linea para poder analizar data-division-content \n"); errorC = 1;}
#line 1567 "proyecto.tab.c"
    break;

  case 15:
#line 117 "proyecto.y"
                                                 {printOnError("Esta mal definido data-division-content. *REVISAR DOCUMENTACION* \n"); errorC = 1;}
#line 1573 "proyecto.tab.c"
    break;

  case 16:
#line 118 "proyecto.y"
                                                                                {printOnError("Error en la recursion de <cobol-source-program>"); errorC = 1;}
#line 1579 "proyecto.tab.c"
    break;

  case 17:
#line 119 "proyecto.y"
                                                                    {printOnError("Error en la recursion de <cobol-source-program>"); errorC = 1;}
#line 1585 "proyecto.tab.c"
    break;

  case 18:
#line 121 "proyecto.y"
                               {derivaciones[i] = "<enviroment-division-content> ==> NL\n"; i++; env = 1; dat = 0;}
#line 1591 "proyecto.tab.c"
    break;

  case 19:
#line 122 "proyecto.y"
                                                                             {/*Agrego al arbol el hijo de cobol-source-program*/
                                                    derivaciones[i]="<enviroment-division-content> ==> <configuration-section> NL <enviroment-division-content>\n";
                                                    i++;  
                                                    showInTree[j]="<configuration-section>"; 
                                                    j++;
                                                    env = 1;}
#line 1602 "proyecto.tab.c"
    break;

  case 20:
#line 128 "proyecto.y"
                                                                            {/*Igual que en el de arriba, pero si se llegase a esta*/
                                                    derivaciones[i]="<enviroment-division-content> ==> <input-output-section> NL <enviroment-division-content>\n";
                                                    i++; 
                                                    showInTree[j]="<input-output-section>";
                                                    j++;
                                                    dat = 1;}
#line 1613 "proyecto.tab.c"
    break;

  case 21:
#line 136 "proyecto.y"
                                                                                    {/*Misma dinamica con el arbol que arriba*/
                                                                                   derivaciones[i]="<configuration-section> ==> CONFIGURATION SECTION DOT NL <configuration-section-paragraphs> \n";
                                                                                    i++; 
                                                                                    showInTree[j]="CONFIGURATION SECTION DOT NL configuration-section-paragraphs";
                                                                                    j++;}
#line 1623 "proyecto.tab.c"
    break;

  case 22:
#line 141 "proyecto.y"
                                                                               {printOnError("Se esperaba el token CONFIGURATION en la primera posicion."); errorC = 1;}
#line 1629 "proyecto.tab.c"
    break;

  case 23:
#line 142 "proyecto.y"
                                                                                          {printOnError("Se esperaba el token SECTION en la segunda posicion."); errorC = 1;}
#line 1635 "proyecto.tab.c"
    break;

  case 24:
#line 143 "proyecto.y"
                                                                                          {printOnError("Se esperaba el token DOT (.) en la tercera posicion."); errorC = 1;}
#line 1641 "proyecto.tab.c"
    break;

  case 25:
#line 144 "proyecto.y"
                                                                                          {printOnError("Se esperaba el token  NL en la cuarta posicion."); errorC = 1;}
#line 1647 "proyecto.tab.c"
    break;

  case 26:
#line 147 "proyecto.y"
                                    {derivaciones[i] = "<configuration-section-paragraphs> ==> NL \n"; i++;}
#line 1653 "proyecto.tab.c"
    break;

  case 27:
#line 148 "proyecto.y"
                                                                                                {derivaciones[i]="<configuration-section-paragraphs> ==> SOURCE COMPUTER DOT ID DOT NL <configuration-section-paragraphs>\n";
                                         i++;  confSecParag=1; /*Si se cuple este o el de abajo, se muestra en el arbol de deriv*/
                                         showInTree[j]="SOURCE COMPUTER DOT ID DOT";
                                         }
#line 1662 "proyecto.tab.c"
    break;

  case 28:
#line 152 "proyecto.y"
                                                                                                {derivaciones[i]="<configuration-section-paragraphs> ==> OBJECT COMPUTER DOT ID DOT NL <configuration-section-paragraphs>\n";
                                         i++;  confSecParag=1;
                                         showInTree[j]="OBJECT COMPUTER DOT ID DOT";}
#line 1670 "proyecto.tab.c"
    break;

  case 29:
#line 155 "proyecto.y"
                                                              {printOnError("Se esperaba token SOURCE o OBJECT en configuration-section-paragraphs"); errorC = 1;}
#line 1676 "proyecto.tab.c"
    break;

  case 30:
#line 156 "proyecto.y"
                                                            {printOnError("Se esperaba token COMPUTER en configuration-section-paragraphs"); errorC = 1;}
#line 1682 "proyecto.tab.c"
    break;

  case 31:
#line 157 "proyecto.y"
                                                                 {printOnError("Se esperaba token DOT en configuration-section-paragraphs"); errorC = 1;}
#line 1688 "proyecto.tab.c"
    break;

  case 32:
#line 158 "proyecto.y"
                                                                  {printOnError("Se esperaba token ID en configuration-section-paragraphs"); errorC = 1;}
#line 1694 "proyecto.tab.c"
    break;

  case 33:
#line 159 "proyecto.y"
                                                                 {printOnError("Se esperaba token DOT en configuration-section-paragraphs"); errorC = 1;}
#line 1700 "proyecto.tab.c"
    break;

  case 34:
#line 160 "proyecto.y"
                                                            {printOnError("Se esperaba token COMPUTER en configuration-section-paragraphs"); errorC = 1;}
#line 1706 "proyecto.tab.c"
    break;

  case 35:
#line 161 "proyecto.y"
                                                                 {printOnError("Se esperaba token DOT en configuration-section-paragraphs"); errorC = 1;}
#line 1712 "proyecto.tab.c"
    break;

  case 36:
#line 162 "proyecto.y"
                                                                  {printOnError("Se esperaba token ID en configuration-section-paragraphs"); errorC = 1;}
#line 1718 "proyecto.tab.c"
    break;

  case 37:
#line 163 "proyecto.y"
                                                                 {printOnError("Se esperaba token DOT en configuration-section-paragraphs"); errorC = 1;}
#line 1724 "proyecto.tab.c"
    break;

  case 38:
#line 166 "proyecto.y"
                         {derivaciones[i]="<data-division-content> ==> NL \n"; i++;}
#line 1730 "proyecto.tab.c"
    break;

  case 39:
#line 167 "proyecto.y"
                                                                  {
                                                                derivaciones[i]="<data-division-content> ==> FILEM SECTION DOT NL <file-description-entry> \n";
                                                                i++; 
                                                                showInTree[j]="FILEM SECTION DOT NL <file-description-entry>";
                                                                j++;
                                                                }
#line 1741 "proyecto.tab.c"
    break;

  case 40:
#line 173 "proyecto.y"
                                                                     {printOnError("Se esperaba el token FILEM en la definicion de data-division-content"); errorC = 1;}
#line 1747 "proyecto.tab.c"
    break;

  case 41:
#line 174 "proyecto.y"
                                                                   {printOnError("Se esperaba el token SECTION en la definicion de data-division-content"); errorC = 1;}
#line 1753 "proyecto.tab.c"
    break;

  case 42:
#line 175 "proyecto.y"
                                                                       {printOnError("Se esperaba el token DOT en la definicion de data-division-content"); errorC = 1;}
#line 1759 "proyecto.tab.c"
    break;

  case 43:
#line 176 "proyecto.y"
                                                                        {printOnError("Se esperaba el token NL en la definicion de data-division-content"); errorC = 1;}
#line 1765 "proyecto.tab.c"
    break;

  case 44:
#line 179 "proyecto.y"
                                  {derivaciones[i]="<file-description-entry> ==> FILEM SECTION DOT NL FD ID \n";
                               i++; 
                               showInTree[j]="FD ID";
                               }
#line 1774 "proyecto.tab.c"
    break;

  case 45:
#line 183 "proyecto.y"
                                   {printOnError("Se esperaba el token FD en file-description-entry"); errorC = 1;}
#line 1780 "proyecto.tab.c"
    break;

  case 46:
#line 184 "proyecto.y"
                                   {printOnError("Se esperaba el token ID en file-description-entry"); errorC = 1;}
#line 1786 "proyecto.tab.c"
    break;

  case 47:
#line 187 "proyecto.y"
                                                             {derivaciones[i]="<input-output-section> ==> FILEM CONTROL DOT NL <file-control-entry> \n";
                                                                i++; 
                                                                showInTree[j]="FILEM CONTROL DOT NL <file-control-entry>";
                                                                j++;}
#line 1795 "proyecto.tab.c"
    break;

  case 48:
#line 191 "proyecto.y"
                                                                {printOnError("Se esperaba el token FILEM en input-output-section"); errorC = 1;}
#line 1801 "proyecto.tab.c"
    break;

  case 49:
#line 192 "proyecto.y"
                                                              {printOnError("Se esperaba el CONTROL en input-output-section");  errorC = 1;}
#line 1807 "proyecto.tab.c"
    break;

  case 50:
#line 193 "proyecto.y"
                                                                  {printOnError("Se esperaba el token DOT en input-output-section"); errorC = 1;}
#line 1813 "proyecto.tab.c"
    break;

  case 51:
#line 194 "proyecto.y"
                                                                   {printOnError("Se esperaba el token NL en input-output-section"); errorC = 1;}
#line 1819 "proyecto.tab.c"
    break;

  case 52:
#line 197 "proyecto.y"
                                {derivaciones[i]="<file-control-entry> ==> ID DOT ID \n";
                                         i++; 
                                         showInTree[j]="ID DOT ID";}
#line 1827 "proyecto.tab.c"
    break;

  case 53:
#line 200 "proyecto.y"
                                   {printOnError("Se esperaba token ID al definir file-control-entry");  errorC = 1;}
#line 1833 "proyecto.tab.c"
    break;

  case 54:
#line 201 "proyecto.y"
                                  {printOnError("Se esperaba token DOT al definir file-control-entry");  errorC = 1;}
#line 1839 "proyecto.tab.c"
    break;

  case 55:
#line 202 "proyecto.y"
                                   {printOnError("Se esperaba token NL al definir file-control-entry");  errorC = 1;}
#line 1845 "proyecto.tab.c"
    break;


#line 1849 "proyecto.tab.c"

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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 207 "proyecto.y"


void showLine(int line){
    printf("N linea: %d", line);
}

void printOnError(char *err){ 
    //Seteo para que sea mas facil pasar un mensaje de error, en los controlados
    printf("\033[0;31m "); //seteo a rojo para la palabra error
    printf("\n ERROR: ");
    //printf("\033[0;35m");
    printf("\033[0m "); //Vuelvo a blanco
    printf("%s \n", err);
}

int yyerror(char *msg){
    /*ESTA FUNCION SE LLAMA SIEMPRE QUE SURJA UN ERROR*/
    printf("\n Error encontrado!\n "); 
    //Ver si con esto logro lo de mostrar una sola vez mi mensaje personalizado
    proneToShow = 1;


}

int main(int argc, char **argv){
    
    if (argc > 1) yyin = fopen(argv[1], "rt\n ");
    else {
        yyin = stdin;
        printf("\n\nRecomiendo leer la documentacion para comprender como manejar los saltos de linea. \n");
        printf("Este analizador intenta emular codigo COBOL. Por lo que es importante considerarlos. \n");
        printf("----------------------------------------------------------\n\n");
        printf("Ingrese su cadena: \n");
        }

    
    yyparse();
    
    return 0;
}
int yywrap() {
	// EstadoScanner=2;
	
	return 1;
}

void dibujoArbol(int caso){
    printf("\t\n_____________-ARBOL DE DERIVACIONES-_____________ \n\n");
    
    for(j; j>=0; j--){
        printf("\t %s", showInTree[j]);
        printf("\n | \n");
    }

}
