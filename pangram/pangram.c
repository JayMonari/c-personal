#include "pangram.h"
#include <stdlib.h>

bool all(const int *alphabet, size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (alphabet[i] < 1)
      return false;
  }
  return true;
}

char *to_lwr(const char *sentence) {
  size_t n = strlen(sentence);
  char *lwr = calloc(n, sizeof(char));
  for (size_t i = 0; i < n; i++) {
    if (sentence[i] >= 'A' && sentence[i] <= 'Z')
      lwr[i] = sentence[i] - 'A' + 'a';
    else
      lwr[i] = sentence[i];
  }
  return lwr;
}

bool is_pangram(const char *sentence) {
  if (sentence == NULL)
    return false;

  int *alphabet = calloc(26, sizeof(int));
  char *lwr = to_lwr(sentence);
  for (int i = 0; lwr[i] != '\0'; i++) {
    alphabet[lwr[i] - 'a']++;
  }

  return all(alphabet, 26);
}
