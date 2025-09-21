// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int num;
//     struct node *left;
//     struct node *right;
// };

// struct node *fnNode, *tmp, *stnode, *p2;
// struct node *createNode(int n);
// int countNodes(struct node *root);
// struct node *insertNode(struct node *root, int data);
// void findElement(struct node *root);


// void preorderTraversal(struct node *root);
// void inorderTraversal(struct node *root);
// void postorderTraversal(struct node *root);

// int main() {
//     int n, m;
//     printf("Enter the number of nodes: ");
//     scanf("%d", &n);
//     struct node* root = NULL;
//     if (n > 0) {
//         root = createNode(n);
//     }

//     printf("\nPreorder traversal:\n");
//     preorderTraversal(root);

//     printf("\nInorder traversal:\n");
//     inorderTraversal(root);

//     printf("\nPostorder traversal:\n");
//     postorderTraversal(root);

//     printf("\nThe number of nodes in the tree is: %d\n", countNodes(root));
//     printf("Enter value to search: ");
//     findElement(root);

//     return 0;
// }

// struct node *createNode(int n) {
//     int num;
//     stnode = (struct node *)malloc(sizeof(struct node));
//     if (stnode != NULL) {
//         printf("Enter data for node 1: ");
//         scanf("%d", &num);
//         stnode->num = num;
//         stnode->left = stnode->right = NULL;
//         tmp = stnode;

//         for (int i = 2; i <= n; i++) {
//             printf("Enter data for node %d: ", i);
//             scanf("%d", &num);
//             tmp = insertNode(tmp, num);
//         }
//     } else {
//         printf("Memory error\n");
//     }
//     return stnode;
// }

// void preorderTraversal(struct node *root) {
//     if (root != NULL) {
//         printf("%d ", root->num);
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
//     }
// }

// void inorderTraversal(struct node *root) {
//     if (root != NULL) {
//         inorderTraversal(root->left);
//         printf("%d ", root->num);
//         inorderTraversal(root->right);
//     }
// }

// void postorderTraversal(struct node *root) {
//     if (root != NULL) {
//         postorderTraversal(root->left);
//         postorderTraversal(root->right);
//         printf("%d ", root->num);
//     }
// }

// void findElement(struct node *root){
//     int lookupVal, iter=1;
//     scanf("%d", &lookupVal);
//     if (root == NULL) {
//         printf("Tree is empty.\n");
//         return;
//     } else {
//         struct node *current = root;
//         while (current != NULL) {
//             if (lookupVal == current->num) {
//                 printf("Element %d found in the tree after %d iterations \n", lookupVal, iter);
//                 printf("Level %d, ", iter-1);
//                 printf("Height %d\n", iter);
//                 return;
//             } else if (lookupVal < current->num) {
//                 current = current->left;
//             } else {
//                 current = current->right;
//             }
//             iter++;
//         }
//         printf("Element %d not found in the tree.\n", lookupVal);   
//     }
// }

// int countNodes(struct node *root) {
//     if (root == NULL) {
//         return 0;
//     }
//     return 1 + countNodes(root->left) + countNodes(root->right);
// }

// struct node *insertNode(struct node *root, int data) {
//     if (root == NULL) {
//         struct node *newNode = (struct node *)malloc(sizeof(struct node));
//         newNode->num = data;
//         newNode->left = newNode->right = NULL;
//         return newNode;
//     }
//     if (data < root->num) {
//         root->left = insertNode(root->left, data);
//     } else {
//         root->right = insertNode(root->right, data);
//     }
//     return root;
// }







// #include <stdio.h>
// #include <stdlib.h>

// struct n {
//     int d;
//     struct n *l, *r;
// };

// struct n* nn(int x) {
//     struct n* t = (struct n*)malloc(sizeof(struct n));
//     t->d = x;
//     t->l = NULL;
//     t->r = NULL;
//     return t;
// }

// struct n* ins(struct n *h, int v) {
//     struct n *a, *b, *c;
//     a = nn(v);
//     if (h == NULL) return a;
//     c = NULL;
//     b = h;
//     while (b != NULL) {
//         c = b;
//         if (v < b->d) b = b->l;
//         else b = b->r;
//     }
//     if (v < c->d) c->l = a;
//     else c->r = a;
//     return h;
// }

