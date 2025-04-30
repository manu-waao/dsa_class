#include <stdio.h>

void makeBig(int arr[], int sz, int i) {
    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < sz && arr[l] > arr[big])
        big = l;
    if (r < sz && arr[r] > arr[big])
        big = r;
    if (big != i) {
        int tmp = arr[i];
        arr[i] = arr[big];
        arr[big] = tmp;
        makeBig(arr, sz, big);
    }
}

void doHeap(int arr[], int sz) {
    for (int i = sz / 2 - 1; i >= 0; i--)
        makeBig(arr, sz, i);
    for (int i = sz - 1; i >= 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        makeBig(arr, i, 0);
    }
}

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
    doHeap(arr, sz);
    printf("Sorted array : ");
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
}
