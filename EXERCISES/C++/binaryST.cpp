//BST

#include <iostream>

typedef struct Node {
    int data;
    Node * left;
    Node * right;
}Node;

Node* createNode(int data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data= data;
    newNode->left=newNode->right= NULL;
}

Node* insertNode(Node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    if(newNode<root->data){
        insertNode(root->left,data);
    }else if (newNode>root->data){
        insertNode(root->right,data);
    }
    return root;
}

Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout<<"Inorder Traversal before deletion: ";
    inorderTraversal(root);
    
    return 0;
}
