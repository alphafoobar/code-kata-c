#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "bloom_filter.h"
#include "../string/strings.h"
#include "../file/read_file.h" // #to_data(string filename)

size_t algo_one(char *word) {
    char *const lower = to_lower(word);
    const size_t hash = latin1_hash_code(to_lower(word)) & ULONG_MAX;
    free(lower);
    return hash % BLOOM_FILTER_SIZE;
}

bool bloom_filter_test(void *self, char *word) {
    // Needs to look word up in the dictionary.
    return ((BloomFilter *) self)->dictionary[algo_one(word)];
}

void bloom_filter_add_word(void *self, char *word) {
    ((BloomFilter *) self)->dictionary[algo_one(word)] = true;
}

void bloom_filter_init(BloomFilter *it) {
    it->test = &bloom_filter_test;
    it->add_word = &bloom_filter_add_word;
}

BloomFilter bloom_filter_init_from_file(char *filename) {
    BloomFilter it;
    bloom_filter_init(&it);

    StringsList *file_data = to_data(filename);
    if (file_data) {
        for (size_t i = 0; i < file_data->lines_count; i++) {
            it.add_word(&it, file_data->lines[i]);
        }
    }
    return it;
}
