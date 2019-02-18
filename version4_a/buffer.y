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
int searchResult,nodeId=1,temp1,temp2,temp3,temp4,temp5,temp6;
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
	int flagC = 0;
	while(1){
		if(p->id==parent)break;
		p = p->next;
	}
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


%token <value> IF O_BRAC C_BRAC OPEN_BRAC CLOSE_BRAC MAIN THEN PERCENT ENDIF ENDWHILE NUM
%token <value> SEMICOLON COLON DOT AMPERSAN BACKSLASH ELSE WHILE SCAN PRINT INT CHAR FLOAT FOR GOTO SWITCH VOID
%token <value> BREAK CASE CONTINUE RETURN COMMA	LETTER NUMBER	INTEGER FLOATING_INT IDENTIFIER
%token <value> Obrac Cbrac

%type <value> main_unit main_decl func_decls body type_spec compound_stmt

%token <value> EQUALS NOT
%token <value> OR EQEQ NEQ G_THAN L_THAN G_EQ L_EQ AND PLUS MINUS MULTIPLY DIVIDE

///////////////////////////////////////////

%type <value> primary_expr multiplicative_expr additive_expr relational_expr equality_expr
%type <value> equality_expr logical_or_expr logical_and_expr assign_expr assign_op boolean_expr expr

////////////////////////////////////////////
%right  EQUALS NOT
%left  OR EQEQ NEQ G_THAN L_THAN G_EQ L_EQ AND PLUS MINUS MULTIPLY DIVIDE

%%
main_unit
			: func_decls main_decl{
									cout<<"1";
									temp1 = addNodeA(nodeId++,strdup("func_decls"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("main_unit"),&tailA,&headA);
									$$.nodeId = temp2;
									$1.nodeId = temp1;
									makeChild($$.nodeId,$1.nodeId,headA);
									makeChild($$.nodeId,$2.nodeId,headA);
			}
      ;
func_decls
			: empty				{
									cout<<"2";

			}
			;
main_decl
			: type_spec MAIN O_BRAC empty C_BRAC body
			{
									cout<<"3";
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
type_spec
			: VOID
			| INT {
									cout<<"6";
									temp1 = addNodeA(nodeId++,strdup("type_spec"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("INT"),&tailA,&headA);
									$$.nodeId = temp1;
									$1.nodeId = temp2;
									makeChild($$.nodeId,$1.nodeId,headA);


			}
			| FLOAT
			| CHAR
			;

empty 		:
			;

body
			: compound_stmt {
									cout<<"4";
									temp1 = addNodeA(nodeId++,strdup("body"),&tailA,&headA);
									$$.nodeId = temp1;
									makeChild($$.nodeId,$1.nodeId,headA);


			}
			;

compound_stmt
			: OPEN_BRAC CLOSE_BRAC{
									cout<<"5";
									temp1 = addNodeA(nodeId++,strdup("compound_stmt"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("OPEN_BRAC"),&tailA,&headA);
									temp3 = addNodeA(nodeId++,strdup("CLOSE_BRAC"),&tailA,&headA);
									$$.nodeId = temp1;
									$1.nodeId = temp2;
									$2.nodeId = temp3;
									makeChild($$.nodeId,$1.nodeId,headA);
									makeChild($$.nodeId,$2.nodeId,headA);

			}
      // to be removed.
      |OPEN_BRAC expr CLOSE_BRAC
			;

/////////////////////////////////////////anuj, bitch////////////////////////////////////////////////////////////////
primary_expr
			: IDENTIFIER
			| INTEGER
			| FLOATING_INT
			| O_BRAC expr C_BRAC
			;

multiplicative_expr
			: primary_expr
			| multiplicative_expr MULTIPLY primary_expr
			| multiplicative_expr DIVIDE primary_expr
			| multiplicative_expr PERCENT primary_expr
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

logical_and_expr
			: equality_expr
			| logical_and_expr AND equality_expr
			;

logical_or_expr
			: logical_and_expr
			| logical_or_expr OR logical_and_expr
			;

assign_expr
			: primary_expr assign_op logical_or_expr{
                    cout<<"18";
                    temp1 = addNodeA(nodeId++,strdup("assign_expr"),&tailA,&headA);
                    $$.nodeId = temp1;
                    makeChild($$.nodeId,$1.nodeId,headA);
                    makeChild($$.nodeId,$2.nodeId,headA);
                    makeChild($$.nodeId,$3.nodeId,headA);
      }
			;

assign_op
      : EQUALS  {
                    cout<<"16";
                    temp1 = addNodeA(nodeId++,strdup("assign_op"),&tailA,&headA);
                    temp2 = addNodeA(nodeId++,strdup("EQUALS"),&tailA,&headA);
                    $$.nodeId = temp1;
                    $1.nodeId = temp2;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
      ;

boolean_expr
      : logical_or_expr {
                    cout<<"14";
                    temp1 = addNodeA(nodeId++,strdup("boolean_expr"),&tailA,&headA);
                    $$.nodeId = temp1;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
			;

expr
			: assign_expr {
                    cout<<"10";
                    temp1 = addNodeA(nodeId++,strdup("expr"),&tailA,&headA);
                    $$.nodeId = temp1;
                    makeChild($$.nodeId,$1.nodeId,headA);
      }
      | boolean_expr {
                    cout<<"12";
                    temp1 = addNodeA(nodeId++,strdup("expr"),&tailA,&headA);
                    $$.nodeId = temp1;
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
