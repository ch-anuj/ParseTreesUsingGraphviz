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


%token <value> IF O_BRAC C_BRAC OPEN_BRAC CLOSE_BRAC MAIN THEN PERCENT ENDIF NUM
%token <value> SEMICOLON COLON DOT AMPERSAN PRECENT BACKSLASH ELSE SCAN PRINT INT CHAR FLOAT WHILE GOTO SWITCH VOID
%token <value> BREAK CASE CONTINUE RETURN COMMA	LETTER NUMBER	INTEGER FLOATING_INT IDENTIFIER
%token <value> Obrac Cbrac 
%token <value> EQUALS NOT DO FOR
%token <value> OR EQEQ NEQ G_THAN L_THAN G_EQ L_EQ AND PLUS MINUS MULTIPLY DIVIDE


%type <value> main_unit main_decl func_decls body type_spec 
%type <value> compound_stmt expr_stmt stmt_list stmt iterate_stmt expr
%right  EQUALS NOT
%left  OR EQEQ NEQ G_THAN L_THAN G_EQ L_EQ AND PLUS MINUS MULTIPLY DIVIDE



%%
main_unit
			: func_decls main_decl{
									cout<<"1 ";
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
									cout<<"2 ";
									
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
			| FLOAT {
									cout<<"13 ";
									temp1 = addNodeA(nodeId++,strdup("type_spec"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("FLOAT"),&tailA,&headA);
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

empty 		: 
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

		//	| OPEN_BRAC decl_list CLOSE_BRAC		//declarations to be added later
		//	| OPEN_BRAC decl_list stmt_list CLOSE_BRAC
			;
stmt_list
			: stmt  			 {
									cout<<"19 ";
									temp1 = addNodeA(nodeId++,strdup("stmt_list"),&tailA,&headA);
									$$.nodeId = temp1;
									makeChild($$.nodeId,$1.nodeId,headA);

									
									}
			| stmt_list stmt 		{
									cout<<"21 ";
									temp1 = addNodeA(nodeId++,strdup("stmt_list"),&tailA,&headA);
									$$.nodeId = temp1;
									makeChild($$.nodeId,$1.nodeId,headA);
									makeChild($$.nodeId,$2.nodeId,headA);

									
									}
			;
stmt
			: compound_stmt			{
									cout<<"23 ";
									temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
									$$.nodeId = temp1;
									makeChild($$.nodeId,$1.nodeId,headA);

									
									}
			| expr_stmt 			{
									cout<<"25 ";
									temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
									$$.nodeId = temp1;
									makeChild($$.nodeId,$1.nodeId,headA);

									
									}
			//| select_stmt		// if else switch to be done later
			| iterate_stmt 			{
									cout<<"27 ";
									temp1 = addNodeA(nodeId++,strdup("stmt"),&tailA,&headA);
									$$.nodeId = temp1;
									makeChild($$.nodeId,$1.nodeId,headA);

									
									}
			// | func_call_stmt //to be done later
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
			| expr SEMICOLON  {
									cout<<"31 ";
									temp1 = addNodeA(nodeId++,strdup("expr_stmt"),&tailA,&headA);
									temp2 = addNodeA(nodeId++,strdup("SEMICOLON"),&tailA,&headA);
									temp3 = addNodeA(nodeId++,strdup("expr"),&tailA,&headA);
									$$.nodeId = temp1;
									$1.nodeId = temp3;
									$2.nodeId = temp2;
									makeChild($$.nodeId,$1.nodeId,headA);
									makeChild($$.nodeId,$2.nodeId,headA);
								}
			;
expr 		
			: empty   {cout<<"33 ";}
			;
iterate_stmt
			: WHILE O_BRAC expr C_BRAC stmt {
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
									$4.nodeId = temp4;
									makeChild($$.nodeId,$1.nodeId,headA);
									makeChild($$.nodeId,$2.nodeId,headA);
									makeChild($$.nodeId,$3.nodeId,headA);
									makeChild($$.nodeId,$4.nodeId,headA);
									makeChild($$.nodeId,$5.nodeId,headA);

			}
			| DO stmt WHILE O_BRAC expr C_BRAC SEMICOLON {
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
			| FOR O_BRAC expr_stmt expr_stmt expr C_BRAC stmt {

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
