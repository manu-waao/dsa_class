#include <stdio.h>
#define MAX 100

int pq[MAX];
int sz = 0;

void addMin(int val) {
    pq[sz] = val;
    int i = sz;
    while (i > 0 && pq[(i - 1) / 2] > pq[i]) {
        int tmp = pq[i];
        pq[i] = pq[(i - 1) / 2];
        pq[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
    sz++;
}

void delMin() {
    if (sz == 0) {
        printf("Queue empty\n");
        return;
    }
    pq[0] = pq[sz - 1];
    sz--;
    int i = 0;
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int small = i;
        if (l < sz && pq[l] < pq[small])
            small = l;
        if (r < sz && pq[r] < pq[small])
            small = r;
        if (small != i) {
            int tmp = pq[i];
            pq[i] = pq[small];
            pq[small] = tmp;
            i = small;
        } else {
            break;
        }
    }
}

void main(void) {
    int ch, val;
    while (1) {
        printf("\n1 add 2 del 3 peek 4 exit : ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("enter val : ");
            scanf("%d", &val);
            addMin(val);
        } else if (ch == 2) {
            delMin();
        } else if (ch == 3) {
            if (sz > 0)
                printf("highets val is : %d\n", pq[0]);
            else
                printf("Queue empty\n");
        } else {
            break;
        }
    }
}
