#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate) {
  int copy = candidate;
  int ndigits = getlen(candidate);
  int sum = 0;
  while (copy > 0) {
    sum += pow(copy % 10, ndigits);
    copy /= 10;
  }
  return sum == candidate;
}

int getlen(int n) {
  if (n > 999999999) return 10;
  if (n > 99999999) return 9;
  if (n > 9999999) return 8;
  if (n > 999999) return 7;
  if (n > 99999) return 6;
  if (n > 9999) return 5;
  if (n > 999) return 4;
  if (n > 99) return 3;
  if (n > 9) return 2;
  return 1;
}
