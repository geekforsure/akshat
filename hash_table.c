#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash % TABLE_SIZE;
}

HashTable *create_table() {
    HashTable *table = malloc(sizeof(HashTable));
    if (!table) return NULL;
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void insert_keyword(HashTable *table, const char *keyword) {
    unsigned int index = hash(keyword);
    Node *new_node = malloc(sizeof(Node));
    new_node->keyword = strdup(keyword);
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

int contains_keyword(HashTable *table, const char *word) {
    unsigned int index = hash(word);
    Node *node = table->buckets[index];
    while (node) {
        if (strcmp(node->keyword, word) == 0)
            return 1;
        node = node->next;
    }
    return 0;
}

void free_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *node = table->buckets[i];
        while (node) {
            Node *temp = node;
            node = node->next;
            free(temp->keyword);
            free(temp);
        }
    }
    free(table);
}
