#include <stdio.h>
int main(){
    int arr[5][5];
    printf("Enter elements for a 5x5 matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The entered matrix is:\n");
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            printf("%d ", arr[x][y]);
        }
        printf("\n"); 
    }
    return 0;
}
