#include <stdio.h>
#define A 5
int q[A];
int front = -1, rear = -1;

void enq(int val){
    if (rear == A - 1){
        printf("Overflow");
    } else {
        if (front == -1) front = 0;
        q[++rear] = val;
    }  
}

void deq(){
    if (front == -1 || front > rear){
        printf("Underflow");
    } else {
        printf("Removed : %d", q[front++]);
    }
}

void display(){
    if (front == -1 || front > rear){
        printf("Empty q");
    } else {
        printf("Data : ");
        for (int i = front; i <= rear; i++){
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

void main(){
    int choice, val;
    while (1){
        printf("\nPress 1 to enq\nPress 2 to deq\nPress 3 tp display\nPress 4 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter val: ");
                scanf("%d", &val);
                enq(val);
                break;
            case 2:
                deq();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid input");
        }
    }
}
