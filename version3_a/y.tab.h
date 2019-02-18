/* A Bison parser, made by GNU Bison 3.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    SEMICOLON = 269,
    COLON = 270,
    DOT = 271,
    AMPERSAN = 272,
    PRECENT = 273,
    BACKSLASH = 274,
    ELSE = 275,
    WHILE = 276,
    SCAN = 277,
    PRINT = 278,
    INT = 279,
    CHAR = 280,
    FLOAT = 281,
    FOR = 282,
    GOTO = 283,
    SWITCH = 284,
    VOID = 285,
    BREAK = 286,
    CASE = 287,
    CONTINUE = 288,
    RETURN = 289,
    COMMA = 290,
    LETTER = 291,
    NUMBER = 292,
    INTEGER = 293,
    FLOATING_INT = 294,
    IDENTIFIER = 295,
    Obrac = 296,
    Cbrac = 297,
    EQUALS = 298,
    NOT = 299,
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
#define ENDWHILE 267
#define NUM 268
#define SEMICOLON 269
#define COLON 270
#define DOT 271
#define AMPERSAN 272
#define PRECENT 273
#define BACKSLASH 274
#define ELSE 275
#define WHILE 276
#define SCAN 277
#define PRINT 278
#define INT 279
#define CHAR 280
#define FLOAT 281
#define FOR 282
#define GOTO 283
#define SWITCH 284
#define VOID 285
#define BREAK 286
#define CASE 287
#define CONTINUE 288
#define RETURN 289
#define COMMA 290
#define LETTER 291
#define NUMBER 292
#define INTEGER 293
#define FLOATING_INT 294
#define IDENTIFIER 295
#define Obrac 296
#define Cbrac 297
#define EQUALS 298
#define NOT 299
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
#line 119 "b_3.y" /* yacc.c:1906  */

	struct{
	char val[15];
	int nodeId;
	}value;	

#line 176 "y.tab.h" /* yacc.c:1906  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
