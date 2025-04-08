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
struct node *deleteNode(struct node *root, int data);
struct node *minValueNode(struct node *node);

int main(){
    int n, m, delValue;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if (n > 0){
        root = createNode(n);
    }
    
    while (1){
        displayTree(root);
        printf("The number of nodes in the tree is: %d\n", countNodes(root));
        printf("Press 1 to insert\nPress 2 to delete\nPress 3 to exit\n");
        scanf("%d", &m);
        if (m == 1){
            int data;
            printf("Enter data for the new node: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            printf("Data: \n");
            displayTree(root);
            printf("Number of nodes: %d\n", countNodes(root));
        } else if (m == 2){
            printf("Enter the value to delete: ");
            scanf("%d", &delValue);
            root = deleteNode(root, delValue);
            printf("Data: \n");
            displayTree(root);
            printf("Number of nodes %d\n", countNodes(root));
        } else if (m == 3){
            break;
        }
    }
    
    return 0;
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

struct node *deleteNode(struct node *root, int data){
    if (root == NULL){
        return root;
    }
    if (data < root->num){
        root->left = deleteNode(root->left, data);
    } else if (data > root->num){
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        } else {
            struct node *temp = minValueNode(root->right);
            root->num = temp->num;
            root->right = deleteNode(root->right, temp->num);
        }
    }
    return root;
}

struct node *minValueNode(struct node *node){
    struct node *current = node;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}
