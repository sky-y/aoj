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

int selectionSort(int a[], int n) {
  int count = 0;

  for (int i = 0; i < n - 1; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }

    // swap
    int tmp = a[minj];
    a[minj] = a[i];
    a[i] = tmp;

    if (i != minj) {
      count++;
    }
  }

  return count;
}

int main() {
  int n;
  int a[MAX];

  // input
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int count;
  count = selectionSort(a, n);
  trace(a, n);
  cout << count << endl;

  return 0;
}