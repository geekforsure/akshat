#ifndef EMAIL_HANDLER_H
#define EMAIL_HANDLER_H

typedef struct HashTable HashTable;  // Forward declaration only

int is_spam(const char *email_text, HashTable *table);
HashTable* create_table();
void insert_keyword(HashTable *table, const char *keyword);
void free_table(HashTable *table);

#endif
