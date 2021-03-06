/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <iostream>
#include<string>
#include <cstring>
#include <cstdlib>
using namespace std;
extern int yylex();
extern int yylineno;
void yyerror (const char* s) {
  cout<<s<<"in line:"<<yylineno<<endl;
}

// -----------------------------------
typedef struct A{
  char label[25];
  int id;
  struct A *next;
  struct B *right;
}A;
typedef struct B
{
  int id;
  struct B *next;
}B;
int searchResult,nodeId=1,temp1,temp2,temp3,temp4,temp5,temp6,temp7;
A* headA = NULL;
A* tailA = NULL;
void printGraph(A* headA){
  cout<<"strict graph G {\n";
  A* temp = headA;
  while(temp!=NULL){
    cout<<temp->id<<" [label=\""<<temp->label<<"\"];"<<endl;
    temp=temp->next;
  }
  temp = headA;
  B* helper;
  while(temp!=NULL){
    if(temp->right!=NULL){
      helper = temp->right;
      cout<<temp->id<<"--";
      while(helper!=NULL){
        if(helper->next!=NULL)
          cout<<helper->id<<", ";
        else
          cout<<helper->id<<" ";
        helper = helper->next;
      }
      cout<<";"<<endl;
    }
    temp = temp->next;
  }
  cout<<"\n}\n";
}
int addNodeA(int id,char* label,A** tailA,A** headA){
  A* temp = (A*)malloc(sizeof(A));
  temp->next = NULL;
  temp->right = NULL;
  temp->id = id;
  strcpy(temp->label,label);
  if((*tailA)!=NULL){
    (*tailA)->next = temp;
  }
  (*tailA) = temp;
  if((*headA)==NULL)(*headA) = (*tailA);
  return id;
}
int findNode(int id,A* headA){
  A* temp = headA;
  while(temp!=NULL){
    if(temp->id==id)return 1;
    temp = temp->next;
  }
  return 0;
}
// makeChild to be called only if both parent and child are already created in the graph
void makeChild(int parent,int child,A* headA){
  A* p=headA;
  B* temp;
  if(p==NULL)return;
  int flagC = 0;
  while(p!=NULL){
    if(p->id==parent)break;
    p = p->next;
  }
  if(p==NULL)return;
  B* c = p->right;
  while(1){
    if(c!=NULL){
      if(c->next==NULL) break;
      else{
        c = c->next;
      }
    }
    else{
      flagC = 1;
      break;
    }
  }
  temp = (B*)malloc(sizeof(B));
  temp->next = NULL;
  temp->id = child;
  if(flagC==0){
    //there is at least one neighbour of the parent
    c->next = temp;
  }
  else{
    p->right = temp;
  }

}

// ----------------------------------






#line 185 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,
    O_BRAC = 259,
    C_BRAC = 260,
    OPEN_BRAC = 261,
    CLOSE_BRAC = 262,
    MAIN = 263,
    THEN = 264,
    PERCENT = 265,
    ENDIF = 266,
    NUM = 267,
    SEMICOLON = 268,
    COLON = 269,
    DOT = 270,
    AMPERSAN = 271,
    PRECENT = 272,
    BACKSLASH = 273,
    ELSE = 274,
    SCAN = 275,
    PRINT = 276,
    INT = 277,
    CHAR = 278,
    FLOAT = 279,
    WHILE = 280,
    GOTO = 281,
    SWITCH = 282,
    VOID = 283,
    BREAK = 284,
    CASE = 285,
    CONTINUE = 286,
    RETURN = 287,
    COMMA = 288,
    LETTER = 289,
    NUMBER = 290,
    INTEGER = 291,
    FLOATING_INT = 292,
    IDENTIFIER = 293,
    Obrac = 294,
    Cbrac = 295,
    EQUALS = 296,
    NOT = 297,
    DO = 298,
    FOR = 299,
    OR = 300,
    EQEQ = 301,
    NEQ = 302,
    G_THAN = 303,
    L_THAN = 304,
    G_EQ = 305,
    L_EQ = 306,
    AND = 307,
    PLUS = 308,
    MINUS = 309,
    MULTIPLY = 310,
    DIVIDE = 311
  };
