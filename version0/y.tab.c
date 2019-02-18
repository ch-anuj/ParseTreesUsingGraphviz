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
#line 1 "new_parser.y" /* yacc.c:338  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N_reg 5

extern int yylineno;

char buffer[120];

char *v,*m,*n,*o,*a,*b;

int count=1,label=1,filledregcount=0,ofset=0,debug,offset_flag;
extern int yylex();
void yyerror(char* s);
typedef struct node{
	int flag;
	char* offset;
	char* reg_n;
	char* l_name;
	struct node* next;
}node;
node* head=NULL;

node* mknode(char* lexeme,int flg){
	node* t=malloc(sizeof(node));
	t->next=NULL;
	t->flag=flg;
	t->l_name=strdup(lexeme);
	return t;
}
void join2(char* a,char* b,char** c){
	int i,j;
	if(a!=NULL&&b!=NULL){
	i=strlen(a);
	j=strlen(b);

	}
	else return;
	*c = malloc(sizeof(char)*(i+j+1));
	memcpy(*c,a,i);
	memcpy(*c+i,b,j+1);

}
void join3(char* a,char*b,char*c,char** d){
	int i,j,k;
	if(a!=NULL&&b!=NULL&&c!=NULL){
	i=strlen(a);
	j=strlen(b);
	k=strlen(c);
	}
	else return;

	*d=malloc(sizeof(char)*(i+j+k+1));
	memcpy(*d,a,i);
	memcpy(*d+i,b,j);
	memcpy(*d+i+j,c,k+1);
}
void join4(char*a,char*b,char*c,char*d,char** e){
	int i,j,k,l;
	if(a!=NULL&&b!=NULL&&c!=NULL&&d!=NULL){
	i=strlen(a);
	j=strlen(b);
	k=strlen(c);
	l=strlen(d);
	}
	else return;
	*e=malloc(sizeof(char)*(i+j+k+l+1));
	memcpy(*e,a,i);
	memcpy(*e+i,b,j);
	memcpy(*e+i+j,c,k);
	memcpy(*e+i+j+k,d,l+1);
}


char* lookup(char* lexeme)
{
	node* start;
	int temp;
	start=head;

	while(start!=NULL){

				temp=strcmp(start->l_name,lexeme);
				if(temp==0){
					if(start->flag==0){
							offset_flag=0;
							return start->reg_n;}
					else{ 	offset_flag=1;
							return start->offset;}
				}
				else start=start->next;

	}

	return NULL;
}
void clear(node* point){
	if(point==NULL)return;

	else clear(point->next);
	free(point);
}
char* reg_gen(){
	a=malloc(2*sizeof(char));
	if(filledregcount<=7){
	a[0]='t';
	a[1]='\0';
	b=malloc(4*sizeof(char));
	sprintf(b,"%d",filledregcount);
	join2(a,b,&v);
	}
	else {
	a[0]='s';
	a[1]='\0';
	 b=malloc(4*sizeof(char));
	sprintf(b,"%d",filledregcount-8);
	join2(a,b,&v);
	}
	filledregcount++;
	return v;
}
void insert(char* lexeme){
	int f;
	if(filledregcount>N_reg) f=1;
	else {f=0;
				}
	node* t=mknode(lexeme,f);
	t->next=head;
	if(f==0){
	t->reg_n=strdup(reg_gen());
	}
	else{
		sprintf(b,"%d",ofset);
		t->offset=strdup(b);
		ofset+=4;
	}

	head=t;

}



char* tempgen(int count){
	a=malloc(2*sizeof(char));
	a[0]='q';
	a[1]='\0';
	 b=malloc(4*sizeof(char));
	sprintf(b,"%d",count);
	join2(a,b,&v);


	return v;
}

char* labelgen(int label){
	a=malloc(2*sizeof(char));
	b=malloc(2*sizeof(char));
	a[0]='L';
	a[1]='\0';
	 b=malloc(4*sizeof(char));
	sprintf(b,"%d",label);
	join2(a,b,&v);


	return v;
}



