#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

struct node *top = NULL;
void push(int val);
void display();
int sumTopK(int k);

void main(void){
    int n, val, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        printf("Enter data for node %d: ", i);
        scanf("%d", &val);
        push(val);
    }
    display();
    printf("Enter k: ");
    scanf("%d", &k);
    printf("Sum of top %d elements: %d\n", k, sumTopK(k));
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

int sumTopK(int k){
    int sum = 0;
    struct node *t = top;
    while (t != NULL && k--){
        sum += t->num;
        t = t->next;
    }
    return sum;
}
