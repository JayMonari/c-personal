#include "resistor_color.h"

resistor_band_t *colors() {
  static resistor_band_t bands[TYPES];
  for (int i = BLACK; i < TYPES; i++) {
    bands[i] = i;
  }
  return bands;
}
