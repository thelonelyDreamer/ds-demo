#include<malloc.h>
#include"linkstackhead.h"
#include<stdlib.h>


// 构建一个字符栈 要什么重写什么就好了

LinkStack initCharStack(){
   return initLinkStack();
}

int clearCharStack(LinkStack p){
	int n = p->length;
	void ** arr =(void **)malloc(sizeof(void*)*n);
	int result = clearLinkStack(p,arr);
	for(int i =0;i<n;i++){
		free((char *)*(arr+i));
	}
	free(arr);
	 
	return result;
}

int destroyCharStack(LinkStack p){
	int n = p->length;
	void ** arr =(void **)malloc(sizeof(void*)*n);
	int result = destroyLinkStack(p,arr);
	for(int i =0;i<n;i++){
		free((char *)*(arr+i));
	}
	free(arr);
	 
	return result;
}

int getCharStackLength(LinkStack p){
	return getLinkStackLength(p);
}

char getCharStackTop(LinkStack p){
	if(getCharStackLength(p)<1){
		exit(0);
	}
	return *(char *)getLinkStackTop(p);
}

int pushCharStack(LinkStack p ,char c){
	char * ptr = (char *)malloc(sizeof(char));
	*ptr = c;
	int result = pushLinkStack(p,ptr);
	return result;
}

char popCharStack(LinkStack p){
	char *temp = (char *) popLinkStack(p);
	char c = *temp;
	free(temp);
	return c;
}


int main(){
	
	for(int i=0;i<100000;i++){
	LinkStack stack = initCharStack();
	pushCharStack(stack,'a');
	pushCharStack(stack,'b');
	printf("%c\n",popCharStack(stack));
	printf("%c\n",getCharStackTop(stack));
	clearCharStack(stack);
	printf("%p \n",stack);
	destroyCharStack(stack);
	}
	return 0;
}