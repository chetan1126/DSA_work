#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct Node {
    int data;
    struct Node* prev;
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
        printf("\n--- Doubly Circular Linked List Menu ---\n");
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
            case 11: reverseDisplay(head); break;
            case 12: reverseList(&head); break;
            case 13: sortList(&head); break;
            case 14: freeAllNodes(&head); exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}

// --- CORE FUNCTIONS ---

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { printf("Memory Fail!\n"); exit(1); }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertAtBeg(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    if (*head == NULL) {
        insertAtBeg(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = (*head)->prev = newNode;
}

void insertAtPos(Node** head, int data, int pos) {
    int count = listNodeCount(*head);
    if (pos < 1 || pos > count + 1) { printf("Invalid Pos!\n"); return; }
    if (pos == 1) { insertAtBeg(head, data); return; }
    
    Node* temp = *head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void insertSorted(Node** head, int data) {
    if (*head == NULL || data <= (*head)->data) {
        insertAtBeg(head, data);
        return;
    }
    Node* curr = *head;
    while (curr->next != *head && curr->next->data < data) curr = curr->next;
    
    Node* newNode = createNode(data);
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next->prev = newNode;
    curr->next = newNode;
}

void deleteFromBeg(Node** head) {
    if (!*head) return;
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* last = temp->prev;
        *head = temp->next;
        (*head)->prev = last;
        last->next = *head;
        free(temp);
    }
}

void deleteFromEnd(Node** head) {
    if (!*head) return;
    if ((*head)->next == *head) {
        deleteFromBeg(head);
        return;
    }
    Node* last = (*head)->prev;
    last->prev->next = *head;
    (*head)->prev = last->prev;
    free(last);
}

void deleteFromPos(Node** head, int pos) {
    int count = listNodeCount(*head);
    if (!*head || pos < 1 || pos > count) return;
    if (pos == 1) { deleteFromBeg(head); return; }
    
    Node* temp = *head;
    for (int i = 1; i < pos; i++) temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void deleteByElement(Node** head, int key) {
    if (!*head) return;
    Node* curr = *head;
    do {
        if (curr->data == key) {
            if (curr == *head) deleteFromBeg(head);
            else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
            }
            return;
        }
        curr = curr->next;
    } while (curr != *head);
    printf("Element not found.\n");
}

int listNodeCount(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do { count++; temp = temp->next; } while (temp != head);
    return count;
}

void displayList(Node* head) {
    if (!head) { printf("List Empty\n"); return; }
    Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");
}

void reverseDisplay(Node* head) {
    if (!head) return;
    Node* last = head->prev;
    Node* temp = last;
    printf("Reverse: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("(Tail)\n");
}

void reverseList(Node** head) {
    if (!*head) return;
    Node *curr = *head, *temp = NULL;
    do {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; // Move to the "next" node
    } while (curr != *head);
    *head = temp->prev;
    printf("List Reversed.\n");
}

void sortList(Node** head) {
    if (!*head) return;
    Node *i, *j;
    int tempVal;
    for (i = *head; i->next != *head; i = i->next) {
        for (j = i->next; j != *head; j = j->next) {
            if (i->data > j->data) {
                tempVal = i->data;
                i->data = j->data;
                j->data = tempVal;
            }
        }
    }
}

void freeAllNodes(Node** head) {
    if (!*head) return;
    Node *curr = *head, *next;
    do {
        next = curr->next;
        free(curr);
        curr = next;
    } while (curr != *head);
    *head = NULL;
    printf("Doubly Circular memory freed.\n");
}
