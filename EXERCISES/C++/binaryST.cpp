//BST

#include <iostream>

typedef struct Node {
    int data;
    Node * left;
    Node * right;
}Node;

Node createNode(int data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data= data;
    newNode->left=newNode->right= NULL;
}

Node insertNode(Node* root, int data){
    if(root==NULL){
        return createNode(data);
    }

    if(newNode<root->data){
        insertNode(root->left,data);
    }else if (newNode<root->data)

}
