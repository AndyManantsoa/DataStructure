#include <iostream>

int linearSearch(int arr[],int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            std::cout<<"\nElement found on index :"<<i;
            return i;
        }
    }
    std::cout<<"Elements not found\n";

    return -1;
}

int main(){
    int n;
    std::cout<<"Enter the size of the array: ";

    std::cin>>n;
    int arr[n];

    std::cout<<"Enter the elements of the array: \n";

    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }

    std::cout<<"\nEnter the elements you want to find: ";

    int key;
    std::cin>>key;

    linearSearch(arr,n,key);

}
