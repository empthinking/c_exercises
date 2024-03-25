int strrindex(char *s, char* t) {
  int i, j, k, lastIndex;
  lastIndex = -1;
  for(i = 0; s[i] != '\0'; ++i) {
    for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k);
    if(k > 0 && t[k] == '\0')
      lastIndex = i;
  }
  return lastIndex;
}

int main() {
  char str[] = "test, test, test";
  char pattern[] = "test";
  int result = strrindex(str, pattern);
  printf("%d\n", result);
  return -1;
}

