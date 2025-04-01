#include <stdio.h>
#include <stdlib.h>

struct root {
    struct root *left;
    int data;
    struct root *right;
};
struct root *temp, *tRoot, *fnRoot;
struct root *createTree(struct root *t);
void displayTree(struct root *t);

void main(void){
    createTree(tRoot);
    displayTree(tRoot);
}


struct root * createTree(struct root *tRoot){
    tRoot = (struct root *)malloc(sizeof(struct root));
    if (tRoot == NULL){
        printF("Not enought memory");
    } else {
        int val, sz;
        printf("Enter the number of nodes : ");
        scanf("%d", &sz);
        printf("Enter data for node : ");
        scanf("%d", &val);
        tRoot->data = val;
        tRoot->left = NULL;
        tRoot->right = NULL;
        temp = tRoot;
        
        for(int i = 2; i < sz; i++){
            fnRoot = (struct root *)malloc(sizeof(struct root));
            if(fnRoot == NULL){
                printf("Memory error");
            } else {
                printf("Enter data : ");
                scanf("%d", &val);
                fnRoot->data = val;
                fnRoot->left = NULL;
                fnRoot->right = NULL;
                if(i&1){
                    temp->left = fnRoot; 
                    temp = temp->right;
                } else {
                    temp->right = fnRoot;
                    temp = temp->left;
                }
            }
        }
    }
}

void displayTree(struct root * tRoot){
    printf("hello");
    
}