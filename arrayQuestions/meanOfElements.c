#include <stdio.h>
void main(){
	int arr[6] = {3, 54, 3, 53, 32, 3};
	int sn = 0;
	for(int i = 0; i <6; i++){
		sn = sn + arr[i];
	}
	sn = sn/6;
	printf("%d is the mean of numbers", sn);
}