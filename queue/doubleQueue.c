#include <stdio.h>
#define MAX 100
int arr[MAX];
int front = -1, rear = -1;

void pushFront(int val) {
    if (front == 0) {
        printf("Cannot insert at front!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    arr[front] = val;
}

void pushRear(int val) {
    if (rear == MAX - 1) {
        printf("No space at rear!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    arr[rear] = val;
}

void popFront() {
    if (front == -1) {
        printf("Empty queue!\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void popRear() {
    if (rear == -1) {
        printf("Empty queue!\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

void main(void) {
    int ch, val;
    while (1) {
        printf("\n1 pushFront 2 pushRear 3 popFront 4 popRear 5 show 6 exit : ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("val to push front : ");
            scanf("%d", &val);
            pushFront(val);
        } else if (ch == 2) {
            printf("val to push rear : ");
            scanf("%d", &val);
            pushRear(val);
        } else if (ch == 3) {
            popFront();
        } else if (ch == 4) {
            popRear();
        } else if (ch == 5) {
            if (front == -1)
                printf("Nothing inside!\n");
            else {
                printf("Deque : ");
                for (int i = front; i <= rear; i++)
                    printf("%d ", arr[i]);
                printf("\n");
            }
        } else {
            break;
        }
    }
}