#endif
/* Tokens.  */
#define IF 258
#define O_BRAC 259
#define C_BRAC 260
#define OPEN_BRAC 261
#define CLOSE_BRAC 262
#define MAIN 263
#define THEN 264
#define PERCENT 265
#define ENDIF 266
#define NUM 267
#define SEMICOLON 268
#define COLON 269
#define DOT 270
#define AMPERSAN 271
#define PRECENT 272
#define BACKSLASH 273
#define ELSE 274
#define SCAN 275
#define PRINT 276
#define INT 277
#define CHAR 278
#define FLOAT 279
#define WHILE 280
#define GOTO 281
#define SWITCH 282
#define VOID 283
#define BREAK 284
#define CASE 285
#define CONTINUE 286
#define RETURN 287
#define COMMA 288
#define LETTER 289
#define NUMBER 290
#define INTEGER 291
#define FLOATING_INT 292
#define IDENTIFIER 293
#define Obrac 294
#define Cbrac 295
#define EQUALS 296
#define NOT 297
#define DO 298
#define FOR 299
#define OR 300
#define EQEQ 301
#define NEQ 302
#define G_THAN 303
#define L_THAN 304
#define G_EQ 305
#define L_EQ 306
#define AND 307
#define PLUS 308
#define MINUS 309
#define MULTIPLY 310
#define DIVIDE 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 121 "parser.y" /* yacc.c:355  */

  struct{
  char val[25];
  int nodeId;
  }value;

