#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_INT 1 << 31

int main() {
  int max = MIN_INT;
  int len = 100;
  int n[len];
  time_t t;
  srand(time(&t));

  for (int i = 0; i < len; ++i) {
    n[i] = rand() % len;
    if (max < n[i])
      max = n[i];
    printf("%d ", n[i]);
  }
  putchar('\n');
  printf("Max: %d\n", max);
  return 0;
}
