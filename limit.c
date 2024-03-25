
#include <stdio.h>
int main() {
  int d = ~0;
  char c = ~0;
  short s = ~0;
  long l = ~0;
  unsigned u = ~0;
  int i;
  for (i = 0; d != 0; d &= d - 1, ++i);
  printf("int: 2^%d\n", i);
  for (i = 0; c != 0; c &= c - 1, ++i);
  printf("char: 2^%d\n", i);
  for (i = 0; s != 0; s &= s - 1, ++i);
  printf("short: 2^%d\n", i);
  for (i = 0; l != 0; l &= l - 1, ++i);
  printf("long: 2^%d\n", i);
  for (i = 0; u != 0; u &= u - 1, ++i);
  printf("unsigned: 2^%d\n", i);
  return 0;
}
