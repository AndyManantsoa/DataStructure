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
    return newNode;
}

Node* insert(Node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        // Handle duplicate data
        std::cerr << "Duplicate data!" << std::endl;
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
