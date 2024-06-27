#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
        return;
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

void correction(char* ch){
    Stack s;
    initialize(&s);
    
    while(*ch != '\0'){
        if(*ch=='{'||*ch=='('||*ch=='['){
            push(&s,*ch);
        } else if(*ch=='}'){
            if(peek(&s)!='{'){
                printf("Invalid\n");
        return;
            }
            pop(&s);
        } else if(*ch==')'){
            if(peek(&s)!='('){
                printf("Invalid\n");
        return;
            }
            pop(&s);
        } else if(*ch==']'){
            if(peek(&s)!='['){
                printf("Invalid\n");
        return;
            }
            pop(&s);
        }
        ch++;
    }
    if(!isEmpty(&s)){
        printf("Invalid\n");
    } else {
        printf("Valid\n");
    }
}

int main() {
    char ch[MAX];

    printf("Enter the expression: ");
    scanf("%s", ch);
    correction(ch);

    return 0;
}