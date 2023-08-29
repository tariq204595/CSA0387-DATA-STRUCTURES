#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
struct Node {
    int key;
    int value;
    struct Node* next;
};
struct HashTable {
    struct Node* table[TABLE_SIZE];
};
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}
int hashFunction(int key) {
    return key % TABLE_SIZE;
}
void insert(struct HashTable* hashTable, int key, int value) {
    int index = hashFunction(key);
    struct Node* newNode = createNode(key, value);

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        struct Node* current = hashTable->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
int search(struct HashTable* hashTable, int key) {
    int index = hashFunction(key);
    struct Node* current = hashTable->table[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return -1; 
}

int main() {
    struct HashTable* hashTable = createHashTable();

    insert(hashTable, 5, 25);
    insert(hashTable, 15, 225);
    insert(hashTable, 25, 625);

    printf("Value for key 5: %d\n", search(hashTable, 5));
    printf("Value for key 15: %d\n", search(hashTable, 15));
    printf("Value for key 25: %d\n", search(hashTable, 25));

    return 0;
}

