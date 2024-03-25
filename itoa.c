#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; --j, ++i) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

char baseConv(unsigned n, int b) {
  return (n = n % b) < 10 ? n + '0' : n - 10 + 'A';
}

void itoa(int n, char s[], int b, int p) {
  int i, j, sign, mod;
  i = 0;
  sign = n < 0;
  s[i++] = baseConv(abs(n), b);
  n = abs(n / b);

  while (n > 0) {
    s[i++] = baseConv(n, b);
    n /= b;
  }

  if (sign)
    s[i++] = '-';

  j = 0;
  while (j < p) {
    s[i++] = ' ';
    ++j;
  }

  s[i] = '\0';
  reverse(s);
}

int main(int argc, char *argv[]) {
  char s[500];
  int n = 128;
  int base = 64;
  int padding = 0;
  itoa(n, s, base, padding);
  printf("%d\n", n);
  puts(s);
  return 0;
}
