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
int isPalindrome(int n, int arr[]);

void main(void){
    int n, val, arr[100], idx = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        printf("Enter data for node %d: ", i);
        scanf("%d", &val);
        push(val);
        arr[idx++] = val;
    }
    display();
    if (isPalindrome(n, arr)){
        printf("Stack is Palindrome\n");
    } else {
        printf("Stack is Not Palindrome\n");
    }
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

void display(){
    struct node *t = top;
    while (t != NULL){
        printf("%d\n", t->num);
        t = t->next;
    }
}

int isPalindrome(int n, int arr[]){
    for (int i = 0; i < n/2; i++){
        if (arr[i] != arr[n-1-i]){
            return 0;
        }
    }
    return 1;
}
