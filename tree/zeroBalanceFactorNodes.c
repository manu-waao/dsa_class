#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct node *createNode(int n);
struct node *insertNode(struct node *root, int data);
int countNodes(struct node *root);
void zeroBalanceNodes(struct node *root);

void main(void){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if(n > 0){
        root = createNode(n);
    }
    printf("Zero balance nodes are:\n");
    zeroBalanceNodes(root);
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

int countNodes(struct node *root){
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void zeroBalanceNodes(struct node *root){
    if(root == NULL) return;
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    if(leftCount == rightCount){
        printf("%d\n", root->num);
    }
    zeroBalanceNodes(root->left);
    zeroBalanceNodes(root->right);
}
