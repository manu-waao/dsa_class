#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

struct node *top = NULL;
void push(int val);
void display();
void deleteMid(int n, int curr);

void main(void){
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        printf("Enter data for node %d: ", i);
        scanf("%d", &val);
        push(val);
    }
    display();
    deleteMid(n, 1);
    printf("middle delted:\n");
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

void deleteMid(int n, int curr){
    if (top == NULL) return;
    int x = pop();
    if (curr != (n/2)+1){
        deleteMid(n, curr+1);
        push(x);
    }
}

void display(){
    struct node *t = top;
    while (t != NULL){
        printf("%d\n", t->num);
        t = t->next;
    }
}
