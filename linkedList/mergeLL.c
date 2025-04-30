#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};
struct node *fnNode, *tmp, *stnode, *stnode2;
struct node * createNodeCircular(int n);
void displayList(struct node *start);
struct node * mergeLists(struct node *list1, struct node *list2);

int main(){
    int n1, n2;
    printf("Enter the number of nodes in first circular list: ");
    scanf("%d", &n1);
    if(n1 > 0){
        stnode = createNodeCircular(n1);
    }
    printf("First list: \n");
    displayList(stnode);
    printf("Enter the number of nodes in second circular list: ");
    scanf("%d", &n2);
    if(n2 > 0){
        stnode2 = createNodeCircular(n2);
    }
    printf("Second list: \n");
    displayList(stnode2);
    struct node *merged = mergeLists(stnode, stnode2);
    printf("Merged list: \n");
    displayList(merged);
}

struct node * createNodeCircular(int n) {
    int num;
    struct node *startNode = (struct node *)malloc(sizeof(struct node));
    if (startNode != NULL) {
        printf("Enter data for node 1: ");
        scanf("%d", &num);
        startNode->num = num;
        startNode->next = NULL;
        tmp = startNode;
        for (int i = 2; i <= n; i++) {
            fnNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data for node %d: ", i);
            scanf("%d", &num);
            if(i == n){
                fnNode->num = num;
                fnNode->next = startNode;
            } else {
                fnNode->num = num;
                fnNode->next = NULL;
            }
            tmp->next = fnNode;
            tmp = tmp->next;
        }
    }
    return startNode;
}

void displayList(struct node *start){
    struct node *tmp;
    if (start != NULL && start->next != NULL) {
        tmp = start;
        do{
            printf("%d\n", tmp->num);
            tmp = tmp->next;
        }while(tmp != start);
    } else {
        printf("Cannot be made\n");
    }
}

struct node * mergeLists(struct node *list1, struct node *list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    struct node *last1 = list1;
    while(last1->next != list1) {
        last1 = last1->next;
    }
    struct node *last2 = list2;
    while(last2->next != list2) {
        last2 = last2->next;
    }
    last1->next = list2;
    last2->next = list1;
    return list1;
}
