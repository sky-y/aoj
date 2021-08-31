#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 100000;
const int MAX_Q = 50000;

vector<int> S(MAX_N), T(MAX_Q);

int main() {
  int n, q;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);

  int sum = 0;
  for (int i = 0; i < q; i++) {
    int k;
    scanf("%d", &k);
    if (*lower_bound(S.begin(), S.begin() + n, k) == k) {
      sum++;
    }
  }

  cout << sum << endl;

  return 0;
}