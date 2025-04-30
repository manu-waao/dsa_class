#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char ch;
    struct node *next;
};
struct node *top = NULL;

void push(char c) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->ch = c;
    tmp->next = top;
    top = tmp;
}

char pop() {
    if (top == NULL) return '\0';
    char c = top->ch;
    struct node *del = top;
    top = top->next;
    free(del);
    return c;
}

void reverseWord(char word[]) {
    for (int i = 0; word[i] != '\0'; i++) {
        push(word[i]);
    }
    while (top != NULL) {
        printf("%c", pop());
    }
}

void main() {
    char str[100], word[100];
    printf("Enter a sentence: ");
    scanf(" %[^\n]", str);
    int j = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            word[j] = '\0';
            reverseWord(word);
            if (str[i] == ' ')
                printf(" ");
            j = 0;
        } else {
            word[j++] = str[i];
        }
    }
    printf("\n");
}
