#include "grade_school.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int student_compare(const void *a, const void *b) {
  const student_t *student_a = a;
  const student_t *student_b = b;
  int namecmp = strcmp(student_a->name, student_b->name);
  if (namecmp == 0)
    return 0;

  if (student_a->grade < student_b->grade)
    return -1;
  else if (student_a->grade > student_b->grade)
    return 1;
  else
    return namecmp;
}

void roster_sort(roster_t *roster) {
  qsort(roster->students, roster->count, sizeof(student_t), student_compare);
}

void init_roster(roster_t *roster) {
  if (roster == NULL)
    roster = (roster_t *)malloc(sizeof(roster_t));
  roster->count = 0;
}

int8_t add_student(roster_t *roster, const char *name, uint8_t grade) {
  if (roster == NULL || grade > 12 || name == NULL ||
      roster->count >= MAX_STUDENTS)
    return 0;

  student_t student = {grade, "\0"};
  strcpy(student.name, name);
  if (bsearch(&student, roster->students, roster->count, sizeof(student_t),
              student_compare) != NULL)
    return 0;

  roster->students[roster->count].grade = grade;
  strcpy(roster->students[roster->count].name, name);
  roster->count++;
  roster_sort(roster);
  return 1;
}

roster_t get_grade(roster_t *roster, uint8_t grade) {
  roster_t new_roster = {0, {(student_t){0, "\0"}}};
  for (size_t i = 0; i < roster->count; i++) {
    if (roster->students[i].grade > grade)
      break;

    if (roster->students[i].grade == grade) {
      new_roster.students[new_roster.count] = roster->students[i];
      new_roster.count++;
    }
  }
  return new_roster;
}
