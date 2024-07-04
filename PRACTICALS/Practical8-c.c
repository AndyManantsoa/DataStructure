// Interpolation Search

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

void printArr(int arr[],int size){
    printf("Your array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int interpolationSearch(int arr[],int left,int right,int key){

    int prob = left + (key-arr[left])*(right-left)
                        /(arr[right]-arr[left]);


    printf("Element found at index %d",prob);
    return prob;
}


int main(){

    printf("  INTERPOLATION SORT: \n\n");
    int n,a;


    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter the elements: ");

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }    

    insertionSort(arr,n);
    printf("Sorted array: ");

    printArr(arr,n);

    printf("\n \n Enter the element that you are searching for: ");
    scanf("%d", &a);

    interpolationSearch(arr,0,n-1,a);
    
    return 0;
}