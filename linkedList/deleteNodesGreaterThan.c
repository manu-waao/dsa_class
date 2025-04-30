#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};
struct node *fnNode, *tmp, *stnode;

struct node * createNodeCircular(int n);
void displayList();
void deleteGreaterThanX();

int main(){
    int n;
    printf("Enter the number of nodes in circulr list: ");
    scanf("%d", &n);
    if(n > 0){
        createNodeCircular(n);
    }
    printf("Displaying node list: \n");
    displayList();
    deleteGreaterThanX();
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

void deleteGreaterThanX() {
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    struct node *cur = stnode, *prev = NULL;
    do {
        if(cur->num > x) {
            if(cur == stnode) {
                struct node *last = stnode;
                while(last->next != stnode) last = last->next;
                stnode = stnode->next;
                last->next = stnode;
                free(cur);
                cur = stnode;
            } else {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        } else {
            prev = cur;
            cur = cur->next;
        }
    } while(cur != stnode);
}
