// p.116 写経
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
  // 全体の総合面積（最初の出力）を求めるスタック
  stack<int> S1;

  // 各水たまりの面積を求めるスタック
  stack<pair<int, int>> S2;

  char ch;
  int sum = 0;

  for (int i = 0; cin >> ch; i++) {
    if (ch == '\\') {
      // 文字が \ ならば、その位置を表す整数 i をスタック S1 に積む
      S1.push(i);
    } else if (ch == '/' && S1.size() > 0) {
      // 文字が / ならば、スタックS1のトップから
      // 対応する \ の位置 j を取り出す
      int j = S1.top();
      S1.pop();

      // 現在の位置との距離 i - j を総面積に加算する
      sum += i - j;

      // 新しくできる面積 i - j
      int a = i - j;

      // 上記に、S2 に積まれている、j の直前までの水たまりの面積の総和を足す
      while (S2.size() > 0 && S2.top().first > j) {
        a += S2.top().second;
        S2.pop();
      }

      // その水たまりの最も左の / の位置と、その水たまりのその時点での面積の組
      S2.push(make_pair(j, a));
    }
  }

  vector<int> ans;

  // 各水たまりの面積を ans に入れる
  while (S2.size() > 0) {
    ans.push_back(S2.top().second);
    S2.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << sum << endl;

  // 水たまりの数を出力
  cout << ans.size();

  // 各水たまりの面積を出力
  for (int i = 0; i < ans.size(); i++) {
    cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
