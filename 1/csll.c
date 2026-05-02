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
void reverseDisplay(Node* head, Node* current);
void reverseList(Node** head);
void sortList(Node** head);
void freeAllNodes(Node** head);

int main() {
    Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert Beg  2. Insert End  3. Insert Pos  4. Insert Sorted\n");
        printf("5. Delete Beg  6. Delete End  7. Delete Pos  8. Delete Element\n");
        printf("9. Display     10. Node Count 11. Rev Display 12. Reverse List\n");
        printf("13. Sort List  14. Free & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Data: "); 
            scanf("%d", &data); insertAtBeg(&head, data); break;
            case 2: printf("Data: "); scanf("%d", &data); insertAtEnd(&head, data); break;
            case 3: printf("Data: "); scanf("%d", &data); printf("Pos: "); scanf("%d", &pos); insertAtPos(&head, data, pos); break;
            case 4: printf("Data: "); scanf("%d", &data); insertSorted(&head, data); break;
            case 5: deleteFromBeg(&head); break;
            case 6: deleteFromEnd(&head); break;
            case 7: printf("Pos: "); scanf("%d", &pos); deleteFromPos(&head, pos); break;
            case 8: printf("Element: "); scanf("%d", &data); deleteByElement(&head, data); break;
            case 9: displayList(head); break;
            case 10: printf("Total Nodes: %d\n", listNodeCount(head)); break;
            case 11: 
                if(!head) printf("Empty List!\n");
                else { printf("Reverse: "); reverseDisplay(head, head); printf("(Back to Head)\n"); }
                break;
            case 12: reverseList(&head); break;
            case 13: sortList(&head); break;
            case 14: freeAllNodes(&head); exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}

// --- HELPER ---
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { printf("Memory Fail!\n"); exit(1); }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// --- INSERTION ---
void insertAtBeg(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Points to itself
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtPos(Node** head, int data, int pos) {
    int count = listNodeCount(*head);
    if (pos < 1 || pos > count + 1) { printf("Invalid Pos!\n"); return; }
    if (pos == 1) { insertAtBeg(head, data); return; }
    
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertSorted(Node** head, int data) {
    if (*head == NULL || data < (*head)->data) {
        insertAtBeg(head, data);
        return;
    }
    Node* curr = *head;
    while (curr->next != *head && curr->next->data < data) curr = curr->next;
    Node* newNode = createNode(data);
    newNode->next = curr->next;
    curr->next = newNode;
}

// --- DELETION ---
void deleteFromBeg(Node** head) {
    if (*head == NULL) return;
    Node *temp = *head, *last = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        while (last->next != *head) last = last->next;
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

void deleteFromEnd(Node** head) {
    if (*head == NULL) return;
    Node *curr = *head, *prev = NULL;
    if (curr->next == *head) {
        free(curr);
        *head = NULL;
        return;
    }
    while (curr->next != *head) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = *head;
    free(curr);
}

void deleteFromPos(Node** head, int pos) {
    int count = listNodeCount(*head);
    if (!*head || pos < 1 || pos > count) return;
    if (pos == 1) { deleteFromBeg(head); return; }
    
    Node* temp = *head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void deleteByElement(Node** head, int key) {
    if (!*head) return;
    if ((*head)->data == key) { deleteFromBeg(head); return; }
    
    Node *curr = *head, *prev = NULL;
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr != *head);
    printf("Element not found.\n");
}

// --- UTILITIES ---
int listNodeCount(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void displayList(Node* head) {
    if (!head) { printf("List Empty\n"); return; }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");
}

void reverseDisplay(Node* head, Node* current) {
    if (current->next != head) reverseDisplay(head, current->next);
    printf("%d -> ", current->data);
}

void reverseList(Node** head) {
    if (!*head || (*head)->next == *head) return;
    Node *prev = NULL, *curr = *head, *next = NULL, *last = *head;
    while (last->next != *head) last = last->next;
    
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != *head);
    
    (*head)->next = prev; // Old head points to new last
    *head = prev;         // New head
    last = *head;         // Find new last to close circle
}

void sortList(Node** head) {
    if (!*head) return;
    Node *i, *j;
    int temp;
    for (i = *head; i->next != *head; i = i->next) {
        for (j = i->next; j != *head; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void freeAllNodes(Node** head) {
    if (!*head) return;
    Node *curr = *head, *next;
    Node *start = *head;
    do {
        next = curr->next;
        free(curr);
        curr = next;
    } while (curr != start);
    *head = NULL;
    printf("Circular memory cleared.\n");
}
