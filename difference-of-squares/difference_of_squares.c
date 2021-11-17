#include "difference_of_squares.h"

// The most performant version is math.
// sum = n * (n + 1) >> 1; return sum * sum;
unsigned int square_of_sum(unsigned int n) {
  unsigned int sum = 0;
  for (unsigned int i = 1; i <= n; i++) {
    sum += i;
  }
  return pow(sum, 2);
}

// The most performant version is math.
// return n * (n + 1) * (2 * n + 1) / 6;
unsigned int sum_of_squares(unsigned int n) {
  unsigned int sum = 0;
  for (unsigned int i = 1; i <= n; i++) {
    sum += pow(i, 2);
  }
  return sum;
}

unsigned int difference_of_squares(unsigned int n) {
  return square_of_sum(n) - sum_of_squares(n);
}
