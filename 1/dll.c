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
        printf("\n--- Doubly Linked List Menu ---\n");
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
            case 12: reverseList(&head); printf("List pointers swapped/reversed.\n"); break;
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
    if (!newNode) { printf("Memory Fail!\n"); exit(1); }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
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
    newNode->prev = temp;
}

void insertAtPos(Node** head, int data, int pos) {
    int count = listNodeCount(*head);
    if (pos < 1 || pos > count + 1) { printf("Invalid Pos!\n"); return; }
    if (pos == 1) { insertAtBeg(head, data); return; }
    
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void insertSorted(Node** head, int data) {
    if (*head == NULL || data <= (*head)->data) {
        insertAtBeg(head, data);
        return;
    }
    Node* curr = *head;
    while (curr->next && curr->next->data < data) curr = curr->next;
    
    Node* newNode = createNode(data);
    newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next) curr->next->prev = newNode;
    curr->next = newNode;
}

void deleteFromBeg(Node** head) {
    if (!*head) return;
    Node* temp = *head;
    *head = (*head)->next;
    if (*head) (*head)->prev = NULL;
    free(temp);
}

void deleteFromEnd(Node** head) {
    if (!*head) return;
    if (!(*head)->next) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deleteFromPos(Node** head, int pos) {
    int count = listNodeCount(*head);
    if (!*head || pos < 1 || pos > count) return;
    if (pos == 1) { deleteFromBeg(head); return; }
    
    Node* temp = *head;
    for (int i = 1; i < pos; i++) temp = temp->next;
    
    temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
}

void deleteByElement(Node** head, int key) {
    Node* temp = *head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) { printf("Not found.\n"); return; }
    
    if (temp == *head) deleteFromBeg(head);
    else {
        temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        free(temp);
    }
}

int listNodeCount(Node* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

void displayList(Node* head) {
    if (!head) printf("Empty List!");
    while (head) {
        printf("%d %s ", head->data, head->next ? "<->" : "->");
        head = head->next;
    }
    printf("NULL\n");
}

void reverseDisplay(Node* head) {
    if (!head) return;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    printf("Reverse: ");
    while (temp) {
        printf("%d %s ", temp->data, temp->prev ? "<->" : "->");
        temp = temp->prev;
    }
    printf("NULL\n");
}

void reverseList(Node** head) {
    Node *temp = NULL, *curr = *head;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; // Moved to next node (which is now stored in prev)
    }
    if (temp) *head = temp->prev;
}

void sortList(Node** head) {
    if (!*head) return;
    Node *i, *j;
    int temp;
    for (i = *head; i->next != NULL; i = i->next) {
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
    printf("Doubly memory freed.\n");
}
