#include <iostream>
#include <string>
using namespace std;

int n;
int A[50];

// 入力値の M から選んだ要素を引いていく再帰関数
bool solve(int i, int m) {
  if (m == 0) {
    return true;
  }

  if (i >= n) {
    return false;
  }

  bool res = solve(i + 1, m) || solve(i + 1, m - A[i]);
  return res;
}

int main() {
  int q, M;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> M;
    if (solve(0, M)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}