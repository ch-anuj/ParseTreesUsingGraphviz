/* A Bison parser, made by GNU Bison 3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "b_6.y" /* yacc.c:338  */

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
	char label[15];
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
	int flagC = 0;
	while(1){
		if(p->id==parent)break;
		p = p->next;
	}
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

// ----------------------------------






#line 186 "y.tab.c" /* yacc.c:338  */
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
    ENDWHILE = 267,
    NUM = 268,
    ENDCOLON = 269,
    COLON = 270,
    DOT = 271,
    AMPERSAN = 272,
    BACKSLASH = 273,
    ELSE = 274,
    WHILE = 275,
    SCAN = 276,
    PRINT = 277,
    INT = 278,
    CHAR = 279,
    FLOAT = 280,
    FOR = 281,
    GOTO = 282,
    SWITCH = 283,
    VOID = 284,
    BREAK = 285,
    CASE = 286,
    CONTINUE = 287,
    RETURN = 288,
    COMMA = 289,
    LETTER = 290,
    NUMBER = 291,
    INTEGER = 292,
    FLOATING_INT = 293,
    IDENTIFIER = 294,
    Obrac = 295,
    Cbrac = 296,
    EQUALS = 297,
    NOT = 298,
    OR = 299,
    EQEQ = 300,
    NEQ = 301,
    G_THAN = 302,
    L_THAN = 303,
    G_EQ = 304,
    L_EQ = 305,
    AND = 306,
    PLUS = 307,
    MINUS = 308,
    MULTIPLY = 309,
    DIVIDE = 310
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
#define ENDWHILE 267
#define NUM 268
#define ENDCOLON 269
#define COLON 270
#define DOT 271
#define AMPERSAN 272
#define BACKSLASH 273
#define ELSE 274
#define WHILE 275
#define SCAN 276
#define PRINT 277
#define INT 278
#define CHAR 279
#define FLOAT 280
#define FOR 281
#define GOTO 282
#define SWITCH 283
#define VOID 284
#define BREAK 285
#define CASE 286
#define CONTINUE 287
#define RETURN 288
#define COMMA 289
#define LETTER 290
#define NUMBER 291
#define INTEGER 292
#define FLOATING_INT 293
#define IDENTIFIER 294
#define Obrac 295
#define Cbrac 296
#define EQUALS 297
#define NOT 298
#define OR 299
#define EQEQ 300
#define NEQ 301
#define G_THAN 302
#define L_THAN 303
#define G_EQ 304
#define L_EQ 305
#define AND 306
#define PLUS 307
#define MINUS 308
#define MULTIPLY 309
#define DIVIDE 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 119 "b_6.y" /* yacc.c:353  */

	struct{
	char val[15];
	int nodeId;
	}value;

