#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

struct node *top = NULL;
void push(int val);
void display();
void removeVal(int x);

void main(void){
    int n, val, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        printf("Enter data for node %d: ", i);
        scanf("%d", &val);
        push(val);
    }
    display();
    printf("Enter value to remove: ");
    scanf("%d", &x);
    removeVal(x);
    printf("Stack after removal:\n");
    display();
}

void push(int val){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->num = val;
    n->next = top;
    top = n;
}

void display(){
    struct node *t = top;
    while (t != NULL){
        printf("%d\n", t->num);
        t = t->next;
    }
}

void removeVal(int x){
    struct node *t = top, *prev = NULL;
    while (t != NULL){
        if (t->num == x){
            if (prev == NULL) top = t->next;
            else prev->next = t->next;
            struct node *d = t;
            t = t->next;
            free(d);
        } else {
            prev = t;
            t = t->next;
        }
    }
}
