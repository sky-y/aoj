// ALDS1_2_D: Shell Sort
// p.75 写経
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;

// 間隔gを指定した挿入ソート
void insertionSort(int A[], int n, int g) {
  for (int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;

    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void shellSort(int A[], int n) {
  // 数列G = {1, 4 , 13, 40, 121, 364, 1093, ...}を生成
  for (int h = 1;;) {
    if (h > n) {
      break;
    }

    G.push_back(h);
    h = 3 * h + 1;
  }

  // 逆順にG[i] = gを指定
  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(A, n, G[i]);
  }
}

int main() {
  cin >> n;

  // より速い入力scanf関数を使用
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  cnt = 0;
  shellSort(A, n);

  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--) {
    printf("%d", G[i]);
    if (i) {
      printf(" ");
    }
  }
  printf("\n");
  printf("%lld\n", cnt);
  for (int i = 0; i < n; i++) {
    printf("%d\n", A[i]);
  }

  return 0;
}