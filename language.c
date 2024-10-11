//
// Created by Angel Miranda on 04/10/24.
//

#include "language.h"

HashTable *language_union(HashTable *language1, HashTable *language2) {
    HashTable *new_language = hash_table_create(language1->size + language2->size);
    for (size_t i = 0; i < language1->capacity; i++) {
        if (language1->entries[i].used) {
            hash_table_insert(new_language, language1->entries[i].key);
        }
    }
    for (size_t i = 0; i < language2->capacity; i++) {
        if (language2->entries[i].used) {
            hash_table_insert(new_language, language2->entries[i].key);
        }
    }
    return new_language;
}

HashTable *language_reverse(HashTable *language) {
    HashTable *new_language = hash_table_create(language->size);
    for (size_t i = 0; i < language->capacity; i++) {
        if (language->entries[i].used) {
            char *reversed = string_reverse(language->entries[i].key);
            hash_table_insert(new_language, reversed);
            free(reversed);
        }
    }
    return new_language;
}

HashTable *language_concatenate(HashTable *language1, HashTable *language2) {
    HashTable *new_language = hash_table_create(language1->size + language2->size);
    for (size_t i = 0; i < language1->capacity; i++) {
        if (!language1->entries[i].used) {
            continue;
        }
        for (size_t j = 0; j < language2->capacity; j++) {
            if (!language2->entries[j].used) {
                continue;
            }
            char *concatenated = string_concatenate(language1->entries[i].key, language2->entries[j].key);
            hash_table_insert(new_language, concatenated);
            free(concatenated);
        }
    }
    return new_language;
}

HashTable *language_power(HashTable *language, int n) {
    if (n == 0) {
        HashTable *new_language = hash_table_create(1);
        hash_table_insert(new_language, LAMBDA);
        return new_language;
    }

    bool negative = false;
    if (n < 0) {
        n *= -1;
        language = language_reverse(language);
        negative = true;
    }

    if (n == 1) {
        return language;
    } else if (n == 2) {
        return language_concatenate(language, language);
    }

    HashTable *result = language_concatenate(language, language);

    for (int i = 2; i < n; i++) {
        HashTable *temp = language_concatenate(result, language);
        hash_table_free(result);
        result = temp;
    }

    if (negative) {
        hash_table_free(language);
    }

    return result;
}