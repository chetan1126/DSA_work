#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Pointers to track the queue
Node* front = NULL;
Node* rear = NULL;

// Function Prototypes
void enqueue(int ele);
void dequeue();
void peep(); // Added Peep function
void display();
int isEmpty();
void checkFull();

int main() {
    int choice, ele;

    while (1) {
        printf("\n--- Circular Linked Queue Menu ---\n");
        printf("1. Enqueue  2. Dequeue  3. Peep (View Front)\n");
        printf("4. Display  5. Is Full?  6. Is Empty?  7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                checkFull();
                break;
            case 6:
                if (isEmpty()) printf("Queue is Empty\n");
                else printf("Queue is not empty\n");
                break;
            case 7:
                while (!isEmpty()) dequeue();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

int isEmpty() {
    return (front == NULL);
}

// Peep function to view the front element
void peep() {
    if (isEmpty()) {
        printf("Queue is empty! Nothing to peep.\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

void enqueue(int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Error!\n");
        return;
    }
    newNode->data = ele;

    if (isEmpty()) {
        front = rear = newNode;
        newNode->next = front; 
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; 
    }
    printf("Inserted %d\n", ele);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }

    Node* temp = front;
    printf("Deleted: %d\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; 
    }
    free(temp);
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    Node* temp = front;
    printf("Circular Queue Loop: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("(Back to Front: %d)\n", front->data);
}

void checkFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Queue is Full (System Out of Memory)\n");
    } else {
        printf("Space is available\n");
        free(temp);
    }
}
