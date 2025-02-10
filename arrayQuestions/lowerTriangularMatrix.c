#include <stdio.h>
int main(){
    int arr[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= i; j++) {
            arr[i][j] = 1;
        }
        for (int j = i + 1; j < 4; j++) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
