#include "set.h"

uint32_t hash_function(char *key) {
    uint32_t hash = 2166136261u;
    while (*key) {
        hash ^= *key++;
        hash *= 16777619u;
    }
    return hash;
}

HashTable *hash_table_create(size_t capacity) {
    HashTable *table = malloc(sizeof(HashTable));
    table->capacity = capacity;
    table->size = 0;
    table->entries = calloc(table->capacity, sizeof(HashEntry));
    return table;
}

int hash_table_insert(HashTable *table, char *key) {
    if ((double) table->size / table->capacity >= LOAD_FACTOR) {
        hash_table_resize(table);
    }

    uint32_t hash = hash_function(key);
    size_t index = hash % table->capacity;

    while (table->entries[index].used) {
        if (string_equals(table->entries[index].key, key)) {
            return 0;
        }
        index = (index + 1) % table->capacity;
    }

    table->entries[index].key = string_copy(key);
    table->entries[index].used = 1;
    table->size++;
    return 1;
}

void hash_table_resize(HashTable *table) {
    size_t old_capacity = table->capacity;
    HashEntry *old_entries = table->entries;

    table->capacity *= 2;
    table->entries = calloc(table->capacity, sizeof(HashEntry));
    table->size = 0;

    printf("Redimensionando tabla de %zu a %zu\n", old_capacity, table->capacity);

    for (size_t i = 0; i < old_capacity; i++) {
        if (old_entries[i].used) {
            hash_table_insert(table, old_entries[i].key);
            free(old_entries[i].key);
        }
    }
    free(old_entries);
}

int hash_table_contains(HashTable *table, char *key) {
    uint32_t hash = hash_function(key);
    size_t index = hash % table->capacity;

    while (table->entries[index].used) {
        if (string_equals(table->entries[index].key, key)) {
            return 1;
        }
        index = (index + 1) % table->capacity;
    }
    return 0;
}

void hash_table_free(HashTable *table) {
    for (size_t i = 0; i < table->capacity; i++) {
        if (table->entries[i].used) {
            free(table->entries[i].key);
        }
    }
    free(table->entries);
    free(table);
}

void hash_table_print(HashTable *table) {
    printf("{");
    for (size_t i = 0; i < table->capacity; i++) {
        HashEntry entry = table->entries[i];
        if (entry.used) {
            printf("%s", entry.key);
            if (i < table->capacity - 1) {
                printf(", ");
            }
        }
    }
    printf("}\nTotal: %zu\n", table->size);
}