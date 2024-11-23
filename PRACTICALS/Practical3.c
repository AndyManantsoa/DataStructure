#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE); 
    }
    return stack->data[stack->top--];
}

int evaluatePostfix(char* postfix) {
    Stack stack;
    initStack(&stack);
    int i, operand1, operand2, result;

    for (i = 0; i < strlen(postfix); i++) {
        if (postfix[i] == ' ') continue;

        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(&stack, num);
            i--; 
        } 
        else { 
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        exit(EXIT_FAILURE); 
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    exit(EXIT_FAILURE);
            }
            push(&stack, result);
        }
    }
    return pop(&stack);
}

int main() {
    printf("   POSTFIX EVALUATION\n\n");
    printf("Enter the postfix expression: ");
    char postfix[MAX];
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("\nThe postfix result : %d\n", result);
    return 0;
}