#include <search.h>
#include <stddef.h>
#include <stdlib.h>
#include "anagram.h"
#include "../file/read_file.h"
#include "../string/strings.h"

StringsList *anagrams_dofree(char *word) {
    char *normalized = sorted_lowercase_string_dofree(word);

    ENTRY find;
    find.key = normalized;
    ENTRY *entry = hsearch(find, FIND);
    if (entry == NULL) {
        return NULL;
    }
    return (StringsList *) (entry->data);
}

void load_anagrams(const char *filename) {
    StringsList *file_data = to_data_dofree(filename);

    for (size_t i = 0; i < file_data->lines_count; i++) {
        char *word = trim(file_data->lines[i]);
        char *normalized = sorted_lowercase_string_dofree(word);

        ENTRY entry;
        entry.key = normalized;
        ENTRY *pEntry = hsearch(entry, FIND);
        if (pEntry == NULL) {
            entry.data = new_strings_list_dofree();
            pEntry = hsearch(entry, ENTER);
        }
        plus_string((StringsList *) (pEntry->data), word);
    }
}

