//11. Implement Traversals Preorder Inorder Postorder on BST

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (newdata < root->data) {
        root->left = insert(root->left, data);
    } else if (newdata > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

void preorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

int main() {
    Node* root = createNode(100);
    root->left = createNode(20);
    root->right = createNode(200);
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(150);
    root->right->right = createNode(300);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
