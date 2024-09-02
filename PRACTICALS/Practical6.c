//Singly linked list;

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Data;
    struct Node* address;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->Data = data;
    newNode->address = NULL;
    return newNode;
}

void insertAtHead(Node** Head, int data) {
    Node* newNode = createNode(data);
    newNode->address = *Head;
    *Head = newNode;
}

void insertAtLast(Node** Head, int data) {
    Node* newNode = createNode(data);

    if (*Head == NULL) {
        *Head = newNode;
    } else {
        Node* temp = *Head;
        while (temp->address != NULL) {
            temp = temp->address;
        }
        temp->address = newNode;
    }
}

void insertAtPosition(Node** Head, int data, int position) {
    Node* newNode = createNode(data);

    if (position == 1) {
        insertAtHead(Head, data);
        return;
    }

    Node* temp = *Head;
    int count = 1;

    while (temp->address != NULL && count < position - 1) {
        temp = temp->address;
        count++;
    }

    if (temp->address == NULL) {
        printf("Position out of range\n");
        return;
    }

    newNode->address = temp->address;
    temp->address = newNode;
}

void deleteHead(Node** Head) {
    if (*Head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = *Head;
    *Head = (*Head)->address;
    free(temp);
}

void deleteAtPosition(Node** Head, int position) {
    if (*Head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = *Head;
    int count = 1;

    while (temp->address != NULL && count < position - 1) {
        temp = temp->address;
        count++;
    }

    if (temp->address == NULL) {
        printf("Position out of range\n");
        return;
    }

    Node* nodeToDelete = temp->address;
    temp->address = nodeToDelete->address;
    free(nodeToDelete);
}

void deleteLastNode(Node** Head) {
    if (*Head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = *Head;

    if (temp->address == NULL) {
        *Head = NULL;
        free(temp);
        return;
    }

    while (temp->address->address != NULL) {
        temp = temp->address;
    }

    Node* nodeToDelete = temp->address;
    temp->address = NULL;
    free(nodeToDelete);
}

void traversing(Node* Head) {
    while (Head) {
        printf("%d ", Head->Data);
        Head = Head->address;
    }
    printf("\n");
}

int main() {
    Node* Head = NULL;

    insertAtLast(&Head, 10);
    insertAtLast(&Head, 20);
    insertAtLast(&Head, 30);
    insertAtLast(&Head, 40);
    insertAtLast(&Head, 50);

    printf("Linked List: ");
    traversing(Head);

    insertAtHead(&Head, 5);
    printf("After inserting at head: ");
    traversing(Head);

    insertAtPosition(&Head, 25, 3);
    printf("After inserting at position 3: ");
    traversing(Head);

    insertAtLast(&Head, 60);
    printf("After inserting at last: ");
    traversing(Head);

    deleteHead(&Head);
    printf("After deleting head: ");
    traversing(Head);

    deleteAtPosition(&Head, 2);
    printf("After deleting at position 2: ");
    traversing(Head);

}