#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1; // Return a special value to indicate empty stack
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

int main() {
    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("Top element: %d\n", top->data);

    struct Node* temp = top;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Bottom element: %d\n", temp->data);

    int popped = pop(&top);
    if (popped != -1) {
        printf("Popped element: %d\n", popped);
    }

    return 0;
}

