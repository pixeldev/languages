//
// Created by Angel Miranda on 04/10/24.
//

#include "string.h"

bool string_equals(char *string1, char *string2) {
    while (*string1 && *string2) {
        if (*string1 != *string2) {
            return false;
        }
        string1++;
        string2++;
    }
    return *string1 == *string2;
}

int string_length(const char *value) {
    int length = 0;
    while (value[length] != '\0') {
        length++;
    }
    return length;
}

char *string_copy(const char *value) {
    int length = string_length(value);
    char *copy = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        copy[i] = value[i];
    }
    copy[length] = '\0';
    return copy;
}

char *string_concatenate(const char *string1, const char *string2) {
    int length1 = string_length(string1);
    int length2 = string_length(string2);
    char *concatenated = malloc(length1 + length2 + 1);
    for (int i = 0; i < length1; i++) {
        concatenated[i] = string1[i];
    }
    for (int i = 0; i < length2; i++) {
        concatenated[length1 + i] = string2[i];
    }
    concatenated[length1 + length2] = '\0';
    return concatenated;
}

char *string_reverse(char *string) {
    int length = string_length(string);
    char *reversed = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        reversed[i] = string[length - i - 1];
    }
    reversed[length] = '\0';
    return reversed;
}

int string_find(const char *string, char to_find) {
    int length = string_length(string);
    for (int i = 0; i < length; i++) {
        if (string[i] == to_find) {
            return i;
        }
    }
    return -1;
}

void string_print(char *string) {
    printf("%s\n", string);
}
