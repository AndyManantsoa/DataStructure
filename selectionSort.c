#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[],int size){
    int i,j,index;
    for(i=0;i<size-1;i++){
        index=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[index]){
                index=j;
            }
        }
            if(index!=i){
                swap(&arr[index],&arr[i]);
            }
    }
}

int main(){
    int arr[]={64,25,12,22,11};
    int size= sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,size);
    printf("Sorted array: \n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}