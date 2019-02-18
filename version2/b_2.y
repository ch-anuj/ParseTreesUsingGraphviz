%{
#include <iostream>
#include<string>
#include <cstring>
#include <cstdlib>
using namespace std;
extern int yylex();
extern int yylineno;
void yyerror (const char* s) {
  cout<<s<<endl;
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
int searchResult,nodeId=1,temp1,temp2,temp3,temp4;
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

%token <value> NUM PLUS MULTIPLY
%type <value> S E T F



%%
S:		E				{
						cout<<"1";
						temp1 = addNodeA(nodeId++,strdup("S"),&tailA,&headA);
						$$.nodeId = temp1;
						makeChild($$.nodeId,$1.nodeId,headA);
						}
		;
E:		 E PLUS T		{
						cout<<"2";
						temp1 = addNodeA(nodeId++,strdup("PLUS"),&tailA,&headA);
						$2.nodeId  = temp1;
						temp2 = addNodeA(nodeId++,strdup("E"),&tailA,&headA);
						$$.nodeId = temp2;
						makeChild($$.nodeId,$1.nodeId,headA);
						makeChild($$.nodeId,$2.nodeId,headA);
						makeChild($$.nodeId,$3.nodeId,headA);
						}	
		|T				{
						cout<<"3";
						temp1 = addNodeA(nodeId++,strdup("E"),&tailA,&headA);
						$1.nodeId  = temp1;
						makeChild($$.nodeId,$1.nodeId,headA);
						}
		;
T:		 T MULTIPLY F	{
							cout<<"4";
							temp1 = addNodeA(nodeId++,strdup("MULTIPLY"),&tailA,&headA);
							temp2 = addNodeA(nodeId++,strdup("T"),&tailA,&headA);
							$$.nodeId = temp2;
							$2.nodeId = temp1;
							makeChild($$.nodeId,$1.nodeId,headA);
							makeChild($$.nodeId,$2.nodeId,headA);
							makeChild($$.nodeId,$3.nodeId,headA);
						}
		|F			{
					cout<<"5";
					temp1 = addNodeA(nodeId++,strdup("T"),&tailA,&headA);
					$$.nodeId = temp1;
					makeChild($$.nodeId,$1.nodeId,headA);
					}
		;
F:		 '('E')'	{cout<<"6";}
		|NUM		{
						cout<<"7";
						temp1=addNodeA(nodeId++,strdup("NUM"),&tailA,&headA);
						temp2=addNodeA(nodeId++,strdup("F"),&tailA,&headA);
						$1.nodeId = temp1;
						$$.nodeId = temp2; 
						makeChild($$.nodeId,$1.nodeId,headA);
					}
		;
%%




int main (){
	yyparse();
	printGraph(headA);
	return 0;
}
