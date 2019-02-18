%{
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





%}


%union {
  struct{
  char val[25];
  int nodeId;
  }value;
}


%token <value> IF O_BRAC C_BRAC OPEN_BRAC CLOSE_BRAC MAIN THEN PERCENT ENDIF NUM
%token <value> SEMICOLON COLON DOT AMPERSAN PRECENT BACKSLASH ELSE SCAN PRINT INT CHAR FLOAT WHILE GOTO SWITCH VOID
%token <value> BREAK CASE CONTINUE RETURN COMMA LETTER NUMBER INTEGER FLOATING_INT IDENTIFIER
%token <value> Obrac Cbrac
%token <value> EQUALS NOT DO FOR
%token <value> OR EQEQ NEQ G_THAN L_THAN G_EQ L_EQ AND PLUS MINUS MULTIPLY DIVIDE


%type <value> main_unit main_decl func_decls func_decl body type_spec param_list param_decl
%type <value> decl_spec declarator declarators init_decl_list declare decl_list
%type <value> compound_stmt expr_stmt stmt_list stmt iterate_stmt log_or_expr jump_stmt empty
%type <value> func_call_stmt with_return without_return call_param_list non_empty_param_list empty_param_list
%type <value> if_stmt primary_expr mul_expr add_expr relational_expr equality_expr log_and_expr assgn_expr
%right  EQUALS NOT
%left  OR EQEQ NEQ G_THAN L_THAN G_EQ L_EQ AND PLUS MINUS MULTIPLY DIVIDE



