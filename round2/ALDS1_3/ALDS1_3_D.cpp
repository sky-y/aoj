#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
  char ch;

  // 「\」の位置を表す整数を格納する
  stack<int> S1;

  // 各水たまりについて (最も左の「\」の位置, その時点の面積) を格納する
  stack<pair<int, int>> S2;

  int sum = 0;
  for (int i = 0; cin >> ch; i++) {
    if (ch == '\\') {
      S1.push(i);
    } else if (ch == '/' && S1.size() > 0) {
      int j = S1.top();
      S1.pop();
      sum += i - j;

      // 新しくできる面積
      int a = i - j;

      // 新しい面積に、jの直前までの面積の総和を追加する
      while (S2.size() > 0 && S2.top().first > j) {
        a += S2.top().second;
        S2.pop();
      }
      S2.push(make_pair(j, a));
    }
  }

  vector<int> ans;
  while (S2.size() > 0) {
    ans.push_back(S2.top().second);
    S2.pop();
  }

  reverse(ans.begin(), ans.end());

  cout << sum << endl;
  cout << ans.size();

  for (int i = 0; i < ans.size(); i++) {
    cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}