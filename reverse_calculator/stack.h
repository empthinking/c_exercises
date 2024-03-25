
typedef struct node {
  struct node* next;
  double value;
} stack;

stack* create(void);
double pop(stack**);
void push(stack**, double);
double top(stack*);
void copy(stack**);
void swap(stack**);
void clear(stack**);
