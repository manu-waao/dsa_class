#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *fnNode, *temp;
struct node *fnNode2, *temp2;
struct node *stNode;

void createLL();
void displayLL();
void mergeLL();

void main(void){
    createLL();
    displayLL();
    // mergeLL();
}

void createLL(){
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


void mergeLL(){
    printf("Press 1 to link head to tail\nPress 2 to link in between\n\n");
    int opt;
    scanf("%d", &opt);
    if(opt == 1){
        
    }
}