#line 344 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 361 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   156,   165,   171,   180,   201,   221,   229,
     239,   250,   254,   258,   264,   276,   285,   294,   304,   315,
     328,   342,   355,   370,   377,   386,   401,   409,   415,   429,
     437,   448,   456,   464,   472,   478,   484,   493,   509,   532,
     539,   547,   567,   587,   593,   601,   609,   618,   635,   646,
     657,   668,   682,   690,   703,   711,   722,   728,   738,   748,
     758,   773,   779,   789,   805,   811,   821,   831,   841,   854,
     860,   870,   883,   889,   902,   908,   921,   931,   947,   964,
     988,  1006
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "O_BRAC", "C_BRAC", "OPEN_BRAC",
  "CLOSE_BRAC", "MAIN", "THEN", "PERCENT", "ENDIF", "NUM", "SEMICOLON",
  "COLON", "DOT", "AMPERSAN", "PRECENT", "BACKSLASH", "ELSE", "SCAN",
  "PRINT", "INT", "CHAR", "FLOAT", "WHILE", "GOTO", "SWITCH", "VOID",
  "BREAK", "CASE", "CONTINUE", "RETURN", "COMMA", "LETTER", "NUMBER",
  "INTEGER", "FLOATING_INT", "IDENTIFIER", "Obrac", "Cbrac", "EQUALS",
  "NOT", "DO", "FOR", "OR", "EQEQ", "NEQ", "G_THAN", "L_THAN", "G_EQ",
  "L_EQ", "AND", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "$accept",
  "main_unit", "func_decls", "main_decl", "func_decl", "type_spec",
  "empty", "param_list", "param_decl", "decl_spec", "declarator", "body",
  "compound_stmt", "decl_list", "declare", "init_decl_list", "declarators",
  "stmt_list", "stmt", "if_stmt", "func_call_stmt", "with_return",
  "without_return", "call_param_list", "empty_param_list",
  "non_empty_param_list", "jump_stmt", "expr_stmt", "primary_expr",
  "mul_expr", "add_expr", "relational_expr", "equality_expr",
  "log_and_expr", "log_or_expr", "assgn_expr", "iterate_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -69,   -69,   -69,    33,     0,   -69,   -69,    32,   -69,
     -69,   -69,    38,    70,   -69,     0,    39,   -69,   -69,    40,
     -69,    41,    75,    75,     0,   -69,   -69,   107,   -69,   -69,
     -69,   -69,    79,   -69,   -69,   -69,    88,    85,    94,    12,
     101,   182,   108,    41,   -69,   134,   -69,    59,   -69,   -69,
     -69,   -69,   -69,   -69,    80,   102,   -69,    25,    25,   -69,
     -69,    25,   -69,   -69,    -2,   -69,    55,    74,    87,    71,
       4,    93,   129,    73,   122,   145,   -69,   -69,   -69,   161,
     -69,   -69,    26,   -69,     6,    10,    14,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,   -69,
      25,   -69,   -69,    43,   -69,   -69,   156,    22,   102,    41,
     -69,   -69,   157,   -69,   124,    75,   182,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,    95,    95,    95,    74,    74,    87,
      71,   158,   132,    25,   170,     2,    23,   -69,    93,   163,
     -69,   -69,   -69,    16,   182,    63,    62,    75,   174,   -69,
     171,   176,   -69,   -69,   182,   -69,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     8,     0,     0,     3,     4,     0,     1,
       2,     5,     0,     0,    11,    11,     0,    16,    12,     0,
      13,     0,     0,     0,     0,    17,    15,     0,     6,    18,
       7,    14,     0,    19,    55,    52,     0,     0,     0,     0,
      54,     0,     0,     0,    31,     0,    23,     0,    29,    36,
      34,    40,    35,    32,     0,    39,    33,     0,     0,    49,
      48,     0,    50,    54,    56,    61,    64,    69,    72,    74,
       0,    11,     0,     0,    27,     0,    26,    21,    24,     0,
      20,    30,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,    46,    45,     0,    43,    44,     0,     0,     0,     0,
      25,    22,    54,    77,    76,     0,     0,    60,    59,    57,
      58,    65,    62,    63,    66,    68,    67,    70,    71,    73,
      75,     0,     0,     0,     0,    56,     0,    28,    11,    37,
      78,    42,    47,     0,     0,     0,     0,     0,     0,    80,
       0,     0,    38,    79,     0,    41,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   186,   191,    27,   138,   -69,   173,    42,
     177,   -19,   -21,   -69,   155,   -69,    97,   164,   -38,   -69,
     -69,   -69,   -69,    64,   -69,   -69,   -69,   -60,   -27,    92,
      49,     3,   103,   110,   -51,   -68,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    17,   102,    19,    20,    21,
      74,    28,    44,    45,    46,    75,    76,    47,    48,    49,
      50,   113,    51,   103,   104,   105,    52,    53,    64,    65,
      66,    67,    68,    69,    70,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      54,    29,    29,    72,    30,   108,    84,    85,    87,    81,
      86,   115,    87,   107,    54,   116,    61,    99,    54,   117,
      54,   148,     1,     2,    34,    62,    61,     8,     3,    61,
      61,   114,     8,     9,    34,    35,   145,    34,    34,   108,
      12,    81,    14,    82,    22,    23,    54,   134,   131,   100,
      63,   100,    54,    88,    89,   100,   136,    88,    89,   100,
      63,   100,    32,    63,   112,    27,    80,   151,   100,    43,
      13,    34,    35,    24,    15,    34,   132,   150,   140,    25,
     135,    27,   143,    57,    36,    34,    35,    43,    37,    54,
      38,    39,    58,   121,    29,   132,   139,    40,    59,   127,
     128,    63,    41,    42,    90,    71,   149,    60,    91,    92,
      32,    63,    73,    27,    33,    83,   156,    54,    54,    34,
      35,    82,    93,    98,    94,    95,    29,    54,   152,     1,
       2,   101,    36,    96,    97,     3,    37,    32,    38,    39,
      27,    77,   124,   125,   126,    40,    34,    35,    91,    92,
      41,    42,    16,    18,   106,   109,     1,     2,   110,    36,
     133,   138,     3,    37,    32,    38,    39,    27,   111,   100,
     142,   141,    40,    34,    35,   144,   154,    41,    42,   118,
     119,   120,   147,   122,   123,    32,    36,   153,    27,   155,
      37,    10,    38,    39,    34,    35,    11,    31,    26,    40,
      78,   129,   146,     0,    41,    42,   137,    36,     0,    79,
     130,    37,     0,    38,    39,     0,     0,     0,     0,     0,
      40,     0,     0,     0,     0,    41,    42
};

