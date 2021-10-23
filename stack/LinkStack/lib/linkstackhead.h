//
// Created by lenovo on 2021/3/23.
//

#ifndef _LINK_LSTACK_HEAD_H_
#define _LINK_LSTACK_HEAD_H_

/**
 * 本文件所有的函数列表
 * initLinkStack() //初始化一个链栈
 * destroyLinkStack(LinkStack p) // 销毁
 *
 */

// 每个节点的数据结构
typedef struct LinkStackNode{
    void *dataPtr;
    struct LinkStackNode *next;
}*LinkStackNodePtr,LinkStackNode;
// 头结点的数据结构,可以保存链表的信息
typedef struct LinkStackHead{
    LinkStackNodePtr node;
    int length;
}*LinkStack,LinkStackHead;

/**
 * 初始化一个栈
 * @return 栈的指针
 */
LinkStack initLinkStack();


/**
 * 销毁栈
 * @param p 栈指针
 * @return  返1代表成功，0 代表失败
 */
int destroyLinkStack(LinkStack p,void * arr[]);

/**
 * 清空栈
 * @param p 栈指针
 * @return  返1代表成功，0代表失败
 */
int clearLinkStack(LinkStack p,void * arr[]);

/**
 * 返回栈的长度
 * @param p 栈的指针
 * @return 栈的容量
 */
int getLinkStackLength(LinkStack p);

/**
 * 空栈返回NULL
 * @param 栈指针
 * @return 获取栈顶元素
 */
void* getLinkStackTop(LinkStack p);

/**
 *
 * @param p 栈
 * @param elemPtr 要入栈的元素的地址
 * @return  返回当前栈的长度
 */
int pushLinkStack(LinkStack p, void * elemPtr);

/**
 * 出栈
 * @param p
 * @return
 */
void* popLinkStack(LinkStack p);


#endif //_LINK_LSTACK_HEAD_H_
