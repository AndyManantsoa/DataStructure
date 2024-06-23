//Insertion Sort

#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int insertionSort(int arr[],int size){
    
}

void printArr(int arr[],int size){
    printf("Your array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nYour initial array: ");
    printArr(arr,n);
    
    insertionSort(arr,n);

    printf("\nYour sorted array: ");
    printArr(arr,n);

}