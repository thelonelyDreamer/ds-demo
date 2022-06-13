//-----循环队列--队列的顺序存储结构-----
#ifdef ElemType
#define MAXSIZE 100

typedef struct{
	ElemType *base;
	int front;
	int rear;
}SqQueue；