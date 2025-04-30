#include <stdio.h>
#include <stdlib.h>

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

struct node* form() {
    int v;
    scanf("%d", &v);
    if (v == -1) return NULL;
    struct node* t = make(v);
    t->l = form();
    t->r = form();
    return t;
}

void dep(struct node* t, int d, int k) {
    if (t == NULL) return;
    if (d == k) {
        printf("%d\n", t->num);
        return;
    }
    dep(t->l, d+1, k);
    dep(t->r, d+1, k);
}

int main() {
    struct node *h = form();
    int k;
    scanf("%d", &k);
    dep(h, 1, k);
    return 0;
}
