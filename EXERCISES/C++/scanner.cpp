#include <iostream>

int main(){
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;

    char* c = new char[a + 1];

    std::cout << "Enter a word in the size of " << a << ": ";
    std::cin.getline(c, a + 1); 

    std::cout << c << std::endl;

    delete[] c;

    return 0;
}