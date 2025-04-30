#include <stdio.h>
void main(void) {
    printf("size of array : ");
    int sz, val, max = 0;
    scanf("%d", &sz);
    int arr[sz];
    for (int i = 0; i < sz; i++) {
        printf("enter val : ");
        scanf("%d", &val);
        arr[i] = val;
        if (val > max)
            max = val;
    }
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < sz; i++)
        count[arr[i]]++;
    int k = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[k] = i;
            k++;
            count[i]--;
        }
    }
    printf("Sorted array : ");
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
}
