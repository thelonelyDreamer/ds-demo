#include<stdio.h> 
#define ElemType int

struct tree{
	ElemType data;
	struct tree* lchild; //�������ĸ��ڵ� 
	struct tree* rchild;	//�������ĸ��ڵ�
}; 

void swapChild(struct tree * root){
	if(root ==NULL) return;
	swapChild(root->lchild);
	swapChild(root->rchild);
	struct tree* temp = root->lchild;
	root->lchild= root->rchild;
	root->rchild= temp;
	return;
} 
