#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 500000;
const int INFTY = 2000000000;
int S[MAX];
int times;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  int L[MAX], R[MAX];
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  L[n1] = INFTY;
  R[n2] = INFTY;

  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    times++;
    if (L[i] < R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  times = 0;

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  mergeSort(S, 0, n);

  int c = 0;
  for (int i = 0; i < n; i++) {
    if (c++) {
      printf(" ");
    }
    printf("%d", S[i]);
  }
  printf("\n");

  printf("%d\n", times);

  return 0;
}