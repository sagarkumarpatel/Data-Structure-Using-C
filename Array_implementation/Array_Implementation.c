//1. create aray
//2. getValue
//3. display/view
//4. insert at the beginning
//5. inset at last
//6. insert at specific position 
//7. delete at first
//8. delete at last
//9. delete at specific position 
//10. update at specific index

// #include<stdio.h>
// #include<stdlib.h>
// int lastindex=0;
// int * createArray(int size){
//     return (int*)malloc(sizeof(int)*size);
// }

// void getValue(int *arr,int size){
//     for(int i=0;i<size;i++){
//         scanf("%d",arr+i);
//     }
//     lastindex=size;
// }

// void display(int *arr,int size){
//     for(int i=0;i<size;i++){
//         printf("%d ",*(arr+i));
//     }
// }

// void insertAtFirst(int *arr,int size){

//     if (lastindex >= size) {
//         printf("Array is full, cannot insert more elements.\n");
//         return;
//     }

//     for(int i=lastindex;i>0;i--){
//         arr[i]=arr[i-1];
//     }
//     printf("The valiue to be inserted\n");
//     scanf("%d",arr+0);
//     lastindex++;
// }

// int main(){

//     int *arr;  //store stating address
//     int size;
//     printf("enter the size: \n");
//     scanf("%d",&size);

//    arr=createArray(size);
//    insertAtFirst(arr,size);
//    getValue(arr,size);
//    printf("the array is: ");
//    display(arr,size);

//     return 0;
// }
#include <stdio.h>

#define MAX_SIZE 100

void createArray(int arr[], int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
    printf("Enter %d elements: ", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtFirst(int arr[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    for (int i = *size; i >= 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*size)++;
}

void insertAtLast(int arr[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    arr[*size] = value;
    (*size)++;
}

void insertAtPosition(int arr[], int *size, int pos, int value) {
    if (*size >= MAX_SIZE || pos < 1 || pos > *size + 1) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    (*size)++;
}

void deleteAtFirst(int arr[], int *size) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteAtLast(int arr[], int *size) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    (*size)--;
}

void deleteAtPosition(int arr[], int *size, int pos) {
    if (*size <= 0 || pos < 1 || pos > *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteAtIndex(int arr[], int *size, int index) {
    if (*size <= 0 || index < 0 || index >= *size) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[MAX_SIZE], size = 0, choice, value, pos;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Array\n2. Display Array\n3. Insert at First\n4. Insert at Last\n");
        printf("5. Insert at Position\n6. Delete at First\n7. Delete at Last\n");
        printf("8. Delete at Position\n9. Delete at Index\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtFirst(arr, &size, value);
                break;
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtLast(arr, &size, value);
                break;
            case 5:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &value);
                insertAtPosition(arr, &size, pos, value);
                break;
            case 6:
                deleteAtFirst(arr, &size);
                break;
            case 7:
                deleteAtLast(arr, &size);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(arr, &size, pos);
                break;
            case 9:
                printf("Enter index to delete: ");
                scanf("%d", &pos);
                deleteAtIndex(arr, &size, pos);
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}