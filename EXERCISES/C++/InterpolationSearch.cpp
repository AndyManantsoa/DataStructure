#include <iostream>

int interpolationSearch(int arr[],int left, int right, int key){

    while(left<=right && key<=arr[right] && key>=arr[left]){
        if(left ==right){
            if(key == arr[left]){
                return left;
            }
            return -1;
        }

        int pos = left + ((left-right)*(key-arr[left]))
                        /(arr[left]-arr[right]);

        if(arr[pos] == key){
            return pos;
        }else if(arr[pos]>key){
            left = pos+1;
        } else{
            right = pos-1;
        }
    }
    return -1;
}

int main(){
    int n;
    std::cout<<"Enter the length of array: ";
    std::cin>>n;
    int arr[n];

    std::cout<<"\nEnter the elements of the array: \n";
    for(int i=0;i<n;i++){
        std::cout<<"Enter the element "<<i+1<<" : ";
        std::cin>>arr[i]; 
        }
    
    int key;

    std::cout<<"\nEnter the element you want to search: ";
    std::cin>>key;

    int x = interpolationSearch(arr,0,n-1,key);
    
    if(x==-1){
        std::cout<<"Element not found\n";
    } else{
        std::cout<<"Element found at index "<<x;

    }
}