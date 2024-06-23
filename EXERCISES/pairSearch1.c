// question: Given a sorted array arr[], sorted in ascending order having n integers.
// Find if there exist any pair of any (n,n) such that their sum is equal to x=7;
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



for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if((arr[j]+arr[i])==x){
                printf("%d,%d " ,arr[i],arr[j]);
        }
    }

}
}