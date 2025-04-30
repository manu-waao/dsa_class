#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};
struct node *fnNode, *tmp, *stnode;

struct node * createNodeCircular(int n);
void displayList();
void removeDuplicates();

int main(){
    int n;
    printf("Enter the number of nodes in circulr list: ");
    scanf("%d", &n);
    if(n > 0){
        createNodeCircular(n);
    }
    printf("Displaying node list: \n");
    displayList();
    removeDuplicates();
    printf("Displaying node list: \n");
    displayList();
    return 0;
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
            printf("Enter data for node %d: ", i);
            scanf("%d", &num);
            if(i == n){
                fnNode->num = num;
                fnNode->next = stnode;
            } else {
                fnNode->num = num;
                fnNode->next = NULL;
            }
            tmp->next = fnNode;
            tmp = tmp->next;
        }
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
    } else {
        printf("Cannot be made\n");
    }
}

void removeDuplicates() {
    struct node *cur = stnode;
    do {
        struct node *runner = cur;
        while(runner->next != stnode) {
            if(runner->next->num == cur->num) {
                struct node *del = runner->next;
                runner->next = del->next;
                free(del);
            } else {
                runner = runner->next;
            }
        }
        cur = cur->next;
    } while(cur != stnode);
}


