#include<stdio.h>
#include<stdlib.h>

#define ElementType int
#define bool char
#define true 1
#define false 0;

typedef struct Node{
	ElementType data;
	struct Node* next;
}Node,*PNode; 
 
typedef PNode LinkList;

bool swap2Element(LinkList head,PNode target){
	if(NULL==head->next) return false;
	PNode pre,p;
	pre=head;
	p=pre->next;
	while(p!=target&&NULL!=p){
		pre=p;
		p=p->next;
	}
	if(NULL==p||NULL==p->next) 
		return false;
	else{
		pre->next = p->next;
		p->next=pre->next->next;
		pre->next->next=p;
		return true;
	}
}

int main(int argc,char** argv){
	
	return 0;
}
 
