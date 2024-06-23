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
    printf("Enter the size of array : ");
    int size;
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements of array : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,size);
    printf("Sorted array : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    printf("\nEnter x : ");
    int x;
    scanf("%d",&x);

    int e=size-1;
    int s=0;

    while (e>0 && s<size-1){
        if(arr[e]+arr[s]==x){
            printf("%d %d  %d %d",arr[s],arr[e],arr[e],arr[s]);
            e--;
            s++;
        }
        else if(arr[e]+arr[s]>x){
            e--;
        }
        else if (arr[e]+arr[s]<x)
        {
            s++;
        }
        else{
            printf("error");
        }
    }
    

}