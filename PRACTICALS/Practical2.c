//2. Implement Infix to Postfix Expression Conversion using Stack

/*
INSTRUCTIONS:

1) create char stack of top size and top; with its operations;
2) create funtion of BODMAS priority that returns in integers the order  ( 0 for "(", 1 fo + or -, 2 for * r /) else 0;
3) create the function infixtopostfix of char *infix ,*postfix:
    while char e is not full
        if alpha numeric then push to postfix
        else if ( then push e
        else if ) then push e and while
    

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
}Stack;

void initialize(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}


void push(Stack* s, char value) {
    if (s->top == MAX - 1) {
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
        return s->items[s->top];
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initialize(&stack);
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("Invalid expression\n");
                exit(1);
            } else {
                pop(&stack); 
            }
        }
        else if (isOperator(ch)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}