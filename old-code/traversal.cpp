//本文件是遍历函数的实现过程
#include "traversal.h"
#include <iostream>
using namespace std;

void visit(BiTree T) {
	if (T != NULL)						//好像有点多余
		cout << T->data << " ";
	return;
}

void pre_order(BiTree T) {
	if (T != NULL) {
		visit(T);
		pre_order(T->lchild);
		pre_order(T->rchild);
	}
}//前序遍历

void in_order(BiTree T) {
	if (T != NULL) {
		in_order(T->lchild);
		visit(T);
		in_order(T->rchild);
	}
}//中序遍历

void post_order(BiTree T) {
	if (T != NULL) {
		post_order(T->lchild);
		post_order(T->rchild);
		visit(T);
	}
}//后续遍历