static const yytype_int16 yycheck[] =
{
      27,    22,    23,    41,    23,    73,    57,    58,    10,    47,
      61,     5,    10,    73,    41,     5,     4,    13,    45,     5,
      47,     5,    22,    23,    12,    13,     4,     0,    28,     4,
       4,    82,     5,     0,    12,    13,    13,    12,    12,   107,
       8,    79,     4,    41,     5,     5,    73,   107,     5,    45,
      38,    45,    79,    55,    56,    45,   107,    55,    56,    45,
      38,    45,     3,    38,    38,     6,     7,     5,    45,    27,
      38,    12,    13,    33,     4,    12,    33,   145,   116,    38,
     107,     6,   133,     4,    25,    12,    13,    45,    29,   116,
      31,    32,     4,    90,   115,    33,   115,    38,    13,    96,
      97,    38,    43,    44,    49,     4,   144,    13,    53,    54,
       3,    38,     4,     6,     7,    13,   154,   144,   145,    12,
      13,    41,    48,    52,    50,    51,   147,   154,   147,    22,
      23,    38,    25,    46,    47,    28,    29,     3,    31,    32,
       6,     7,    93,    94,    95,    38,    12,    13,    53,    54,
      43,    44,    14,    15,    25,    33,    22,    23,    13,    25,
       4,     4,    28,    29,     3,    31,    32,     6,     7,    45,
      38,    13,    38,    12,    13,     5,     5,    43,    44,    87,
      88,    89,    19,    91,    92,     3,    25,    13,     6,    13,
      29,     5,    31,    32,    12,    13,     5,    24,    21,    38,
      45,    98,   138,    -1,    43,    44,   109,    25,    -1,    45,
     100,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    23,    28,    58,    59,    60,    61,    62,     0,
      60,    61,     8,    38,     4,     4,    63,    62,    63,    64,
      65,    66,     5,     5,    33,    38,    67,     6,    68,    69,
      68,    65,     3,     7,    12,    13,    25,    29,    31,    32,
      38,    43,    44,    66,    69,    70,    71,    74,    75,    76,
      77,    79,    83,    84,    85,    92,    93,     4,     4,    13,
      13,     4,    13,    38,    85,    86,    87,    88,    89,    90,
      91,     4,    75,     4,    67,    72,    73,     7,    71,    74,
       7,    75,    41,    13,    91,    91,    91,    10,    55,    56,
      49,    53,    54,    48,    50,    51,    46,    47,    52,    13,
      45,    38,    63,    80,    81,    82,    25,    84,    92,    33,
      13,     7,    38,    78,    91,     5,     5,     5,    86,    86,
      86,    88,    86,    86,    87,    87,    87,    88,    88,    89,
      90,     5,    33,     4,    84,    85,    91,    73,     4,    68,
      75,    13,    38,    91,     5,    13,    80,    19,     5,    75,
      92,     5,    68,    13,     5,    13,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    60,    61,    62,    62,
      62,    63,    64,    64,    64,    65,    66,    67,    68,    69,
      69,    69,    69,    70,    70,    71,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    79,    80,    80,    81,    82,    82,    83,    83,
      83,    83,    84,    84,    85,    85,    86,    86,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     6,     6,     1,     1,
       1,     0,     1,     1,     3,     2,     1,     1,     1,     2,
       3,     3,     4,     1,     2,     3,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     5,     7,     1,
       1,     5,     5,     1,     1,     1,     1,     3,     2,     2,
       2,     3,     1,     2,     1,     1,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     3,     3,     5,     7,
       6,     8
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 149 "parser.y" /* yacc.c:1646  */
    {
                  //cout<<"1 ";
                  temp2 = addNodeA(nodeId++,strdup("main_unit"),&tailA,&headA);
                  (yyval.value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 156 "parser.y" /* yacc.c:1646  */
    {
                  //cout<<"71 ";
                  temp1 = addNodeA(nodeId++,strdup("main_unit"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

      }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 165 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"43 ";
                  temp1 = addNodeA(nodeId++,strdup("func_decls"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 171 "parser.y" /* yacc.c:1646  */
    {
                  //cout<<"45 ";
                  temp1 = addNodeA(nodeId++,strdup("func_decls"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 181 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"3 ";
                  temp1 = addNodeA(nodeId++,strdup("MAIN"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("main_decl"),&tailA,&headA);
                  (yyval.value).nodeId = temp4;
                  (yyvsp[-4].value).nodeId = temp1;
                  (yyvsp[-3].value).nodeId = temp2;
                  (yyvsp[-1].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-5].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

      }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 201 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"47 ";
                  temp1 = addNodeA(nodeId++,strdup("func_decl"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-4].value).nodeId = temp2;
                  (yyvsp[-3].value).nodeId = temp3;
                  (yyvsp[-1].value).nodeId = temp4;
                  makeChild((yyval.value).nodeId,(yyvsp[-5].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

      }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 221 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"11 ";
                  temp1 = addNodeA(nodeId++,strdup("type_spec"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("VOID"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[0].value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 229 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"6 ";
                  temp1 = addNodeA(nodeId++,strdup("type_spec"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("INT"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[0].value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


      }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 239 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"15 ";
                  temp1 = addNodeA(nodeId++,strdup("type_spec"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("CHAR"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[0].value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 250 "parser.y" /* yacc.c:1646  */
    {;}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 254 "parser.y" /* yacc.c:1646  */
    {  //  cout<<"69 ";
                    temp1= addNodeA(nodeId++,strdup("param_list"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
        }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 258 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"49 ";
                  temp1 = addNodeA(nodeId++,strdup("param_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 264 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"51 ";
                  temp1 = addNodeA(nodeId++,strdup("param_list"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("COMMA"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-1].value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 276 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"53 ";
                  temp1 = addNodeA(nodeId++,strdup("param_decl"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 285 "parser.y" /* yacc.c:1646  */
    {
               // cout<<"55 ";
                temp1 = addNodeA(nodeId++,strdup("decl_spec"),&tailA,&headA);
                (yyval.value).nodeId = temp1;
                makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 294 "parser.y" /* yacc.c:1646  */
    {
              //  cout<<"57 ";
                temp1 = addNodeA(nodeId++,strdup("declarator"),&tailA,&headA);
                temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                (yyval.value).nodeId = temp1;
                (yyvsp[0].value).nodeId = temp2;
                makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 304 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"4 ";
                  temp1 = addNodeA(nodeId++,strdup("body"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


      }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 315 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"5 ";
                  temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-1].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

      }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 328 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"17 ";
                  temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-2].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

      }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 342 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"85 ";
                  temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-2].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

      }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 355 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"87 ";
                  temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-3].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 370 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"73 ";
                  temp1 = addNodeA(nodeId++,strdup("decl_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

      }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 377 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"75 ";
                  temp1 = addNodeA(nodeId++,strdup("decl_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 386 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"77 ";
                  temp1 = addNodeA(nodeId++,strdup("declare"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[0].value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);



      }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 401 "parser.y" /* yacc.c:1646  */
    {
              //  cout<< "79 ";
                temp1 = addNodeA(nodeId++,strdup("init_decl_list"),&tailA,&headA);
                (yyval.value).nodeId = temp1;
                makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 409 "parser.y" /* yacc.c:1646  */
    {
               // cout<< "81 ";
                temp1 = addNodeA(nodeId++,strdup("declarators"),&tailA,&headA);
                (yyval.value).nodeId = temp1;
                makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 415 "parser.y" /* yacc.c:1646  */
    {
               // cout<<"83 ";
                temp1 = addNodeA(nodeId++,strdup("declarators"),&tailA,&headA);
                temp2 = addNodeA(nodeId++,strdup("COMMA"),&tailA,&headA);
                (yyval.value).nodeId = temp1;
                (yyvsp[-1].value).nodeId = temp2;
                makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


      }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 429 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"19 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


                  }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 437 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"21 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


                  }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 448 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"23 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


                  }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 456 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"25 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


                  }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 464 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"27 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


                  }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 472 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"91 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
         }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 478 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"59 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
                  }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 484 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"68 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
                  }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 493 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"72";
                  temp1 = addNodeA(nodeId++,strdup("if_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IF"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-4].value).nodeId = temp2;
                  (yyvsp[-3].value).nodeId = temp3;
                  (yyvsp[-1].value).nodeId = temp4;
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 509 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"74";
                  temp1 = addNodeA(nodeId++,strdup("if_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IF"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("ELSE"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-6].value).nodeId = temp2;
                  (yyvsp[-5].value).nodeId = temp3;
                  (yyvsp[-3].value).nodeId = temp4;
                  (yyvsp[-1].value).nodeId = temp5;
                  makeChild((yyval.value).nodeId,(yyvsp[-6].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-5].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 532 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"93 ";
                  temp1 = addNodeA(nodeId++,strdup("func_call_stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

      }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 539 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"95 ";
                  temp1 = addNodeA(nodeId++,strdup("func_call_stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 547 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"97 ";
                  temp1 = addNodeA(nodeId++,strdup("with_return"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp6 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp7 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-4].value).nodeId = temp2;
                  (yyvsp[-3].value).nodeId = temp5;
                  (yyvsp[-1].value).nodeId = temp6;
                  (yyvsp[0].value).nodeId = temp7;
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 567 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"99 ";
                  temp1 = addNodeA(nodeId++,strdup("without_return"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-4].value).nodeId = temp2;
                  (yyvsp[-3].value).nodeId = temp3;
                  (yyvsp[-1].value).nodeId = temp4;
                  (yyvsp[0].value).nodeId = temp5;
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 587 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"101 ";
                  temp1 = addNodeA(nodeId++,strdup("call_param_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 593 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"103 ";
                  temp1 = addNodeA(nodeId++,strdup("call_param_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 601 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"107 ";
                  temp1 = addNodeA(nodeId++,strdup("empty_param_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;

      }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 609 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"105 ";
                  temp1 = addNodeA(nodeId++,strdup("non_empty_param_list"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[0].value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

            }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 619 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"107 ";
                  temp1 = addNodeA(nodeId++,strdup("non_empty_param_list"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("COMMA"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-1].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

        }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 635 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"61 ";
                  temp1 = addNodeA(nodeId++,strdup("jump_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("CONTINUE"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-1].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
                  }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 646 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"63 ";
                  temp1 = addNodeA(nodeId++,strdup("jump_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("BREAK"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-1].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
                  }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 657 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"65 ";
                  temp1 = addNodeA(nodeId++,strdup("jump_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("RETURN"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-1].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
                  }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 668 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"67 ";
                  temp1 = addNodeA(nodeId++,strdup("jump_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("RETURN"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-2].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
                  }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 682 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"29 ";
                  temp1 = addNodeA(nodeId++,strdup("expr_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[0].value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 690 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"31 ";
                  temp1 = addNodeA(nodeId++,strdup("expr_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[0].value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
                }
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 703 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"56 ";
                    temp1 = addNodeA(nodeId++,strdup("primary_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[0].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 711 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"58 ";
                    temp1 = addNodeA(nodeId++,strdup("primary_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("NUM"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[0].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 722 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"46 ";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 728 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"42 ";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("MULTIPLY"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 738 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"44 ";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("DIVIDE"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 748 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"46 ";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("PERCENT"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 758 "parser.y" /* yacc.c:1646  */
    {
      			//	cout<<"201 ";
      				temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
      				temp2 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
      				temp3 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
      				(yyval.value).nodeId = temp1;
      				(yyvsp[-2].value).nodeId = temp2;
      				(yyvsp[0].value).nodeId = temp3;
      				makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      				}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 773 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"48 ";
                    temp1 = addNodeA(nodeId++,strdup("add_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 779 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"50 ";
                    temp1 = addNodeA(nodeId++,strdup("add_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("PLUS"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 789 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"52 ";
                    temp1 = addNodeA(nodeId++,strdup("add_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("MINUS"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 805 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"32 ";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 811 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"34 ";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("L_THAN"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 821 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"36";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("G_THAN"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 831 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"38 ";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("L_EQ"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 841 "parser.y" /* yacc.c:1646  */
    {
                   // cout<<"40 ";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("G_EQ"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 854 "parser.y" /* yacc.c:1646  */
    {
                   // cout<<"30 ";
                    temp1 = addNodeA(nodeId++,strdup("equality_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 860 "parser.y" /* yacc.c:1646  */
    {
                   // cout<<"26 ";
                    temp1 = addNodeA(nodeId++,strdup("equality_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("EQEQ"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 870 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"28 ";
                    temp1 = addNodeA(nodeId++,strdup("equality_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("NEQ"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 883 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"22 ";
                    temp1 = addNodeA(nodeId++,strdup("log_and_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 889 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"24 ";
                    temp1 = addNodeA(nodeId++,strdup("log_and_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("AND"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 902 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"18 ";
                    temp1 = addNodeA(nodeId++,strdup("log_or_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 908 "parser.y" /* yacc.c:1646  */
    {
                   // cout<<"20 ";
                    temp1 = addNodeA(nodeId++,strdup("log_or_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("OR"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 921 "parser.y" /* yacc.c:1646  */
    {
                   // cout<<"200 ";
                    temp1 = addNodeA(nodeId++,strdup("assgn_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("EQUALS"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 931 "parser.y" /* yacc.c:1646  */
    {
                  //  cout<<"12 ";
                    temp1 = addNodeA(nodeId++,strdup("assgn_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("EQUALS"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 947 "parser.y" /* yacc.c:1646  */
    {
                 // cout<<"35 ";
                  temp1 = addNodeA(nodeId++,strdup("iterate_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("WHILE"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-4].value).nodeId = temp2;
                  (yyvsp[-3].value).nodeId = temp3;
                  (yyvsp[-1].value).nodeId = temp4;
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

      }
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 964 "parser.y" /* yacc.c:1646  */
    {
                //  cout<<"37 ";
                  temp1 = addNodeA(nodeId++,strdup("iterate_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("DO"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("WHILE"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("expr"),&tailA,&headA);
                  temp6 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp7 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-6].value).nodeId = temp2;
                  (yyvsp[-4].value).nodeId = temp3;
                  (yyvsp[-3].value).nodeId = temp4;
                  (yyvsp[-2].value).nodeId = temp5;
                  (yyvsp[-1].value).nodeId = temp6;
                  (yyvsp[0].value).nodeId = temp7;
                  makeChild((yyval.value).nodeId,(yyvsp[-6].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-5].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 988 "parser.y" /* yacc.c:1646  */
    {

                //  cout<<"39 ";
                  temp1 = addNodeA(nodeId++,strdup("iterate_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("FOR"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-5].value).nodeId = temp2;
                  (yyvsp[-4].value).nodeId = temp3;
                  (yyvsp[-1].value).nodeId = temp4;
                  makeChild((yyval.value).nodeId,(yyvsp[-5].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1006 "parser.y" /* yacc.c:1646  */
    {

                //  cout<<"41 ";
                  temp1 = addNodeA(nodeId++,strdup("iterate_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("FOR"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[-7].value).nodeId = temp2;
                  (yyvsp[-6].value).nodeId = temp3;
                  (yyvsp[-3].value).nodeId = temp4;
                  (yyvsp[-1].value).nodeId = temp5;
                  makeChild((yyval.value).nodeId,(yyvsp[-7].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-6].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-5].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-4].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-3].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
                      }
#line 2745 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2749 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1030 "parser.y" /* yacc.c:1906  */





int main (){
  yyparse();
  cout<<endl;
  printGraph(headA);
  return 0;
}
