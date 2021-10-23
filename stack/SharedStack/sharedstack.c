

#include<stdio.h>
#include<malloc.h>


#define ElemType int
#define MAX_SIZE 100


typedef struct{
	ElemType arr[MAX_SIZE];
	int top0;
	int top1;
}*StackPtr,Stack;

// 初始化
StackPtr initStack(){
	StackPtr p = (StackPtr)malloc(sizeof(Stack));
	p->top0 = -1;
	p->top1 = MAX_SIZE;
	
	return p;
}
// 栈判空
int isEmpty(StackPtr sPtr,int i){
	int result = 1;
	switch(i){
		case 0 :
			if(0!=sPtr->top0){
				result = 0;
				break;
			}	
		case 1 :
			if(MAX_SIZE!=sPtr->top1){
				result = 0;
				break;
			}
	}
	return result;
}

// 栈判满
int isfull(StackPtr sPtr){
	if(1==(sPtr->top1-sPtr->top0))
		return 1;
	else
		return 0;
}

// 清空栈
void clearStack(StackPtr sPtr){
	sPtr->top0 = -1;
	sPtr->top1 = MAX_SIZE;
}
	
// 已明白原理，有时间再写
// 入栈先判满
// 出栈先判空
// 入栈

// 出栈


// 销毁栈 要释放申请的空间，避免内存泄露