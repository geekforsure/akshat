#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 100

typedef struct Node {
    char *keyword;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node *buckets[TABLE_SIZE];
} HashTable;

unsigned int hash(const char *str);
HashTable *create_table();
void insert_keyword(HashTable *table, const char *keyword);
int contains_keyword(HashTable *table, const char *word);
void free_table(HashTable *table);

#endif
