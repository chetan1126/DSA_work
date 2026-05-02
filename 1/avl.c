#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

// --- Utility Functions ---

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1; // New node is added at leaf level
    return node;
}

int getBalanceFactor(struct Node *n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// --- Rotations ---

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// --- Insertion ---

struct Node* insert(struct Node* node, int data) {
    // 1. Standard BST Insertion
    if (node == NULL) return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Duplicate data not allowed

    // 2. Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get balance factor to check for imbalance
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// --- Cleanup & Traversal ---

void clearTree(struct Node* root) {
    if (root == NULL) return;
    clearTree(root->left);
    clearTree(root->right);
    free(root);
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d (h:%d) ", root->data, root->height);
        inorder(root->right);
    }
}

// --- Main Menu ---

int main() {
    struct Node *root = NULL;
    int choice, val;

    while (1) {
        printf("\n--- AVL Tree Menu ---\n");
        printf("1. Insert  2. Display Inorder  3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                if (!root) printf("Tree is empty!");
                else inorder(root);
                printf("\n");
                break;
            case 3:
                clearTree(root);
                printf("Memory freed. Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
