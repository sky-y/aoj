// 番兵を使ったバージョン
#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 10010;
const int MAX_Q = 510;

int S[MAX_N];
int T[MAX_Q];

bool search(int A[], int n, int key) {
  int i = 0;
  A[n] = key;
  while (A[i] != key) {
    i++;
  }

  return i != n;
}

int main() {
  int n, q;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }

  cin >> q;

  for (int i = 0; i < q; i++) {
    cin >> T[i];
  }

  int count = 0;

  for (int j = 0; j < q; j++) {
    if (search(S, n, T[j])) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}