//
// Created by Angel Miranda on 04/10/24.
//

#ifndef SECOND_PRACTICE_STRING_H
#define SECOND_PRACTICE_STRING_H

#include <stdio.h>
#include <stdlib.h>

#define LAMBDA "λ"

bool string_equals(char *string1, char *string2);

int string_length(const char *value);

char *string_copy(const char *value);

char *string_concatenate(const char *string1, const char *string2);

char *string_reverse(char *string);

int string_find(const char *string, char to_find);

void string_print(char *string);

#endif //SECOND_PRACTICE_STRING_H
