%{
#include <stdio.h>

int regs[26];
int base;

%}

%start main_unit

%token IF O_BRAC C_BRAC OPEN_BRAC CLOSE_BRAC MAIN
%token SEMICOLON COLON DOT AMPERSAN PRECENT BACKSLASH ELSE WHILE SCAN PRINT INT CHAR FLOAT FOR GOTO SWITCH VOID
%token BREAK CASE CONTINUE RETURN COMMA	LETTER NUMBER	INTEGER FLOATING_INT IDENTIFIER

%right EQUALS NOT
%left OR EQEQ NEQ G_THAN L_THAN G_EQ L_EQ AND PLUS MINUS MULTIPLY DIVIDE


%%
/* Grammar Rules*/
// Needed to change the lexer therfor i am just working on the grammar part, you change the lexer then
// link it with yacc and try if its working fine or not.

//https://www.lysator.liu.se/c/ANSI-C-grammar-y.html#compound-`statement`
// source of grammar is mentioned abouve.
main_unit
			: func_decls main_decl
      ;

main_decl
			: type_spec MAIN O_BRAC param_list C_BRAC body
			;

func_decls
			: empty
			| func_decl
			| func_decls func_decl
			;

func_decl
			: type_spec IDENTIFIER O_BRAC param_list C_BRAC body
			;

type_spec
			: VOID
			| INT
			| FLOAT
			| CHAR
			;

param_list
			: empty
			| param_decl
			| param_list COMMA param_decl
			;

empty : ;

param_decl
			: decl_spec declarator
			;

decl_spec
			: type_spec
			;

declarator
			: IDENTIFIER
			| IDENTIFIER OBRAC expr CBRAC
			;

body
			: compound_stmt
			;

compound_stmt
			: OPEN_BRAC CLOSE_BRAC
			| OPEN_BRAC stmt_list CLOSE_BRAC
			| OPEN_BRAC decl_list CLOSE_BRAC
			| OPEN_BRAC decl_list stmt_list CLOSE_BRAC
			;

decl_list
			: declare
			| decl_list declare
			;

declare
			: decl_spec init_decl_list SEMICOLON
			;

init_decl_list
			: declarators
			| initializers
			;

initializers
			: assign_expr
			| OBRAC init_list CBRAC
			;

init_list
			: initialize
			| init_list COMMA initialize
			;

initialize
			: primary_expr
			;

declarators
			: declarator
			| declarators COMMA declarator
			;

stmt_list
			: stmt
			| stmt_list stmt
			;

stmt
			: compound_stmt
			| expr_stmt
			| select_stmt
			| iterate_stmt
			| jump_stmt
			| func_call_stmt
			;

func_call_stmt
			: with_return
			| without_return
			;

with_return
			: IDENTIFIER EQUALS IDENTIFIER O_BRAC call_param_list C_BRAC SEMICOLON
			;

without_return
			: IDENTIFIER O_BRAC call_param_list C_BRAC SEMICOLON
			;

call_param_list
			: empty
			| call_param
			| call_param_list COMMA call_param
			;

call_param
			: primary_expr
			;

expr_stmt
			: SEMICOLON
			| expr SEMICOLON
			;

// Grammar order should be changed.
primary_expr
			: IDENTIFIER
			| INTEGER
			| FLOATING_INT
			| O_BRAC expr C_BRAC
			;

postfix_expr
			: primary_expr
			| postfix_expr O_BRAC expr C_BRAC
			| postfix_expr O_BRAC C_BRAC
			| postfix_expr O_BRAC assign_expr C_BRAC
			;

// Can we keep sizeof expression
unary_expr
			: postfix_expr
			| SIZEOF unary_expr
			| SIZEOF O_BRAC type_name C_BRAC
			;

multiplicative_expr
			: unary_expr
			| multiplicative_expr MULTIPLY unary_expr
			| multiplicative_expr DIVIDE unary_expr
			| multiplicative_expr PRECENT unary_expr
			;

additive_expr
			: multiplicative_expr
			| additive_expr PLUS multiplicative_expr
			| additive_expr MINUS multiplicative_expr
			;

relational_expr
			: additive_expr
			| relational_expr L_THAN additive_expr
			| relational_expr G_THAN additive_expr
			| relational_expr L_EQ additive_expr
			| relational_expr G_EQ additive_expr
			;

equality_expr
			: relational_expr
			| equality_expr EQEQ relational_expr
			| equality_expr NEQ relational_expr
			;

and_expr
			: equality_expr
			| and_expr AMPERSAN equality_expr
			;

logical_and_expr
			: and_expr
			| logical_and_expr AND and_expr
			;

logical_or_expr
			: logical_and_exprfunc_call_stmtfunc_call_stmtfunc_call_stmt
			| logical_or_expr OR logical_and_expr
			;

conditional_expr
			: logical_or_expr
// should keep this				// | logical_or_expr '?' expr ':' conditional_expr
			;

assign_expr
			: conditional_expr
			| unary_expr assign_op assign_expr
			;

assign_op
			: EQUALS
			// | MUL_ASSIGN not found tokens for these.
			// | DIV_ASSIGN
			// | MOD_ASSIGN
			// | ADD_ASSIGN
			// | SUB_ASSIGN
			;

expr
			: assign_expr
			| expr COMMA assign_expr
			;

constant_expr
			: conditional_expr
			;

select_stmt
			: IF O_BRAC expr C_BRAC stmt
			| IF O_BRAC expr C_BRAC stmt ELSE stmt
			| SWITCH O_BRAC expr C_BRAC stmt
			;

iterate_stmt
			: WHILE O_BRAC expr O_BRAC stmt
			| DO stmt WHILE O_BRAC expr C_BRAC SEMICOLON
			| FOR O_BRAC expr_stmt expr_stmt O_BRAC stmt
			| FOR O_BRAC expr_stmt expr_stmt expr C_BRAC stmt
			;

jump_stmt
			: GOTO IDENTIFIER SEMICOLON
			| CONTINUE SEMICOLON
			| BREAK SEMICOLON
			| RETURN SEMICOLON
			| RETURN expr SEMICOLON
			;
%%

main()
{
 return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

yywrap()
{
  return(1);
}
