/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 169 "compiler4.y" /* yacc.c:1909  */

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
	   	

#line 134 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
