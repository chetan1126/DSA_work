#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define EMPTY_VAL -99

// Function Prototypes
void enqueue(int queue[], int *front, int *rear, int ele);
void dequeue(int queue[], int *front, int *rear);
void peep(int queue[], int front);
void display(int queue[], int front, int rear);
int isFull(int front, int rear);
int isEmpty(int front);

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, ele;

    // Initialize array with default values
    for (int i = 0; i < SIZE; i++) queue[i] = EMPTY_VAL;

    while (1) {
        printf("\n--- Circular Queue (Array) Menu ---\n");
        printf("1. Enqueue  2. Dequeue  3. Peep\n");
        printf("4. Display  5. Is Full?  6. Is Empty?  7. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                enqueue(queue, &front, &rear, ele);
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
                if (isFull(front, rear)) printf("Queue is Full\n");
                else printf("Space available\n");
                break;
            case 6:
                if (isEmpty(front)) printf("Queue is Empty\n");
                else printf("Queue is not empty\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

int isFull(int front, int rear) {
    if ((rear + 1) % SIZE == front) return 1;
    return 0;
}

int isEmpty(int front) {
    if (front == -1) return 1;
    return 0;
}

void enqueue(int queue[], int *front, int *rear, int ele) {
    if (isFull(*front, *rear)) {
        printf("Overflow! Cannot insert %d\n", ele);
        return;
    }
    if (*front == -1) *front = 0; // First insertion

    *rear = (*rear + 1) % SIZE;   // Wrap around logic
    queue[*rear] = ele;
    printf("Inserted %d at index %d\n", ele, *rear);
}

void dequeue(int queue[], int *front, int *rear) {
    if (isEmpty(*front)) {
        printf("Underflow! Nothing to delete.\n");
        return;
    }
    printf("Deleted: %d from index %d\n", queue[*front], *front);
    queue[*front] = EMPTY_VAL; // Optional: visual clear

    if (*front == *rear) {
        // Queue becomes empty
        *front = *rear = -1;
    } else {
        *front = (*front + 1) % SIZE; // Wrap around logic
    }
}

void peep(int queue[], int front) {
    if (isEmpty(front)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d (at index %d)\n", queue[front], front);
    }
}

void display(int queue[], int front, int rear) {
    printf("Physical Array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] ", queue[i]);
    }
    printf("\nFront Index: %d, Rear Index: %d\n", front, rear);
}
