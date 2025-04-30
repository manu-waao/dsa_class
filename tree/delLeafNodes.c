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

struct node* cut(struct node* t) {
    if (t == NULL) return NULL;
    if (t->l == NULL && t->r == NULL) {
        free(t);
        return NULL;
    }
    t->l = cut(t->l);
    t->r = cut(t->r);
    return t;
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
    h = cut(h);
    show(h);
}
