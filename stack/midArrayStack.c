#include <stdio.h>
#include <stdlib.h>

int *arr;
int counter = 0;
int s;

void push(int *arr, int *counter);
void displayStack(int *arr, int counter);
int findMiddle(int *arr, int counter);

void main(void) {
    printf("Enter size of stack: ");
    scanf("%d", &s);
    arr = (int *) malloc(s * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    while(1){
        printf("\nPress 1 to push to stack\n");
        printf("Press 2 to display stack\n");
        printf("Press 3 to find the middle element\n");
        printf("Press 0 to exit the program\n\n");
        
        int opt;
        scanf("%d", &opt);
        
        if (!opt) {
            free(arr);
            exit(0);
        } else if (opt == 1) {
            push(arr, &counter);
        } else if (opt == 2){
            displayStack(arr, counter);
        } else if (opt == 3){
            int mid = findMiddle(arr, counter);
            if (mid != -1){
                printf("Middle element of the stack is : %d\n", mid);
            }
        } else {
            printf("Invalid input\n");
        }
    }
}

void push(int *arr, int *counter) {
    if (*counter != s) {
        int val;
        printf("Enter value to push into stack: ");
        scanf("%d", &val);
        arr[*counter] = val;
        (*counter)++;
        printf("Pushed %d to stack.\n", val);
    } else {
        printf("Overflow\n");
    }
}

void displayStack(int *arr, int counter) {
    if (counter == 0) {
        printf("Stack is empty\n");
    } else {
        for (int i = counter - 1; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int findMiddle(int *arr, int counter){
    if (counter == 0) {
        printf("Stack is empty\n");
        return -1; 
    }
    return arr[counter / 2]; 
}
