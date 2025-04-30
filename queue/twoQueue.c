#include <stdio.h>
#define MAX 100

int arr[MAX];
int front1 = 0, rear1 = -1;
int front2 = MAX, rear2 = MAX;

void enQueue1(int val) {
    if (rear1 + 1 == rear2) {
        printf("Full\n");
        return;
    }
    rear1++;
    arr[rear1] = val;
}

void enQueue2(int val) {
    if (rear1 + 1 == rear2) {
        printf("Full\n");
        return;
    }
    rear2--;
    arr[rear2] = val;
}

void deQueue1() {
    if (front1 > rear1) {
        printf("Empty\n");
        return;
    }
    front1++;
}

void deQueue2() {
    if (rear2 == MAX) {
        printf("Empty\n");
        return;
    }
    rear2++;
}

void showQueue1() {
    if (front1 > rear1) {
        printf("Empty\n");
        return;
    }
    for (int i = front1; i <= rear1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void showQueue2() {
    if (rear2 == MAX) {
        printf("Empty\n");
        return;
    }
    for (int i = rear2; i < MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main(void) {
    int ch, val;
    while (1) {
        printf("1 2 3 4 5 6 7 : ");
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d", &val);
            enQueue1(val);
        } else if (ch == 2) {
            scanf("%d", &val);
            enQueue2(val);
        } else if (ch == 3) {
            deQueue1();
        } else if (ch == 4) {
            deQueue2();
        } else if (ch == 5) {
            showQueue1();
        } else if (ch == 6) {
            showQueue2();
        } else {
            break;
        }
    }
}
