#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define EMPTY_VAL -99

// Function Prototypes
void push(int stack[], int *top, int ele);
void pop(int stack[], int *top);
void peep(int stack[], int top); // New Peep Function
void display(int stack[], int top);
int isFull(int top);
int isEmpty(int top);
void clearInputBuffer(); // Fail-safe for invalid inputs

int main() {
    int stack[SIZE];
    int top = -1;
    int choice, ele;

    // Initialize stack
    for (int i = 0; i < SIZE; i++) {
        stack[i] = EMPTY_VAL;
    }

    while (1) {
        printf("\n---  Stack Menu ---\n");
        printf("1. Push  2. Pop  3. Peep  4. Display  5. Full?  6. Empty?  7. Exit\n");
        printf("Enter your choice: ");
        
        // Fail-safe: Check if input is a valid integer
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                if (scanf("%d", &ele) != 1) {
                    printf("Invalid element! Push cancelled.\n");
                    clearInputBuffer();
                } else {
                    push(stack, &top, ele);
                }
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peep(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                if (isFull(top)) printf("Result: Stack is Full (Overflow condition)\n");
                else printf("Result: Stack has %d space(s) left\n", (SIZE - 1 - top));
                break;
            case 6:
                if (isEmpty(top)) printf("Result: Stack is Empty (Underflow condition)\n");
                else printf("Result: Stack contains %d element(s)\n", (top + 1));
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Choose 1-7.\n");
        }
    }
    return 0;
}

// --- Logic Functions ---

int isFull(int top) {
    return (top == SIZE - 1);
}

int isEmpty(int top) {
    return (top == -1);
}

void push(int stack[], int *top, int ele) {
    if (isFull(*top)) {
        printf("Error: Stack Overflow! Cannot push %d\n", ele);
        return;
    }
    stack[++(*top)] = ele;
    printf("Successfully pushed %d onto the stack.\n", ele);
}

void pop(int stack[], int *top) {
    if (isEmpty(*top)) {
        printf("Error: Stack Underflow! Nothing to remove.\n");
        return;
    }
    int temp = stack[*top];
    stack[(*top)--] = EMPTY_VAL; 
    printf("Popped element: %d\n", temp);
}

// Peep: View the top element without removing it
void peep(int stack[], int top) {
    if (isEmpty(top)) {
        printf("Stack is empty! Nothing to peep.\n");
        return;
    }
    printf("Top element (Peep): %d\n", stack[top]);
}

void display(int stack[], int top) {
    printf("\nStack Layout (Size %d):\n", SIZE);
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("[%d]", stack[i]);
        if (i == top) printf(" <- TOP");
        if (stack[i] == EMPTY_VAL) printf(" (empty)");
        printf("\n");
    }
}

// Fail-safe: Clears the stdin buffer to prevent infinite loops on char input
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
