#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define MAXSTRLEN 255

typedef struct{
	char *ch;
	int length;
}HString;

void Init_HString(HString &S);//随机初始化串
void PrintfS(HString S);//打印串
void StrInsert(HString &S,int pos,HString T);//插入串
int StrLen(HString S);//返回串的长度
void StrAssign(HString &S,char *chars);//把串常量赋给串
int StrCompare(HString S,HString T);//串比较
void StrClear(HString S);//串清空
void Concat(HString &T,HString S1,HString S2);//合并串
void SubString(HString &T,HString S,int pos,int len);//求子串

int main(void){
	HString S,T;
	Init_HString(S);
	Init_HString(T);
	StrInsert(S,10,T);
	PrintfS(S);
	system("pause");
	return 0;
}

void Init_HString(HString &S){
	srand((unsigned int)time(NULL));
	S.length=rand()%(MAXSTRLEN+1);
	if(S.length ==0){
		S.ch=NULL;
		return;
	}
	S.ch=(char*)malloc(S.length*sizeof(char));
	for(int i=0;i<S.length;i++)
		S.ch[i]=(char)(rand()%96+32);
	return;
}

void PrintfS(HString S){
	for(int i=0;i<S.length;i++)
		printf("%c",S.ch[i]);
	printf("\n");
	printf("%d",S.length);
	return;
}

void StrInsert(HString &S,int pos,HString T){
	if(pos<1||pos>S.length+1){
		printf("position is illegal");
		system("pause");
		exit(1);
	}
	if(T.length){
		if(!(S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char)))){
			printf("failure in memory allocation");
			system("pause");
			exit(1);
		}
		for(int i=S.length-1;i>=pos-1;i--)
			S.ch[i+T.length]=S.ch[i];
		for(int i=pos-1;i<pos+T.length-1;i++)
			S.ch[i]=T.ch[i-pos+1];
		S.length+=T.length;
		return;
	}
}

int StrLen(HString S){
	return S.length;
}

void StrAssign(HString &S,char *chars){
	if(S.ch)
		free (S.ch);
	int i;
	char *c;
	for(i=0,c=chars;*c;i++,c++);
	if(!i){
		S.ch=NULL;
		S.length=0;
	}
	else{
		if(!(S.ch=(char*)malloc(i*sizeof(char)))){
			printf("failure in memory allocation");
			system("pause");
			exit(1);
		}
		for(int j=0;j<i;j++)
		S.ch[j]=chars[j];
		S.length=i;
		return;
	}
}

int StrCompare(HString S,HString T){
	for(int i=0;i<=S.length&&i<=S.length;i++)
		if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];
	return S.length-T.length;
}

void StrClear(HString S){
	if(S.ch){
		free(S.ch);
		S.ch=NULL;
	}
	S.length=0;
}

void Concat(HString &T,HString S1,HString S2){
	if(T.ch)
		free(T.ch);
	if(!(T.ch=(char*)malloc((S1.length+S2.length)*sizeof(char)))){
		printf("failure in memory allocation");
		system("pause");
		exit(1);
	}
	for(int i=1;i<S1.length;i++)
		T.ch [i]=S1.ch[i];
	T.length=S1.length+S2.length;
	for(int i=S1.length;i<T.length;i++)
		T.ch[i]=S2.ch[i-S1.length];
	return;
}

void SubString(HString &T,HString S,int pos,int len){
	if(pos<1||pos>S.length||len<0||len>S.length-pos+1){
		printf("error in SubString");
		system("pause");
		exit(0);
	}
	if(T.ch) free(T.ch);
	if(!len){
		T.ch=NULL;
		T.length=0;
	}
	else{
		T.ch=(char*)malloc(len*sizeof(char));
		for(int i=0;i<len;i++)
			T.ch[i]=S.ch[pos+i-1];
		T.length=len;
	}
	return;
}