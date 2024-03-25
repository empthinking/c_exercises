#include <ctype.h>
#include <stdio.h>
#include <string.h>
void expand(char s1[], char s2[]) {
  int i, j, start, end, size = strlen(s1);
  for(i = 0, j = 0; i < size; ++i) {
    if(s1[i] != '-') continue;
    start = (i > 0) ? ((i > 1 && s1[i - 2] == '-') ? s1[i-1] + 1 : s1[i-1]) : isdigit(s1[i+1]) ? '0' : islower(s1[i+1]) ? 'a' : 'A';
    end = (s1[i+1] != '\0') ? ((size-i>2 && s1[i+2] == '-' && start > s1[i+1]) ? s1[i+1] - 1 : s1[i+1]) : isdigit(s1[i-1]) ? '9' : islower(s1[i-1]) ? 'z' : 'Z';
    printf("%c %c\n", start, end);
    if(start <= end) {
      for(; start <= end; ++j, ++start) s2[j] = start;
      continue;
    }
    if(start > end) {
      for(; start >= end; ++j, --start) s2[j] = start;
      continue;
    }
  }
  s2[j] = '\0';
}


int main(int argc, char *argv[]) {
  char s[100];
  expand(argv[1], s);
  puts(s);
  return 0;
}
