#include <stdio.h>
#include <stdlib.h>

int *arr;
int counter = 0;
int s;

int popArrayStack();
void pushArrayStack();
void displayArrayStack();

void main(void) {
    printf("Enter size of stack: ");
    scanf("%d", &s);
    arr = (int *) malloc(s * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    while(1) {
        printf("\nPress 1 to push to stack\n");
        printf("Press 2 to pop from stack\n");
        printf("Press 3 to display the stack\n");
        printf("Press 0 to exit the program\n\n");
        int opt;
        scanf("%d", &opt);
        if (!opt){
            free(arr);
            exit(0);
        } else if (opt == 1){
            pushArrayStack();
        } else if (opt == 2) {
            popArrayStack();
        } else if (opt == 3){
            displayArrayStack();
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
}

void pushArrayStack() {
    if (counter != s){
        int val;
        printf("Enter value to push into stack: ");
        scanf("%d", &val);
        arr[counter] = val;
        counter++;
        printf("Pushed %d to stack\n", val);
    } else {
        printf("Overflow\n");
    }
}

int popArrayStack(){     
    if (counter == 0){ 
        printf("Underflow\n");
        return -1;
    } else {
        counter--;
        int rtnVal = arr[counter];
        printf("Popped %d from stack\n", rtnVal);
        return rtnVal;
    }
}

void displayArrayStack() {
    if (counter == 0){
        printf("Stack is empty\n"); 
    } else {        
        for (int i = counter - 1; i >= 0; i--){ 
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
