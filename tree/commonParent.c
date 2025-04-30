#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    int h;
    struct node *left;
    struct node *right;
};

int max(int a, int b) { return a > b ? a : b; }
int height(struct node *n) { return n ? n->h : 0; }

struct node *createAVL(int n);
struct node *insertNode(struct node *root, int data);
struct node *rotateRight(struct node *y);
struct node *rotateLeft(struct node *x);
int getBalance(struct node *n);
struct node *findLCA(struct node *root, int n1, int n2);

void main(void){
    int n, a, b;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if(n > 0){
        root = createAVL(n);
    }
    printf("Enter two node values to find LCA: ");
    scanf("%d %d", &a, &b);
    struct node *lca = findLCA(root, a, b);
    if(lca)
        printf("Lowest Common Ancestor of %d and %d is: %d\n", a, b, lca->num);
    else
        printf("LCA not found!\n");
}

struct node *createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = data;
    newNode->left = newNode->right = NULL;
    newNode->h = 1;
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

int getBalance(struct node *n){
    return n ? height(n->left) - height(n->right) : 0;
}

struct node *rotateRight(struct node *y){
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->h = max(height(y->left), height(y->right)) + 1;
    x->h = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct node *rotateLeft(struct node *x){
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->h = max(height(x->left), height(x->right)) + 1;
    y->h = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct node *insertNode(struct node *root, int data){
    if (root == NULL)
        return createNode(data);
    if (data < root->num)
        root->left = insertNode(root->left, data);
    else if (data > root->num)
        root->right = insertNode(root->right, data);
    else
        return root;

    root->h = 1 + max(height(root->left), height(root->right));
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

struct node *findLCA(struct node *root, int n1, int n2){
    if (root == NULL)
        return NULL;

    if (root->num > n1 && root->num > n2)
        return findLCA(root->left, n1, n2);

    if (root->num < n1 && root->num < n2)
        return findLCA(root->right, n1, n2);

    return root;
}
