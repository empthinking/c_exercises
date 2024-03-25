#include "calculator.h"
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char s[MAXOP];
int p = 0;

int getop(char *expr) {
  int i, c;

  while (isblank(c = s[0] = expr[p]))
    ++p;

  s[1] = '\0';

  if (!isdigit(c) && c != '.') {
    ++p;
    return c;
  }

  i = 0;

  if (isdigit(c))
    while (isdigit(c = s[++i] = expr[++p]))
      ;

  if (c == '.')
    while (isdigit(c = s[++i] = expr[++p]))
      ;

  s[i] = '\0';

  return NUMBER;
}

double calculate(char *expr) {
  int type;
  double result;
  stack *op;

  op = create();

  while ((type = getop(expr)) != '\n' && type != '\0') {
    switch (type) {
    case NUMBER:
      push(&op, atof(s));
      break;
    case '+':
      push(&op, pop(&op) + pop(&op));
      break;
    case '*':
      push(&op, pop(&op) * pop(&op));
      break;
    case '-':
      swap(&op);
      push(&op, pop(&op) - pop(&op));
      break;
    case '/':
      swap(&op);
      if (top(op) != 0)
        push(&op, pop(&op) / pop(&op));
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      swap(&op);
      if (top(op) != 0)
        push(&op, (int)pop(&op) / pop(&op));
      else
        printf("error: zero divisor\n");
      break;
    default:
      printf("error: unknown command %s\n", s);
      return 0.0;
      break;
    }
  }

  result = pop(&op);
  return result;
}
