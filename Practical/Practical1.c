#include <stdio.h>
#include <stdbool.h>

#define MAX 3

typedef struct {
    int values[MAX];
    int top;
}Stack;

//helper functions
void initStack(Stack *p){
    p->top = -1;
    printf("Stack initialized\n\n");
}

bool isFull(Stack *p ){
    return p->top == MAX-1;
}

bool isEmpty(Stack *p ){
    return p->top == -1;
}

//The operational functions

void push(Stack *p, int value){
    if(isFull(p)){
        printf("Alert! Stack overflow\n");
        return;
    }    
    printf(" Pushing : the value %d is pushed to the stack \n",value);

    p->values[++(p->top)] = value;
}

int pop(Stack *p){
    if(isEmpty(p)){
        printf("\nAlert! Stack underflow");
        return -1;
    }
    printf(" Poping: the value %d is removed from the stack \n",p->values[p->top]);
    return p->values[(p->top)--];
}

int peek(Stack *p){
    if(isEmpty(p)){
        printf("\n Peeking :The stack doesn't contain any data\n");
        return -1;
    }
    printf(" Peeking: the value %d is peeked from the stack \n",p->values[p->top]);
    return p->values[(p->top)];
}


int main(){
    Stack s;
    initStack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    
    printf("\n");

    peek(&s);
    
    printf("\n");

    
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    
    printf("\n");
    
    peek(&s);

    return 0;
}