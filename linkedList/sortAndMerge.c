#include <stdio.h>
#include <stdlib.h>
#define A 10
int x = 10;
int arr[A];

struct node {
    int data;
    struct node *next;
};

struct node *fnNode, *temp;
struct node *fnNode2, *temp2;
struct node *stNode, *trav, *trav2, *sorted;


void createLL();
void displayLL();
void mergeLL();

void main(void){
    createLL();
    displayLL();
    mergeLL();
}

void createLL(){

    int x = 10;
    int arr2[x];

    int val;
    printf("Enter data for first linked list :\n\n ");
    fnNode = (struct node *)malloc(sizeof(struct node));
    if(fnNode == NULL) return;

    printf("Enter data for firt node: ");
    scanf("%d", &val);
    fnNode-> data = val;
    fnNode->next = NULL;
    temp = fnNode;
    printf("Enter the number of nodes you want to keep in linked list : ");
    int iter;
    scanf("%d", &iter);
    
    for(int i = 0; i < iter-1; i++){
        stNode = (struct node *)malloc(sizeof(struct node));
        if (stNode != NULL){
            printf("Enter value for node : ");
            scanf("%d", &val);
            stNode->data = val;
            stNode->next = NULL;
            temp->next = stNode;
            temp = temp->next;
        }
    }

    printf("Enter data for second linked list : \n\n\n");
    fnNode2 = (struct node *)malloc(sizeof(struct node));
    if(fnNode2 == NULL) return;
    printf("Enter data for first node : ");
    scanf("%d", &val);
    fnNode2-> data = val;
    fnNode2->next = NULL;
    temp2 = fnNode2;
    printf("\n\nEnter the number of nodes in second list : ");
    scanf("%d", &iter);
    for(int i = 0; i < iter - 1; i++){
        stNode = (struct node *)malloc(sizeof(struct node));
        if(stNode != NULL){
            printf("Enter data : ");
            scanf("%d", &val);
            stNode->data = val;
            stNode->next = NULL;
            temp2->next = stNode;
            temp2 = temp2->next;
        }
    }

}


void displayLL(){
    struct node *disp, *disp2;
    if (fnNode != NULL){
        disp = fnNode;
        printf("Data for List 1 : ");
        while(disp != NULL){
            printf("%d ", disp->data);
            disp = disp->next;
        }
        printf("\n");
    } else {
        printf("Empty list\n");
    }

    if (fnNode2 != NULL){
        disp2 = fnNode2;
        printf("Data for list 2 : ");
        while (disp2 != NULL){
            printf("%d ", disp2->data);
            disp2 = disp2->next;
        }
        printf("\n");
    } else {
        printf("Empty list\n");
    }
}

void sortArr(){
    for (int i = 0; i < A - 1; i++){
        for (int j = i + 1; j < A; j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void displaySorted(){
    struct node *disp3;
    if(sorted != NULL){
        disp3 = fnNode;
        printf("Data for sortedL: ");
        while(disp3 != NULL){
            printf("%d ", disp3->data);
            disp3 = disp3->next;
        }
        printf("\n");
    } else {
        printf("Empty list\n");
    }
}



void mergeLL(){
    trav = fnNode;
    int counter = 0;
    while(trav != NULL){
        printf("%d", trav->data);
        arr[counter] = trav->data;
        trav = trav->next;
        counter++;
    }
    trav2 = fnNode2;
    while(trav2 != NULL){
        printf("%d", trav2->data);
        arr[counter] = trav2->data;
        trav2 = trav2->next;
        counter++;
    }
    sortArr();
    printf("\n\n");
    for(int i = 0; i < A; i++){
        printf("%d", arr[i]);
    }

    sorted = (struct node *)malloc(sizeof(struct node));
    struct node *temp3, *var;
    if(sorted != NULL){
        sorted->data = -1;
        sorted->next=NULL;
        temp3-> next = sorted;
        temp3 = temp3->next;
    } else {
        printf("Memory bounf");
    }
    

    printf("Here ");
    for(int i = 0; i < A; i++){
        int toAppend = arr[i];
        int valToAppend;
        temp = fnNode;
        while(temp != NULL){
            if (toAppend == temp->data){
                printf("so far");
                var = (struct node *)malloc(sizeof(struct node));
                if (var != NULL){
                printf("%d", temp->data);
                var->data = toAppend;
                var->next = NULL;
                temp3-> next = var;
                temp3 = temp3->next;
            } else {
                printf("Memory out of bound");
            }
            }
        }
    }
    displaySorted();
}