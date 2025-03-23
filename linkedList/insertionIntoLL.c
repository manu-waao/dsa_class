#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtBeginning();
void insertAtEnd();
void insertBeforeNode();
void insertAfterNode();
void displayList();
void disposeList();

void main(void){
    while(1){
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert Before Node\n4. Insert After Node\n5. Display List\n0. Exit\n");
        int opt;
        scanf("%d", &opt);
        if(opt == 0){
            disposeList();
            exit(0);
        } else if(opt == 1){
            insertAtBeginning();
        } else if(opt == 2){
            insertAtEnd();
        } else if(opt == 3){
            insertBeforeNode();
        } else if(opt == 4){
            insertAfterNode();
        } else if(opt == 5){
            displayList();
        } else {
            printf("Invalid input\n");
        }
    }
}

void insertAtBeginning(){
    int val;
    scanf("%d", &val);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(){
    int val;
    scanf("%d", &val);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    } else {
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertBeforeNode(){
    int val, newVal;
    scanf("%d", &val);
    scanf("%d", &newVal);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newVal;

    if(head == NULL) return;

    if(head->data == val){
        newNode->next = head;
        head = newNode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL && temp->next->data != val){
        temp = temp->next;
    }

    if(temp->next == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfterNode(){
    int val, newVal;
    scanf("%d", &val);
    scanf("%d", &newVal);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newVal;

    if(head == NULL) return;

    struct node *temp = head;
    while(temp != NULL && temp->data != val){
        temp = temp->next;
    }

    if(temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList(){
    if(head == NULL) return;

    struct node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void disposeList(){
    struct node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
