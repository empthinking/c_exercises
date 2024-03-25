#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack* create(void) {
  stack* root;
  root = NULL;
  return root;
}
double pop(stack**root) {
  if(*root == NULL) {
    printf("Stack is empty\n");
    return 0.0;
  }
  stack* temp;
  double n;
  temp = (*root)->next;
  n = (*root)->value;
  free(*root);
  *root = temp;
  printf("Popped: %lf\n", n);
  return n;
}

void push(stack** root, double n) {
  stack * temp;
  temp = (stack*)malloc(sizeof(stack));
  temp->next = *root;
  temp->value = n;
  *root = temp;
  printf("Pushed: %lf\n", n);
}
double top(stack* root) {
  if(root == NULL) {
    printf("Stack is empty\n");
    return 0.0;
  }
  return root->value;
}
void copy(stack** root){
  push(root, (*root)->value);
}
void swap(stack**root) {
  if(*root == NULL || (*root)->next == NULL) {
    printf("Stack has one or none elements\n");
    return;
  }
  double temp;
  temp = (*root)->value;
  (*root)->value = (*root)->next->value;
  (*root)->next->value = temp;
}
void clear(stack** root) {
  while(*root != NULL) {
    pop(root);
  }
}
