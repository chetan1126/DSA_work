#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Pointers to track the front and rear of the queue
Node* front = NULL;
Node* rear = NULL;

// Function Prototypes
void enqueue(int ele);
void dequeue();
void peep();
void display();
int isEmpty();
void checkFull();

int main() {
    int choice, ele;

    while (1) {
        printf("\n--- Linear Linked Queue Menu ---\n");
        printf("1. Enqueue (Insert)  2. Dequeue (Delete)  3. Peep (View Front)\n");
        printf("4. Display           5. Is Full?          6. Is Empty?  7. Exit\n");
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
                if (isEmpty()) printf("Result: Queue is Empty\n");
                else printf("Result: Queue is not empty\n");
                break;
            case 7:
                // Cleanup memory before exiting
                while (front != NULL) dequeue();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    return (front == NULL);
}

// Peep: Look at the front element without removing it
void peep() {
    if (isEmpty()) {
        printf("Queue is empty! Nothing to peep.\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

// Enqueue: Add element to the end (rear)
void enqueue(int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = ele;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Successfully inserted %d\n", ele);
}

// Dequeue: Remove element from the start (front)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    Node* temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    // If front becomes NULL, the queue is now empty, so reset rear
    if (front == NULL) {
        rear = NULL;
    }

    free(temp); // Free memory to prevent leaks
}

// Display: Traverse from front to NULL
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    Node* temp = front;
    printf("Queue Status: ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Full Check: Only full if malloc fails
void checkFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Queue is Full (Memory Exhausted)\n");
    } else {
        printf("Queue has space (Dynamic Allocation)\n");
        free(temp);
    }
}
