#include <stdio.h>
void main(){
	int i, j;
	printf("Enter number of rows : ");
	scanf("%d", &i);
	printf("Enter number of columns : ");
	scanf("%d", &j);
	int arr[i][i];
	int transpose[i][j];
	printf("Enter elements : ");
	for(int a = 0; a < 3; a++){
		for(int b = 0; b < 3; b++){
			scanf("%d", &arr[a][b]);
		}
	}
	for(int a = 0; a < 3; a++){
		for(int b = 0; b < 3; b++){
			if (a != b){
				transpose[a][b] = arr[b][a];
			}
			else{
				transpose[a][b] = arr[a][b];
			}
		}
	}
	for(int a = 0; a < 3 ; a++){
		for(int b = 0; b < 3; b++){
			printf("%d", transpose[a][b]);
		}
		printf("\n");
	}
}