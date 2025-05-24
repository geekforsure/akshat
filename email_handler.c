#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "email_handler.h"
#include "hash_table.h"

// Helper: checks if a single word is spam by looking it up in the hash table
static int is_word_spam(HashTable *table, const char *word) {
    return contains_keyword(table, word);
}

// Returns 1 if email_text contains any spam keyword, else 0
int is_spam(const char *email_text, HashTable *table) {
    char *copy = strdup(email_text);
    if (!copy) return 0;

    // tokenize on spaces and punctuation, convert to lowercase
    char *token = strtok(copy, " ,.!?;:\"()\n\t\r");
    while (token) {
        // lowercase token
        for (char *p = token; *p; ++p) *p = tolower(*p);

        if (is_word_spam(table, token)) {
            free(copy);
            return 1;  // spam keyword found
        }
        token = strtok(NULL, " ,.!?;:\"()\n\t\r");
    }

    free(copy);
    return 0;  // no spam keywords found
}
