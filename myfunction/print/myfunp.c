#include<stdio.h>
#include"myfunp.h"
void printArray(int *arr,int n){
	int i=0;
	for( i=0;i<n;i++){
		printf("%d ",*(arr+i));
	}
}
