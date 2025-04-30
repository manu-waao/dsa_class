#include <stdio.h>
#define SIZE 32

void smallSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

void mixIt(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void doTimeSort(int arr[], int sz) {
    for (int i = 0; i < sz; i += SIZE)
        smallSort(arr, i, (i + SIZE - 1 < sz - 1) ? (i + SIZE - 1) : (sz - 1));
    for (int size = SIZE; size < sz; size = 2 * size) {
        for (int left = 0; left < sz; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < sz - 1) ? (left + 2 * size - 1) : (sz - 1);
            if (mid < right)
                mixIt(arr, left, mid, right);
        }
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
    doTimeSort(arr, sz);
    printf("Sorted array : ");
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
}
