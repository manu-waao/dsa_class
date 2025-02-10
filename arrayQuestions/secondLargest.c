
#include <stdio.h>
void main(){
	int arr[10] = {};
	printf("Enter 10 elements : ");
	for(int j =0; j <10; j++){
		scanf("%d", &arr[j]);
	}
	int largest = arr[0];
	int secondLargest = arr[0];
	for(int i = 0; i < 10; i++){
		if(arr[i] > largest){
			largest = arr[i];
		}
		if(largest > arr[i] && secondLargest < arr[i]){
			secondLargest = arr[i];
		} 
	}
	printf("Second largest is : %d", secondLargest);
}