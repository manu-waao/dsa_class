#include <stdio.h>
#include <stdlib.h>
void main(){
    int A[20][20], B[20][20], R[20][20], m, n, p, q, i, j, x, y, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m,&n);
    printf("\nEnter elements: \n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
             scanf("%d", &A[i][j]);
     printf("\nEnter rows and columns: ");
     scanf("%d %d", &p, &q);
     printf("\nEnter elements: \n");
     for (x = 0; x < p; x++)
         for (y = 0; y < q; y++)
             scanf("%d", &B[x][y]);
     if (n != p) {
         printf("Product of A and B is not possible");
         exit(0);
     }
     for (i = 0; i < m; i++) {
         for (j = 0; j < q; j++) {
             R[i][j] = 0;
             for (c = 0; c < n; c++)
                 R[i][j] += A[i][c] * B[c][j];
         }
    }

	 printf("\n");
     printf("Resultant matrix \n");
     for (i = 0; i < m; i++) {
         for (j = 0; j < q; j++)
             printf("%d ", R[i][j]);
         printf("\n");
     }

}
