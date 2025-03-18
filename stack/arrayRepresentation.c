#include <stdio.h>
#include <stdlib.h>
void arrStackPush(int *p, int counter);
int arrStackPop(int *p, int counter);
void arrStackDisp(int arr[]);
int s = 10, counter = 0;
int arr[s];
int *p = &arr;

void main(void){

    int option;
    while(1){
        printf("Press 1 for adding to stack\nPress 2 for poping from stack\nPress 3 to display the stack\nPress 0 to exit\n\n");
        scanf("%d", &option);
        if(!option){
            printf("Program Ended");
            exit(0);
        }
        else if(option == 1){
            arrStackPush(*p, counter);
        }
    }
}


void arrStackPush(int *p, int counter){
    int val;
    printf("Enter value to enter into stack : ");
    scanf("%d", &val);
    if(counter != s){
        p[counter] = val;
        counter++;
    } else { 
        printf("Overflow");
    }
}

int arrStackPop(int *p, int counter){
    if(counter == 0){
        printf("Underflow");
        return 0;
    } else {
        printf("%d", p[counter - 1]);
        counter--;
        s--;

    }
}