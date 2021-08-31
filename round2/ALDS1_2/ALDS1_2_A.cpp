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

void bubbleSort(int a[], int n) {
  bool isSwapped = true;
  int count = 0;

  for (int i = 0; i < n && isSwapped; i++) {
    isSwapped = false;
    for (int j = n - 1; j >= i + 1; j--) {
      if (a[j - 1] > a[j]) {
        // swap
        int tmp = a[j - 1];
        a[j - 1] = a[j];
        a[j] = tmp;

        isSwapped = true;
        count++;
      }
    }
  }
  trace(a, n);
  cout << count << endl;
}

int main() {
  int n;
  int a[MAX];

  // input
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  bubbleSort(a, n);

  return 0;
}