#include <stdio.h>
void main(){
	int stuCount;
	printf("Enter number of students : ");
	scanf("%d", &stuCount);
	int stuArr[stuCount][3];
	for(int i = 0; i < stuCount; i++){
		for(int j = 0; j <3; j++){
			scanf("%d", &stuArr[i][j]);
		}
	}
	for(int i = 0; i < 3; i++){
		int highest = stuArr[i][0];
		for(int j = 0; j <stuCount; j++){
			if (highest < stuArr[j][i]){
				highest = stuArr[j][i];
			}
		}
		printf("Highest for student %d: %d\n",i+1, highest);
	}
}