typedef struct mode{
	int data;
	struct node *link;
}NODE;
typedef NODE *PNODE;

void func (PNODE h,int n){
	PNODE p=h,r;
	int *q,m
	q=(int*)malloc(sizeof(int)*(n+1));
for(int i=0;i<n+1;i++)
	*(q+i)=0;
while(p->link!=NULL)
	{
		m=p->link->data>0?p->link->data:-p->link->data;
		if(*(q+m)==0){
			*(q+m)=1;
			p=p->link;
		}
		else{
			r=p-link;
			p->link=r->link;
			free(r);
		}
			
	}
	free q;
}

//删除带头结点单链表中重复的值