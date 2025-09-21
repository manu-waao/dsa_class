#include <stdio.h>

int doPart(int arr[], int low, int high) {
    int pivot = arr[high];
    int idx = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            idx++;
            int tmp = arr[idx];
            arr[idx] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[idx + 1];
    arr[idx + 1] = arr[high];
    arr[high] = tmp;
    return (idx + 1);
}

void doQuick(int arr[], int low, int high) {
    if (low < high) {
        int p = doPart(arr, low, high);
        doQuick(arr, low, p - 1);
        // doQuick(arr, p + 1, high);
        doQuick(arr, high, p-1);
    }
}

void main(void) {
    printf("Size of array : ");
    int sz, val;
    scanf("%d", &sz);
    int arr[sz];

    for (int i = 0; i < sz; i++) {
        printf("enter val : ");
        scanf("%d", &val);
        arr[i] = val;
    }
    doQuick(arr, 0, sz - 1);
    printf("Sorted array  ");
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
}
