#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX = 1000000;

int A[MAX], n;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  int q, k, sum = 0;
  cin >> q;
  for (int i = 0; i < q; i++) {
    scanf("%d", &k);
    int *pos = lower_bound(A, A + n, k);
    if (*pos == k) {
      sum++;
    }
  }

  cout << sum << endl;
}