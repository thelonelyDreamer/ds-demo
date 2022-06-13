typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *link;
}LNode,*Linklist;
int Search_k(Linklist L,int k){
	LNode *p=list->list ,*q=list->list;
	int count=0;
	while(p!=NULL){
		if(count<k) count++;
		else q=q->link;
		p=p->link;
	}
	if(count<k)
		return 0;
	else{
		printf(%d,q->data);
		return 1;
	}
}