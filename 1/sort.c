#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Fixed size for simplicity

// Function Prototypes
void bubble(int a[]);
void insertion(int a[]);
void selection(int a[]);
void quickSort(int a[], int first, int last);
void mergeSort(int a[], int l, int r);
void heapSort(int a[]);

// Helper Functions
void display(int a[]);
void reset(int a[], int org[]);

int main() {
    int org[SIZE] = {12, 5, 1, 9, 3}; // Original data
    int a[SIZE];
    int choice;

    while (1) {
        reset(a, org); // Reset array before every sort
        printf("\n1.Bubble 2.Insertion 3.Selection 4.Quick 5.Merge 6.Heap 7.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 7) exit(0);

        printf("Unsorted: "); display(a);

        switch (choice) {
            case 1: bubble(a); break;
            case 2: insertion(a); break;
            case 3: selection(a); break;
            case 4: quickSort(a, 0, SIZE - 1); break;
            case 5: mergeSort(a, 0, SIZE - 1); break;
            case 6: heapSort(a); break;
            default: printf("Invalid choice!\n"); continue;
        }

        printf("Sorted:   "); display(a);
    }
    return 0;
}

// --- 1. BUBBLE SORT (Heavy elements sink to the end) ---
void bubble(int a[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// --- 2. INSERTION SORT (Picking a card and placing it correctly) ---
void insertion(int a[]) {
    for (int i = 1; i < SIZE; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// --- 3. SELECTION SORT (Find minimum and swap with start) ---
void selection(int a[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        int min = i;
        for (int j = i + 1; j < SIZE; j++)
            if (a[j] < a[min]) min = j;
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

// --- 4. QUICK SORT (Pivot based partitioning) ---
void quickSort(int a[], int first, int last) {
    if (first < last) {
        int pivot = first, i = first, j = last, temp;
        while (i < j) {
            while (a[i] <= a[pivot] && i < last) i++;
            while (a[j] > a[pivot]) j--;
            if (i < j) {
                temp = a[i]; a[i] = a[j]; a[j] = temp;
            }
        }
        temp = a[pivot]; a[pivot] = a[j]; a[j] = temp;
        quickSort(a, first, j - 1);
        quickSort(a, j + 1, last);
    }
}

// --- 5. MERGE SORT (Divide and Conquer) ---
void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0, b[SIZE];
    while (i <= m && j <= r)
        b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l, k = 0; i <= r; i++, k++) a[i] = b[k];
}
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// --- 6. HEAP SORT (Binary Tree based) ---
void heapify(int a[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        int temp = a[i]; a[i] = a[largest]; a[largest] = temp;
        heapify(a, n, largest);
    }
}
void heapSort(int a[]) {
    for (int i = SIZE / 2 - 1; i >= 0; i--) heapify(a, SIZE, i);
    for (int i = SIZE - 1; i > 0; i--) {
        int temp = a[0]; a[0] = a[i]; a[i] = temp;
        heapify(a, i, 0);
    }
}

// --- Helpers ---
void display(int a[]) {
    for (int i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
}
void reset(int a[], int org[]) {
    for (int i = 0; i < SIZE; i++) a[i] = org[i];
}
