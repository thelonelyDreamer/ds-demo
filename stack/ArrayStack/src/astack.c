//
// Created by lenovo on 2021/3/20.
//

#include <malloc.h>
#include <stdlib.h>
#include  <stdio.h>
#include "astack.h"

/**
 * 初始化一个栈，根据用户传入的参数定义
 * @param size 栈的大小
 * @return 栈的指针
 */
pastack initAStack(int size) {
    if (size <= 0) {
        printf("error in initAStack of astack.c\nsize is invalid\n");
        return NULL;
    }
    pastack p = (pastack) malloc(sizeof(astack));
    p->pElem = (int *) malloc(sizeof(elementtype) * size);
    p->top = -1;
    p->maxCount = size;
    return p;
}

/**
 * 清空栈
 * @param p 栈指针
 * @return  返0代表成功，1 代表失败
 */
int destroyAStack(pastack p) {
    int result = 1;
    if (NULL != p) {
        free(p->pElem);
        free(p);
        result = 0;
    } else {
        printf("error in destroyAStack of astack.c\np is null\n");
    }
    return result;
}

/**
 * 清空栈
 * @param p 栈指针
 * @return  返0代表成功，1 代表失败
 */
int clearAStack(pastack p) {
    int result = 1;
    if (NULL == p) {
        printf(" error in clearAStack() of astack.c\np is null\n");
    } else {
        p->top = -1;
        result = 0;
    }
    return result;
}

/**
 * 返回栈的长度
 * @param p 栈的指针
 * @return 栈的容量
 */
int getAStackLength(pastack p) {
    if (NULL == p) {
        printf("null point in getAStackLength() of astack.c\n");
        exit(1);
    } else {
        return p->top + 1;
    }
}

/**
 * 空栈返回NULL
 * @param 栈指针
 * @return 获取栈顶元素
 */
elementtype getAStackTop(pastack p) {
    if (NULL == p) {
        printf("null point in getAStackTop() of astack.c\n");
        exit(0);
    }
    return *(p->pElem + p->top);
}

/**
 *
 * @param p 栈
 * @param e 要入栈的元素
 * @return  返回当前栈的长度
 */
int pushAStack(pastack p, elementtype e) {

    if (NULL == p) {
        printf("null point in pushAStack() of astack.c\n");
        exit(0);
    }
    else if (p->top >= -1 && p->top+1 < p->maxCount) {
        p->top++;
        *(p->pElem + p->top) = e;
        return p->top + 1;
    }else{
        return -1;
    }
}

/**
 * 出栈
 * @param p
 * @return
 */
elementtype popAStack(pastack p){
    if (NULL == p) {
        printf("null point in popAStack() of astack.c\n");
        exit(0);
    }
    else if (p->top > -1 && p->top < p->maxCount) {
        elementtype e = *(p->pElem + p->top);
        p->top--;
        return e;
    }else{
        return -1;
    }
}

/**
 * 对栈里面的元素进行操作,
 * @param p
 * @param func
 * @return
 */
int aStackTraverse(pastack p, astacktra func,int argc,char **argv){
    if (NULL == p) {
        printf("null point in AStackTra() of astack.c\n");
        exit(0);
    }
    else if (p->top > -1 && p->top < p->maxCount) {
        int result=0;
        for(int i=0;i<=p->top;i++){
            if(func(p->pElem+i,argc,argv))
                result=-1;
        }
        return result;
    }else{
        return -1;
    }
}

/**
 * 打印,这个暂时不提供！
 * @param p
 * @return 成功返回0；
 */
int aStackPrint(pastack p){
    for(int i =0;i<=p->top;i++){
        printf("%c ",*(p->pElem+i));
    }
}