#include "raindrops.h"

char *convert(char result[], int drops) {
  int n = snprintf(result, BUFFER_SIZE, "%s%s%s",
      drops % 3 == 0 ? "Pling" : "",
      drops % 5 == 0 ? "Plang" : "",
      drops % 7 == 0 ? "Plong" : "");

  if (!n)
    sprintf(result, "%d", drops);
  return result;
}
