#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  int n, q, t;
  string name;

  queue<pair<string, int>> Q;

  cin >> n >> q;

  // 全てのプロセスをキューに順番に追加する
  for (int i = 0; i < n; i++) {
    cin >> name >> t;
    Q.push(make_pair(name, t));
  }

  pair<string, int> u;
  int elaps = 0, a;

  // シミュレーション
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();

    // q または必要な時間 u.second だけ処理を行う
    a = min(u.second, q);

    // 残りの必要時間を計算
    u.second -= a;

    // 経過時間を計算
    elaps += a;

    if (u.second > 0) {
      Q.push(u);
    } else {
      cout << u.first << " " << elaps << endl;
    }
  }

  return 0;
}