//
// Created by lenovo on 2021/3/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Row 8
#define Col 8
#define maxStep 64

typedef struct {
    int abscissa;  //������
    int ordinate;  //������
    int direction;  //����
}SqStack;

int ChessBoard[Row+1][Col+1]={}; //����·��������

//�ֱ��У�1 ~ 8��������
int HTry1[8]={1, -1, -2, 2, 2, 1, -1, -2};
int HTry2[8]={2, -2, 1, 1, -1, -2, 2, -1};

SqStack PointStack[maxStep];
int top = -1; //ջ��

int flagOperate = 0; //�������
int num = 0;  //��¼�����

void printChessBoard() {
    printf("����·����:\n");
    for(int i = 1;i <= Row;i++) {
        for(int j = 1;j <= Col;j++) {
            printf("%5d ", ChessBoard[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

//��ջ
void push(int abscissa, int ordinate) {
    ++top;
    PointStack[top].abscissa = abscissa;
    PointStack[top].ordinate = ordinate;
    PointStack[top].direction = -1; //��ʼ������
}

//��ջ
void pop() {
    PointStack[top].abscissa = 0;
    PointStack[top].ordinate = 0;
    PointStack[top].direction = -1; //��ʼ������
    --top;
}

//��ӡջ
void printStack() {
    printf("Ŀǰջ�����:\n");
    for(int i = 0;i < maxStep;i++) {
        printf("x:%d , y:%d, d:%d\n", PointStack[i].abscissa, PointStack[i].ordinate, PointStack[i].direction);
    }
    printf("\n\n");
}

//�������
void markChessBoard(int abscissa, int ordinate) {
    ChessBoard[ordinate][abscissa] = top+1;
}


void runChessBoard() {
    int xNow, yNow; //��ǰ�����ڵ�����

    while(1) {

        if(flagOperate == 1) {
            if(top == maxStep - 1) {
                printChessBoard();
                break;
            }
        }else if(flagOperate == 2 ) {
            if(top == maxStep - 1){
                printChessBoard();
                num++;
                printf("%d \n\n", num);
            }
        }



        xNow = PointStack[top].abscissa;
        yNow = PointStack[top].ordinate;

        //������˸������������򣬳������ٵ�����
        int count[8]={};
        for(int i = 0;i < 8;i++) {
            int xNext = xNow, yNext = yNow;
            xNext += HTry1[i];
            yNext += HTry2[i];
            if(xNext > 0 && xNext <= Col && yNext > 0 && yNext <= Row && ChessBoard[yNext][xNext] == 0) {
                for(int j = 0;j < 8;j++) {
                    int xNextNext = xNext, yNextNext = yNext;
                    xNextNext += HTry1[j];
                    yNextNext += HTry2[j];
                    if(xNextNext > 0 && xNextNext <= Col  && yNextNext > 0 && yNextNext <= Row && ChessBoard[yNextNext][xNextNext] == 0) {
                        count[i]++;
                    }
                }
            }
        }


        //�Է����������ʵ��Ҫ�ߵķ����¼��directionNext��
        int directionNext[8] = {};
        int temp = 9;
        int  k = 0;
        for(int i = 0;i < 8;i++) {
            temp = 9;
            for(int j = 0;j < 8;j++) {
                if(count[j]<temp){
                    directionNext[i] = j;
                    temp = count[j];
                    k = j;
                }
            }
            count[k] = 9;
        }

        //����һ��
        int direnow = 0;
        for(direnow = PointStack[top].direction + 1 ; direnow < 8 ; direnow++) {
            int xRealNext = xNow, yRealNext = yNow;
            xRealNext += HTry1[directionNext[direnow]];
            yRealNext += HTry2[directionNext[direnow]];
            PointStack[top].direction += 1;
            if(xRealNext <= Col && xRealNext > 0 && yRealNext <= Row && yRealNext > 0 &&ChessBoard[yRealNext][xRealNext] == 0) {
                push(xRealNext, yRealNext);
                markChessBoard(xRealNext, yRealNext);
                break;
            }
        }

        //�ж���·���߳�ջ
        if(PointStack[top].direction >= 7) {
            int x, y;
            x = PointStack[top].abscissa;
            y = PointStack[top].ordinate;
            ChessBoard[y][x] = 0; //���̱��ȡ��
            pop();
        }
    }
}

void InitStartPoint() {
    int x, y;

    //������ʼ�����
    printf("��������ʼ�㣨x��y��:");
    scanf("%d %d", &x, &y);
    printf("��������Ҫ����ķ�ʽ��\n  1.�ҳ�һ�����\n  2.�ҳ����н��(����������)\n����:");
    scanf("%d", &flagOperate);
    while(((x > Col||x <= 0)&&(y > Row||y <= 0))||(flagOperate <= 0 && flagOperate >= 3)) {
        if((x > Col||x <= 0)&&(y > Row||y <= 0)) {
            printf("��������곬����Χ�����������루0~8����");
            scanf("%d %d", &x, &y);
        }else if(flagOperate <= 0 && flagOperate >= 3) {
            printf("����������������룺\n");
            printf("��������Ҫ����ķ�ʽ��\n  1.�ҳ�һ�����\n  2.�ҳ����н��(����������)\n����:");
            scanf("%d", &flagOperate);
        }
    }

    //����ջ
    push(x, y);
    markChessBoard(x, y);
}

int main() {
    InitStartPoint();
    clock_t start,finish; //��ʼ����ʱ��
    double duration;  //������ʱ
    start = clock();
    runChessBoard();
    finish = clock();
    duration = (double) (finish - start) / CLOCKS_PER_SEC;
    printf("������ʱ: %f second\n", duration);
}