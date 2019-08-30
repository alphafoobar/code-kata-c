#ifndef C_ANAGRAM_H
#define C_ANAGRAM_H

#include "../file/read_file.h"

StringsList *anagrams_dofree(char *input);

void load_anagrams(const char *filename);

#endif //C_ANAGRAM_H
