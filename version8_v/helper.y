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





%}


%union {
  struct{
  char val[15];
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
%type <value> decl_spec declarator
%type <value> compound_stmt expr_stmt stmt_list stmt iterate_stmt expr jump_stmt empty
%right  EQUALS NOT
%left  OR EQEQ NEQ G_THAN L_THAN G_EQ L_EQ AND PLUS MINUS MULTIPLY DIVIDE



%%



init_decl_list
      : declarators
      ;

declarators
      : declarator
      | declarator COMMA declarators
      ;
empty     
      :  {;}
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



%%




int main (){
  yyparse();
  cout<<endl;
  printGraph(headA);
  return 0;
}
