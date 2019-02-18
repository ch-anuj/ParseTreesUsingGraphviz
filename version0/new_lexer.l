%{
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include "y.tab.h"

%}



EQUALS "="
PLUS "+"
MINUS "-"
MULTIPLY "*"
DIVIDE "/"
EQEQ "=="
NEQ "!="
G_THAN ">"
L_THAN "<"
G_EQ ">="
L_EQ "<="
AND "&&"
OR "||"
NOT "!"
IF if
O_BRAC "("
C_BRAC ")"
Obrac "["
Cbrac "]"
THEN then
ENDIF endif
ELSE else
WHILE while
ENDWHILE endwhile
SCAN scan
PRINT print
INT int
ENDCOLON [;]
COMMA	[,]
LETTER	[a-zA-Z]
NUMBER	[0-9]
NUM [0-9]+
id {LETTER}({LETTER}|{NUMBER})*
WSPACE	[ \t\n]+


%option noyywrap
%option yylineno


%%

{EQUALS}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return EQUALS;  }
{PLUS}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
 					 return PLUS; }
{MINUS}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return MINUS;  }
{MULTIPLY}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return MULTIPLY; }
{DIVIDE}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return DIVIDE; }
{EQEQ}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return EQEQ;  }
{NEQ}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return NEQ;  }
{G_THAN}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return G_THAN;  }
{L_THAN}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return L_THAN;  }
{G_EQ}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return G_EQ;  }
{L_EQ}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return L_EQ;  }
{AND}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return AND;  }
{OR}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return OR;  }
{NOT}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return NOT;  }
{IF} 				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return IF;  }
{O_BRAC}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return O_BRAC;  }
{C_BRAC}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return C_BRAC;  }
{THEN}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return THEN;  }
{ENDIF}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return ENDIF;  }
{ELSE}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return ELSE;  }
{WHILE}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return WHILE;  }
{ENDWHILE}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return ENDWHILE;  }
{SCAN}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return SCAN;  }
{PRINT}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return PRINT;  }
{INT}			{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
				 return INT;}
{COMMA}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					return yytext[0];}

{id}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return id; }
{NUM}				{cout << "";
 	 	 	 	 	 	strcpy(yylval.value.val,yytext);
					 return NUM;}
{WSPACE}			{;}
{Obrac}					{return Obrac;}
{Cbrac}					{return Cbrac;}


%%
