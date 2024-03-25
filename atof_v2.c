#include <ctype.h>
#include <stdio.h>

double atof(char*);

int main() {
  char d[] = ".14e-2";
  double n = atof(d);
  printf("String: %s\nDouble: %lf\n", d, n);
  return 0;
}

double atof(char *s) {
  double val, power;
  int i, sign, e, esign;

  for (i = 0; isspace(s[i]); ++i)
    ;

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '-' || s[i] == '+')
    ++i;

  for (val = 0.0; isdigit(s[i]); ++i) 
    val = 10 * val + s[i] - '0';

  if (s[i] == '.')
    ++i;

  for (power = 1.0; isdigit(s[i]); ++i, power *= 10.0)
    val = 10 * val + s[i] - '0';

  if (s[i++] == 'e') {
    esign = (s[i] == '-');

    if (s[i] == '-')
      ++i;

    for(e = 0; isdigit(s[i]); ++i)
      e = 10 * e + s[i] - '0';

    while(e--)
      power = esign ? power * 10 : power / 10; 
  }

  return sign * val / power;
}

