#include <search.h>
#include <stddef.h>
#include <stdlib.h>
#include "anagram.h"
#include "../file/read_file.h"
#include "../string/strings.h"

StringsList *anagrams(char *word) {
    char *normalized = sorted_lowercase_string(word);

    ENTRY find;
    find.key = normalized;
    ENTRY *entry = hsearch(find, FIND);
    if (entry == NULL) {
        return NULL;
    }
    return (StringsList *) (entry->data);
}

void load_anagrams(const char *filename) {
    StringsList *file_data = to_data(filename);

    for (size_t i = 0; i < file_data->lines_count; i++) {
        char *word = trim(file_data->lines[i]);

        char *normalized = sorted_lowercase_string(word);
        ENTRY find;
        find.key = normalized;
        ENTRY *entry = hsearch(find, FIND);
        if (entry == NULL) {
            entry = (ENTRY *) malloc(sizeof(ENTRY));
            entry->key = normalized;
            entry->data = new_strings_list();
            entry = hsearch(*entry, ENTER);
        }
        plus_string_if_unique((StringsList *) (entry->data), word);
    }
}

