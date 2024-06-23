//Linear Search

#include<stdio.h>

int linearSearch(int arr[],int n,int a){
    for(int i=0;i<n;i++){
        if(arr[i]==a){
            printf("\nElement found on index %d",i);
            return i;
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

    linearSearch(arr,n,a);

    return 0;
}