%%
main_unit
      : func_decls main_decl{
                  cout<<"1 ";
                  temp2 = addNodeA(nodeId++,strdup("main_unit"),&tailA,&headA);
                  $$.nodeId = temp2;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
      }
      | main_decl{
                  cout<<"71 ";
                  temp1 = addNodeA(nodeId++,strdup("main_unit"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);

      }
      ;
func_decls
      : func_decl  {
                  cout<<"43 ";
                  temp1 = addNodeA(nodeId++,strdup("func_decls"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
      }
      | func_decls func_decl  {
                  cout<<"45 ";
                  temp1 = addNodeA(nodeId++,strdup("func_decls"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
      }
      ;
main_decl
      : type_spec MAIN O_BRAC empty C_BRAC body
      {
                  cout<<"3 ";
                  temp1 = addNodeA(nodeId++,strdup("MAIN"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("main_decl"),&tailA,&headA);
                  $$.nodeId = temp4;
                  $2.nodeId = temp1;
                  $3.nodeId = temp2;
                  $5.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);
                  makeChild($$.nodeId,$6.nodeId,headA);

      }
      ;

func_decl
      : type_spec IDENTIFIER O_BRAC param_list C_BRAC body {
                  cout<<"47 ";
                  temp1 = addNodeA(nodeId++,strdup("func_decl"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $2.nodeId = temp2;
                  $3.nodeId = temp3;
                  $5.nodeId = temp4;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);
                  makeChild($$.nodeId,$6.nodeId,headA);

      }
      ;
type_spec
      : VOID {
                  cout<<"11 ";
                  temp1 = addNodeA(nodeId++,strdup("type_spec"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("VOID"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  makeChild($$.nodeId,$1.nodeId,headA);
      }
      | INT {
                  cout<<"6 ";
                  temp1 = addNodeA(nodeId++,strdup("type_spec"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("INT"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  makeChild($$.nodeId,$1.nodeId,headA);


      }
      | CHAR {
                  cout<<"15 ";
                  temp1 = addNodeA(nodeId++,strdup("type_spec"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("CHAR"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  makeChild($$.nodeId,$1.nodeId,headA);
      }
      ;

empty
      :  {;}
      ;

param_list
      : empty {    cout<<"69 ";
                    temp1= addNodeA(nodeId++,strdup("param_list"),&tailA,&headA);
                    $$.nodeId = temp1;
        }
      | param_decl {
                  cout<<"49 ";
                  temp1 = addNodeA(nodeId++,strdup("param_list"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
      }
      | param_list COMMA param_decl {
                  cout<<"51 ";
                  temp1 = addNodeA(nodeId++,strdup("param_list"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("COMMA"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $2.nodeId = temp2;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
      }
      ;
param_decl
      : decl_spec declarator {
                  cout<<"53 ";
                  temp1 = addNodeA(nodeId++,strdup("param_decl"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
      }
      ;
decl_spec
      : type_spec {
                cout<<"55 ";
                temp1 = addNodeA(nodeId++,strdup("decl_spec"),&tailA,&headA);
                $$.nodeId = temp1;
                makeChild($$.nodeId,$1.nodeId,headA);
      }
      ;

declarator
      : IDENTIFIER {
                cout<<"57 ";
                temp1 = addNodeA(nodeId++,strdup("declarator"),&tailA,&headA);
                temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                $$.nodeId = temp1;
                $1.nodeId = temp2;
                makeChild($$.nodeId,$1.nodeId,headA);
      }
      ;
body
      : compound_stmt {
                  cout<<"4 ";
                  temp1 = addNodeA(nodeId++,strdup("body"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);


      }
      ;

compound_stmt
      : OPEN_BRAC CLOSE_BRAC{
                  cout<<"5 ";
                  temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);

      }

      | OPEN_BRAC stmt_list CLOSE_BRAC {
                  cout<<"17 ";
                  temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $3.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);

      }

      | OPEN_BRAC decl_list CLOSE_BRAC  {
                  cout<<"85 ";
                  temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $3.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);

      }
      | OPEN_BRAC decl_list stmt_list CLOSE_BRAC {
                  cout<<"87 ";
                  temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $4.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
      }
      ;
decl_list
      : declare {
                  cout<<"73 ";
                  temp1 = addNodeA(nodeId++,strdup("decl_list"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);

      }
      | decl_list declare {
                  cout<<"75 ";
                  temp1 = addNodeA(nodeId++,strdup("decl_list"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
      }
      ;
declare
      : decl_spec init_decl_list SEMICOLON {
                  cout<<"77 ";
                  temp1 = addNodeA(nodeId++,strdup("declare"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $3.nodeId = temp2;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);



      }
      ;
init_decl_list
      : declarators {
                cout<< "79 ";
                temp1 = addNodeA(nodeId++,strdup("init_decl_list"),&tailA,&headA);
                $$.nodeId = temp1;
                makeChild($$.nodeId,$1.nodeId,headA);
      }
      ;
declarators
      : declarator {
                cout<< "81 ";
                temp1 = addNodeA(nodeId++,strdup("declarators"),&tailA,&headA);
                $$.nodeId = temp1;
                makeChild($$.nodeId,$1.nodeId,headA);
      }
      | declarator COMMA declarators {
                cout<<"83 ";
                temp1 = addNodeA(nodeId++,strdup("declarators"),&tailA,&headA);
                temp2 = addNodeA(nodeId++,strdup("COMMA"),&tailA,&headA);
                $$.nodeId = temp1;
                $2.nodeId = temp2;
                makeChild($$.nodeId,$1.nodeId,headA);
                makeChild($$.nodeId,$2.nodeId,headA);
                makeChild($$.nodeId,$3.nodeId,headA);


      }
      ;
stmt_list
      : stmt         {
                  cout<<"19 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt_list"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);


                  }
      | stmt_list stmt    {
                  cout<<"21 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt_list"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);


                  }
      ;
stmt
      : compound_stmt     {
                  cout<<"23 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);


                  }
      | expr_stmt       {
                  cout<<"25 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);


                  }
      | iterate_stmt      {
                  cout<<"27 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);


                  }
      | func_call_stmt  {
                  cout<<"91 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
         }
      | jump_stmt  {
                  cout<<"59 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  }
      | if_stmt {
                  cout<<"68 ";
                  temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  }
      ;

if_stmt
      : IF O_BRAC log_or_expr C_BRAC body{
                  cout<<"72";
                  temp1 = addNodeA(nodeId++,strdup("if_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IF"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  $4.nodeId = temp4;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);
      }
      | IF O_BRAC log_or_expr C_BRAC body ELSE body{
                  cout<<"74";
                  temp1 = addNodeA(nodeId++,strdup("if_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IF"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("ELSE"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  $4.nodeId = temp4;
                  $6.nodeId = temp5;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);
                  makeChild($$.nodeId,$6.nodeId,headA);
                  makeChild($$.nodeId,$7.nodeId,headA);
      }
      ;

func_call_stmt// modified grammar to eliminate reduce/reduce conflict
      : assgn_expr {
                  cout<<"93 ";
                  temp1 = addNodeA(nodeId++,strdup("func_call_stmt"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);

      }
      | without_return {
                  cout<<"95 ";
                  temp1 = addNodeA(nodeId++,strdup("func_call_stmt"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
      }
      ;
with_return
      : IDENTIFIER O_BRAC call_param_list C_BRAC SEMICOLON {
                  cout<<"97 ";
                  temp1 = addNodeA(nodeId++,strdup("with_return"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp6 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp7 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp5;
                  $4.nodeId = temp6;
                  $5.nodeId = temp7;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);
      }
      ;
without_return
      : IDENTIFIER O_BRAC call_param_list C_BRAC SEMICOLON {
                  cout<<"99 ";
                  temp1 = addNodeA(nodeId++,strdup("without_return"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  $4.nodeId = temp4;
                  $5.nodeId = temp5;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);
      }
      ;
call_param_list
      : empty_param_list {
                  cout<<"101 ";
                  temp1 = addNodeA(nodeId++,strdup("call_param_list"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
      }
      | non_empty_param_list {
                  cout<<"103 ";
                  temp1 = addNodeA(nodeId++,strdup("call_param_list"),&tailA,&headA);
                  $$.nodeId = temp1;
                  makeChild($$.nodeId,$1.nodeId,headA);
      }
      ;
empty_param_list
      : empty {
                  cout<<"107 ";
                  temp1 = addNodeA(nodeId++,strdup("empty_param_list"),&tailA,&headA);
                  $$.nodeId = temp1;

      }
      ;
non_empty_param_list
      : IDENTIFIER {
                  cout<<"105 ";
                  temp1 = addNodeA(nodeId++,strdup("non_empty_param_list"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  makeChild($$.nodeId,$1.nodeId,headA);

            }
      | call_param_list COMMA IDENTIFIER   //ideally it should be expression instead of identifier which I will do later
        {
                  cout<<"107 ";
                  temp1 = addNodeA(nodeId++,strdup("non_empty_param_list"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("COMMA"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $2.nodeId = temp2;
                  $3.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);

        }
      ;

jump_stmt
      : CONTINUE SEMICOLON {
                  cout<<"61 ";
                  temp1 = addNodeA(nodeId++,strdup("jump_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("CONTINUE"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  }
      | BREAK SEMICOLON  {
                  cout<<"63 ";
                  temp1 = addNodeA(nodeId++,strdup("jump_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("BREAK"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  }
      | RETURN SEMICOLON {
                  cout<<"65 ";
                  temp1 = addNodeA(nodeId++,strdup("jump_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("RETURN"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  }
      | RETURN log_or_expr SEMICOLON {
                  cout<<"67 ";
                  temp1 = addNodeA(nodeId++,strdup("jump_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("RETURN"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $3.nodeId = temp3;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  }
      ;
expr_stmt
      : SEMICOLON  {
                  cout<<"29 ";
                  temp1 = addNodeA(nodeId++,strdup("expr_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  makeChild($$.nodeId,$1.nodeId,headA);
      }
      | assgn_expr SEMICOLON  {
                  cout<<"31 ";
                  temp1 = addNodeA(nodeId++,strdup("expr_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $2.nodeId = temp2;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                }
      ;

////////////////////////////////////
primary_expr
			: IDENTIFIER{
                    cout<<"56";
                    temp1 = addNodeA(nodeId++,strdup("primary_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("IDENTIFIER"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $1.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
			| NUM{
                    cout<<"58";
                    temp1 = addNodeA(nodeId++,strdup("primary_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("NUM"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $1.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
			;

mul_expr
			: primary_expr{
                    cout<<"46";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    $$.nodeId = temp1;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
			| mul_expr MULTIPLY primary_expr{
                    cout<<"42";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("MULTIPLY"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			| mul_expr DIVIDE primary_expr{
                    cout<<"44";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("DIVIDE"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
      | mul_expr PERCENT primary_expr{
                    cout<<"46";
                    temp1 = addNodeA(nodeId++,strdup("mul_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("PERCENT"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			;

add_expr
			: mul_expr{
                    cout<<"48";
                    temp1 = addNodeA(nodeId++,strdup("add_expr"),&tailA,&headA);
                    $$.nodeId = temp1;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
			| add_expr PLUS mul_expr{
                    cout<<"50";
                    temp1 = addNodeA(nodeId++,strdup("add_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("PLUS"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			| add_expr MINUS mul_expr{
                    cout<<"52";
                    temp1 = addNodeA(nodeId++,strdup("add_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("MINUS"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }

			;



relational_expr
			: add_expr{
                    cout<<"32";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    $$.nodeId = temp1;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
			| relational_expr L_THAN add_expr{
                    cout<<"34";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("L_THAN"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			| relational_expr G_THAN add_expr{
                    cout<<"36";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("G_THAN"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			| relational_expr L_EQ add_expr{
                    cout<<"38";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("L_EQ"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			| relational_expr G_EQ add_expr{
                    cout<<"40";
                    temp1 = addNodeA(nodeId++,strdup("relational_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("G_EQ"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			;

equality_expr
			: relational_expr{
                    cout<<"30";
                    temp1 = addNodeA(nodeId++,strdup("equality_expr"),&tailA,&headA);
                    $$.nodeId = temp1;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
			| equality_expr EQEQ relational_expr{
                    cout<<"26";
                    temp1 = addNodeA(nodeId++,strdup("equality_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("EQEQ"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			| equality_expr NEQ relational_expr{
                    cout<<"28";
                    temp1 = addNodeA(nodeId++,strdup("equality_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("NEQ"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			;

log_and_expr
			: equality_expr{
                    cout<<"22";
                    temp1 = addNodeA(nodeId++,strdup("log_and_expr"),&tailA,&headA);
                    $$.nodeId = temp1;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
			| log_and_expr AND equality_expr{
                    cout<<"24";
                    temp1 = addNodeA(nodeId++,strdup("log_and_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("AND"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			;

log_or_expr
			: log_and_expr{
                    cout<<"18";
                    temp1 = addNodeA(nodeId++,strdup("log_or_expr"),&tailA,&headA);
                    $$.nodeId = temp1;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
			| log_or_expr OR log_and_expr{
                    cout<<"20";
                    temp1 = addNodeA(nodeId++,strdup("log_or_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("OR"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			;

assgn_expr// modified grammar to eliminate reduce/reduce conflict
			: primary_expr EQUALS log_or_expr{
                    cout<<"12";
                    temp1 = addNodeA(nodeId++,strdup("assgn_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("EQUALS"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
      | primary_expr EQUALS with_return{
                    cout<<"12";
                    temp1 = addNodeA(nodeId++,strdup("assgn_expr"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("EQUALS"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $2.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			;


//////////////////////////////////////
iterate_stmt
      : WHILE O_BRAC log_or_expr C_BRAC stmt {
                  cout<<"35 ";
                  temp1 = addNodeA(nodeId++,strdup("iterate_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("WHILE"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("expr"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  $3.nodeId = temp4;
                  $4.nodeId = temp5;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);

      }
      | DO stmt WHILE O_BRAC log_or_expr C_BRAC SEMICOLON {
                  cout<<"37 ";
                  temp1 = addNodeA(nodeId++,strdup("iterate_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("DO"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("WHILE"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("expr"),&tailA,&headA);
                  temp6 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  temp7 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $3.nodeId = temp3;
                  $4.nodeId = temp4;
                  $5.nodeId = temp5;
                  $6.nodeId = temp6;
                  $7.nodeId = temp7;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);
                  makeChild($$.nodeId,$6.nodeId,headA);
                  makeChild($$.nodeId,$7.nodeId,headA);
      }
      | FOR O_BRAC expr_stmt expr_stmt C_BRAC stmt {

                  cout<<"39 ";
                  temp1 = addNodeA(nodeId++,strdup("iterate_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("FOR"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  $5.nodeId = temp4;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);
                  makeChild($$.nodeId,$6.nodeId,headA);
      }
      | FOR O_BRAC expr_stmt expr_stmt log_or_expr C_BRAC stmt {

                  cout<<"41 ";
                  temp1 = addNodeA(nodeId++,strdup("iterate_stmt"),&tailA,&headA);
                  temp2 = addNodeA(nodeId++,strdup("FOR"),&tailA,&headA);
                  temp3 = addNodeA(nodeId++,strdup("O_BRAC"),&tailA,&headA);
                  temp4 = addNodeA(nodeId++,strdup("expr"),&tailA,&headA);
                  temp5 = addNodeA(nodeId++,strdup("C_BRAC"),&tailA,&headA);
                  $$.nodeId = temp1;
                  $1.nodeId = temp2;
                  $2.nodeId = temp3;
                  $5.nodeId = temp4;
                  $6.nodeId = temp5;
                  makeChild($$.nodeId,$1.nodeId,headA);
                  makeChild($$.nodeId,$2.nodeId,headA);
                  makeChild($$.nodeId,$3.nodeId,headA);
                  makeChild($$.nodeId,$4.nodeId,headA);
                  makeChild($$.nodeId,$5.nodeId,headA);
                  makeChild($$.nodeId,$6.nodeId,headA);
                  makeChild($$.nodeId,$7.nodeId,headA);
                      }
      ;

%%




int main (){
  yyparse();
  cout<<endl;
  printGraph(headA);
  return 0;
}
