#include <iostream>
using namespace std;

const int MAX_N = 100000;
const int MAX_Q = 50000;

bool search(int A[], int n, int key) {
  int left = 0;
  int right = n;

  while (left < right) {
    int mid = (left + right) / 2;
    if (key == A[mid]) {
      return true;
    } else if (key > A[mid]) {
      left = mid + 1;
    } else if (key < A[mid]) {
      right = mid;
    }
  }

  return false;
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