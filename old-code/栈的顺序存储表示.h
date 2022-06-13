//-----栈的顺序存储表示-----
#ifdef ElemType

typedef struct{
	ElemType *base;//在栈构造之前和销毁之后，base的值为NULL
	ElemType *top;//栈顶指针
	int stacksize;//当前已分配的存取空间，以元素为单位
}SqStack;