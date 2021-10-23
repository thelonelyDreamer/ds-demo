/**
 *
 *
 *
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 8
#define COL 8
#define TOTAL_CELL 64
#define ERR 1
#define FILENAME "greedy-my"

typedef struct {
    int xPosition;
    int yPosition;
    int direction;
    int greedyDir[8];
} cell;

typedef struct {
    cell lattice[TOTAL_CELL];
    int top;
} stack;

int HTry1[8]={1, -1, -2, 2, 2, 1, -1, -2};
int HTry2[8]={2, -2, 1, 1, -1, -2, 2, -1};

void initStack(stack *cellStack) {
    cellStack->top = -1;
}
int getTop(stack *cellStack){
    int top = cellStack->top;
    if(top<0||top>=TOTAL_CELL){
        printf("top error in getTop");
        exit(ERR);
    }
    return top;
}

void push(stack *cellStack,int i,int j,int *arr,int arrayLength) {
    if(cellStack->top<-1||cellStack->top>(TOTAL_CELL-2)){
        printf("error in push: top is not valid");
        exit(ERR);
    }
    (cellStack->top)++;
    cellStack->lattice[cellStack->top].xPosition= i;
    cellStack->lattice[cellStack->top].yPosition= j;
    cellStack->lattice[cellStack->top].direction= -1;
    int index = i*COL+j;
    if(index<0||index>=arrayLength){
        printf("error in push - "FILENAME);
        exit(ERR);
    }
    arr[index]=cellStack->top+1;
}
// isInfo为1 表示只取信息，不做其他操作
cell pop(stack *cellStack,int *arr,int arrayLength,int isInfo){
    if(cellStack->top<0||cellStack->top>(TOTAL_CELL-1)){
        printf("error in pop: top is not valid");
        exit(ERR);
    }
    cell node = cellStack->lattice[cellStack->top];
    if(isInfo!=1) {
        cellStack->top--;
        int index = node.xPosition*COL+node.yPosition;
        if(index<0||index>=arrayLength){
            printf("error in push - "FILENAME);
            exit(ERR);
        }
        arr[index]=-1;
    }

    return node;
}
cell popInfo(stack *cellStack){
    return pop(cellStack,NULL,0,1);
}
void setGreedyArray(stack *cellStack,int a[],int arrayLength){
    //省略栈判空
    for(int i= 0;i<arrayLength;i++)
        cellStack->lattice[cellStack->top].greedyDir[i]=a[i];
}

// 用来初始化棋盘，默认为-1 表示没有走过
void initArr(int * arr,int arrayLength){
    for(int i=0;i<arrayLength;i++)
        arr[i]=-1;
}
void storeResult(int *arr,int flag,int arrayLength){
    FILE *fp = NULL;
    if (0 == flag) {
        fp = fopen("result.txt", "w");
    } else {
        fp = fopen("result.txt", "a+");
    }
    for(int i=0;i<arrayLength;i++){
        if(0==i%COL)
            fprintf(fp,"\n");
        fprintf(fp,"%d\t",arr[i]);
    }
    fclose(fp);
}

//当栈顶节点为刚入栈节点时，为其动态生成策略
void createGreedyDir(int * arr,int arrayLength,stack * skp){
    // 确定每个选择以后会发生什么
    int count[8];
    for(int m=0;m<8;m++){

        int nowX =popInfo(skp).xPosition + HTry1[m];
        int nowY =popInfo(skp).yPosition + HTry2[m];
        if(nowX<0||nowY<0||nowX>=ROW||nowY>=COL||arr[nowX*COL+nowY]!=-1){
            count[m]=-1;
        } else{
            int sum=8;
            for(int n = 0;n<8;n++){
                int nowXX =nowX + HTry1[m];
                int nowYY =nowY + HTry2[m];
                if(nowXX<0||nowYY<0||nowXX>=ROW||nowYY>=COL||arr[nowXX*COL+nowYY]!=-1)
                    sum--;
            }
            count[m]=sum;
        }
    }

    //排序
    int index=0;
    int temp[8];
    for(int k=0;k<=8;k++){
        for(int l=0;l<8;l++){
            if(count[l]==k){
                temp[index]=l;
                index++;
            }
        }
    }
    for(;index<8;index ++){
        temp[index]=-1;
    }
    //储存
    setGreedyArray(skp,temp,8);
}

int solve(int i,int j,int * arr,int arrayLength,stack * skp){
    int result=1;
    push(skp,i,j,arr,arrayLength);
    while((TOTAL_CELL-1)>getTop(skp)&&getTop(skp)>-1){
       cell node = popInfo(skp);
       if(node.direction==-1){
           createGreedyDir(arr,arrayLength,skp);
       }
       int direction =  node.direction;
       // 走下一步
       if(7==direction||(-1==node.greedyDir[direction+1])){
           pop(skp,arr,arrayLength,0);
           continue;
       } else{
          int direction = node.greedyDir[node.direction+1];
          int newX =node.xPosition+HTry1[direction];
          int newY =node.yPosition+HTry2[direction];
          push(skp,newX,newY,arr,arrayLength);
       }
    }
    if(getTop(skp)+1==TOTAL_CELL)
        result=0;
    else
        result=1;
    return result;
}
int main(void) {
    int arr[TOTAL_CELL];
    stack cellStack;
    int flag = 0;
    clock_t start,end;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            start = clock();
            initArr(arr,TOTAL_CELL);
            initStack(&cellStack);
            int result = solve(i, j, arr,TOTAL_CELL,&cellStack);
            if (0 == result) {
                storeResult(arr, flag,TOTAL_CELL);
                flag++;
            }else{
                printf("the %d row %d col  no answer\n",i,j);
            }
            end =clock();
            double time = (double )(end-start)/CLOCKS_PER_SEC;
            printf("the %d row %d col const %f\n",i,j,time);
        }
    }
    printf("求解出了%d个结果",flag);
    return 0;
}