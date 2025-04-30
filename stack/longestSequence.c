#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};
struct node *createNode(int n);
void findLongestInc(struct node *top);

void main(void){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node* top = NULL;
    if(n > 0){
        top = createNode(n);
    }
    findLongestInc(top);
}

struct node *createNode(int n){
    int num;
    struct node *stnode = NULL, *tmp;
    for (int i = 1; i <= n; i++){
        printf("Enter data for node %d: ", i);
        scanf("%d", &num);
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->num = num;
        newNode->next = stnode;
        stnode = newNode;
    }
    return stnode;
}

void findLongestInc(struct node *top){
    int max = 0, curr = 1;
    struct node *tmp = top;
    if(tmp == NULL){
        printf("0\n");
        return;
    }
    int prev = tmp->num;
    tmp = tmp->next;
    while(tmp != NULL){
        if(tmp->num > prev){
            curr++;
            if(curr > max) max = curr;
        } else {
            curr = 1;
        }
        prev = tmp->num;
        tmp = tmp->next;
    }
    if(max == 0) max = 1;
    printf("%d\n", max);
}
