typedef struct node{
	char data;
	struct node *next;
}SNode;
int listlen(SNode *head){
	int len==0;
	while(head->next!=NULL){
		len++;
		head=head—>next;
	}
	return head;
}

SNode *find(SNode *str1;SNode *str2){
	int m,n;
	SNode *P=NULL；
	SNode *q=NULL;
	m=listlen(str1);
	n=listlen(str2);
	for(p=str1;m>n;m--)
		p=p->next;
	for(q=str2;m<n;n--)
		q=q->next;
	while(p->next!=NULL&&p->next!=q->nest){
		p=p->next;
		q=q-next;
	}
	return p-next;
	
}