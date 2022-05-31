#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char *string, *string_so_far;
  int length = 0;
  for (int i = 0; i < argc; i++) {
    length += strlen(argv[i]) + 1;
    string = malloc(length + 1);
    // never call free(string)

    if (string_so_far != (char *)0)
      strcpy(string, string_so_far);
    else
      *string = '\0';

    strcat(string, argv[i]);
    if (i < argc - 1)
      strcat(string, " ");
    string_so_far = string;
  }

  printf("You entered: %s\n", string_so_far);
  return 0;
}
