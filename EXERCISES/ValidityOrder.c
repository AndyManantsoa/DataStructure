//sStack practice: Check if notation of oppening brawcket is valid or not 

#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
}Stack;

void initialize(Stack* s) {
    s->top = -1;
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}


void push(Stack* s, char value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        s->items[++(s->top)] = value;
    }
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        return s->items[(s->top)--];
    }
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        return s->items[(s->top)];
    }
}
