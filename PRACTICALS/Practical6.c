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
    return newNode;
}

//insertion:
//at Head;
void insertAtHead(Node ** Head, int data){
    Node * temp = * Head;
    Node *newNode = createNode(data);
    newNode->address = temp;
    *Head = newNode;
}

//traversing
void traversing(Node ** Head){
    Node * temp= *Head;
    while(temp->address!=NULL){
        temp = temp -> address;
        printf("%d ", temp->Data);
    }
}

int main(){
    return 0;
}