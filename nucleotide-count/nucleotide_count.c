#include "nucleotide_count.h"

char *count(const char *dna_strand) {
  size_t acnt = 0, ccnt = 0, gcnt = 0, tcnt = 0;
  for ( ; *dna_strand; dna_strand++) {
    switch (*dna_strand) {
    case 'A': acnt++; break;
    case 'C': ccnt++; break;
    case 'G': gcnt++; break;
    case 'T': tcnt++; break;
    default:
      return calloc(1, sizeof(char));
    }
  }

  char *res = (char *) malloc(strlen(FORMAT));
  sprintf(res, FORMAT, acnt, ccnt, gcnt, tcnt);
  return res;
}
