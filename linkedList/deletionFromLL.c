#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *fnNode = NULL, *temp = NULL;


void displayNodeList();
void pushNodeList();
void deleteFromBeginning();
void deleteAfterNode();
void deleteBeforeNode();
void deleteAtEnd();
void disposeNodeList();

void main(void) {
    while(1) {
        printf("Press 1 to push value to linked list\n");
        printf("Press 2 to delete node from the beginning\n");
        printf("Press 3 to delete node after a specific node\n");
        printf("Press 4 to delete node before a specific node\n");
        printf("Press 5 to delete node from the end\n");
        printf("Press 6 to display linked list\n");
        printf("Press 0 to exit\n\n");

        int opt;
        scanf("%d", &opt);
        if(opt == 0) {
            disposeNodeList();
            exit(0);
        } else if(opt == 1) {
            pushNodeList();
        } else if(opt == 2) {
            deleteFromBeginning();
        } else if(opt == 3) {
            deleteAfterNode();
        } else if(opt == 4) {
            deleteBeforeNode();
        } else if(opt == 5) {
            deleteAtEnd();
        } else if(opt == 6) {
            displayNodeList();
        } else {
            printf("Invalid input\n");
        }
    }
}


void pushNodeList() {
    int val;
    printf("Enter value to push to linked list: ");
    scanf("%d", &val);

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(fnNode == NULL) {
        fnNode = newNode;
    } else {
        temp = fnNode;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteFromBeginning() {
    if(fnNode == NULL) {
        printf("Underflow\n");
        return;
    }
    temp = fnNode;
    fnNode = fnNode->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

void deleteAfterNode() {
    if(fnNode == NULL) {
        printf("Underflow\n");
        return;
    }
    
    int val;
    printf("Enter the value of the node after which you want to delete: ");
    scanf("%d", &val);

    temp = fnNode;
    while(temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        printf("No node found\n");
        return;
    }

    struct node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node deleted after %d.\n", val);
}

void deleteBeforeNode() {
    if(fnNode == NULL || fnNode->next == NULL) {
        printf("Cannot delete before specific node \n");
        return;
    }

    int val;
    printf("Enter node val: ");
    scanf("%d", &val);

    temp = fnNode;
    struct node *prev = NULL;
    while(temp != NULL && temp->next != NULL && temp->next->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        printf("No node found\n");
        return;
    }
    struct node *nodeToDelete = prev;
    if(prev == NULL) {
        printf("Underflow\n");
        return;
    }

    if(nodeToDelete == fnNode) {
        fnNode = fnNode->next;
        free(nodeToDelete);
    } else {
        prev->next = temp;
        free(nodeToDelete);
    }
    printf("Node deleted before %d\n", val);
}


void deleteAtEnd() {
    if(fnNode == NULL) {
        printf("Underflow\n");
        return;
    }

    temp = fnNode;
    struct node *prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL) {
        free(fnNode);
        fnNode = NULL;
    } else {
        prev->next = NULL;
        free(temp);
    }
    printf("Node deleted\n");
}

void displayNodeList() {
    if(fnNode == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = fnNode;
    while(temp != NULL) {
        printf("%d -> ", temp->data); 
        temp = temp->next;
    }
    printf("NULL\n");
}

void disposeNodeList(){
    temp = fnNode;
    while(temp != NULL){
        struct node *toDelete = temp;  
        temp = temp->next;
        free(toDelete); 
    }
    printf("All nodes deleted\n");
}
