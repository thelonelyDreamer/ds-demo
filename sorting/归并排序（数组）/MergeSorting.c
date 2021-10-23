#include<stdio.h>
#include<stdlib.h>

void merge(int* arr,int* bak,int low,int high,int mid){
	int k;
	for(k=low;k<=high;k++) *(bak+k)=*(arr+k);
	int i,j;
	for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
		if(*(bak+i)<=*(bak+j)){
			*(arr+k)=*(bak+i);
			i++; 
		}else{
			*(arr+k)=*(bak+j);
			j++;
		}
	}
	while(i<=mid) {
		*(arr+k)=*(bak+i);
		k++;
		i++;	
	}
	while(j<=high) {
		*(arr+k)=*(bak+j);
		k++;
		j++;	
	}
}

void mergeSort(int* arr,int* bak,int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergeSort(arr,bak,low,mid);
		mergeSort(arr,bak,mid+1,high);
		merge(arr,bak,low,high,mid);
	}
}

void megerSortArray(int* arr,int n){
	int* bak = (int*)malloc(sizeof(int)*n);
	mergeSort(arr,bak,0,n-1);
	free(bak);
}
void printfArray(int* arr,int n){
	int i;
	for(i=0;i<n;i++) printf("%d ",*(arr+i));
	printf("\n");
}

int main(void){
	int arr[10];
	int i=9;
	srand((unsigned)time(NULL));
	while(i>=0){
		arr[i]= rand();
		i--;
	}
	printfArray(arr,10);
	megerSortArray(arr,10);
	printfArray(arr,10);
	return 0;
}
