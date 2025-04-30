#include <stdio.h>
#define L 100


int q[L], p = -1, r = -1;
void e(int x) {
    if (r == L - 1) return;
    if (p == -1) p = 0;
    q[++r] = x;
}

void d() {
    if (p == -1 || p > r) {
        printf("empty\n");
        return;
    }
    p++;
}

void s() {
    if (p == -1 || p > r) {
        printf("empty\n");
        return;
    }
    for (int i = p; i <= r; i++)
        printf("%d ", q[i]);
    printf("\n");
}

void z(int x) {
    if (p == -1 || p > r) {
        printf("empty\n");
        return;
    }
    int t = p;
    for (int i = p; i <= r; i++) {
        if (q[i] != x)
            q[t++] = q[i];
    }
    r = t - 1;
    if (r < p) p = -1;
}

void main() {
    int c, x;
    while (1) {
        printf("1add 2del 3rem 4see 5x: ");
        scanf("%d", &c);
        if (c == 1) {
            printf("val: ");
            scanf("%d", &x);
            e(x);
        } else if (c == 2) {
            d();
        } else if (c == 3) {
            printf("val: ");
            scanf("%d", &x);
            z(x);
        } else if (c == 4) {
            s();
        } else {
            break;
        }
    }
}
