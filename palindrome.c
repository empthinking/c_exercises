#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define BUFFER 100

bool isPalindrome(const char *s, size_t length) {
  int i = 0, j = length - 1;
  if (j < 1)
    return false;
  while (i < j)
    if (s[i++] != s[j--])
      return false;
  return true;
}
