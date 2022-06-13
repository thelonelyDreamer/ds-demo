//-----binary_linked_list.h-----
//本文件定义二叉链表的存储结构。
#ifndef _BINARY_LINKED_LINKED_LIST_H_
#define _BINARY_LINKED_LINKED_LIST_H_
#include "element_type.h"
#include "sequence_binary_tree.h"

typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

BiTNode *arraytobitree(SqBiTree bt,int n,int m=0);

#endif // !_BINARY_LINKED_LINKED_LIST_H_

