%{
#include <iostream>
#include<string>
#include <cstring>
#include <cstdlib>
#include"y.tab.h"
using namespace std;

%}

PLUS "+"
MULTIPLY "*"
NUM [0-9]+
WSPACE [ \t\n] 
OTHERS .


%option noyywrap
%option yylineno

%%

{NUM}		{
			cout<<"NUM ";
			strcpy(yylval.value.val,yytext);
			 return NUM;
			}
{PLUS}		{
			cout<<"PLUS ";
			strcpy(yylval.value.val,yytext);
			 return PLUS;
			}
{MULTIPLY}	{
			cout<<"MULTIPLY ";
			strcpy(yylval.value.val,yytext);
			 return MULTIPLY;
			}
{WSPACE}	{cout<<"WSPACE ";}
{OTHERS}		{cout<<"OTHERS ";}
%%



