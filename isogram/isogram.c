#include "isogram.h"

bool is_isogram(const char phrase[]) {
  if (phrase == NULL)
    return false;

  bool found[ALPHABET_LEN];
  for (size_t i = 0; i < ALPHABET_LEN; i++)
    found[i] = false;

  for (size_t i = 0; phrase[i] != '\0'; i++) {
    if (!isalpha(phrase[i]))
      continue;

    int letter = (tolower(phrase[i]) - 'a');
    if (found[letter])
      return false;
    found[letter] = true;
  }

  return true;
}
