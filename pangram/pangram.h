#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool all(const int *alphabet, size_t n);
char *to_lwr(const char *sentence);
bool is_pangram(const char *sentence);

#endif
