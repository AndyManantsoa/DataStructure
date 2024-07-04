// Interpolation Search

#include<stdio.h>

int interpolationSearch(int arr[],int left,int right,int key){
    int prob = left + (key-arr[left])*(right-left)/(arr[right]-arr[left]);
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

    printf("Enter the element that you are searching for: ");
    scanf("%d", &a);

    interpolationSearch(arr,0,n-1,a);
    
    return 0;
}