#line 242 "y.tab.c" /* yacc.c:338  */
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
    id = 258,
    NUM = 259,
    EQUALS = 260,
    PLUS = 261,
    MINUS = 262,
    MULTIPLY = 263,
    DIVIDE = 264,
    EQEQ = 265,
    NEQ = 266,
    G_THAN = 267,
    L_THAN = 268,
    G_EQ = 269,
    L_EQ = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    O_BRAC = 274,
    C_BRAC = 275,
    THEN = 276,
    ENDIF = 277,
    COMMA = 278,
    ELSE = 279,
    IF = 280,
    WHILE = 281,
    ENDWHILE = 282,
    INT = 283,
    PRINT = 284,
    SCAN = 285,
    Obrac = 286,
    Cbrac = 287
  };
#endif
/* Tokens.  */
#define id 258
#define NUM 259
#define EQUALS 260
#define PLUS 261
#define MINUS 262
#define MULTIPLY 263
#define DIVIDE 264
#define EQEQ 265
#define NEQ 266
#define G_THAN 267
#define L_THAN 268
#define G_EQ 269
#define L_EQ 270
#define AND 271
#define OR 272
#define NOT 273
#define O_BRAC 274
#define C_BRAC 275
#define THEN 276
#define ENDIF 277
#define COMMA 278
#define ELSE 279
#define IF 280
#define WHILE 281
#define ENDWHILE 282
#define INT 283
#define PRINT 284
#define SCAN 285
#define Obrac 286
#define Cbrac 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 174 "new_parser.y" /* yacc.c:353  */

	struct D{
	char* cd;
	char* id_cd;
	int n_cd;
	int f;

	}D;
	   	char* code;
	struct E{
	char* var;
	char* cd;
	}E;


#line 362 "y.tab.c" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  97

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

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
       2,     2,     2,     2,    33,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   244,   244,   248,   250,   251,   257,   262,   266,   270,
     274,   275,   276,   278,   279,   280,   296,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   312,   329,   349,
     372,   375,   379,   381,   385,   455,   459,   465,   470
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "id", "NUM", "EQUALS", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "EQEQ", "NEQ", "G_THAN", "L_THAN", "G_EQ", "L_EQ",
  "AND", "OR", "NOT", "O_BRAC", "C_BRAC", "THEN", "ENDIF", "COMMA", "ELSE",
  "IF", "WHILE", "ENDWHILE", "INT", "PRINT", "SCAN", "Obrac", "Cbrac",
  "','", "$accept", "Start", "Type", "Decl", "Lables", "Stmt", "b_Expr",
  "Expr", "R_Expr", "VAR", YY_NULLPTR
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
     285,   286,   287,    44
};
# endif

#define YYPACT_NINF -30

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-30)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -5,   -30,    68,    23,    25,   -30,     0,   -19,     3,    53,
      54,    55,    56,   -30,    25,    41,    72,    74,   -30,    26,
      49,     9,     9,    26,    26,   -30,   -30,    47,    15,    50,
     -30,   -30,    57,    51,    52,     9,   -10,    46,     5,    58,
      62,   -30,    81,    82,    67,    26,    26,    26,    26,    83,
      84,   -30,     9,     9,    66,    26,    26,    26,    26,    26,
      26,    25,    25,    25,   -30,    59,    60,    61,   -30,   -30,
     -30,   -30,    26,    26,   -30,    78,    25,   -30,   -30,   -30,
     -30,   -30,   -30,    63,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,    45,   -30,   -30,    25,    73,   -30
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     0,     1,     0,     5,     0,     0,
       0,     0,     0,     2,    10,     0,     0,     0,     4,     0,
       0,     0,     0,     0,     0,    11,     7,     0,     0,    35,
      36,    27,    34,     0,     0,     0,     0,    26,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,    31,    30,
      33,    32,     0,     0,    19,    18,     0,    20,    21,    22,
      23,    24,    25,     0,    15,    16,     8,    38,    37,    29,
      28,     0,    14,    12,     0,     0,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,    89,   -30,   -14,   -11,   -30,   -29,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     7,    13,    36,    14,    31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    37,    37,    39,    40,    15,    52,    53,    19,     1,
      54,    38,    29,    30,    17,    37,    68,    69,    70,    71,
      42,    52,    53,     1,    51,    61,     6,    35,     8,    29,
      30,    16,    37,    37,    20,    77,    78,    79,    80,    81,
      82,    74,    75,    89,    90,    26,    43,    83,    84,    85,
       9,    10,    33,    34,    11,    12,    55,    56,    57,    58,
      59,    60,    91,    45,    46,    47,    48,    93,     5,    94,
      66,    67,    21,    22,    23,    24,    27,    28,    62,    41,
      95,    44,    63,    49,    50,    64,    65,    76,    72,    73,
      92,    86,    87,    88,    52,    96,    18
};

