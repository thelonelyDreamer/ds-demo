//-----trifurcate_linked_list.h-----
//本文件定义三叉链表的存储结构。
#ifndef _TRIFURCATE_LINKED_LINKED_LIST_H_
#define _TRIFURCATE_LINKED_LINKED_LIST_H_
#include "element_type.h"

typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, *parent,* rchild;
}BiTNode, * BiTree;

#endif // !_TRIFURCATE_LINKED_LINKED_LIST_H_


