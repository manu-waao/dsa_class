#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct node *createNode(int n);
struct node *insertNode(struct node *root, int data);
void displayInorder(struct node *root);
struct node *deleteOutOfRange(struct node *root, int l, int r);

void main(void) {
    int n, l, r;
    printf("Enter nodes count: ");
    scanf("%d", &n);
    struct node *root = NULL;
    if (n > 0) {
        root = createNode(n);
    }
    printf("Tree inorder:\n");
    displayInorder(root);
    printf("\nEnter L and R: ");
    scanf("%d %d", &l, &r);
    root = deleteOutOfRange(root, l, r);
    printf("Tree after deletion:\n");
    displayInorder(root);
}

struct node *createNode(int n) {
    int num;
    struct node *root = NULL;
    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &num);
        root = insertNode(root, num);
    }
    return root;
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

void displayInorder(struct node *root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("%d ", root->num);
        displayInorder(root->right);
    }
}

struct node *deleteOutOfRange(struct node *root, int l, int r) {
    if (root == NULL)
        return NULL;
    root->left = deleteOutOfRange(root->left, l, r);
    root->right = deleteOutOfRange(root->right, l, r);
    if (root->num < l) {
        struct node *rChild = root->right;
        free(root);
        return rChild;
    }
    if (root->num > r) {
        struct node *lChild = root->left;
        free(root);
        return lChild;
    }
    return root;
}
