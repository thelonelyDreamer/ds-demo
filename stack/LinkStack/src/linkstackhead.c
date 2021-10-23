//
// Created by lenovo on 2021/3/23.
//

#include <malloc.h>
#include <stdio.h>
#include"linkstackhead.h"
#include <stdlib.h>


/**
 * 初始化一个栈
 * @return 栈的指针
 */
LinkStack initLinkStack(){
	LinkStack ptr = (LinkStack) malloc(sizeof(LinkStackHead));
	ptr->node = NULL;
	ptr->length = 0;
}


/**
 * 因为使用了泛型，使用时应该重写此方法
 * 销毁栈
 * @param p 栈指针
 * @return  返1代表成功，0 代表失败
 */
int destroyLinkStack(LinkStack p,void * arr[]){
	if(NULL == p){
		// 传入空指针，认为不需要管理此块内存，所以返回成功
		return 1;
	}
	
	LinkStackNodePtr nodePtr = p->node;
	int i = 0;
	// 将栈的地址元素移到外层处理，同时避免数组越界（防止代码写错）
	while(NULL != nodePtr&&i<p->length){
		LinkStackNodePtr temp = nodePtr;
		nodePtr = nodePtr-> next;
		arr[i] = temp->dataPtr;
		i++;
		free(temp);
	}	
	free(p);
	return 1;
}

/**
 * 清空栈
 * @param p 栈指针
 * @return  返1代表成功，0代表失败
 */
int clearLinkStack(LinkStack p,void * arr[]){
	if(NULL == p){
		// 传入空指针，认为不该指针不是栈的指针，返回操作失败，避免后续误操作
		return 0;
	}
	LinkStackNodePtr nodePtr = p->node;
	int i = 0;
	// 将栈的地址元素移到外层处理，同时避免数组越界（防止代码写错）
	while(NULL != nodePtr&&i<p->length){
		LinkStackNodePtr temp = nodePtr;
		nodePtr = nodePtr-> next;
		arr[i] = temp->dataPtr;
		i++;
		free(temp);
	}	
	p->node=NULL;
	p->length=0;
	return 1;
}

/**
 * 返回栈的长度
 * @param p 栈的指针
 * @return 栈的容量
 */
int getLinkStackLength(LinkStack p){
	if(NULL == p){
		// 传入空指针，认为不该指针不是栈的指针，返回-1，避免后续误操作
		return -1;
	}
	return p->length;
}

/**
 * 空栈返回NULL
 * @param 栈指针
 * @return 获取栈顶元素的地址
 */
void* getLinkStackTop(LinkStack p){
	if (NULL == p){
		// 传入空指针，直接报错
		printf("pointer is null");
		exit(1);
	}
	if(NULL == p->node){
		return NULL;
	}else{
		return p->node->dataPtr;
	}
}

/**
 *
 * @param p 栈
 * @param elemPtr 要入栈的元素的地址
 * @return  返回当前栈的长度
 */
int pushLinkStack(LinkStack p, void * elemPtr){
	if (NULL == p){
		// 传入空指针，直接报错
		printf("pointer is null");
		exit(1);
	}
	LinkStackNodePtr nodePtr = (LinkStackNodePtr)malloc(sizeof(LinkStackNode));
	nodePtr->dataPtr = elemPtr;
	nodePtr->next = p->node;
	p->node = nodePtr;
	p->length++;
	return p->length;
}


/**
 * 出栈
 * @param p
 * @return
 */
void* popLinkStack(LinkStack p){
	if (NULL == p){
		// 传入空指针，直接报错
		printf("pointer is null");
		exit(1);
	}
	// 如果栈中没有元素，则直接返回空指针，便于用户操作
	if(p->length<1){
		return NULL;
	}
	LinkStackNodePtr temp = p->node;
	p->node = temp->next;
	void * result = temp->dataPtr;
	free(temp);
	return result;
}

