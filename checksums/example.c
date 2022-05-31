#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *corrupt_msg(const char *msg, int num_bits) {
  char *result = strdup(msg);

  for (int i = 0; i < num_bits; i++) {
    int rbyte = rand() % strlen(msg);
    int rbit = rand() % 8;
    result[rbyte] ^= 1 << rbit;
  }
  return result;
}

unsigned char checksum1(const char *msg, int n) {
  unsigned char result = 0;
  for (int i = 0; i < n; i++) {
    result += msg[i];
  }
  return result;
}

unsigned char checksum2(const char *msg, int n) {
  unsigned char result = 0;
  for (int i = 0; i < n; i++) {
    result ^= msg[i];
  }
  return result;
}

int main(void) {
  srand(time(NULL));
  char *msg = "This is a message about checksums and stuff!";
  printf("BEFORE:\t%s\t%x\t%x\n", msg, checksum1(msg, strlen(msg)),
         checksum2(msg, strlen(msg)));
  char *cmsg = corrupt_msg(msg, 10);
  printf("AFTER:\t%s\t%x\t%x\n", cmsg, checksum1(cmsg, strlen(cmsg)),
         checksum2(cmsg, strlen(cmsg)));
  free(cmsg);
  return EXIT_SUCCESS;
}
