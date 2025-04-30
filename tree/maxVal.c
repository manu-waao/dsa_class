#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct node *createNode(int n);
struct node *insertNode(struct node *root, int data);
int findMax(struct node *root);

void main(void){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if(n > 0){
        root = createNode(n);
    }
    printf("Maximum node value is: %d\n", findMax(root));
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

int findMax(struct node *root){
    if(root == NULL) return -99;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root->num;
    if(leftMax > max) max = leftMax;
    if(rightMax > max) max = rightMax;
    return max;
}
