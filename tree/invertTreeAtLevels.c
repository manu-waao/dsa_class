#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct node *createNode(int n);
struct node *insertNode(struct node *root, int data);
void displayTree(struct node *root);
void invertAlternate(struct node *a, struct node *b, int lvl);

void main(void) {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node *root = NULL;
    if (n > 0) {
        root = createNode(n);
    }
    printf("Before:\n");
    displayTree(root);
    invertAlternate(root->left, root->right, 0);
    printf("After:\n");
    displayTree(root);
}

struct node *createNode(int n) {
    int num;
    struct node *stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode != NULL) {
        printf("Enter data for node 1: ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->left = stnode->right = NULL;
        struct node *tmp = stnode;

        for (int i = 2; i <= n; i++) {
            printf("Enter data for node %d: ", i);
            scanf("%d", &num);
            insertNode(stnode, num);
        }
    }
    return stnode;
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

void displayTree(struct node *root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("%d\n", root->num);
        displayTree(root->right);
    }
}

void invertAlternate(struct node *a, struct node *b, int lvl) {
    if (a == NULL || b == NULL)
        return;
    if (lvl % 2 == 0) {
        int tmp = a->num;
        a->num = b->num;
        b->num = tmp;
    }
    invertAlternate(a->left, b->right, lvl + 1);
    invertAlternate(a->right, b->left, lvl + 1);
}
