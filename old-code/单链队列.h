//-----单链队列--队列的链式存储结构-----
#ifdef ElemType

typedef struct QNode{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

#endif