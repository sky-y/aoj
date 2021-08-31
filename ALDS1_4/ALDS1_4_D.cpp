// p.137 写経
#include <iostream>
using namespace std;

#define MAX 100000
#define MAX_W 10000
typedef long long llong;

int n; // 荷物の個数
int k; // トラックの台数
llong T[MAX];

// 最大積載量 P の k 台のトラックで何個の荷物を積めるか？
int check(llong P) {
  // 荷物の個数
  int i = 0;

  // j: トラックの番号
  for (int j = 0; j < k; j++) {
    llong s = 0;

    // 積載量がP以下である限り、荷物を順番に積んでいく
    while (s + T[i] <= P) {
      s += T[i];
      i++;
      if (i == n) {
        return n;
      }
    }
  }

  // 積載量がPを越えたら、その時点での荷物の個数を返す
  return i;
}

llong solve() {
  llong left = 0;
  llong right = MAX * MAX_W; // 荷物の個数 × 1個あたりの最大重量
  llong mid;

  while (right - left > 1) {
    mid = (left + right) / 2;
    int v = check(mid); // mid == P を決めて何個積めるかチェック
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