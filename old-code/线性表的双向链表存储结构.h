//-----���Ա��˫������洢�ṹ-----
#ifdef ElemType

typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;

#endif