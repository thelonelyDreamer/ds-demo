//-----sequence_binary_tree.h-----
//本文件定义二叉树的顺序存储表示
//数组第一个元素存储结点个数(含不存在的虚拟结点),与完全二叉树序号对应的结点存储在对应的数组元素中，不存在的结点用特殊值表示

#ifndef _SEQUENCE_BINARY_TREE_H_
#define _SEQUENCE_BINARY_TREE_H_
#include "element_type.h"

#define MAX_TREE_SIZE 127
typedef ElemType SqBiTree[MAX_TREE_SIZE + 1];

#endif // !_SEQUENCE_BINARY_TREE_H_

