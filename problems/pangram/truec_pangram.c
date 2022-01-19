#include "pangram.h"

#define set_has(set, c) ((set & (1 << (c - 'a'))) != 0)
#define set_add(set, c) set |= 1 << (c - 'a')

bool is_pangram(const char *sentence) {
  uint32_t bitset = 0u;
  unsigned len = 0u;
  if (!sentence)
    return false;

  for (char *c = (char *)sentence; *c; ++c) {
    if (!isalpha(*c))
      continue;
    if (!set_has(bitset, tolower(*c))) {
      set_add(bitset, tolower(*c));
      ++len;
    }
  }

  return len == 26;
}
