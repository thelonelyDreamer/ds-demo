#ifndef _S_STACK_
#define _S_STACK_
/**
 * 由用户定义元素类型 很重要
 *
 */
#ifndef elementtype
#define elementtype int
#endif
// 暂时使用动态分配数组
#define MAX_ELEMENT_COUNT
typedef struct {
    elementtype *pElem;
    int maxCount;
    int top;
} astack, *pastack;

/**
 * pastack initAStack(int size);
 * int destroyAStack(pastack p);
 * int clearAStack(pastack p);
 * int getAStackLength(pastack p);
 * elementtype getAStackTop(pastack p);
 * int pushAStack(pastack p, elementtype e);
 * elementtype popAStack(pastack p);
 * int aStackTraverse(pastack p, astacktra func,int argc,char **argv);
 */

/**
 * 初始化一个栈，根据用户传入的参数定义
 * @param size 栈的大小
 * @return 栈的指针
 */
pastack initAStack(int size);


/**
 * 销毁栈
 * @param p 栈指针
 * @return  返0代表成功，1 代表失败
 */
int destroyAStack(pastack p);

/**
 * 清空栈
 * @param p 栈指针
 * @return  返0代表成功，1 代表失败
 */
int clearAStack(pastack p);

/**
 * 返回栈的长度
 * @param p 栈的指针
 * @return 栈的容量
 */
int getAStackLength(pastack p);

/**
 * 空栈返回NULL
 * @param 栈指针
 * @return 获取栈顶元素
 */
elementtype getAStackTop(pastack p);

/**
 *
 * @param p 栈
 * @param e 要入栈的元素
 * @return  返回当前栈的长度
 */
int pushAStack(pastack p, elementtype e);

/**
 * 出栈
 * @param p
 * @return
 */
elementtype popAStack(pastack p);


typedef int (*astacktra)(elementtype * ele, int argc, char **argv);

/**
 * 对栈里面的元素进行操作
 * @param p
 * @param func
 * @return
 */
int aStackTraverse(pastack p, astacktra func,int argc,char **argv);

/**
 * 打印
 * @param p
 * @return 成功返回0；
 */
int aStackPrint(pastack p);

#endif