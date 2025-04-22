#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct node *createNode(int n);
void displayTree(struct node *root);
int countNodes(struct node *root);
struct node *insertNode(struct node *root, int data);
void traverseInBfs(struct node *root);

void main(void){
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if (n > 0){
        root = createNode(n);
    }
    displayTree(root);
    printf("The number of nodes in the tree is: %d\n", countNodes(root));
    traverseInBfs(root);
}

struct node *createNode(int n){
    int num;
    struct node *stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode != NULL){
        printf("Enter data for node 1: ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->left = stnode->right = NULL;
        struct node *tmp = stnode;

        for (int i = 2; i <= n; i++){
            printf("Enter data for node %d: ", i);
            scanf("%d", &num);
            tmp = insertNode(tmp, num);
        }
    } else {
        printf("Memory error\n");
    }
    return stnode;
}

void displayTree(struct node *root){
    if (root != NULL){
        printf("%d\n", root->num);
        displayTree(root->left);
        printf("left over");
        displayTree(root->right);
    }
}

int countNodes(struct node *root){
    if (root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
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


void traverseInBfs(struct node *root){
    if(root==NULL) return;
    printf("%d->", root->num);
    printf("\n\n\n\n");
    traverseInBfs(root->left);
    printf("this is right----");
    traverseInBfs(root->right);
    printf("-----right");
}