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

    for (int i = 1; i < sz; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted array : ");
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
}
