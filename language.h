//
// Created by Angel Miranda on 04/10/24.
//

#ifndef SECOND_PRACTICE_LANGUAGE_H
#define SECOND_PRACTICE_LANGUAGE_H

#include "set.h"
#include <stdio.h>
#include <stdlib.h>

HashTable *language_union(HashTable *language1, HashTable *language2);

HashTable *language_concatenate(HashTable *language1, HashTable *language2);

HashTable *language_reverse(HashTable *language);

HashTable *language_power(HashTable *language, int n);

#endif //SECOND_PRACTICE_LANGUAGE_H
