//-----trifurcate_linked_list.h-----
//���ļ�������������Ĵ洢�ṹ��
#ifndef _TRIFURCATE_LINKED_LINKED_LIST_H_
#define _TRIFURCATE_LINKED_LINKED_LIST_H_
#include "element_type.h"

typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, *parent,* rchild;
}BiTNode, * BiTree;

#endif // !_TRIFURCATE_LINKED_LINKED_LIST_H_


