#include <stdio.h>
#include <unistd.h>

int main() {
  for(int i = 10; i > 0; --i) {
    printf("%d\n", i);
    sleep(1);
  }
  puts("Done");
  return 0;
}
