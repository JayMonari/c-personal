#include "binary_search.h"

int *binary_search(int target, const int *arr, size_t n) {
  int lo = 0, hi = n - 1, mid;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    if (arr[mid] < target)
      lo = mid + 1;
    else if (arr[mid] > target)
      hi = mid - 1;
    else
      return (int *)&arr[mid];
  }

  return NULL;
}
