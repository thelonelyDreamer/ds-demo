
void doubleBubbleSort(int a[],int n){
	low=0;
	high=n-1;
	change=1;
	int i;
	int temp;
	while(low<high&&change){
		change=0;
		for(int i=low;i<high;i++){
			if(a[i+1]<a[i]){
				temp= a[i+1];
				a[i+1]=a[i];
				a[i=]=temp;
				change=1; 
			}
		}
		high--;
		for(int i=high;i>low;i--){
			if(a[i-1]>a[i]){
				temp= a[i-1];
				a[i-1]=a[i];
				a[i=]=temp;
				change=1; 
			}
		}
		low++;
	}
} 
