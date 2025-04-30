#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int num;
    struct node *l;
    struct node *r;
};

struct node* make(int v) {
    struct node* z = (struct node*)malloc(sizeof(struct node));
    z->num = v;
    z->l = NULL;
    z->r = NULL;
    return z;
}

struct node* find(struct node* arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i]->num == x)
            return arr[i];
    }
    return NULL;
}

int leaf(struct node* t) {
    if (t == NULL) return 0;
    if (t->l == NULL && t->r == NULL) return t->num;
    return leaf(t->l) + leaf(t->r);
}

int main() {
    int n;
    scanf("%d", &n);
    struct node* arr[n];
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr[i] = make(x);
    }
    for (int i = 0; i < n - 1; i++) {
        int p, c;
        char side;
        scanf("%d %d %c", &p, &c, &side);
        struct node* par = find(arr, n, p);
        struct node* chi = find(arr, n, c);
        if (side == 'L')
            par->l = chi;
        else
            par->r = chi;
    }
    struct node* root = arr[0];
    printf("%d\n", leaf(root));
    return 0;
}
