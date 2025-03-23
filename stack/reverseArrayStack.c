#include <stdio.h>
#include <stdlib.h>

int *arr;
int counter = 0;
int s;

void push(int *arr, int *counter);
void displayStack(int *arr, int counter);
void reverseStack(int *arr, int *counter);

int main(void) {
    printf("Enter size of stack: ");
    scanf("%d", &s);  // Removed the newline character
    
    arr = (int *) malloc(s * sizeof(int));
    
    while(1) {
        int opt;
        printf("Press 1 to push to stack\nPress 2 to display stack\nPress 3 to reverse a stack\nPress any other number to exit\n\n");
        scanf("%d", &opt);
        
        if (opt == 1) push(arr, &counter);
        else if (opt == 2) displayStack(arr, counter);
        else if (opt == 3) reverseStack(arr, &counter);
        else break;
    }

    free(arr);
    return 0;
}

void push(int *arr, int *counter) {
    if (*counter < s) {
        int val;
        printf("Enter value to push to stack: ");
        scanf("%d", &val);
        arr[*counter] = val;
        (*counter)++;
    } else {
        printf("Stack Overflow\n");
    }
}

void displayStack(int *arr, int counter) {
    if (counter == 0) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = counter - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}  

void reverseStack(int *arr, int *counter) {
    int start = 0, end = *counter - 1, temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;  
    }
    printf("Stack reversed\n");
}