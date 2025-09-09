#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("%d inserted.\n", key);
}

void search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    while (temp) {
        if (temp->data == key) {
            printf("%d found in hash table.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found.\n", key);
}

void deleteKey(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp) {
        if (temp->data == key) {
            if (prev)
                prev->next = temp->next;
            else
                hashTable[index] = temp->next;
            free(temp);
            printf("%d deleted from hash table.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not found.\n", key);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    while (1) {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
