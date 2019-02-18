%{
#include <iostream>
#include<string>
#include <cstring>
using namespace std;
extern int yylex();
extern int yylineno;
void yyerror (const char* s) {
  cout<<s<<endl;
}


%}


%union {
	struct{
	char val[15];
	}value;	
}

%token <value> NUM PLUS MULTIPLY
%type <value> E T F



%%
S:		E	{cout<<"1";}
		;
E:		 E PLUS T	{cout<<"2";}	
		|T	{cout<<"3";}
		;
T:		 T MULTIPLY F	{cout<<"4";}
		|F	{cout<<"5";}
		;
F:		 '('E')'	{cout<<"6";}
		|NUM		{cout<<"7";}
		;
%%




int main (){
yyparse();
return 0;
}
