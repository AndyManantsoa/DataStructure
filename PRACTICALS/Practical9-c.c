//Insertion Sort

#include<stdio.h>

void insertionSort(int arr[], int size){
    int j, key;

    for(int i = 1; i < size; i++){
        key = arr[i];
        j = i - 1; 

        while(j >= 0 && key < arr[j]){ 
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArr(int arr[], int size){
    printf("Your array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n"); 
}

int main(){

    printf("  INSERTION SORT: \n\n");

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nYour initial array: ");
    printArr(arr, n);
    
    insertionSort(arr, n);

    printf("\nYour sorted array: ");
    printArr(arr, n);

    return 0; 
    }