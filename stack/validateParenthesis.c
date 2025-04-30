#include <stdio.h>
#include <stdlib.h>

struct node {
    char ch;
    struct node *next;
};

struct node *push(struct node *top, char c);
struct node *pop(struct node *top, char *out);
void checkValid(struct node *top);

void main(void){
    int n;
    char c;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    struct node* top = NULL;
    for (int i = 1; i <= n; i++){
        printf("Enter char %d: ", i);
        scanf(" %c", &c);
        top = push(top, c);
    }
    checkValid(top);
}

struct node *push(struct node *top, char c){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->ch = c;
    newNode->next = top;
    return newNode;
}

struct node *pop(struct node *top, char *out){
    if (top == NULL) return NULL;
    *out = top->ch;
    struct node *tmp = top;
    top = top->next;
    free(tmp);
    return top;
}

void checkValid(struct node *top){
    struct node *stk = NULL;
    char arr[100];
    int k = 0;
    while (top != NULL){
        arr[k++] = top->ch;
        top = top->next;
    }
    for (int i = k-1; i >=0; i--){
        char c = arr[i];
        if (c == '(' || c == '{' || c == '['){
            stk = push(stk, c);
        } else {
            if (stk == NULL){
                printf("Not Valid\n");
                return;
            }
            char t;
            stk = pop(stk, &t);
            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '[')){
                printf("Not Valid\n");
                return;
            }
        }
    }
    if (stk == NULL){
        printf("Valid\n");
    } else {
        printf("Not Valid\n");
    }
}
