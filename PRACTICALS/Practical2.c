//2. Implement Infix to Postfix Expression Conversion using Stack

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
    int j = 0;
    char ch;

    for (int i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (isspace(ch)) {
            continue;
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) == '(') {
                pop(&stack); 
            } else {
                printf("Invalid expression\n");
                exit(1);
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