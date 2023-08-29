#include <stdio.h>
#include <stdlib.h>
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1; 
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}
void push(struct Queue* queue1, struct Queue* queue2, int item) {
    if (isFull(queue1))
        return;

    enqueue(queue1, item);
}
int pop(struct Queue* queue1, struct Queue* queue2) {
    if (isEmpty(queue1))
        return -1;

    while (queue1->size > 1) {
        enqueue(queue2, dequeue(queue1));
    }

    int popped = dequeue(queue1);
    struct Queue* temp = queue1;
    queue1 = queue2;
    queue2 = temp;

    return popped;
}

int main() {
    struct Queue* queue1 = createQueue(100);
    struct Queue* queue2 = createQueue(100);

    push(queue1, queue2, 10);
    push(queue1, queue2, 20);
    push(queue1, queue2, 30);

    printf("Popped: %d\n", pop(queue1, queue2));
    printf("Popped: %d\n", pop(queue1, queue2));

    push(queue1, queue2, 40);

    printf("Popped: %d\n", pop(queue1, queue2));

    free(queue1->array);
    free(queue2->array);
    free(queue1);
    free(queue2);

    return 0;
}

