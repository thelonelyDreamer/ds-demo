#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define MAXSTRLEN 255

typedef char SString[MAXSTRLEN+1];

void initS_rand(SString &S);//随机初始化串
int strlen(SString S);//计算串长
void printfS(SString S);//打印串
void concat(SString &T,SString S1,SString S2);//合并两串
void substring(SString &Sub,SString S,int pos,int len);//求子串

int main(void){
	SString T,S1,S2,SubT;
	initS_rand(S1);
	initS_rand(S2);
	concat(T,S1,S2);
	substring(SubT,T,100,30);
	printfS(SubT);
	system("pause");
	return 0;
}

void initS_rand(SString &S){
	int n;//n为串长
	srand((int)time(NULL));
	n=rand()%MAXSTRLEN;
	S[0]=n;
	for(int i=1;i<=n;i++)
	S[i]=(char)(rand()%96+32);
	return;
}

int strlen(const SString S){
	return (S[0]+MAXSTRLEN+1)%(MAXSTRLEN+1);
}


void printfS(SString S){
	int n=strlen(S);
	for(int i=1;i<=n;i++)
		printf("%c",S[i]);
	printf("\n%d\n",n);
	return;
}


void concat(SString &T,SString S1,SString S2){
	int n1,n2,i;
	n1=strlen(S1);
	n2=strlen(S2);
	if(n1+n2<=MAXSTRLEN){
		for(i=1;i<=n1;i++)
			T[i]=S1[i];
		for(i;i<=n1+n2;i++)
			T[i]=S2[i-n1];
		T[0]=n1+n2;
	return;
	}
	else if(n1<MAXSTRLEN){
		for(i=1;i<=n1;i++)
			T[i]=S1[i];
		for(i;i<=MAXSTRLEN;i++)
			T[i]=S2[i-n1];
		T[0]=MAXSTRLEN;
	}
	else{
		for(i=0;i<=n1;i++)
			T[i]=S1[i];
	}
}

void substring(SString &Sub,SString S,int pos,int len){
	int n,i;
	n=strlen(S);
	if(pos<1||pos>n||len<0||len>n-pos+1){
		printf("error in substring!");
		system("pause");
		exit(1);
	}
	for(i=1;i<=len;i++)
		Sub[i]=S[pos+i-1];
	Sub[0]=len;
	return;
}
		