#line 346 "y.tab.c" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   71

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  77

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   160,   166,   186,   187,   197,   198,   201,
     205,   216,   229,   246,   260,   268,   284,   290,   300,   309,
     315,   325,   341,   364,   372,   383,   389,   399,   409,   422,
     428,   438,   454,   460,   470,   480,   490,   503,   509,   519,
     532,   538,   551,   557,   570,   576
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "O_BRAC", "C_BRAC", "OPEN_BRAC",
  "CLOSE_BRAC", "MAIN", "THEN", "PERCENT", "ENDIF", "ENDWHILE", "NUM",
  "ENDCOLON", "COLON", "DOT", "AMPERSAN", "BACKSLASH", "ELSE", "WHILE",
  "SCAN", "PRINT", "INT", "CHAR", "FLOAT", "FOR", "GOTO", "SWITCH", "VOID",
  "BREAK", "CASE", "CONTINUE", "RETURN", "COMMA", "LETTER", "NUMBER",
  "INTEGER", "FLOATING_INT", "IDENTIFIER", "Obrac", "Cbrac", "EQUALS",
  "NOT", "OR", "EQEQ", "NEQ", "G_THAN", "L_THAN", "G_EQ", "L_EQ", "AND",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "$accept", "main_unit",
  "func_decls", "main_decl", "type_spec", "empty", "body", "compound_stmt",
  "decl_stmt", "declarators", "stmt_list", "stmt", "if_stmt",
  "primary_expr", "mul_expr", "add_expr", "relational_expr",
  "equality_expr", "log_and_expr", "log_or_expr", "assgn_expr", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -63,    11,    23,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
       6,    17,   -63,    24,    26,    -1,   -63,   -63,    35,   -63,
     -63,   -63,    12,   -63,     2,   -63,   -63,    15,   -10,   -16,
     -30,    -3,     9,    18,    47,    -9,   -63,    49,   -63,   -63,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,
      -9,    -9,    -9,    -9,   -63,   -63,    -4,    25,    18,   -63,
     -63,   -63,   -10,   -10,   -16,   -16,   -16,   -16,   -30,   -30,
      -3,     9,    26,   -63,    46,    26,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     0,     3,     1,     6,     8,     7,     5,     2,
       0,     0,     9,     0,     0,     0,     4,    10,     0,    11,
      24,    23,     0,    20,     0,    16,    19,    25,    29,    32,
      37,    40,    42,    44,     0,     0,    14,     0,    12,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    25,     0,    13,    45,    28,
      26,    27,    30,    31,    34,    33,    36,    35,    38,    39,
      41,    43,     0,    15,    21,     0,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   -63,    64,    55,   -62,   -63,   -63,   -63,
     -63,    44,   -63,    -8,     5,     7,     8,    19,    16,   -32,
     -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     9,    22,     3,    16,    17,    23,    37,
      24,    25,    26,    55,    28,    29,    30,    31,    32,    33,
      34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    72,    18,    56,    20,    18,    19,    27,    58,    38,
      74,     4,    20,    76,    11,    20,    27,    46,    47,    48,
      49,    12,     5,     6,     7,     5,     6,     7,     8,    14,
      21,     8,    15,    59,    60,    61,    44,    45,    21,    35,
      53,    21,    50,    51,    42,    43,     5,     6,     7,    62,
      63,    36,     8,    64,    65,    66,    67,    40,    68,    69,
      52,    54,    53,    57,    73,    75,    10,    13,    39,    71,
       0,    70
};

static const yytype_int8 yycheck[] =
{
      10,     5,     3,    35,    13,     3,     7,    15,    40,     7,
      72,     0,    13,    75,     8,    13,    24,    47,    48,    49,
      50,     4,    23,    24,    25,    23,    24,    25,    29,     5,
      39,    29,     6,    41,    42,    43,    52,    53,    39,     4,
      44,    39,    45,    46,    54,    55,    23,    24,    25,    44,
      45,    39,    29,    46,    47,    48,    49,    42,    50,    51,
      51,    14,    44,    14,    39,    19,     2,    12,    24,    53,
      -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,    61,     0,    23,    24,    25,    29,    59,
      60,     8,     4,    61,     5,     6,    62,    63,     3,     7,
      13,    39,    60,    64,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     4,    39,    65,     7,    67,
      42,    10,    54,    55,    52,    53,    47,    48,    49,    50,
      45,    46,    51,    44,    14,    69,    75,    14,    75,    69,
      69,    69,    70,    70,    71,    71,    71,    71,    72,    72,
      73,    74,     5,    39,    62,    19,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    59,    60,    60,    60,    60,    61,
      62,    63,    63,    64,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    72,    73,    73,    73,
      74,    74,    75,    75,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     6,     1,     1,     1,     1,     0,
       1,     2,     3,     3,     1,     3,     1,     2,     2,     1,
       1,     5,     7,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3
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
  YYUSE (yytype);
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
  unsigned long yylno = yyrline[yyrule];
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

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
                  (unsigned long) yystacksize));

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
#line 149 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"1";
									temp1 = addNodeA(nodeId++,strdup("func_decls"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("main_unit"),&tailA,&headA);
									(yyval.value).nodeId = temp2;
									(yyvsp[-1].value).nodeId = temp1;
									makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
									makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
			}
#line 1497 "y.tab.c" /* yacc.c:1645  */
    break;

  case 3:
#line 160 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"2";

			}
#line 1506 "y.tab.c" /* yacc.c:1645  */
    break;

  case 4:
#line 167 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"3";
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
#line 1528 "y.tab.c" /* yacc.c:1645  */
    break;

  case 6:
