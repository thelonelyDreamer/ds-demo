#include<stdio.h>
void add1Array(int arr[],int n);
void printArray(int arr[],int n);
int main(void){
	int arr[]={0,1,3};
	printArray(arr,3);
	add1Array(arr,3);
	printArray(arr,3);
	return 0;
}

void add1Array(int arr[],int n){
	int i=0;
	for(i=0;i<n;i++){
		arr[i]+=1;
	}
		
}

void printArray(int arr[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
