#include <stdio.h>
void main(){
    int arr[5][3];
    printf("Enter the sales of each product by the salesman in one line, space sparated : \n");
    for(int i = 0; i < 5; i++){
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    for(int j = 0; j < 5; j++){
        int salesByEachEmployee = 0;
        for(int k = 0; k <3; k++){
            salesByEachEmployee += arr[j][k];
        }
        printf("\nSales by Employee %d is %d", j+1, salesByEachEmployee);
    }
    printf("\n");
    for(int x = 0; x < 3; x++){
        int salesByProduct = 0;
        for(int k = 0; k < 5; k++){
            salesByProduct += arr[k][x];
        }
        printf("\nSales of Product %d is %d", x+1, salesByProduct);
    }
}