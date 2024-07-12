#include <iostream>

int binarySearch(int arr[],int left,int right, int x){
    while(left<=right){
        int mid = left + (right-left)/2;
        if(x==arr[mid]){
            std::cout<<"Element fond on index: "<<mid;
            return mid;
        }else if(arr[mid]>x){
            left =mid+1;
        }else{
            right = mid;
        }
    }
    return -1;
}

int main(){
    std::cout<<" BINARY SEARCH \n\n";

    int n;
    std::cout<<"Enter the length of the array: ";
    std::cin>>n;

    int arr[n];
    std::cout<<"Enter the elements of the array : \n";
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }

    int x;
    std::cout<<"Enter the elements of you want to find: ";
    std::cin>>x;

    binarySearch(arr,0,n-1,x);
};

