#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};
struct node *fnNode, *tmp, *stnode;
struct node * createNodeCircular(int n);
void displayList();
struct node *insertionInCircular(struct node * h, int n);
void insertAtEnd();
void insertBeforeNode();
void insertAfterNode();
void deleteFromBeginning();
void deleteAtEnd();


int main(){
    int n, m;
    printf("Enter the number of nodes in circulr list: ");
    scanf("%d", &n);
    struct node* okay;
    if(n > 0){
        okay = createNodeCircular(n);
    }
    printf("Displaying node list: \n");
    displayList();
    printf("Press 1 to insert\nPress 2 to delete\n");
    scanf("%d", &m);
    if(m == 1){
        insertionInCircular(okay, n);
    } 
    // else if (m == 2){
    //     deleteAtEnd();
    //     deleteFromBeginning();
    // }
    printf("Displaying node list: \n");
    displayList();
    return 0;
}


struct node * insertionInCircular(struct node * h, int n){
    int optionNode, status, data;
    printf("Enter node number to insert at : ");
    scanf("%d", &optionNode);
    printf("Enter before or after : ");
    scanf("%d", status);
    printf("Enter data : ");
    scanf("%d", data);
    struct node *nthNode;
    nthNode = (struct node *)malloc(sizeof(struct node));
    nthNode->num=data;
    nthNode->next=NULL;
    if(optionNode == 1){
        nthNode->next = h;
        while(h!=NULL){
            h = h->next;
        }
        h->next = nthNode;
    }
    return nthNode;
}

struct node * createNodeCircular(int n) {
    int num;
    stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode != NULL) {
        printf("Enter data for node 1: ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->next = NULL;
        tmp = stnode;
        for (int i = 2; i <= n; i++) {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if (fnNode == NULL) {
                printf("Memory allocation failed!\n");
                break;
            } else {
                printf("Enter data for node %d: ", i);
                scanf("%d", &num);
                if(i == n){
                    fnNode->num = num;
                    fnNode->next = stnode;
                }else {
                    fnNode->num = num;
                    fnNode->next = NULL;
                }
                tmp->next = fnNode;
                tmp = tmp->next;
            }
        }
    } else {
        printf("Memory allocation failed for the first node!\n");
    }
    return stnode;
}

void displayList(){
    struct node *tmp;
    if (stnode != NULL && stnode->next != NULL) {
        tmp = stnode;
        do{
            printf("%d\n", tmp->num);
            tmp = tmp->next;
        }while(tmp != stnode);
        printf("\n");
    } else {
        printf("Cannot be made\n");
    }
}



void insertAtEnd(){
    int val;
    scanf("%d", &val);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->num = val;
    newNode->next = NULL;

    if(stnode == NULL){
        stnode = newNode;
    } else {
        struct node *temp = stnode;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

}

void deleteFromBeginning() {
    if(stnode == NULL) {
        printf("Underflow\n");
        return;
    }
    struct node * del = (struct node *)malloc(sizeof(struct node));
    del = stnode;
    stnode = stnode->next;
    free(del);
    printf("Node deleted from the beginning\n");
}



void insertBeforeNode(){
    int val, newVal;
    scanf("%d", &val);
    scanf("%d", &newVal);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->num = newVal;

    if(stnode == NULL) return;

    if(stnode->num == val){
        newNode->next = stnode;
        stnode = newNode;
        return;
    }

    struct node *temp = stnode;
    while(temp->next != NULL && temp->next->num != val){
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
    newNode->num = newVal;

    if(stnode == NULL) return;

    struct node *temp = stnode;
    while(temp != NULL && temp->num != val){
        temp = temp->next;
    }
    if(temp == NULL) return;
    newNode->next = temp->next;
    temp->next = newNode;
}



void deleteAtEnd() {
    if(fnNode == NULL) {
        printf("Underflow\n");
        return;
    }
    struct node * del2 = (struct node *)malloc(sizeof(struct node));
    del2 = fnNode;
    struct node *prev = NULL;
    while(del2->next != NULL) {
        prev = del2;
        del2 = del2->next;
    }

    if(prev == NULL) {
        free(fnNode);
        fnNode = NULL;
    } else {
        prev->next = NULL;
        free(del2);
    }
    printf("Node deleted\n");
}
