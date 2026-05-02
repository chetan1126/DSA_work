#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function Prototypes
Node* createNode(int data);
void insertAtBeg(Node** head, int data);
void insertAtEnd(Node** head, int data);
void insertAtPos(Node** head, int data, int pos);
void insertSorted(Node** head, int data);
void deleteFromBeg(Node** head);
void deleteFromEnd(Node** head);
void deleteFromPos(Node** head, int pos);
void deleteByElement(Node** head, int key);
int listNodeCount(Node* head);
void displayList(Node* head);
void reverseDisplay(Node* head);
void reverseList(Node** head);
void sortList(Node** head);
void freeAllNodes(Node** head);

int main() {
    Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert Beg  2. Insert End  3. Insert Pos  4. Insert Sorted\n");
        printf("5. Delete Beg  6. Delete End  7. Delete Pos  8. Delete Element\n");
        printf("9. Display     10. Node Count 11. Rev Display 12. Reverse List\n");
        printf("13. Sort List  14. Free & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Data: "); scanf("%d", &data); insertAtBeg(&head, data); break;
            case 2: printf("Data: "); scanf("%d", &data); insertAtEnd(&head, data); break;
            case 3: printf("Data: "); scanf("%d", &data); printf("Pos: "); scanf("%d", &pos); insertAtPos(&head, data, pos); break;
            case 4: printf("Data: "); scanf("%d", &data); insertSorted(&head, data); break;
            case 5: deleteFromBeg(&head); break;
            case 6: deleteFromEnd(&head); break;
            case 7: printf("Pos: "); scanf("%d", &pos); deleteFromPos(&head, pos); break;
            case 8: printf("Element: "); scanf("%d", &data); deleteByElement(&head, data); break;
            case 9: displayList(head); break;
            case 10: printf("Total Nodes: %d\n", listNodeCount(head)); break;
            case 11: printf("Reverse: "); reverseDisplay(head); printf("NULL\n"); break;
            case 12: reverseList(&head); printf("List Reversed.\n"); break;
            case 13: sortList(&head); printf("List Sorted.\n"); break;
            case 14: freeAllNodes(&head); exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}

// --- CORE FUNCTIONS ---

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertAtPos(Node** head, int data, int pos) {
    int count = listNodeCount(*head);
    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position!\n");
        return;
    }
    if (pos == 1) {
        insertAtBeg(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next && curr->next->data < data) curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
}

void deleteFromBeg(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteFromPos(Node** head, int pos) {
    int count = listNodeCount(*head);
    if (*head == NULL || pos < 1 || pos > count) {
        printf("Invalid Position or Empty List!\n");
        return;
    }
    if (pos == 1) {
        deleteFromBeg(head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void deleteByElement(Node** head, int key) {
    if (*head == NULL) return;
    if ((*head)->data == key) {
        deleteFromBeg(head);
        return;
    }
    Node* temp = *head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) {
        printf("Element not found!\n");
    } else {
        Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

int listNodeCount(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void displayList(Node* head) {
    if (!head) printf("Empty List!");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void reverseDisplay(Node* head) {
    if (head == NULL) return;
    reverseDisplay(head->next);
    printf("%d -> ", head->data);
}

void reverseList(Node** head) {
    Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void sortList(Node** head) {
    if (!*head || !(*head)->next) return;
    Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void freeAllNodes(Node** head) {
    Node* curr = *head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
    printf("Memory Freed. Exiting...\n");
}
