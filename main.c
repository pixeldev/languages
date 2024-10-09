#include "language.h"

int main(void) {
    int first_language_size = 0;

    while (first_language_size < 1) {
        printf("Introduce el tamaño del primer lenguaje:\n>> ");
        scanf("%d", &first_language_size);
    }

    HashTable *first_language = hash_table_create(first_language_size);

    char buffer[100];
    printf("Introduce palabras separadas por espacios:\n>> ");
    for (int i = 0; i < first_language_size; i++) {
        scanf("%99s", buffer);
        hash_table_insert(first_language, buffer);
    }

    int second_language_size = 0;

    while (second_language_size < 1) {
        printf("Introduce el tamaño del segundo lenguaje:\n>> ");
        scanf("%d", &second_language_size);
    }

    HashTable *second_language = hash_table_create(second_language_size);

    printf("Introduce palabras separadas por espacios:\n>> ");
    for (int i = 0; i < second_language_size; i++) {
        scanf("%99s", buffer);
        hash_table_insert(second_language, buffer);
    }

    printf("--=-- L1 --=--\n");
    hash_table_print(first_language);
    printf("--=-- L2 --=--\n");
    hash_table_print(second_language);

    int option = 0;

    while (option != 4) {
        printf("Selecciona una opción:\n");
        printf("1. Unión\n");
        printf("2. Concatenación\n");
        printf("3. Potencia\n");
        printf("4. Salir\n");
        printf(">> ");

        scanf("%d", &option);

        switch (option) {
            case 1: {
                HashTable *first_second_union_table = language_union(first_language, second_language);
                printf("--=-- L1 ∪ L2 --=--\n");
                hash_table_print(first_second_union_table);
                hash_table_free(first_second_union_table);

                HashTable *second_first_union_table = language_union(second_language, first_language);
                printf("--=-- L2 ∪ L1 --=--\n");
                hash_table_print(second_first_union_table);
                hash_table_free(second_first_union_table);
                break;
            }
            case 2: {
                HashTable *first_second_concatenation_table = language_concatenate(first_language, second_language);
                printf("--=-- L1L2 --=--\n");
                hash_table_print(first_second_concatenation_table);
                hash_table_free(first_second_concatenation_table);

                HashTable *second_first_concatenation_table = language_concatenate(second_language, first_language);
                printf("--=-- L2L1 --=--\n");
                hash_table_print(second_first_concatenation_table);
                hash_table_free(second_first_concatenation_table);
                break;
            }
            case 3: {
                int n;
                printf("Introduce la potencia:\n>> ");
                scanf("%d", &n);

                int which_language;
                printf("¿Sobre qué lenguaje quieres aplicar la potencia? (1 o 2)\n>> ");
                scanf("%d", &which_language);

                HashTable *power_table;
                if (which_language == 1) {
                    power_table = language_power(first_language, n);
                } else {
                    power_table = language_power(second_language, n);
                }

                printf("--=-- Potencia --=--\n");
                hash_table_print(power_table);
                hash_table_free(power_table);
                break;
            }
        }
    }

    hash_table_free(first_language);
    hash_table_free(second_language);

    return 0;
}
