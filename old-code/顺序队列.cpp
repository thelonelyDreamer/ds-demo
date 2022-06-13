#include<stdio.h>
#define ElemType int
#define MaxSize 100

typedef struct Queue{
	ElemType data[MaxSize];
	int front,rear;
}Queue;

void InitQueue(Queue &Q);
bool isEmpty(Queue Q);
bool EnQueue(Queue &Q,ElemType x);
bool DeQueue(Queue &Q,ElemType &x);

int main(void){
	Queue Q;
	InitQueue(Q);
	int i;
	ElemType y,x[5]={2,5,3,2,3};
	for(i=0;i<5;i++)
		EnQueue(Q,x[i]);
	for(i=0;i<5;i++){
		DeQueue(Q,y);
		printf("%d\n",y);
	}

	return 0;
}

void InitQueue(Queue &Q){
	Q.front=Q.rear=0;
}

bool isEmpty(Queue Q){
	if(Q.front=Q.rear)
		return true;
	else
		return false;
}

bool EnQueue(Queue &Q,ElemType x){
	if((Q.rear+1)%MaxSize==Q.front)
		return false;
	Q.data[(Q.rear)]=x;
	Q.rear=(Q.rear+1)%MaxSize;
	return true;
}

bool DeQueue(Queue &Q,ElemType &x){
	if(Q.rear==Q.front)
		return false;
	x=Q.data[Q.front];
	Q.front =(Q.front+1)%MaxSize;
	return true;
}