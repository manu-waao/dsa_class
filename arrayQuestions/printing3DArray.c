
#include <stdio.h>
void main(){
	int arr[3][3][3];
	for(int i = 0; i <= 2; i++){
		for(int j = 0; j <= 2; j++){
			for(int k = 0; k <= 2; k++){
				scanf("%d", &arr[i][j][k]);
			}
		}
	}
	for(int i = 0; i <= 2; i++){
		for(int j = 0; j <= 2; j++){
			for(int k = 0; k <= 2; k++){
				printf("%d", arr[i][j][k]);
			}
		}
	}
}