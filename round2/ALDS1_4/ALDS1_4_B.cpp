#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 100000;
const int MAX_Q = 50000;

int S[MAX_N];
int T[MAX_Q];

bool binarySearch(int A[], int n, int key) {
  int mid;
  int left = 0;
  int right = n;

  while (left < right) {
    mid = (left + right) / 2;
    if (A[mid] == key) {
      return true;
    } else if (A[mid] > key) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return false;
}

int main() {
  int n, q;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }

  cin >> q;

  for (int i = 0; i < q; i++) {
    int key;
    cin >> T[i];
  }

  int cnt = 0;
  for (int i = 0; i < q; i++) {
    if (binarySearch(S, n, T[i])) {
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}