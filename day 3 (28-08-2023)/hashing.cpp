#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

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

void insert(struct Node* hashTable[], int key, int value) {
    int index = key % TABLE_SIZE;
    struct Node* newNode = createNode(value);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printHashTable(struct Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node* hashTable[TABLE_SIZE] = { NULL };

    insert(hashTable, 5, 15);
    insert(hashTable, 1, 10);
    insert(hashTable, 6, 20);
    insert(hashTable, 3, 30);
    insert(hashTable, 8, 25);
    insert(hashTable, 9, 40);

    printHashTable(hashTable);

    return 0;
}

