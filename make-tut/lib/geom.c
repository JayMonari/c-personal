#include "../include/gd.h"
#include "../include/geom.h"

void square_nums() {
  double x = get_double("Enter the x value: ", -100, 100);
  double y = get_double("Enter the y value: ", -100, 100);
  double d = sqrt(pow(x, 2) + pow(y, 2));
  printf("Distance is %lf meters\n", d);
}
