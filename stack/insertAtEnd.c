#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

struct node *top = NULL;
void push(int val);
int pop();
void display();
void insertBottom(int x);

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
    printf("Enter value to insert at bottom: ");
    scanf("%d", &x);
    insertBottom(x);
    printf("Stack after insertion:\n");
    display();
}

void push(int val){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->num = val;
    n->next = top;
    top = n;
}

int pop(){
    int x = top->num;
    struct node *t = top;
    top = top->next;
    free(t);
    return x;
}

void insertBottom(int x){
    if (top == NULL){
        push(x);
        return;
    }
    int y = pop();
    insertBottom(x);
    push(y);
}

void display(){
    struct node *t = top;
    while (t != NULL){
        printf("%d\n", t->num);
        t = t->next;
    }
}
