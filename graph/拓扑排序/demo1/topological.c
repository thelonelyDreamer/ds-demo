#include<stdio.h>
#include<stdlib.h>

struct Edge{
	int headIndex;
	struct Edge* next;
};

struct Vertex{
	int data;
	struct Edge* firstEdge;
};
 
struct Graph{
	int totalVertex;
	struct Vertex* vertexArray;
};
typedef struct Graph Graph;

Graph* initGraph(int* arr,int n){
	// 忽略分配失败 
	Graph* temp = (Graph*)malloc(sizeof(Graph));
	temp->vertexArray=(struct Vertex*)malloc(sizeof(struct Vertex)*n);
	// 图的每个节点赋值 
	int i;
	for(i=0;i<n;i++){
		(temp->vertexArray+i)->data=*(arr+i); 
		(temp->vertexArray+i)->firstEdge=NULL; 
	}
	temp->totalVertex = n;
	return temp; 
}
void destroyGraph(Graph* g){
	free(g->vertexArray);
	free(g);
}

//  注意数组越界 
void countGraphInDegree(Graph* g,int* arr){
	int i;
	for(i=0;i<g->totalVertex;i++) arr[i]=0;
	struct Edge* temp;
	for(i=0;i<g->totalVertex;i++){
		temp = (g->vertexArray+i)->firstEdge;
		while(temp!=NULL){
			arr[temp->headIndex]+=1;
		} 
	}
}

struct StackNode{
	int data;
	struct StackNode* next;
};

struct StackInt{
	struct StackNode* next;
};
typedef struct StackInt StackInt;

StackInt* initStack(){
	StackInt* temp = (StackInt*)malloc(sizeof(StackInt));
	temp->next=NULL;
	return temp; 
}
void destroySatckInt(StackInt* stack){
	struct StackNode* p;
	struct StackNode* temp = stack->next;
	while(temp!=NULL){
		p=temp;
		temp =temp->next;
		free(p);
	}
}
void pushStackInt(int m,StackInt* stack){
	struct StackNode* p = (struct StackNode*)malloc(sizeof(struct StackNode));
	p->data =m;
	p->next = stack->next;
	stack->next=p;
}
int popStackInt(StackInt* stack){
	struct StackNode* p = stack->next;
	int ret=-1;
	if(p!=NULL){
		stack->next=p->next;
 		ret=p->data;
		free(p);
	}
	return ret; 
}
int isEmptyStackInt(StackInt* stack){
	if(stack->next!=NULL) return 0;
	else return 1;
}

int main(void){
	int arr[100];
	int i;
	for(i=0;i<100;i++) arr[i]=rand()%1000;
	Graph* g  = initGraph(arr,100);
	destroyGraph(g);
	return 0;
}
