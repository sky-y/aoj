#include <iostream>
using namespace std;

const int MAX_N = 10000;
const int MAX_Q = 500;

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
    for (int j = 0; j < n; j++) {
      if (S[j] == T[i]) {
        count++;
        break;
      }
    }
  }

  cout << count << endl;

  return 0;
}