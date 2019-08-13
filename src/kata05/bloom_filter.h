#ifndef C_BLOOM_FILTER_H
#define C_BLOOM_FILTER_H

#include <stdbool.h>

#define BLOOM_FILTER_SIZE 552523

typedef struct bloom_filter {
    bool dictionary[BLOOM_FILTER_SIZE];

    void (*add_word)(void *self, char *word);

    bool (*test)(void *self, char *word);
} BloomFilter;

void bloom_filter_init(BloomFilter *it);

BloomFilter bloom_filter_init_from_file(char *filename);

#endif //C_BLOOM_FILTER_H
