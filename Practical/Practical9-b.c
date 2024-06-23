//Selection Sort

#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[],int size){
    for (int i=0;i<size-1;i++){
        for(int j=i+1;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[i]);
            }
        }
    }
}

void printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[]={5,4,3,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    printArr(arr,size);
    bubbleSort(arr,size);
    printf("Sorted array: ");
    printArr(arr,size);
}