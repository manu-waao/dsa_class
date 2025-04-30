#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct node *createNode(int n);
struct node *insertNode(struct node *root, int data);
int countGreater(struct node *root, int x);

void main(void){
    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if(n > 0){
        root = createNode(n);
    }
    printf("Enter value x: ");
    scanf("%d", &x);
    printf("Count of nodes greater than %d is: %d\n", x, countGreater(root, x));
}

struct node *createNode(int n){
    int num;
    struct node *stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode != NULL){
        printf("Enter data for node 1: ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->left = stnode->right = NULL;
        for (int i = 2; i <= n; i++){
            printf("Enter data for node %d: ", i);
            scanf("%d", &num);
            insertNode(stnode, num);
        }
    }
    return stnode;
}

struct node *insertNode(struct node *root, int data){
    if (root == NULL){
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->num = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->num){
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int countGreater(struct node *root, int x){
    if(root == NULL) return 0;
    int count = 0;
    if(root->num > x) count++;
    count += countGreater(root->left, x);
    count += countGreater(root->right, x);
    return count;
}
