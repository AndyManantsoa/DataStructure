// Binary Search

#include<stdio.h>

int binarySearch(){
    
}

int main(){
    int n,a;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter the elements: ");

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the element that you are searching for: ");
    scanf("%d", &a);

    binarySearch(arr,0,n-1,a);

    return 0;
}