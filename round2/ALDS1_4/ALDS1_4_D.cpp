#include <iostream>
using namespace std;

const int MAX = 100000;
typedef long long llong;

int n, k;
llong T[MAX];

// 最大積載量 P の k 台のトラックで何個の荷物を積めるか？
int check(llong P) {
  int i = 0;
  for (int j = 0; j < k; j++) {
    llong sum = 0;
    while (sum + T[i] <= P) {
      sum += T[i];
      i++;
      if (i == n) {
        return n;
      }
    }
  }

  return i;
}

llong solve() {
  llong left = 0;
  llong right = 100000 * 10000;
  llong mid;

  while (right - left > 1) {
    mid = (left + right) / 2;
    int v = check(mid);
    if (v >= n) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return right;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> T[i];
  }

  llong ans = solve();
  cout << ans << endl;

  return 0;
}