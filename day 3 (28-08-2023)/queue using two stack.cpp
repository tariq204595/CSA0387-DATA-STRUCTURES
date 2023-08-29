#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

int isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, int item) {
    if (isStackFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isStackEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (isStackEmpty(queue->stack1) && isStackEmpty(queue->stack2));
}

void enqueue(struct Queue* queue, int item) {
    while (!isStackEmpty(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }
    push(queue->stack1, item);
    while (!isStackEmpty(queue->stack2)) {
        push(queue->stack1, pop(queue->stack2));
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return pop(queue->stack1);
}

int main() {
    struct Queue* queue = createQueue(100);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 40);

    printf("Dequeued: %d\n", dequeue(queue));

    free(queue->stack1->array);
    free(queue->stack1);
    free(queue->stack2->array);
    free(queue->stack2);
    free(queue);

    return 0;
}

