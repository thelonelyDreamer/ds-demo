typedef struct node{
	Element data;
	struct node *lchild,*rchild;
}bitree,*bp;

int judgebitree(bp bt1,bp bt2){
	if(bt1==NULL&&bt2==NULL)
		return 1;
	else if(bt1==NULL||bt2==NULL||bt1->data!=bt2->data)
		return 0;
	else
		return(judgebitree(bt1->lchild，bt2->lchild)*judgebitree(bt1->rchild，bt2->rchild);
}