//���ļ��Ǳ���������ʵ�ֹ���
#include "traversal.h"
#include <iostream>
using namespace std;

void visit(BiTree T) {
	if (T != NULL)						//�����е����
		cout << T->data << " ";
	return;
}

void pre_order(BiTree T) {
	if (T != NULL) {
		visit(T);
		pre_order(T->lchild);
		pre_order(T->rchild);
	}
}//ǰ�����

void in_order(BiTree T) {
	if (T != NULL) {
		in_order(T->lchild);
		visit(T);
		in_order(T->rchild);
	}
}//�������

void post_order(BiTree T) {
	if (T != NULL) {
		post_order(T->lchild);
		post_order(T->rchild);
		visit(T);
	}
}//��������