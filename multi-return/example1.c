#include <assert.h>
#include <stdio.h>

typedef struct {
  double min, max;
} number_range;

number_range get_min_and_max_by_struct(double *values, int length) {
  assert(length > 0);
  double max = values[0];
  double min = values[0];
  for (int i = 1; i < length; i++) {
    if (values[i] < min)
      min = values[i];
    if (values[i] > max)
      max = values[i];
  }
  return (number_range){.min = min, .max = max};
}

void get_min_and_max_by_pointer(double *values, int length, double *pmin,
                                double *pmax) {
  assert(length > 0);
  double max = values[0];
  double min = values[0];
  for (int i = 1; i < length; i++) {
    if (values[i] < min)
      min = values[i];
    if (values[i] > max)
      max = values[i];
  }
  if (pmin != NULL)
    *pmin = min;
  if (pmax != NULL)
    *pmax = max;
}

int main() {
  double values[5] = {0.8, 1.2, -75.2, 14, 3};

  double mymin, mymax;
  get_min_and_max_by_pointer(values, 5, &mymin, &mymax);
  printf("By pointer: (%1f, %1f)\n", mymin, mymax);


  number_range nr = get_min_and_max_by_struct(values, 5);
  printf("By struct: (%1f, %1f)\n", nr.min, nr.max);
}
