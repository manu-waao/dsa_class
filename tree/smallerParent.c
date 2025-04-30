#include <stdio.h>
#include <stdlib.h>

struct node {
    int num, h;
    struct node *left, *right;
};

struct node *createNode(int data);
struct node *insertNode(struct node *root, int data);
struct node *createAVL(int n);
int countBothChildrenGreater(struct node *root);

void main(void){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if(n > 0){
        root = createAVL(n);
    }
    printf("Nodes with both children greater than parent: %d\n", countBothChildrenGreater(root));
}

int countBothChildrenGreater(struct node *root){
    if(root == NULL) return 0;
    int count = 0;
    if(root->left && root->right){
        if(root->left->num > root->num && root->right->num > root->num)
            count = 1;
    }
    return count + countBothChildrenGreater(root->left) + countBothChildrenGreater(root->right);
}

int max(int a, int b) { return a > b ? a : b; }
int height(struct node *root){
    if (root == NULL) return -1;
    return 1 + max(height(root->left), height(root->right));
}

struct node *rotateRight(struct node *y){
    struct node *x = y->left, *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

struct node *rotateLeft(struct node *x){
    struct node *y = x->right, *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

int getBalance(struct node *n){
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}

struct node *insertNode(struct node *root, int data){
    if (root == NULL)
        return createNode(data);
    if (data < root->num)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->num)
        return rotateRight(root);
    if (balance < -1 && data > root->right->num)
        return rotateLeft(root);
    if (balance > 1 && data > root->left->num){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && data < root->right->num){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

struct node *createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = data;
    newNode->h = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *createAVL(int n){
    int num;
    struct node *stnode = NULL;
    printf("Enter data for node 1: ");
    scanf("%d", &num);
    stnode = insertNode(stnode, num);
    for (int i = 2; i <= n; i++){
        printf("Enter data for node %d: ", i);
        scanf("%d", &num);
        stnode = insertNode(stnode, num);
    }
    return stnode;
}
