// Binary Search

#include<stdio.h>

int binarySearch(int arr[],int left,int right,int key){
    int mid=left+(right-left)/2;
    while(left<=right){
        if(arr[mid]==key){
            printf("Element found at index %d",mid);
            return mid;
        }else if(arr[mid]>key){
            left=mid+1;
        }else if(arr[mid]<key){
            right=mid-1;
        }
    }
    return -1;
    
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