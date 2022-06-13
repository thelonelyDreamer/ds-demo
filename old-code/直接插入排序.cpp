#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define ElemType int

typedef struct{
	ElemType data[MaxSize+1];
	int length;
}SqList;

void FR(FILE *fp,SqList &L);//输入文件
void InsertSort(SqList &L);//直接插入排序
void ShellSort(SqList &L);//希尔排序
void BInsertSort(SqList &L);//折半插入排序
void FW(FILE *fp,SqList L);//输出文件

int main(void){
	SqList L;
	FILE *fp1,*fp2;
	fp1=fopen("100个整数乱序.txt","r");
	fp2=fopen("排序结果.txt","w");
	FR(fp1,L);
	//InsertSort(L);
	//ShellSort(L);
	BInsertSort(L);
	FW(fp2,L);
	fclose(fp1);
	fclose(fp2);

	return 0;
}

void FR(FILE *fp,SqList &L){
	int i;
	for(i=1;i<=MaxSize;i++)
		fscanf(fp,"%d ",&L.data[i]);
	L.length=MaxSize+1;
	return;
}

void FW(FILE *fp,SqList L){
	int i;
	for(i=1;i<=MaxSize;i++)
		fprintf(fp,"%d ",L.data[i]);
	return;
}

void InsertSort(SqList &L){
	for(int i=2;i<=MaxSize;i++){
		L.data[0]=L.data[i];
		int j;
		for(j=i-1;L.data[j]>L.data[0];j--)
			L.data[j+1]=L.data[j];
		L.data[j+1]=L.data[0];
	}
	return;
}

void ShellSort(SqList &L){
	int dk=L.length/2;
	for(;dk>=1;dk/=2)
		for(int i=dk+1;i<=L.length;i++)
			if(L.data[i]<L.data[i-dk]){
				L.data[0]=L.data[i];
				int j;
				for(j=i-dk;j>0&&L.data[j]>L.data[0];j-=dk)
					L.data[j+dk]=L.data[j];
				L.data[j+dk]=L.data[0];
			}
			return;
}

void BInsertSort(SqList &L){
	int i,j,low,high,mid;
	for(i=2;i<=MaxSize;i++){
		L.data[0]=L.data[i];
		low=1;
		high=i-1;
		while(low<=high){
			mid=(low+high)/2;
			if(L.data[mid]>L.data[0])
				high=mid-1;
			else
				low=high+1;
		}
		for(j=i-1;j>high+1;j--)
			L.data[j+1]=L.data[j];
			L.data[high+1]=L.data[0];
	}
}