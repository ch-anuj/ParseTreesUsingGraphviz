#include <iostream>
#include<string>
#include <cstring>
#include <cstdlib>
using namespace std;
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
void addNodeA(int id,char* label,A** tailA,A** headA){
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
	cout<<"--------------\n";
	A* temp = headA;
	while(temp!=NULL){
		cout<<temp->id<<" "<<temp->label<<endl;
		temp=temp->next;
	}
	temp = headA;
	B* helper;
	while(temp!=NULL){
		if(temp->right!=NULL){
			helper = temp->right;
			cout<<temp->id<<":";
			while(helper!=NULL){
				cout<<helper->id;
				helper = helper->next;
			}
			cout<<endl;
		}
		temp = temp->next;
	}
	cout<<"-------------\n";
}
int main(){
	A* headA = NULL;
	A* tailA = NULL;
	addNodeA(1,strdup("S"),&tailA,&headA);
	addNodeA(2,strdup("E"),&tailA,&headA);
	addNodeA(3,strdup("E"),&tailA,&headA);
	addNodeA(4,strdup("A"),&tailA,&headA);
	addNodeA(5,strdup("T"),&tailA,&headA);
	addNodeA(6,strdup("T"),&tailA,&headA);
	addNodeA(7,strdup("T"),&tailA,&headA);
	addNodeA(8,strdup("B"),&tailA,&headA);
	addNodeA(9,strdup("F"),&tailA,&headA);
	makeChild(1,2,headA);
	makeChild(2,3,headA);
	makeChild(2,4,headA);
	makeChild(2,5,headA);
	makeChild(3,6,headA);
	makeChild(6,7,headA);
	makeChild(6,8,headA);
	makeChild(6,9,headA);
	printGraph(headA);
	int k;
	for(int i=0;i<15;i++){
		k = findNode(i,headA);
		cout<<i<<","<<k<<endl;
	}
	return 0;
}