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

void swp(struct node *t, int d, int k) {
    if (t == NULL) return;
    if (d % k == 0) {
        struct node* temp = t->l;
        t->l = t->r;
        t->r = temp;
    }
    swp(t->l, d+1, k);
    swp(t->r, d+1, k);
}

void show(struct node* t) {
    if (t) {
        show(t->l);
        printf("%d\n", t->num);
        show(t->r);
    }
}

void main() {
    struct node *h = form();
    int k;
    scanf("%d", &k);
    swp(h, 1, k);
    show(h);
}