#line 187 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"6";
									temp1 = addNodeA(nodeId++,strdup("type_spec"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("INT"),&tailA,&headA);
									(yyval.value).nodeId = temp1;
									(yyvsp[0].value).nodeId = temp2;
									makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


			}
#line 1543 "y.tab.c" /* yacc.c:1645  */
    break;

  case 10:
#line 205 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"4";
									temp1 = addNodeA(nodeId++,strdup("body"),&tailA,&headA);
									(yyval.value).nodeId = temp1;
									makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);


			}
#line 1556 "y.tab.c" /* yacc.c:1645  */
    break;

  case 11:
#line 216 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"5";
									temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
									temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
									(yyval.value).nodeId = temp1;
									(yyvsp[-1].value).nodeId = temp2;
									(yyvsp[0].value).nodeId = temp3;
									makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
									makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);

			}
#line 1573 "y.tab.c" /* yacc.c:1645  */
    break;

  case 12:
#line 229 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"60";
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
#line 1590 "y.tab.c" /* yacc.c:1645  */
    break;

  case 13:
#line 246 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"76";
									temp1 = addNodeA(nodeId++,strdup("decl_stmt"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("ENDCOLON"),&tailA,&headA);
									(yyval.value).nodeId = temp1;
									(yyvsp[0].value).nodeId = temp2;
									makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
									makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
									makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
			}
#line 1605 "y.tab.c" /* yacc.c:1645  */
    break;

  case 14:
