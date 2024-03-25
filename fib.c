unsigned long fib(unsigned n) {
  unsigned long temp, n1, n2;
  if(n < 2) return n;
  n1 = 0;
  n2 = 1;
  while(--n) {
    temp = n1;
    n1   = n2;
    n2   = temp + n2;
  }
  return n2;
}
