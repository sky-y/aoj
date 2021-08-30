#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string s;
  stack<int> S;

  while (cin >> s) {
    int a, b;
    switch (s[0]) {
    case '+':
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push(a + b);
      break;

    case '-':
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push(b - a);
      break;

    case '*':
      a = S.top();
      S.pop();
      b = S.top();
      S.pop();
      S.push(a * b);
      break;

    default:
      S.push(stoi(s));
      break;
    }
  }
  cout << S.top() << endl;
  return 0;
}