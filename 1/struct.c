#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enums and Unions for ID Proof
typedef enum { ADHAR = 1, PASSPORT, PAN_CARD } IDType;

typedef union {
    char adhar[13];
    char passport[10];
    char pan[11];
} IDProof;

// Date Structure
typedef struct {
    int day, month, year;
} Date;

// Employee Structure (Doubly Circular Linked List Node)
typedef struct Employee {
    int id;
    char name[50];
    int age;
    char address[100];
    Date doj;
    IDType proofType;
    IDProof proof;
    struct Employee *next;
    struct Employee *prev;
} Employee;

// Function Prototypes
Employee* createNode();
void insertSorted(Employee **head, Employee *newEmp);
void displayList(Employee *head);
void deleteById(Employee **head, int id);
void findEmployee(Employee *head);
void saveToFile(Employee *head);
void loadFromFile(Employee **head);
void displayByYear(Employee *head, int year);
void sortByAge(Employee **head);
void cleanup(Employee **head);
int validateDate(int d, int m, int y);

int main() {
    Employee *head = NULL;
    int choice, tempInt;

    while (1) {
        printf("\n--- Employee Database (Doubly Circular) ---\n");
        printf("1. Add Employee (Sorted ID)\n2. Display All\n3. Delete by ID\n");
        printf("4. Find (Name/ID)\n5. Sort by Age\n6. Save to File\n");
        printf("7. Load from File\n8. Filter by Joining Year\n9. Exit\n");
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                insertSorted(&head, createNode());
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &tempInt);
                deleteById(&head, tempInt);
                break;
            case 4:
                findEmployee(head);
                break;
            case 5:
                sortByAge(&head);
                break;
            case 6:
                saveToFile(head);
                break;
            case 7:
                loadFromFile(&head);
                break;
            case 8:
                printf("Enter year: ");
                scanf("%d", &tempInt);
                displayByYear(head, tempInt);
                break;
            case 9:
                cleanup(&head);
                printf("System cleaned. Exiting...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}

// --- Memory & Validation ---

Employee* createNode() {
    Employee *newEmp = (Employee*)malloc(sizeof(Employee));
    if (!newEmp) {
        printf("Heap Exhausted!\n");
        exit(1);
    }

    // ID Validation
    do {
        printf("Enter Unique ID (Positive): ");
        scanf("%d", &newEmp->id);
    } while (newEmp->id <= 0);

    printf("Enter Name: ");
    scanf(" %[^\n]s", newEmp->name);

    // Age Validation
    do {
        printf("Enter Age (18-65): ");
        scanf("%d", &newEmp->age);
    } while (newEmp->age < 18 || newEmp->age > 65);

    printf("Enter Address: ");
    scanf(" %[^\n]s", newEmp->address);

    // Date Validation
    do {
        printf("Enter Date of Joining (DD MM YYYY): ");
        scanf("%d %d %d", &newEmp->doj.day, &newEmp->doj.month, &newEmp->doj.year);
    } while (!validateDate(newEmp->doj.day, newEmp->doj.month, newEmp->doj.year));

    printf("ID Proof: 1.Adhar 2.Passport 3.PAN: ");
    int pt;
    scanf("%d", &pt);
    newEmp->proofType = (IDType)pt;
    printf("Enter Proof Number: ");
    scanf("%s", newEmp->proof.adhar); // Union sharing same space

    newEmp->next = newEmp->prev = NULL;
    return newEmp;
}

int validateDate(int d, int m, int y) {
    if (y < 1900 || y > 2100) return 0;
    if (m < 1 || m > 12) return 0;
    if (d < 1 || d > 31) return 0;
    return 1;
}

// --- List Operations ---

void insertSorted(Employee **head, Employee *newEmp) {
    if (*head == NULL) {
        *head = newEmp;
        newEmp->next = newEmp->prev = newEmp;
        return;
    }

    Employee *curr = *head;
    
    // Check if ID already exists (Unique check)
    Employee *check = *head;
    do {
        if (check->id == newEmp->id) {
            printf("Error: ID %d already exists!\n", newEmp->id);
            free(newEmp);
            return;
        }
        check = check->next;
    } while (check != *head);

    // Sorted Insertion logic
    if (newEmp->id < curr->id) {
        // Insert before head
        Employee *last = (*head)->prev;
        newEmp->next = *head;
        newEmp->prev = last;
        last->next = (*head)->prev = newEmp;
        *head = newEmp;
    } else {
        while (curr->next != *head && curr->next->id < newEmp->id) {
            curr = curr->next;
        }
        newEmp->next = curr->next;
        newEmp->prev = curr;
        curr->next->prev = newEmp;
        curr->next = newEmp;
    }
    printf("Employee %d Added.\n", newEmp->id);
}

void deleteById(Employee **head, int id) {
    if (*head == NULL) return;

    Employee *curr = *head;
    do {
        if (curr->id == id) {
            if (curr->next == curr) { // Only one node
                free(curr);
                *head = NULL;
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                if (curr == *head) *head = curr->next;
                free(curr);
            }
            printf("Employee Deleted.\n");
            return;
        }
        curr = curr->next;
    } while (curr != *head);
    printf("ID not found.\n");
}

// --- Sorting by Age (Bubble Sort on Linked List) ---

void sortByAge(Employee **head) {
    if (*head == NULL) return;
    int swapped;
    Employee *ptr1;
    Employee *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != *head && ptr1->next != lptr) {
            if (ptr1->age > ptr1->next->age) {
                // Swap data (Simpler for this scope)
                int tAge = ptr1->age; ptr1->age = ptr1->next->age; ptr1->next->age = tAge;
                int tId = ptr1->id; ptr1->id = ptr1->next->id; ptr1->next->id = tId;
                char tName[50]; strcpy(tName, ptr1->name); strcpy(ptr1->name, ptr1->next->name); strcpy(ptr1->next->name, tName);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("List sorted by Age.\n");
}

// --- File Handling ---

void saveToFile(Employee *head) {
    FILE *fp = fopen("employees.txt", "w");
    if (!fp) return;

    if (head == NULL) { fclose(fp); return; }

    Employee *curr = head;
    do {
        fprintf(fp, "%d|%s|%d|%s|%d %d %d|%d|%s\n", 
                curr->id, curr->name, curr->age, curr->address, 
                curr->doj.day, curr->doj.month, curr->doj.year,
                curr->proofType, curr->proof.adhar);
        curr = curr->next;
    } while (curr != head);

    fclose(fp);
    printf("Data Saved to employees.txt\n");
}

void loadFromFile(Employee **head) {
    FILE *fp = fopen("employees.txt", "r");
    if (!fp) return;

    cleanup(head); // Clear current list before loading

    Employee temp;
    char line[300];
    while (fgets(line, sizeof(line), fp)) {
        Employee *newNode = (Employee*)malloc(sizeof(Employee));
        sscanf(line, "%d|%[^|]|%d|%[^|]|%d %d %d|%d|%s", 
               &newNode->id, newNode->name, &newNode->age, newNode->address,
               &newNode->doj.day, &newNode->doj.month, &newNode->doj.year,
               (int*)&newNode->proofType, newNode->proof.adhar);
        
        newNode->next = newNode->prev = NULL;
        insertSorted(head, newNode);
    }
    fclose(fp);
    printf("Data Loaded Successfully.\n");
}

// --- Utilities ---

void displayList(Employee *head) {
    if (head == NULL) { printf("List Empty.\n"); return; }
    Employee *curr = head;
    printf("\nID\tNAME\t\tAGE\tJOIN_DATE\n");
    do {
        printf("%d\t%-15s\t%d\t%02d/%02d/%d\n", curr->id, curr->name, curr->age, curr->doj.day, curr->doj.month, curr->doj.year);
        curr = curr->next;
    } while (curr != head);
}

void displayByYear(Employee *head, int year) {
    if (head == NULL) return;
    Employee *curr = head;
    printf("Employees joining AFTER %d:\n", year);
    do {
        if (curr->doj.year > year)
            printf("ID: %d | Name: %s | Year: %d\n", curr->id, curr->name, curr->doj.year);
        curr = curr->next;
    } while (curr != head);
}

void findEmployee(Employee *head) {
    if (!head) return;
    char searchName[50];
    int sId, mode;
    printf("Search by: 1.ID  2.Name: ");
    scanf("%d", &mode);

    Employee *curr = head;
    if (mode == 1) {
        printf("ID: "); scanf("%d", &sId);
        do {
            if (curr->id == sId) { printf("Found: %s\n", curr->name); return; }
            curr = curr->next;
        } while (curr != head);
    } else {
        printf("Name: "); scanf("%s", searchName);
        do {
            if (strcmp(curr->name, searchName) == 0) { printf("Found ID: %d\n", curr->id); return; }
            curr = curr->next;
        } while (curr != head);
    }
    printf("Not found.\n");
}

void cleanup(Employee **head) {
    if (*head == NULL) return;
    Employee *curr = *head;
    Employee *next;
    do {
        next = curr->next;
        free(curr);
        curr = next;
    } while (curr != *head);
    *head = NULL;
}
