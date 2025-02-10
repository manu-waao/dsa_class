#include <stdio.h>
void main(){
	int arr[6] = {};
    for(int x = 0; x < 6; x++){
        scanf("%d", &arr[x]);
    }
	for(int i = 0; i < 6; i++){
		for(int j = i+1; j < 6; j++){
			if(arr[i] == arr[j]){
				printf("\nDuplicate found : %d", arr[i]);
			}
	    }
    }
}