//selection sort

#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void selectionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int index=i;
        for(int j=1+i;j<size;j++){
            if(arr[index]>arr[j]){
                index=j;
            }
            if(index!=i){
                swap(&arr[index],&arr[i]);
            }
        }
    }
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

    printf("\nEnter the elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("\nYour initial array: ");
    printArr(arr,n);
    
    selectionSort(arr,n);
    printf("\nYour sorted array: ");
    printArr(arr,n);

}