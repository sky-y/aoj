#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAX_INPUT = 10000;
const int MAX_STACK = 1000;

int top;
int S[MAX_STACK];

void initialize() { top = 0; }

bool isEmpty() { return top == 0; }

bool isFull() { return top >= MAX_STACK - 1; }

void push(int x) {
  if (isFull()) {
    fprintf(stderr, "overflow");
    exit(1);
  }
  top++;
  S[top] = x;
}

int pop() {
  if (isEmpty()) {
    fprintf(stderr, "underflow");
    exit(1);
  }
  top--;
  return S[top + 1];
}

int main() {
  int a, b;
  char s[MAX_INPUT];

  initialize();

  while (scanf("%s", s) != EOF) {
    switch (s[0]) {
    case '+':
      a = pop();
      b = pop();
      push(a + b);
      break;

    case '-':
      b = pop();
      a = pop();
      push(a - b);
      break;

    case '*':
      a = pop();
      b = pop();
      push(a * b);
      break;

    default:
      push(atoi(s));
      break;
    }
  }

  printf("%d\n", pop());

  return 0;
}