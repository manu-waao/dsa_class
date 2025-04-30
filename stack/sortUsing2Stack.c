#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

struct node *push(struct node *top, int n);
struct node *pop(struct node *top, int *out);
void displayStack(struct node *top);
struct node *sortStack(struct node *top);

void main(void){
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    struct node *top = NULL;
    for (int i = 0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &x);
        top = push(top, x);
    }
    printf("Stack before sorting:\n");
    displayStack(top);

    top = sortStack(top);

    printf("Stack after sorting:\n");
    displayStack(top);
}

struct node *push(struct node *top, int n){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = n;
    newNode->next = top;
    return newNode;
}

struct node *pop(struct node *top, int *out){
    if (top == NULL) return NULL;
    *out = top->num;
    struct node *tmp = top;
    top = top->next;
    free(tmp);
    return top;
}

void displayStack(struct node *top){
    struct node *p = top;
    while (p != NULL){
        printf("%d\n", p->num);
        p = p->next;
    }
}

struct node *sortStack(struct node *top){
    struct node *sorted = NULL;
    int tmp;
    while (top != NULL){
        top = pop(top, &tmp);
        while (sorted != NULL && sorted->num > tmp){
            int val;
            sorted = pop(sorted, &val);
            top = push(top, val);
        }
        sorted = push(sorted, tmp);
    }
    return sorted;
}