#ifndef CODE_KATA_TOKENIZER_H
#define CODE_KATA_TOKENIZER_H

char **tokenize_string(const char *s, const char *delimiter, size_t *num_tokens);

void free_array_of_strings(char **tokens, size_t number_of_tokens);

#endif //CODE_KATA_TOKENIZER_H
