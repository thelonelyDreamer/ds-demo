#include<stdio.h>
#include<stdlib.h>
#define ElemType int
#define InitSize 50
#define ListIncrement 10

typedef struct{
	ElemType *data;
	int length,MaxSize;
}SeqList;

bool InitList(SeqList &L);//初始化线性表
int Length(SeqList L);//求表长
bool DestroyList(SeqList &L);//销毁线性表??
bool ClearList(SeqList &L);//将现行表置空

int main(void){

	return 0;
}

bool InitList(SeqList &L){
	L.data=(ElemType *)malloc(InitSize*sizeof(ElemType));
	if(!L.data) return false;
	L.length=0;
	L.MaxSize=InitSize;
	return true;
}

int Length(SeqList L){
	return L.length;
}

bool DestroyList(SeqList &L){
	if(L.data)
		free(L.data);
	L.length=-1;
	L.MaxSize=-1;
	return true;
}

bool ClearList(SeqList &L){
	L.length=0;
	return true;
}