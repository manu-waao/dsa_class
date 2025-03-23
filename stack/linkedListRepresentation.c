#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
void pushStack();
int popStack();
void displayStack();
void emptyAllStack();

void main(void) {
    while(1) {
        printf("\nPress 1 to push value onto stack\n");
        printf("Press 2 to pop value from stack\n");
        printf("Press 3 to display stack\n");
        printf("Press 0 to exit\n\n");

        int opt;
        scanf("%d", &opt);
        if(opt == 0) {
            emptyAllStack();
            exit(0);
        } else if(opt == 1) {
            pushStack();
        } else if(opt == 2) {
            int val = popStack();
            printf("Value :  %d\n", val);
        } else if(opt == 3) {
            displayStack();
        } else {
            printf("Invalid input\n");
        }
    }
}

void pushStack() {
    int val;
    printf("Enter value to push onto stack: ");
    scanf("%d", &val);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Value pushed :%d\n", val);
}

int popStack() {
    if(top == NULL) {
        printf("Underflow\n");
        return -1;
    }
    struct node *temp = top;
    top = top->next;
    return temp->data;
    free(temp);
}

void displayStack() {
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Stack: ");
    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void emptyAllStack() {
    struct node *temp;
    while(top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
    printf("Deleted all nodess from the program\n");
}
