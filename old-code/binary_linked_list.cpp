//本文件定义转换成二叉链表的函数实现
#include "binary_linked_list.h"
#include <stdlib.h>

BiTNode* arraytobitree(SqBiTree bt, int n, int m ) {
	if (bt==NULL||m>n)
		return NULL;
	BiTNode *p;
	p = (BiTNode*)malloc(sizeof(BiTNode));
	if (p != NULL) {
		p->data = bt[m];
		p->lchild = arraytobitree(bt, n, 2 * m);
		p->rchild = arraytobitree(bt, n, 2 * m + 1);
	}

	return p;
}