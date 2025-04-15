#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct node *fnNode, *tmp, *stnode, *p2;
struct node *createNode(int n);
void displayTree(struct node *root);
int countNodes(struct node *root);
struct node *root, *root2;
struct node *mirrorImage(struct node *root);

void main() {
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    root = createNode(n);
    printf("Original tree: \n");
    displayTree(root);
    printf("The number of nodes: %d\n", countNodes(root));
    root2 = mirrorImage(root);
    printf("Tree after inversion: \n");
    displayTree(root2);
}

struct node *createNode(int n) {
    int num;
    stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode != NULL) {
        printf("Enter data for node 1: ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->left = NULL;
        stnode->right = NULL;
        tmp = stnode;
        for (int i = 2; i <= n; i++) {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if (fnNode == NULL) {
                printf("Memory error\n");
                break;
            } else {
                printf("Enter data for node %d: ", i);
                scanf("%d", &num);
                fnNode->num = num;
                fnNode->left = NULL;
                fnNode->right = NULL;
                if(i&1){
                    tmp->right = fnNode;
                    tmp = tmp->right;
                } else {
                    tmp->left = fnNode;
                    tmp = tmp->left;
                }
            }
        }
    } else {
        printf("Memory error\n");
    }
    return stnode;
}

void displayTree(struct node *root) {
    if (root != NULL) {
        printf("%d\n", root->num);
        displayTree(root->left);
        displayTree(root->right);
    }
}

int countNodes(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

struct node *mirrorImage(struct node *root){
    struct node *ptr;
    if(root!=NULL){
        mirrorImage(root->left);
        printf("Hello");
        ptr=root->left;
        printf("Hello2");
        ptr->left = ptr->right;
        printf("Hello3");
        root->right=ptr;
        mirrorImage(root->right);
    }
}


