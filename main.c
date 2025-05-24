#include <stdio.h>
#include "email_handler.h"
#include "hash_table.h"

int main() {
    HashTable *table = create_table();

    insert_keyword(table, "win");
    insert_keyword(table, "money");
    insert_keyword(table, "prize");
    insert_keyword(table, "offer");

    const char *email1 = "You have won a money prize!";
    const char *email2 = "Meeting agenda for tomorrow.";

    printf("Email 1 is %s\n", is_spam(email1, table) ? "SPAM" : "NOT SPAM");
    printf("Email 2 is %s\n", is_spam(email2, table) ? "SPAM" : "NOT SPAM");

    free_table(table);
    return 0;
}
