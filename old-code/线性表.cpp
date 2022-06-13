#include<stdio.h>
#include<stdlib.h>
#define ElemType int
#define InitSize 50
#define ListIncrement 10

typedef struct{
	ElemType *data;
	int length,MaxSize;
}SeqList;

bool InitList(SeqList &L);//��ʼ�����Ա�
int Length(SeqList L);//���
bool DestroyList(SeqList &L);//�������Ա�??
bool ClearList(SeqList &L);//�����б��ÿ�

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