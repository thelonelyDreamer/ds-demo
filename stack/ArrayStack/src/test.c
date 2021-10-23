//
// Created by lenovo on 2021/3/20.
//

#include "stdio.h"
#ifdef elementtype
#undef elementtype
#endif
#define elementtype char
#include "astack.h"
/**
 * /**
 * pastack initAStack(int size); 已完成
 * int destroyAStack(pastack p);已完成
 * int clearAStack(pastack p);  已完成
 * int getAStackLength(pastack p);已完成
 * elementtype getAStackTop(pastack p);已完成
 * int pushAStack(pastack p, elementtype e);已完成
 * elementtype popAStack(pastack p);已完成
 * int aStackTraverse(pastack p, astacktra func,int argc,char **argv);
 *
 * @return
 */
int  visit(elementtype *e,int argc,char ** argv) {
    *e+=1;
    return 0;
}

int main(void){
    elementtype ele[5] = {'a','b','c','d','e'};
    pastack  p = initAStack(5);
    clearAStack(p);
    for(int i=0;i<5;i++){
        pushAStack(p,ele[i]);
    };
    printf("%c\n",getAStackTop(p));
    printf("%c\n",popAStack(p));
    printf("%d\n",getAStackLength(p));
    printf("%d\n",sizeof (*p->pElem));
    astacktra func =visit;
    aStackTraverse(p,func,0,NULL);
    printf("%c\n",getAStackTop(p));
    aStackPrint(p);
    return 0;
}