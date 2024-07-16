//Singly linked list;

#include<stdio.h>

typedef struct Node{
    int Data;
    struct Node *address;
}Node;

//Cerating new node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = data;
    newNode->address = NULL;
}

//

int main(){
    return 0;
}