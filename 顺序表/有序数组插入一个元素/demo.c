#include<stdio.h>
#include<stdlib.h>

#define bool char
#define true 1
#define false 0

bool insertSortedArray(int* a,int* np,int max,int elem){
	if(*np>=max) return false;
	int i,j;
	for(i=0;i<*np;i++){
		if(a[i]<=elem) i++;
		else break;
	}
	for(j=*np-1;j>=i;j--){
		a[j+1]=a[j];
	}
	a[i]=elem;
	*np++;
	return true;
} 
