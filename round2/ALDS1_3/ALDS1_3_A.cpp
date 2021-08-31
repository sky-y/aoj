#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000;

int S[MAX];
int top;

void push(int x) {
  if (top > MAX) {
    cerr << "ERROR" << endl;
    exit(1);
  }
  S[top++] = x;
}

int pop() {
  if (top < 0) {
    cerr << "ERROR" << endl;
    exit(1);
  }

  return S[--top];
}

int main() {
  top = 0;

  int a, b;

  for (;;) {
    string x;
    if (!(cin >> x)) {
      break;
    }

    switch (x[0]) {
    case '+':
      a = pop();
      b = pop();
      push(a + b);
      break;

    case '-':
      a = pop();
      b = pop();
      push(b - a);
      break;

    case '*':
      a = pop();
      b = pop();
      push(a * b);
      break;

    default:
      push(stoi(x));
      break;
    }
  }

  int ans = pop();
  cout << ans << endl;

  return 0;
}