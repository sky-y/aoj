// 番兵を使ったバージョン
#include <iostream>
using namespace std;

const int MAX_N = 10001;
const int MAX_Q = 500;

bool search(int A[], int n, int key) {
  // 番兵をセットする
  A[n] = key;

  int i = 0;
  while (A[i] != key) {
    i++;
  }

  return i != n;
}

int main() {
  int n;
  int S[MAX_N];
  int q;
  int T[MAX_Q];

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }

  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> T[i];
  }

  // 探索
  int count = 0;
  for (int i = 0; i < q; i++) {
    bool found = search(S, n, T[i]);
    if (found) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}