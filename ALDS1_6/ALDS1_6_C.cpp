#include <iostream>
#include <string>
using namespace std;

struct Card {
  char suit;
  int value;
};

const int MAX = 100000;
const int INFTY = 2000000000;

Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void swap(Card A[], int i, int j) {
  Card tmp;
  tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

void merge(Card A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  L[n1].value = INFTY;
  R[n2].value = INFTY;

  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (L[i].value < R[j].value) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(Card A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int partition(Card A[], int p, int r) {
  Card x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j].value <= x.value) {
      i++;
      swap(A, i, j);
    }
  }
  swap(A, i + 1, r);
  return i + 1;
}

void quickSort(Card A[], int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int main() {
  Card A[MAX], B[MAX];

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    char s;
    int v;
    cin >> s >> v;

    A[i].suit = s;
    B[i].suit = s;
    A[i].value = v;
    B[i].value = v;
  }

  mergeSort(A, 0, n);
  quickSort(B, 0, n - 1);

  bool stable = true;
  for (int i = 0; i < n; i++) {
    if (A[i].suit != B[i].suit) {
      cout << "A: " << A[i].suit << " " << A[i].value << endl;
      cout << "B: " << B[i].suit << " " << B[i].value << endl;
      stable = false;
    }
  }

  if (stable) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  int c = 0;
  for (int i = 0; i < n; i++) {
    cout << B[i].suit << " " << B[i].value << endl;
  }

  return 0;
}