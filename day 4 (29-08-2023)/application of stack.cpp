#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
struct Stack {
    int top;
    int items[MAX_SIZE];
};
void initialize(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->items[++(stack->top)] = item;
    } else {
        printf("Stack is full, cannot push.\n");
    }
}
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[(stack->top)--];
    }
    printf("Stack is empty, cannot pop.\n");
    return -1;
}
int evaluatePostfix(char* expression) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char expression[] = "235*+";

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}