#line 260 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"78";
									temp1 = addNodeA(nodeId++,strdup("declarators"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
									(yyval.value).nodeId = temp1;
									(yyvsp[0].value).nodeId = temp2;
									makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
			}
#line 1618 "y.tab.c" /* yacc.c:1645  */
    break;

  case 15:
#line 268 "b_6.y" /* yacc.c:1645  */
    {
									cout<<"80";
									temp1 = addNodeA(nodeId++,strdup("declarators"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("COMMA"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
									(yyvsp[-1].value).nodeId = temp2;
                  (yyvsp[0].value).nodeId = temp3;
                  makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
			}
#line 1635 "y.tab.c" /* yacc.c:1645  */
    break;

  case 16:
#line 284 "b_6.y" /* yacc.c:1645  */
    {
                  cout<<"62";
                  temp1 = addNodeA(nodeId++,strdup("stmt_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1646 "y.tab.c" /* yacc.c:1645  */
    break;

  case 17:
#line 290 "b_6.y" /* yacc.c:1645  */
    {
                  cout<<"64";
                  temp1 = addNodeA(nodeId++,strdup("stmt_list"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
      }
#line 1658 "y.tab.c" /* yacc.c:1645  */
    break;

  case 18:
#line 300 "b_6.y" /* yacc.c:1645  */
    {
                  cout<<"66";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("ENDCOLON"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  (yyvsp[0].value).nodeId = temp2;
                  makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1672 "y.tab.c" /* yacc.c:1645  */
    break;

  case 19:
#line 309 "b_6.y" /* yacc.c:1645  */
    {
                  cout<<"68";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1683 "y.tab.c" /* yacc.c:1645  */
    break;

  case 20:
#line 315 "b_6.y" /* yacc.c:1645  */
    {
                  cout<<"70";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  (yyval.value).nodeId = temp1;
                  makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1694 "y.tab.c" /* yacc.c:1645  */
    break;

  case 21:
#line 325 "b_6.y" /* yacc.c:1645  */
    {
                  cout<<"72";
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
#line 1715 "y.tab.c" /* yacc.c:1645  */
    break;

  case 22:
#line 341 "b_6.y" /* yacc.c:1645  */
    {
                  cout<<"74";
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
#line 1740 "y.tab.c" /* yacc.c:1645  */
    break;

  case 23:
#line 364 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"56";
                    temp1 = addNodeA(nodeId++,strdup("primary_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[0].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1753 "y.tab.c" /* yacc.c:1645  */
    break;

  case 24:
#line 372 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"58";
                    temp1 = addNodeA(nodeId++,strdup("primary_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("NUM"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[0].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1766 "y.tab.c" /* yacc.c:1645  */
    break;

  case 25:
#line 383 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"46";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1777 "y.tab.c" /* yacc.c:1645  */
    break;

  case 26:
#line 389 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"42";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("MULTIPLY"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1792 "y.tab.c" /* yacc.c:1645  */
    break;

  case 27:
#line 399 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"44";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("DIVIDE"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1807 "y.tab.c" /* yacc.c:1645  */
    break;

  case 28:
#line 409 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"46";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("PERCENT"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1822 "y.tab.c" /* yacc.c:1645  */
    break;

  case 29:
#line 422 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"48";
                    temp1 = addNodeA(nodeId++,strdup("add_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1833 "y.tab.c" /* yacc.c:1645  */
    break;

  case 30:
#line 428 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"50";
                    temp1 = addNodeA(nodeId++,strdup("add_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("PLUS"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1848 "y.tab.c" /* yacc.c:1645  */
    break;

  case 31:
#line 438 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"52";
                    temp1 = addNodeA(nodeId++,strdup("add_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("MINUS"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1863 "y.tab.c" /* yacc.c:1645  */
    break;

  case 32:
#line 454 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"32";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1874 "y.tab.c" /* yacc.c:1645  */
    break;

  case 33:
#line 460 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"34";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("L_THAN"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1889 "y.tab.c" /* yacc.c:1645  */
    break;

  case 34:
#line 470 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"36";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("G_THAN"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1904 "y.tab.c" /* yacc.c:1645  */
    break;

  case 35:
#line 480 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"38";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("L_EQ"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1919 "y.tab.c" /* yacc.c:1645  */
    break;

  case 36:
#line 490 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"40";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("G_EQ"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1934 "y.tab.c" /* yacc.c:1645  */
    break;

  case 37:
#line 503 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"30";
                    temp1 = addNodeA(nodeId++,strdup("equality_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1945 "y.tab.c" /* yacc.c:1645  */
    break;

  case 38:
#line 509 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"26";
                    temp1 = addNodeA(nodeId++,strdup("equality_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("EQEQ"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1960 "y.tab.c" /* yacc.c:1645  */
    break;

  case 39:
#line 519 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"28";
                    temp1 = addNodeA(nodeId++,strdup("equality_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("NEQ"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1975 "y.tab.c" /* yacc.c:1645  */
    break;

  case 40:
#line 532 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"22";
                    temp1 = addNodeA(nodeId++,strdup("log_and_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 1986 "y.tab.c" /* yacc.c:1645  */
    break;

  case 41:
#line 538 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"24";
                    temp1 = addNodeA(nodeId++,strdup("log_and_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("AND"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2001 "y.tab.c" /* yacc.c:1645  */
    break;

  case 42:
#line 551 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"18";
                    temp1 = addNodeA(nodeId++,strdup("log_or_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2012 "y.tab.c" /* yacc.c:1645  */
    break;

  case 43:
#line 557 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"20";
                    temp1 = addNodeA(nodeId++,strdup("log_or_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("OR"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2027 "y.tab.c" /* yacc.c:1645  */
    break;

  case 44:
#line 570 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"10";
                    temp1 = addNodeA(nodeId++,strdup("assgn_expr"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2038 "y.tab.c" /* yacc.c:1645  */
    break;

  case 45:
#line 576 "b_6.y" /* yacc.c:1645  */
    {
                    cout<<"12";
                    temp1 = addNodeA(nodeId++,strdup("assgn_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("EQUALS"),&tailA,&headA);
                    (yyval.value).nodeId = temp1;
                    (yyvsp[-1].value).nodeId = temp2;
                    makeChild((yyval.value).nodeId,(yyvsp[-2].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[-1].value).nodeId,headA);
                    makeChild((yyval.value).nodeId,(yyvsp[0].value).nodeId,headA);
      }
#line 2053 "y.tab.c" /* yacc.c:1645  */
    break;


#line 2057 "y.tab.c" /* yacc.c:1645  */
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
#line 589 "b_6.y" /* yacc.c:1903  */



int main() {
    std::cout << "%%";
  	yyparse();
  	cout<<endl;
  	printGraph(headA);
  	return 0;
}
