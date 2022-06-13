#include<stdio.h>
#define CHUCKSIZE 80

typedef struct Chunk{
	char ch[CHUCKSIZE];
	struct Chunk *next;
}Chunk;
typedef struct{
	Chunk *head,*tail;
	int curlen;
}LString;

int main(void){

	return 0;
}