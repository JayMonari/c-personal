#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FORMAT "A:%zu C:%zu G:%zu T:%zu"

char *count(const char *dna_strand);

#endif
