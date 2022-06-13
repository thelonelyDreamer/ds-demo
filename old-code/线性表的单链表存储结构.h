//-----线性表的单链表存储结构-----
#ifdef ElemType

typedef struct LNode{
	Elemtype data;
	struct LNode *next;
}LNode,*LinkList;

#endif