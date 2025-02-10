#include <stdio.h>
void main(){
	int arr[2][2];
	int arr2[2][2];
	printf("Enter elements : ");
	for(int p = 0; p <2; p++){
		for(int q = 0; q < 2; q++){
			scanf("%d", &arr[p][q]);
		}
	}
	printf("Enter elements again : ");
	for(int p = 0; p <2; p++){
		for(int q = 0; q < 2; q++){
			scanf("%d", &arr2[p][q]);
		}
	}
	
	int arr3[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			int sn = arr[i][j]+ arr2[i][j];
			arr3[i][j] = sn;
		}
	}

	for(int x = 0; x < 2; x++){
		for(int y = 0; y < 2; y++){
			printf("%d", arr3[x][y]);
			printf(" ");
		}
		printf("\n");
	}
}