static const yytype_uint8 yycheck[] =
{
      14,    21,    22,    23,    24,     5,    16,    17,     5,    28,
      20,    22,     3,     4,    33,    35,    45,    46,    47,    48,
       5,    16,    17,    28,    35,    20,     3,    18,     3,     3,
       4,    31,    52,    53,    31,    55,    56,    57,    58,    59,
      60,    52,    53,    72,    73,     4,    31,    61,    62,    63,
      25,    26,     3,     4,    29,    30,    10,    11,    12,    13,
      14,    15,    76,     6,     7,     8,     9,    22,     0,    24,
       3,     4,    19,    19,    19,    19,     4,     3,    20,    32,
      94,    31,    20,    32,    32,     4,     4,    21,     5,     5,
      27,    32,    32,    32,    16,    22,     7
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    35,    36,    37,     0,     3,    38,     3,    25,
      26,    29,    30,    39,    41,     5,    31,    33,    37,     5,
      31,    19,    19,    19,    19,    39,     4,     4,     3,     3,
       4,    42,    43,     3,     4,    18,    40,    43,    40,    43,
      43,    32,     5,    31,    31,     6,     7,     8,     9,    32,
      32,    40,    16,    17,    20,    10,    11,    12,    13,    14,
      15,    20,    20,    20,     4,     4,     3,     4,    42,    42,
      42,    42,     5,     5,    40,    40,    21,    43,    43,    43,
      43,    43,    43,    39,    39,    39,    32,    32,    32,    42,
      42,    39,    27,    22,    24,    39,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    37,    37,    38,    38,    38,    38,
      39,    39,    39,    39,    39,    39,    39,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    41,    41,    41,
      42,    42,    42,    42,    42,    43,    43,    43,    43
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     5,     3,     6,     4,
       1,     2,     7,     9,     6,     5,     5,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     6,     6,
       3,     3,     3,     3,     1,     1,     1,     4,     4
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
#line 244 "new_parser.y" /* yacc.c:1645  */
    {	sprintf(buffer,".data\n%s\n.text\nmain:\n",(yyvsp[-1].code));
						join2(buffer,(yyvsp[0].code),&(yyval.code));
					 printf("%s",(yyval.code));}
#line 1499 "y.tab.c" /* yacc.c:1645  */
    break;

  case 5:
#line 251 "new_parser.y" /* yacc.c:1645  */
    {
							sprintf((yyval.code),"%s\narray:\t.space 800\n",(yyvsp[0].code));

							}
#line 1508 "y.tab.c" /* yacc.c:1645  */
    break;

  case 6:
#line 257 "new_parser.y" /* yacc.c:1645  */
    {

			sprintf(buffer,"%s:\t.word %s\n",(yyvsp[-2].code),(yyvsp[0].code));
			join2((yyvsp[-4].code),buffer,&(yyval.code));
		}
#line 1518 "y.tab.c" /* yacc.c:1645  */
    break;

  case 7:
#line 262 "new_parser.y" /* yacc.c:1645  */
    {
		 sprintf((yyval.code),"%s:\t.word %s\n",(yyvsp[-2].code),(yyvsp[0].code));

		}
#line 1527 "y.tab.c" /* yacc.c:1645  */
    break;

  case 8:
#line 266 "new_parser.y" /* yacc.c:1645  */
    {
			sprintf(buffer,"%s:\t.space %d",(yyvsp[-3].code),4*atoi((yyvsp[-1].code)));
			join2((yyvsp[-5].code),buffer,&(yyval.code));
		}
#line 1536 "y.tab.c" /* yacc.c:1645  */
    break;

  case 9:
#line 270 "new_parser.y" /* yacc.c:1645  */
    {
		 sprintf((yyval.code),"%s:\t.space %d\n",(yyvsp[-3].code),4*atoi((yyvsp[-1].code)));
		}
#line 1544 "y.tab.c" /* yacc.c:1645  */
    break;

  case 10:
#line 274 "new_parser.y" /* yacc.c:1645  */
    {(yyval.code)=(yyvsp[0].code);}
#line 1550 "y.tab.c" /* yacc.c:1645  */
    break;

  case 15:
#line 280 "new_parser.y" /* yacc.c:1645  */
    {
							sprintf(buffer,"li $v0,1\n");
							if((yyvsp[-2].D).f==0){
				 				sprintf(buffer,"%slw $a0,%s\n",buffer,(yyvsp[-2].D).cd);

				 			}
				 			else if((yyvsp[-2].D).f==1){
				 				sprintf(buffer,"li $a0,%s\n",(yyvsp[-2].D).cd);
				 			}
				 			else{
				 			sprintf(buffer,"%sla $s5,%s\n",buffer,(yyvsp[-2].D).cd);
				 			sprintf(buffer,"%slw $a0,%d(%s)\n",buffer,4*(yyvsp[-2].D).n_cd,(yyvsp[-2].D).cd);
				 			}
				 			sprintf((yyval.code),"%ssyscall\n",buffer);

						}
#line 1571 "y.tab.c" /* yacc.c:1645  */
    break;

  case 27:
#line 312 "new_parser.y" /* yacc.c:1645  */
    {
			m=lookup((yyvsp[0].E).var);
			if(offset_flag==0){

				sprintf(buffer,"sw $%s,%s\n",m,(yyvsp[-2].code));

			}
			else{

				sprintf(buffer,"lw $s6,(%s)array\n",m);
				sprintf(buffer,"%ssw $s6,%s\n",buffer,(yyvsp[-2].code));

			}
			sprintf((yyval.code),"%s%s",(yyvsp[0].E).cd,buffer);
			clear(head);

		}
#line 1593 "y.tab.c" /* yacc.c:1645  */
    break;

  case 28:
#line 329 "new_parser.y" /* yacc.c:1645  */
    {

		 m=lookup((yyvsp[0].E).var);
			if(offset_flag==0){

				sprintf(buffer,"la $s5,%s\n",(yyvsp[-5].code));
				sprintf(buffer,"%ssw $%s,%d(%s)\n",buffer,m,4*atoi((yyvsp[-3].code)),(yyvsp[-5].code));

			}
			else{

				sprintf(buffer,"%slw $s6,(%s)array\n",buffer,m);
				sprintf(buffer,"la $s5,%s\n",(yyvsp[-5].code));
				sprintf(buffer,"%ssw $s6,%d(%s)\n",buffer,4*atoi((yyvsp[-3].code)),(yyvsp[-5].code));

			}
			sprintf((yyval.code),"%s%s",(yyvsp[0].E).cd,buffer);
			clear(head);

		}
#line 1618 "y.tab.c" /* yacc.c:1645  */
    break;

  case 29:
#line 349 "new_parser.y" /* yacc.c:1645  */
    {

		 m=lookup((yyvsp[0].E).var);
			if(offset_flag==0){

				sprintf(buffer,"%slw $s6,%s\n",buffer,(yyvsp[-3].code));
				sprintf(buffer,"%sSLL $s6,$s6,2\n",buffer);
				sprintf(buffer,"%ssw $%s,$s6(%s)\n",buffer,m,(yyvsp[-5].code));

			}
			else{

				sprintf(buffer,"lw $s6,array(%s)\n",m);
				sprintf(buffer,"%slw $s7,%s\n",buffer,(yyvsp[-3].code));
				sprintf(buffer,"%sSLL $s7,$s7,2\n",buffer);
				sprintf(buffer,"%ssw $s6,$s7(%s)\n",buffer,(yyvsp[-5].code));

			}
			sprintf((yyval.code),"%s",buffer);
			clear(head);
		}
#line 1644 "y.tab.c" /* yacc.c:1645  */
    break;

  case 30:
#line 372 "new_parser.y" /* yacc.c:1645  */
    {

}
#line 1652 "y.tab.c" /* yacc.c:1645  */
    break;

  case 31:
#line 375 "new_parser.y" /* yacc.c:1645  */
    {


					}
#line 1661 "y.tab.c" /* yacc.c:1645  */
    break;

  case 32:
#line 379 "new_parser.y" /* yacc.c:1645  */
    {
	  			}
#line 1668 "y.tab.c" /* yacc.c:1645  */
    break;

  case 33:
#line 383 "new_parser.y" /* yacc.c:1645  */
    {
	  			}
#line 1675 "y.tab.c" /* yacc.c:1645  */
    break;

  case 34:
#line 385 "new_parser.y" /* yacc.c:1645  */
    {




			(yyval.E).var=tempgen(count);count++;

			insert((yyval.E).var);
			m=lookup((yyval.E).var);   			// string m = lookup(RE.var)


			if(offset_flag==0){

				if((yyvsp[0].D).f==0){

					sprintf(buffer,"lw $%s,%s\n",m,(yyvsp[0].D).cd);

				}
				else if((yyvsp[0].D).f==1){

					sprintf(buffer,"li $%s,%s\n",m,(yyvsp[0].D).cd);

				}
				else if((yyvsp[0].D).f==2){

					sprintf(buffer,"la $s5,%s\n",(yyvsp[0].D).cd);
					sprintf(buffer,"%slw $%s,%d(%s)\n",buffer,m,(yyvsp[0].D).n_cd,(yyvsp[0].D).cd);

				}
				else {

					sprintf(buffer,"la $s5,%s\n",(yyvsp[0].D).cd);
					sprintf(buffer,"%slw $s6,%s\n",buffer,(yyvsp[0].D).id_cd);
					sprintf(buffer,"%slw $%s,$s6(%s)\n",buffer,m,(yyvsp[0].D).cd);

				}

			}
			else{

				if((yyvsp[0].D).f==0){

					sprintf(buffer,"lw $s4,%s\n",(yyvsp[0].D).cd);

				}
				else if((yyvsp[0].D).f==1){

					sprintf(buffer,"li $s4,%s",(yyvsp[0].D).cd);
				}
				else if((yyvsp[0].D).f==2){

					sprintf(buffer,"la $s5,%s\n",(yyvsp[0].D).cd);
					sprintf(buffer,"%slw $s4,(%d)$s5\n",buffer,4*(yyvsp[0].D).n_cd);
				}
				else{

					sprintf(buffer,"la $s5,%s\n",(yyvsp[0].D).cd);
					sprintf(buffer,"%slw $s6,%s\n",buffer,(yyvsp[0].D).id_cd);
					sprintf(buffer,"%slw $s4,($s6)$s5\n",buffer);
				}
				sprintf(buffer,"%ssw $s4,(%s)arrray",buffer,m);

			}


			(yyval.E).cd=strdup(buffer);


		}
#line 1749 "y.tab.c" /* yacc.c:1645  */
    break;

  case 35:
#line 455 "new_parser.y" /* yacc.c:1645  */
    {
					(yyval.D).f=0;
					(yyval.D).cd=(yyvsp[0].code);
		}
#line 1758 "y.tab.c" /* yacc.c:1645  */
    break;

  case 36:
#line 459 "new_parser.y" /* yacc.c:1645  */
    {
			(yyval.D).f=1;
			(yyval.D).cd=(yyvsp[0].code);


		}
#line 1769 "y.tab.c" /* yacc.c:1645  */
    break;

  case 37:
#line 465 "new_parser.y" /* yacc.c:1645  */
    {
			(yyval.D).f=2;
			(yyval.D).cd=(yyvsp[-3].code);
			(yyval.D).n_cd=atoi((yyvsp[-1].code));
		}
#line 1779 "y.tab.c" /* yacc.c:1645  */
    break;

  case 38:
#line 470 "new_parser.y" /* yacc.c:1645  */
    {
			(yyval.D).f=3;
			(yyval.D).cd=(yyvsp[-3].code);
			(yyval.D).id_cd=(yyvsp[-1].code);
		}
#line 1789 "y.tab.c" /* yacc.c:1645  */
    break;


#line 1793 "y.tab.c" /* yacc.c:1645  */
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
#line 478 "new_parser.y" /* yacc.c:1903  */


void yyerror(char* s){
	fprintf(stderr,"\nError: %s in line %d\n",s,yylineno);
	exit(1);
}
int main (){
yyparse();
printf("li $v0,10\n");
printf("syscall\n");
return 0;
}
