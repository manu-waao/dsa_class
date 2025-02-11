#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};
struct node *fnNode, *tmp, *stnode;
void createNodeList(int n);
void displayList();

int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createNodeList(n);
    printf("Displaying node list: ");
    displayList();
    return 0;
}

void createNodeList(int n) {
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
                fnNode->num = num;
                fnNode->next = NULL;
                tmp->next = fnNode;
                tmp = tmp->next;
            }
        }
    } else {
        printf("Memory allocation failed for the first node!\n");
    }
}

void displayList(){
    struct node *tmp;
    if (stnode != NULL) {
        tmp = stnode;
        while (tmp != NULL) {
            printf("%d ", tmp->num);
            tmp = tmp->next;
        }
        printf("\n");
    } else {
        printf("The list is empty.\n");
    }
}
