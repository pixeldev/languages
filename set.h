//
// Created by Angel Miranda on 04/10/24.
//

#ifndef SECOND_PRACTICE_SET_H
#define SECOND_PRACTICE_SET_H

#include "string.h"
#include <stdio.h>
#include <stdlib.h>

#define LOAD_FACTOR 0.75

typedef struct {
    char *key;
    uint8_t used;
} HashEntry;

typedef struct {
    HashEntry *entries;
    size_t capacity;
    size_t size;
} HashTable;

uint32_t hash_function(char *key);

HashTable *hash_table_create(size_t capacity);

int hash_table_insert(HashTable *table, char *key);

void hash_table_resize(HashTable *table);

int hash_table_contains(HashTable *table, char *key);

void hash_table_free(HashTable *table);

void hash_table_print(HashTable *table);

#endif //SECOND_PRACTICE_SET_H
