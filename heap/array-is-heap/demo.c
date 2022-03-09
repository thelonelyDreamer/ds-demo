
int isHeap(int arr[],int length){
	if(length<0){
		return -1;
	}
	if(0==length){
		return 1;
	}
	int i=0;
	if(0==length%2) {
		if(arr[length-1]>arr[length/2-1]){
			return 0;
		}
		for(i=length/2-2;i>=0;i++){
			if(arr[i]>arr[2*i+1]||arr[i]>arr[2*i+2]){
				return 0;
			}
		}	
	}else{
		for(i=length/2-1;i>=0;i++){
			if(arr[i]>arr[2*i+1]||arr[i]>arr[2*i+2]){
				return 0;
			}
	}
} 
