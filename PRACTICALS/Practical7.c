//7. Implement Double Linked lists and its operations(creation insertion deletion traversal search reverse)

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(Node ** Head , int data, int position){
    Node* newNode = createNode(data);
    if (position ==1){
        newNode->next = *Head;
        if (*Head != NULL){
            (*Head)->prev = newNode;
        }
        *Head = newNode;
    }
    
}