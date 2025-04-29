#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char firstName[50];
    char lastName[50];
    int regNum;
    struct node *next;
};

void addPerson(struct node **head, char *firstName, char *lastName, int regNum);
int removePerson(struct node **head, char *firstName, char *lastName);
void showList(struct node *head, const char *listName);
void processFile(const char *filename, int maxPeople);
void freeList(struct node *head);
void moveToTrip(struct node **bookingList, struct node **tripList, struct node **waitList, int maxPeople);
int removeFromAllLists(struct node **bookingList, struct node **tripList, struct node **waitList, char *firstName, char *lastName);

int main() {
    int maxPeople;
    printf("Enter the number of tourists to accommodate: ");
    scanf("%d", &maxPeople);
    processFile("EASYTRIP.txt", maxPeople);
    return 0;
}

void addPerson(struct node **head, char *firstName, char *lastName, int regNum) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->firstName, firstName);
    strcpy(newNode->lastName, lastName);
    newNode->regNum = regNum;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int removePerson(struct node **head, char *firstName, char *lastName) {
    struct node *temp = *head, *prev = NULL;

    if (temp == NULL) {
        return 0;
    }

    if (strcmp(temp->firstName, firstName) == 0 && strcmp(temp->lastName, lastName) == 0) {
        *head = temp->next;
        free(temp);
        return 1;
    }

    while (temp != NULL && !(strcmp(temp->firstName, firstName) == 0 && strcmp(temp->lastName, lastName) == 0)) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return 0;
    }

    prev->next = temp->next;
    free(temp);
    return 1;
}

void showList(struct node *head, const char *listName) {
    if (head == NULL) {
        printf("%s is empty.\n", listName);
        return;
    }

    printf("%s ", listName);
    struct node *tmp = head;
    while (tmp != NULL) {
        printf("%d %s %s ", tmp->regNum, tmp->firstName, tmp->lastName);
        tmp = tmp->next;
    }
    printf("\n");
}

void freeList(struct node *head) {
    struct node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void moveToTrip(struct node **bookingList, struct node **tripList, struct node **waitList, int maxPeople) {
    struct node *current = *bookingList;
    int count = 0;

    while (current != NULL && count < maxPeople) {
        addPerson(tripList, current->firstName, current->lastName, current->regNum);
        count++;
        current = current->next;
    }

    while (current != NULL) {
        addPerson(waitList, current->firstName, current->lastName, current->regNum);
        current = current->next;
    }

    *bookingList = NULL;
}

int removeFromAllLists(struct node **bookingList, struct node **tripList, struct node **waitList, char *firstName, char *lastName) {
    int found = 0;

    if (removePerson(bookingList, firstName, lastName)) {
        found = 1;
    }

    if (removePerson(tripList, firstName, lastName)) {
        found = 1;
    }

    if (removePerson(waitList, firstName, lastName)) {
        found = 1;
    }

    return found;
}


// void recursiveReverse(struct Node** head_ref)
// {
// 	struct Node* first;
// 	struct Node* rest;
// 	if (*head_ref == NULL)
// 	return; 
// 	first = *head_ref; 
// 	rest = first->next;
// 	if (rest == NULL)
// 	return;
// 	recursiveReverse(&rest);
// 	first->next->next = first; 
// 	first->next = NULL;		 
// 	*head_ref = rest;			 
// }


void processFile(const char *filename, int maxPeople) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open the file %s\n", filename);
        return;
    }

    struct node *bookingList = NULL;
    struct node *tripList = NULL;
    struct node *waitList = NULL;

    int op;
    char first[50], last[50];
    int day;

    fscanf(file, "%d", &maxPeople);

    while (fscanf(file, "%d", &op) != EOF) {
        if (op == 1) {
            fscanf(file, "%s %s %d", first, last, &day);
            addPerson(&bookingList, first, last, day);
            addPerson(&waitList, first, last, day);
            moveToTrip(&bookingList, &tripList, &waitList, maxPeople);
        } else if (op == 2) {
            fscanf(file, "%s %s", first, last);
            int found = removeFromAllLists(&bookingList, &tripList, &waitList, first, last);
            if (!found) {
                printf("Tourist %s %s not found!\n", first, last);
            }
        } else if (op == 3) {
            showList(bookingList, "BOOKING");
        } else if (op == 4) {
            showList(tripList, "TRIP");
        } else if (op == 8) {
            showList(waitList, "WAITLIST");
        }
    }

    showList(bookingList, "BOOKING");
    showList(tripList, "TRIP");
    showList(waitList, "WAITLIST");

    fclose(file);

    freeList(bookingList);
    freeList(tripList);
    freeList(waitList);
}




