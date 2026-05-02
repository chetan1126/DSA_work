/*write a c program to display the shopping list in a link list manner with insert at beg/end and delete from beg/end, and search the shopping items from name or price of the item and show the total sum of the shopping list. Use sorting to sort the items in ascending order from low price to high price, the contents in the shopping list are:

Struct ShoppinList{
Tomato 40
Chips 80
Can 100
Drinks 180
}List
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ShoppingList {
    char name[20];
    int price;
    struct ShoppingList *next;
};

typedef struct ShoppingList node;

void display(node *head) {
    node *t1;
    t1 = head;
    
    if (head == NULL) {
        printf("\nShopping List is empty!\n");
        return;
    }
    
    printf("\n===== SHOPPING LIST =====\n");
    printf("%-15s %s\n", "Item Name", "Price");
    printf("-------------------------\n");
    while (t1 != NULL) {
        printf("%-15s Rs.%d\n", t1->name, t1->price);
        t1 = t1->next;
    }
    printf("=========================\n");
}

int totalSum(node *head) {
    node *t1;
    t1 = head;
    int sum = 0;
    
    while (t1 != NULL) {
        sum += t1->price;
        t1 = t1->next;
    }
    return sum;
}

void insertAtBegin(node **head) {
    node *temp;
    temp = (node *)malloc(sizeof(node));
    
    printf("Enter item name: ");
    scanf("%s", temp->name);
    printf("Enter price: ");
    scanf("%d", &temp->price);
    
    temp->next = *head;
    *head = temp;
    printf("\nItem inserted at beginning!\n");
}

void insertAtEnd(node **head) {
    node *temp, *t1;
    temp = (node *)malloc(sizeof(node));
    
    printf("Enter item name: ");
    scanf("%s", temp->name);
    printf("Enter price: ");
    scanf("%d", &temp->price);
    
    temp->next = NULL;
    
    if (*head == NULL) {
        *head = temp;
    } else {
        t1 = *head;
        while (t1->next != NULL) {
            t1 = t1->next;
        }
        t1->next = temp;
    }
    printf("\nItem inserted at end!\n");
}

void deleteFromBegin(node **head) {
    node *temp;
    
    if (*head == NULL) {
        printf("\nShopping List is empty! Cannot delete.\n");
        return;
    }
    
    temp = *head;
    printf("\nDeleted item: %s (Rs.%d)\n", temp->name, temp->price);
    *head = temp->next;
    free(temp);
    printf("Item deleted from beginning!\n");
}

void deleteFromEnd(node **head) {
    node *temp, *t1;
    
    if (*head == NULL) {
        printf("\nShopping List is empty! Cannot delete.\n");
        return;
    }
    
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    
    // If only one node
    if ((*head)->next == NULL) {
        printf("\nDeleted item: %s (Rs.%d)\n", (*head)->name, (*head)->price);
        free(*head);
        *head = NULL;
        printf("Item deleted from end!\n");
        return;
    }
    
    t1 = *head;
    while (t1->next->next != NULL) {
        t1 = t1->next;
    }
    
    temp = t1->next;
    printf("\nDeleted item: %s (Rs.%d)\n", temp->name, temp->price);
    t1->next = NULL;
    free(temp);
    printf("Item deleted from end!\n");
}

void searchByName(node *head) {
    node *t1;
    char searchName[20];
    int found = 0;
    
    t1 = head;
    
    printf("Enter item name to search: ");
    scanf("%s", searchName);
    
    printf("\n===== Search Results =====\n");
    while (t1 != NULL) {
        if (strcmp(t1->name, searchName) == 0) {
            printf("Item Found: %s - Rs.%d\n", t1->name, t1->price);
            found = 1;
        }
        t1 = t1->next;
    }
    
    if (!found) {
        printf("Item '%s' not found in the list!\n", searchName);
    }
    printf("==========================\n");
}

void searchByPrice(node *head) {
    node *t1;
    int searchPrice;
    int found = 0;
    
    t1 = head;
    
    printf("Enter price to search: ");
    scanf("%d", &searchPrice);
    
    printf("\n===== Search Results =====\n");
    while (t1 != NULL) {
        if (t1->price == searchPrice) {
            printf("Item Found: %s - Rs.%d\n", t1->name, t1->price);
            found = 1;
        }
        t1 = t1->next;
    }
    
    if (!found) {
        printf("Item with price Rs.%d not found in the list!\n", searchPrice);
    }
    printf("==========================\n");
}

void sortByPrice(node **head) {
    node *t1, *t2;
    char tempName[20];
    int tempPrice;
    
    if (*head == NULL || (*head)->next == NULL) {
        printf("\nList is empty or has only one element. No sorting needed.\n");
        return;
    }
    
    // Bubble sort based on price (ascending order - low to high)
    for (t1 = *head; t1 != NULL; t1 = t1->next) {
        for (t2 = t1->next; t2 != NULL; t2 = t2->next) {
            if (t1->price > t2->price) {
                // Swap name
                strcpy(tempName, t1->name);
                strcpy(t1->name, t2->name);
                strcpy(t2->name, tempName);
                
                // Swap price
                tempPrice = t1->price;
                t1->price = t2->price;
                t2->price = tempPrice;
            }
        }
    }
    
    printf("\nList sorted by price (Low to High)!\n");
    display(*head);
}

void initializeList(node **head) {
    // Create initial shopping list
    node *temp;
    
    // Tomato - 40
    temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, "Tomato");
    temp->price = 40;
    temp->next = NULL;
    *head = temp;
    
    // Chips - 80
    temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, "Chips");
    temp->price = 80;
    temp->next = *head;
    *head = temp;
    
    // Can - 100
    temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, "Can");
    temp->price = 100;
    temp->next = *head;
    *head = temp;
    
    // Drinks - 180
    temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, "Drinks");
    temp->price = 180;
    temp->next = *head;
    *head = temp;
    
    printf("\nInitial shopping list created with:\n");
    printf("Tomato - Rs.40\n");
    printf("Chips - Rs.80\n");
    printf("Can - Rs.100\n");
    printf("Drinks - Rs.180\n");
}

int main() {
    node *head;
    head = NULL;  // head is local
    
    int choice;
    int searchChoice;
    
    // Initialize with given data
    initializeList(&head);
    
    while (1) {
        printf("\n========== SHOPPING LIST MENU ==========\n");
        printf("1. Display Shopping List\n");
        printf("2. Insert Item at Beginning\n");
        printf("3. Insert Item at End\n");
        printf("4. Delete Item from Beginning\n");
        printf("5. Delete Item from End\n");
        printf("6. Search Item\n");
        printf("7. Show Total Sum\n");
        printf("8. Sort by Price (Low to High)\n");
        printf("9. Exit\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display(head);
                break;
                
            case 2:
                insertAtBegin(&head);
                break;
                
            case 3:
                insertAtEnd(&head);
                break;
                
            case 4:
                deleteFromBegin(&head);
                break;
                
            case 5:
                deleteFromEnd(&head);
                break;
                
            case 6:
                printf("\n--- Search Menu ---\n");
                printf("1. Search by Name\n");
                printf("2. Search by Price\n");
                printf("Enter choice: ");
                scanf("%d", &searchChoice);
                
                if (searchChoice == 1) {
                    searchByName(head);
                } else if (searchChoice == 2) {
                    searchByPrice(head);
                } else {
                    printf("\nInvalid choice!\n");
                }
                break;
                
            case 7:
                printf("\nTotal Sum of Shopping List: Rs.%d\n", totalSum(head));
                break;
                
            case 8:
                sortByPrice(&head);
                break;
                
            case 9:
                printf("\nThank you for using Shopping List Program!\n");
                exit(0);
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
