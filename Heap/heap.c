#include <stdio.h>
#include <stdlib.h>

// Heapify function for max-heap
void heapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && heap[left] > heap[largest])
        largest = left;

    if (right <= n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(heap, n, largest);
    }
}


// Insert a value into the heap
int insert(int heap[], int n, int value) {
    // Increase the heap size and insert the new value at the last position
    heap[n + 1] = value;
    int i = n + 1;

    // move the value upwards to restore the heap property
    while (i > 1 && heap[i / 2] < heap[i]) {
        // Swap parent and current node
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;

        // Move up the index to the parent's position
        i = i / 2;
    }

    // Return the new size of the heap
    return n + 1;
}


// Delete the root of the heap
int deleteRoot(int heap[], int n) {
    if (n == 0) {
        printf("Heap is empty!\n");
        return n;
    }

    // Replace root with the last element
    heap[1] = heap[n];

    // Decrease the size of the heap
    n--;

    // Heapify from the root to restore the heap property
    heapify(heap, n, 1);

    return n;
}


// Print the heap
void printHeap(int heap[], int n) {
    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Heap array: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main function with do-while loop
int main() {
    int heap[100];  // Array to store heap
    int n = 0;      // Number of elements in the heap
    int choice, value;

    do {
        printf("\nHeap Operations Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete root element\n");
        printf("3. Print the heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert an element
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                n = insert(heap, n, value);
                printf("Element inserted.\n");
                break;

            case 2:
                // Delete root element
                n = deleteRoot(heap, n);
                printf("Root element deleted.\n");
                break;

            case 3:
                // Print the heap
                printHeap(heap, n);
                break;

            case 4:
                // Exit the program
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 4); // Loop until user chooses to exit

    return 0;
}