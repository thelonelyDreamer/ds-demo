//
// Created by lenovo on 2021/3/19.
//

// 这个代码太费时间，应该用贪心算法
#include <stdio.h>
#include <malloc.h>
#include <time.h>

#define ROW 8
#define COL 8
#define lattice 64
typedef struct {
    int arr[lattice];
    int top;
} stack, *pStack;

//分别有（1 ~ 8）个方向
int HTry1[8] = {1, -1, -2, 2, 2, 1, -1, -2};
int HTry2[8] = {2, -2, 1, 1, -1, -2, 2, -1};

void init(int *arr) {
    for (int i = 0; i < lattice; i++) {
        arr[i] = -1;
    }
}

//是否是第一次出结果，如果是，则覆盖写入，如果不是，则追加写入,第一次求解处理应该传入0
void storeResult(pStack ps, int isFirst) {
    FILE *fp = NULL;
    int arr[lattice];
    for (int t = 0; t < lattice; t++) {
        arr[ps->arr[t]] = t + 1;
    }

    if (0 == isFirst) {
        fp = fopen("result.txt", "w");
    } else {
        fp = fopen("result.txt", "a+");
    }
    fprintf(fp, "%d %d \n", ps->arr[0] / 8 + 1, ps->arr[0] % 8 + 1);
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            fprintf(fp, "%d\t", arr[i * COL + j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
    fclose(fp);
    return;
}

int solve(int i, int j, int *arr, stack *ps) {
    //将此格点入栈
    ps->top = ps->top + 1;
    ps->arr[ps->top] = i * COL + j;
    // 默认是找到的，当没有找到抛出1
    int result = 0;
    while ((lattice - 1) != ps->top) {
        if (ps->top == -1) {
            result = 1;
            break;
        }
        // 当前节点号
        int k = ps->arr[ps->top];
        // 取出当前节点的策略
        int strategy = arr[k];
        if (strategy == 7) {
            ps->top--;
            arr[k] = -1;
            continue;
        }
        //下一节点的行号
        int s;
        //下一节点的列号
        int t;
        do {
            if (7 == strategy) {
                ps->top--;
                arr[k] = -1;
                break;
            }
            strategy = strategy + 1;
            s = k / COL + HTry1[strategy];
            t = k % ROW + HTry2[strategy];

        } while (s < 0 || s >= ROW || t < 0 || t >= COL);
        // 下一个目标的合法值
        int next = s * COL + t;

        if(arr[next]!=-1){
            arr[k]=strategy;
            continue;
        }
        arr[k] = strategy;
        ps->top = ps->top + 1;
        ps->arr[ps->top] = next;
        printf("%d",next);
    }

    return result;
}

int main(void) {
    clock_t start,end;
    start =clock();
    // 用于记录方向以及判读是否走过，-1 值表示未走过
    int arr[lattice];
    // 用于判读是否第一次得出结果，如果不是，则不为0;
    int flag = 0;
    pStack ps = (pStack) malloc(sizeof(stack));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            init(arr);
            ps->top = -1;
            int result = solve(i, j, arr, ps);
            if (0 == result) {
                storeResult(ps, flag);
                flag++;
            }
        }
    }
    printf("\n %d", flag);
    end= clock();
    double time = (double )(end-start);
    printf("%lf",time/60000);
    return 0;
}
