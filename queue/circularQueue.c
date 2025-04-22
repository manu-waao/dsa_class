#include <stdio.h>
#define A 10
int q[A];
int front = -1, rear = -1;

void enq(int val){
    if ((rear + 1) % A == front){
        printf("Overflow\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % A;  
        q[rear] = val;
        printf("Insrted value  %d\n", val);
    }
}

void deq(){
    if (front == -1){
        printf("Underflow\n"); 
    } else { 
        printf("Removed %d\n", q[front]);
        if (front == rear){
            front = rear = -1; 

        } else {
            front = (front + 1) % A;
        }
    }
}

void display(){
    if (front == -1){
        printf("Empty q\n");
    } else { 
        printf("Data :");
        int i = front;
        while (i != rear){
            printf("%d ", q[i]);
            i = (i + 1) % A;
        }
        printf("%d\n", q[rear]);
    }
}

int main(){
    int choice, val;
    while (1){
        printf("\nPress 1 to enq\nPress 2 to deq\nPress 3 to display\nPress 4 to exit\n");
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
                return 0;
            default:
                printf("Invalid input\n");
        }
    }
}



