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
void invertTree(struct node *root);

int main() {
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if (n > 0) {
        root = createNode(n);
    }
    
    printf("Original tree: \n");
    displayTree(root);
    printf("The number of nodes in the tree is: %d\n", countNodes(root));

    invertTree(root);
    printf("Tree after inversion: \n");
    displayTree(root);
    printf("The number of nodes in the tree is: %d\n", countNodes(root));

    printf("Press 1 to insert a new node\nPress 2 to exit\n");
    scanf("%d", &m);
    if (m == 1) {
        int data;
        printf("Enter data for the new node: ");
        scanf("%d", &data);
        root = insertNode(root, data);
        printf("Displaying tree after insertion: \n");
        displayTree(root);
        printf("The number of nodes in the tree is: %d\n", countNodes(root));
    }
    
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
            fnNode = (struct node *)malloc(sizeof(struct node));
            if (fnNode == NULL) {
                printf("Memory error\n");
                break;
            } else {
                printf("Enter data for node %d: ", i);
                scanf("%d", &num);
                fnNode->num = num;
                fnNode->left = fnNode->right = NULL;
                tmp->left = fnNode;
                tmp = tmp->left;
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

struct node *insertNode(struct node *root, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = data;
    newNode->left = newNode->right = NULL;

    if (root == NULL) {
        return newNode;
    } else {
        struct node *tmp = root;
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }
        tmp->left = newNode;
    }
    
    return root;
}

void invertTree(struct node *root) {
    if (root == NULL) {
        return;
    }
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
}
