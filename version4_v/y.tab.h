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
#line 119 "b_4.y" /* yacc.c:1909  */

	struct{
	char val[15];
	int nodeId;
	}value;	

#line 173 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
