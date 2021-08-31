#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> S;
  int a, b, x;
  string s;

  while (cin >> s) {
    switch (s[0]) {
    case '+':
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push(a + b);
      break;

    case '-':
      b = S.top();
      S.pop();
      a = S.top();
      S.pop();
      S.push(a - b);
      break;

    case '*':
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push(a * b);
      break;

    default:
      S.push(atoi(s.c_str()));
      break;
    }
  }

  cout << S.top() << endl;

  return 0;
}
