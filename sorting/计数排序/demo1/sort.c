#include<stdio.h>
#include<stdlib.h>

void cmpCountSort(int a[],int b[],int n){
	int i,j,*count;
	count=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++) count[i]=0;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			if(a[i]<=a[j])count[j]++;
			else count[i]++;
		}
	for(i=0;i<n;i++) b[count[i]]=b[i];
	free(count);
} 


int main(void){
	
	return 0;
}
