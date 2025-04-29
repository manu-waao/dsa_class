#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted: %d\n", queue[front++]);
        if (front > rear) front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void reverse_queue() {
    if (front == -1) {
        printf("Queue is Empty, cannot reverse.\n");
        return;
    }
    int temp;
    for (int i = front, j = rear; i < j; i++, j--) {
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
    }
    printf("Queue Reversed.\n");
}


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *lfront = NULL, *lrear = NULL;

void ll_enqueue(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if (lrear == NULL) {
        lfront = lrear = temp;
    } else {
        lrear->next = temp;
        lrear = temp;
    }
}

void ll_dequeue() {
    if (lfront == NULL) {
        printf("Queue Underflow\n");
    } else {
        Node* temp = lfront;
        printf("Deleted: %d\n", temp->data);
        lfront = lfront->next;
        free(temp);
        if (lfront == NULL) lrear = NULL;
    }
}

void ll_display() {
    Node* temp = lfront;
    if (temp == NULL) {
        printf("Queue is Empty\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    reverse_queue();
    display();

    ll_enqueue(100);
    ll_enqueue(200);
    ll_display();
    ll_dequeue();
    ll_display();
}
