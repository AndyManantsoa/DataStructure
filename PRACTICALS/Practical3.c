//3. Implement Postfix evaluation using Stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        return 0;
    }
    return stack->data[stack->top--];
}

int evaluatePostfix(char* postfix) {
    Stack stack;
    initStack(&stack);
    int i, operand1, operand2, result;
    for (i = 0; i < strlen(postfix); i++) {
        if (postfix[i] == ' ') continue;
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(&stack, postfix[i] - '0');
        } else {
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
                    result = operand1 / operand2;
                    break;
            }
            push(&stack, result);
        }
    }
    return pop(&stack);
}

int main() {
    char postfix[] = "23+45*";
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}

