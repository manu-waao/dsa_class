#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char ch;
    struct node *next;
};

struct node *push(struct node *top, char c);
struct node *pop(struct node *top, char *out);
int precedence(char c);
void reverse(char arr[], int n);
void infixToPrefix(int n, char arr[]);

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
    infixToPrefix(n, arr);
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

void reverse(char arr[], int n){
    int l = 0, r = n -1;
    while (l < r){
        char tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}

void infixToPrefix(int n, char arr[]){
    reverse(arr, n);
    for (int i = 0; i < n; i++){
        if (arr[i] == '(') arr[i] = ')';
        else if (arr[i] == ')') arr[i] = '(';
    }

    struct node *stk = NULL;
    char result[100];
    int k = 0;

    for (int i = 0; i < n; i++){
        char c = arr[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result[k++] = c;
        } else if (c == '('){
            stk = push(stk, c);
        } else if (c == ')'){
            char t;
            while (stk != NULL){
                stk = pop(stk, &t);
                if (t == '(') break;
                result[k++] = t;
            }
        } else {
            while (stk != NULL && precedence(stk->ch) >= precedence(c)){
                char t;
                stk = pop(stk, &t);
                result[k++] = t;
            }
            stk = push(stk, c);
        }
    }
    while (stk != NULL){
        char t;
        stk = pop(stk, &t);
        result[k++] = t;
    }

    reverse(result, k);
    for (int i = 0; i < k; i++){
        printf("%c", result[i]);
    }
    printf("\n");
}
