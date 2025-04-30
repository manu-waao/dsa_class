#include <stdio.h>
#include <stdlib.h>

struct node {
    char ch;
    struct node *next;
};

struct node *push(struct node *top, char c);
struct node *pop(struct node *top, char *out);
int precedence(char c);
void infixToPostfix(int n, char arr[]);

void main(void){
    int n;
    char c;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    char arr[100];
    for (int i = 0; i < n; i++){
        printf("Enter char %d: ", i+1);
        scanf(" %c", &arr[i]);
    }
    infixToPostfix(n, arr);
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

int precedence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(int n, char arr[]){
    struct node *stk = NULL;
    for (int i = 0; i < n; i++){
        char c = arr[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            printf("%c", c);
        } else if (c == '('){
            stk = push(stk, c);
        } else if (c == ')'){
            char t;
            while (stk != NULL){
                stk = pop(stk, &t);
                if (t == '(') break;
                printf("%c", t);
            }
        } else {
            while (stk != NULL && precedence(stk->ch) >= precedence(c)){
                char t;
                stk = pop(stk, &t);
                printf("%c", t);
            }
            stk = push(stk, c);
        }
    }
    while (stk != NULL){
        char t;
        stk = pop(stk, &t);
        printf("%c", t);
    }
    printf("\n");
}
