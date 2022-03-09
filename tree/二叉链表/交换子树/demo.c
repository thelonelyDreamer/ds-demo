#include<stdio.h> 
#define ElemType int

struct tree{
	ElemType data;
	struct tree* lchild; //左子树的根节点 
	struct tree* rchild;	//右子树的根节点
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
