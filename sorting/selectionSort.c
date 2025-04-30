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
        int minIdx = i;
        for (int j = i + 1; j < sz; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int tmp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = tmp;
    }

    printf("Sorted array : ");
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
}
