#include "anagram.h"

StringsList *anagrams(char *input) {
    StringsList *list = new_strings_list();

    plus_string(list, input);
    return list;
}
