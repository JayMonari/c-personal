#include <stdio.h>
#include <string.h>

struct Person {
  char name[64];
  int age;
};

int main(int argc, char **argv) {
  for (int i = 0; i < argc; i++) {
    printf("arg %d - %s\n", i, argv[i]);
  }
  struct Person people[10];
  struct Person *p_Person = people;
  for (int i = 0; i < 10; i++) {
    p_Person->age = 24;
    char n[64];
    sprintf(n, "Str Copy with leN %d", i);
    strncpy(p_Person->name, n, 64);
    p_Person += 1;
  }
  for (int i = 0; i < 10; i++) {
    p_Person = &people[i];
    printf("Age: %d Name: %s\n", p_Person->age, p_Person->name);
  }
}
