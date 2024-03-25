#include <stdio.h>
#include <string.h>

typedef struct {
  int start;
  int end;
} patternMatch;

patternMatch strnindex(char *s, char *p, int start) {
  int i, j, k;
  patternMatch match = {-1, -1};
  for (i = start; s[i] != '\0'; ++i) {
    for (j = i, k = 0; p[k] != '\0' && s[j] == p[k]; ++j, ++k)
      ;
    if (k > 0 && p[k] == '\0') {
      match.start = i;
      match.end = i + k - 1;
      return match;
    }
  }
  return match;
}

void toMorse(char *in, char *out) {
  int i, j;
  patternMatch match;
  i = j = 0;
  while (in[i] != '\0') {
    match = strnindex(in, "dot", i);
    if (match.start == i) {
      out[j++] = '.';
    } else {
      match = strnindex(in, "dash", i);
      out[j++] = '-';
    }
    i = match.end + 1;
  }
  out[j] = '\0';
}

void toText(char *s, char *out) {
  int i;
  strcpy(out, "");
  for (i = 0; s[i] != '\0'; ++i)
    if (s[i] == '.')
      strcat(out, "dot");
    else
      strcat(out, "dash");
}
int main(int argc, char *argv[]) {

  char s[] = "dotdotdotdashdashdashdotdotdot"; // -> ...---...
  char m[] = "...---...";
  char tomorse[100];
  char totxt[100];
  toMorse(s, tomorse);
  puts(tomorse);
  toText(m, totxt);
  puts(totxt);
  return 0;
}
