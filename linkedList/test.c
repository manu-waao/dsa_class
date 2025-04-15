#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

struct node *fnNode, *tmp, *stnode, *p2;
struct node * createNodeCircular(int n);
void displayList();
struct node *insertionInCircular(struct node * h, int n);
void del(int val);

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
    else if (m == 2){
        del(3);
    }
    displayList();
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


void del(int val){
    if(stnode == NULL){ 
        printf("Empty string");
    } else {
        struct node * temp = (struct node *)malloc(sizeof(struct node));
        temp = stnode->next;
        while(temp != stnode){
            if(temp->num = val){
                break;
            }
            temp = temp->next;
        }
        p2 = temp->next;
        temp->next = temp->next->next;
        free(p2);
    }
}


