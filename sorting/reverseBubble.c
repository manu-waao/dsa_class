#include <stdio.h>
void main(void) {
    printf("Enter the size of array : ");
    int sz, val;
    scanf("%d", &sz);
    int arr[sz];

    for (int i = 0; i < sz; i++) {
        printf("enter val : ");
        scanf("%d", &val);
        arr[i] = val;
    }

    for (int i = 0; i < sz - 1; i++) {
        for (int j = 0; j < sz - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    printf("Sorted array : ");
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
}
