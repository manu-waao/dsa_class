#include <stdio.h>
#define Z 100

int a[Z], b = 0;

void f(int x) {
    a[b] = x;
    int y = b;
    while (y > 0 && a[(y - 1) / 2] > a[y]) {
        int t = a[y];
        a[y] = a[(y - 1) / 2];
        a[(y - 1) / 2] = t;
        y = (y - 1) / 2;
    }
    b++;
}

void g() {
    if (b == 0) {
        printf("empty\n");
        return;
    }
    a[0] = a[b - 1];
    b--;
    int y = 0;
    while (1) {
        int l = 2 * y + 1, r = 2 * y + 2, s = y;
        if (l < b && a[l] < a[s]) s = l;
        if (r < b && a[r] < a[s]) s = r;
        if (s != y) {
            int t = a[y];
            a[y] = a[s];
            a[s] = t;
            y = s;
        } else break;
    }
}

void main() {
    int m, x;
    while (1) {
        printf("1add 2del 3see 4x: ");
        scanf("%d", &m);
        if (m == 1) {
            printf("val: ");
            scanf("%d", &x);
            f(x);
        } else if (m == 2) {
            g();
        } else if (m == 3) {
            if (b > 0)
                printf("%d\n", a[0]);
            else
                printf("empty\n");
        } else {
            break;
        }
    }
}
