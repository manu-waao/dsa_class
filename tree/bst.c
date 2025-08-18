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
struct node *insertNode(struct node *root, int data);
void findElement(struct node *root);

int main() {
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if (n > 0) {
        root = createNode(n);
    }
    printf("BST tree (in preorder): \n");
    displayTree(root);
    printf("The number of nodes in the tree is: %d\n", countNodes(root));
    findElement(root);
    return 0;
}

struct node *createNode(int n) {
    int num;
    stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode != NULL) {
        printf("Enter data for node 1: ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->left = stnode->right = NULL;
        tmp = stnode;

        for (int i = 2; i <= n; i++) {
            printf("Enter data for node %d: ", i);
            scanf("%d", &num);
            tmp = insertNode(tmp, num);
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

void findElement(struct node *root){
    int lookupVal, iter=1;
    scanf("%d", &lookupVal);
    printf("Enter value to search: ");
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }else{
        struct node *current = root;
        while (current != NULL) {
            if (lookupVal == current->num) {
                printf("Element %d found in the tree after %d iterations \n", lookupVal, iter);
                printf("Level %d, ", iter-1);
                printf("Height %d, ", iter);
                return;
            } else if (lookupVal < current->num) {
                current = current->left;
            } else {
                current = current->right;
            }
            iter++;
        }
        printf("Element %d not found in the tree.\n", lookupVal);   
    }
}



int countNodes(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

struct node *insertNode(struct node *root, int data) {
    if (root == NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->num = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->num) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}
