//-----��������--���е���ʽ�洢�ṹ-----
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