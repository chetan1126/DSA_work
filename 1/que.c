#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define EMPTY_VAL -99

// Function Prototypes
void enqueue(int queue[], int *rear, int ele);
void dequeue(int queue[], int *front, int *rear);
void peep(int queue[], int front);
void display(int queue[], int front, int rear);
int isFull(int rear);
int isEmpty(int front, int rear);

int main() {
    int queue[SIZE];
    int front = -1;
    int rear = -1;
    int choice, ele;

    // Initialize array with default values
    for (int i = 0; i < SIZE; i++) {
        queue[i] = EMPTY_VAL;
    }

    while (1) {
        printf("\n--- Linear Queue (Array) Menu ---\n");
        printf("1. Enqueue  2. Dequeue  3. Peep\n");
        printf("4. Display  5. Is Full?  6. Is Empty?  7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                enqueue(queue, &rear, ele);
                // Set front to 0 on the very first insertion
                if (front == -1 && rear == 0) front = 0;
                break;
            case 2:
                dequeue(queue, &front, &rear);
                break;
            case 3:
                peep(queue, front);
                break;
            case 4:
                display(queue, front, rear);
                break;
            case 5:
                if (isFull(rear)) printf("Queue is Full\n");
                else printf("Space available\n");
                break;
            case 6:
                if (isEmpty(front, rear)) printf("Queue is Empty\n");
                else printf("Queue is not empty\n");
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Full Check: Simply checks if rear reached the last index
int isFull(int rear) {
    if (rear == SIZE - 1) return 1;
    return 0;
}

// Empty Check: Either front is -1 or front has passed rear
int isEmpty(int front, int rear) {
    if (front == -1 || front > rear) return 1;
    return 0;
}

void enqueue(int queue[], int *rear, int ele) {
    if (isFull(*rear)) {
        printf("Overflow! Rear reached the end of the array.\n");
        return;
    }
    (*rear)++;
    queue[*rear] = ele;
    printf("Inserted %d at index %d\n", ele, *rear);
}

void dequeue(int queue[], int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Underflow! Queue is empty.\n");
        return;
    }
    printf("Deleted: %d from index %d\n", queue[*front], *front);
    queue[*front] = EMPTY_VAL; // Visual clear
    
    (*front)++;

    // Optimization: If queue becomes empty, reset pointers to reuse array
    if (*front > *rear) {
        *front = *rear = -1;
    }
}

void peep(int queue[], int front) {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is: %d (at index %d)\n", queue[front], front);
    }
}

void display(int queue[], int front, int rear) {
    printf("Current Array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] ", queue[i]);
    }
    printf("\nFront: %d, Rear: %d\n", front, rear);
}
