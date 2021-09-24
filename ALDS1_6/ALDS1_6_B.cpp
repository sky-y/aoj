#include <iostream>
#include <string>
using namespace std;

const int MAX = 100000;

void swap(int A[], int i, int j) {
  int tmp;
  tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

int partition(int A[], int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      swap(A, i, j);
    }
  }
  swap(A, i + 1, r);
  return i + 1;
}

int main() {
  int n;
  int A[MAX];

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int result = partition(A, 0, n - 1);

  int c = 0;
  for (int i = 0; i < n; i++) {
    if (c++) {
      cout << " ";
    }
    if (i == result) {
      cout << "[" << A[i] << "]";
    } else {
      cout << A[i];
    }
  }
  cout << endl;

  return 0;
}