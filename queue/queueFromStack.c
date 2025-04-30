#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Stack {
    int arr[SIZE];
    int top;
};

void push(struct Stack *s, int value) {
    s->arr[++(s->top)] = value;
}

int pop(struct Stack *s) {
    return s->arr[(s->top)--];
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

struct Stack s1 = {.top = -1};
struct Stack s2 = {.top = -1};

void enqueue(int value) {
    push(&s1, value);
}

void dequeue() {
    if (isEmpty(&s2)) {
        while (!isEmpty(&s1))
            push(&s2, pop(&s1));
    }
    if (isEmpty(&s2))
        printf("Queue is empty\n");
    else
        printf("%d dequeued\n", pop(&s2));
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
