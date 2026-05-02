#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

// Prototypes
void insert(struct node **head, int element);
void display_inorder(struct node *head);
void display_preorder(struct node *head);
void display_postorder(struct node *head);
struct node* search(struct node *head, int key);
struct node* deleteNode(struct node *root, int key);
struct node* minValueNode(struct node* node);
void clearTree(struct node* root); // To prevent memory leaks

int main() {
    int element, choice, key;
    struct node *head = NULL;
    struct node *temp = NULL;

    while (1) {
        printf("\n--- Leak-Proof BST Menu ---\n");
        printf("1. Insert  2. Display All  3. Search  4. Delete  5. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Cleaning up and exiting...\n");
            break; 
        }

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &element);
                insert(&head, element);
                break;
            case 2:
                if (head == NULL) printf("Tree is empty!\n");
                else {
                    printf("\nInorder:   "); display_inorder(head);
                    printf("\nPreorder:  "); display_preorder(head);
                    printf("\nPostorder: "); display_postorder(head);
                    printf("\n");
                }
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                temp = search(head, key);
                if (temp) printf("Found %d\n", temp->data);
                else printf("Not found.\n");
                break;
            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                break;
            case 5:
                printf("Freeing all memory...\n");
                clearTree(head); // PREVENTS MEMORY LEAK
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    clearTree(head); // Final safety cleanup
    return 0;
}

// --- CORE FUNCTIONS ---

void insert(struct node **head, int element) {
    if (*head == NULL) {
        *head = (struct node*)malloc(sizeof(struct node));
        if (*head == NULL) {
            printf("Memory full!\n");
            return;
        }
        (*head)->data = element;
        (*head)->left = (*head)->right = NULL;
    } else {
        if (element > (*head)->data) insert(&(*head)->right, element);
        else if (element < (*head)->data) insert(&(*head)->left, element);
    }
}

// RECURSIVE MEMORY CLEANUP (Post-order)
void clearTree(struct node* root) {
    if (root == NULL) return;
    
    // First, delete subtrees
    clearTree(root->left);
    clearTree(root->right);
    
    // Then, delete the node
    free(root);
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node *root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// --- TRAVERSALS & UTILS ---

struct node* search(struct node *head, int key) {
    if (head == NULL || head->data == key) return head;
    if (key > head->data) return search(head->right, key);
    return search(head->left, key);
}

void display_inorder(struct node *head) {
    if (head != NULL) {
        display_inorder(head->left);
        printf("%d ", head->data);
        display_inorder(head->right);
    }
}

void display_preorder(struct node *head) {
    if (head != NULL) {
        printf("%d ", head->data);
        display_preorder(head->left);
        display_preorder(head->right);
    }
}

void display_postorder(struct node *head) {
    if (head != NULL) {
        display_postorder(head->left);
        display_postorder(head->right);
        printf("%d ", head->data);
    }
}