// void ino(struct n* h) {
//     if (h) {
//         ino(h->l);
//         printf("%d ", h->d);
//         ino(h->r);
//     }
// }

// void pre(struct n* h) {
//     if (h) {
//         printf("%d ", h->d);
//         pre(h->l);
//         pre(h->r);
//     }
// }

// void post(struct n* h) {
//     if (h) {
//         post(h->l);
//         post(h->r);
//         printf("%d ", h->d);
//     }
// }

// int main() {
//     struct n* rt = NULL;
//     int arr[] = {10,20,30,40,50,60};
//     int s = sizeof(arr)/sizeof(arr[0]);
//     for (int i=0;i<s;i++) rt = ins(rt, arr[i]);
//     printf("ino:\n"); ino(rt); printf("\n");
//     printf("pre:\n"); pre(rt); printf("\n");
//     printf("post:\n"); post(rt); printf("\n");
//     return 0;
// }






// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *left;
//     struct node *right;
// };

// struct node* createNode(int data) {
//     struct node* temp = (struct node*)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->left = NULL;
//     temp->right = NULL;
//     return temp;
// }

// struct node* insertNode(struct node *tree, int val) {
//     struct node *ptr, *trav, *parent;
//     ptr = createNode(val);

//     if (tree == NULL)
//         return ptr;

//     parent = NULL;
//     trav = tree;

//     while (trav != NULL) {
//         parent = trav;
//         if (val < trav->data)
//             trav = trav->left;
//         else
//             trav = trav->right;
//     }

//     if (val < parent->data)
//         parent->left = ptr;
//     else
//         parent->right = ptr;

//     return tree;
// }

// void inorder(struct node* tree) {
//     if (tree != NULL) {
//         inorder(tree->left);
//         printf("%d ", tree->data);
//         inorder(tree->right);
//     }
// }

// int searchNode(struct node* tree , int val , int depth){
//     depth += 1;
//     if(tree == NULL) {
//         printf("Element %d was not located in the tree.\n", val);
//         return 0;
//     }
//     if(tree->data < val) {
//         searchNode(tree->right , val , depth);
//     }
//     else if(tree->data > val) {
//         searchNode(tree->left , val , depth);
//     }
//     else {
//         printf("Element %d is present in the tree.\n", val);
//         printf("Its distance from the root is %d step(s).\n", depth);
//         return 1;
//     }
//     return 0;
// }

// int main() {
//     struct node* root = NULL;
//     int values[] = {50,40,20,10,30,80,70,60,90,100};
//     int n = sizeof(values) / sizeof(values[0]);

//     for (int i = 0; i < n; i++) {
//         root = insertNode(root, values[i]);
//     }

//     printf("Tree in Inorder Traversal:\n");
//     inorder(root);
//     printf("\n");

//     int val;
//     printf("Enter a number to look for: ");
//     scanf("%d", &val);
//     int depth = -1;

//     searchNode(root , val , depth);

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct node *fnNode, *tmp, *stnode, *p2;
struct node *createNode(int n);
int countNodes(struct node *root);
struct node *insertNode(struct node *root, int data);
struct node *deleteNode(struct node *root, int key);
void preorderTraversal(struct node *root);

int main() {
    int n, delVal;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node* root = NULL;
    if (n > 0) {
        root = createNode(n);
    }

    printf("\nPreorder traversal before deletion:\n");
    preorderTraversal(root);

    printf("\nEnter a value to delete: ");
    scanf("%d", &delVal);
    root = deleteNode(root, delVal);

    printf("\nPreorder traversal after deletion:\n");
    preorderTraversal(root);

    printf("\nThe number of nodes in the tree is: %d\n", countNodes(root));

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

void preorderTraversal(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->num);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
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

struct node *findMin(struct node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) return root;

    if (key < root->num) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->num) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right);
        root->num = temp->num;
        root->right = deleteNode(root->right, temp->num);
    }
    return root;
}
