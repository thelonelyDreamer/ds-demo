//------traversal.h------
//本文件声明二叉链表的定义结构

#ifndef _TRAVERSAL_H_
#define _TRAVERSAL_H_
#include "binary_linked_list.h"

void visit(BiTree T);
void pre_order(BiTree T);//前序遍历-递归
void in_order(BiTree T);//中序遍历-递归
void post_orer(BiTree T);//后续遍历-递归


#endif // !_TRAVERSAL_H_

