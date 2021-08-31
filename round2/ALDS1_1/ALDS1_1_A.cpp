#include <iostream>
using namespace std;

const int MAX = 100000;

void trace(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;
}

void insertionSort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    trace(a, n);
  }
}

int main() {
  int n;
  int a[MAX];

  // input
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  trace(a, n);
  insertionSort(a, n);

  return 0;
}