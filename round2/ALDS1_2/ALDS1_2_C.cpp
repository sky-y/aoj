#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 1000;
const int MAX_STR = 1000;

struct Card {
  char suit;
  char value;
};

void trace(Card a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i].suit << a[i].value;
  }
  cout << endl;
}

void bubbleSort(Card a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= i + 1; j--) {
      if (a[j].value < a[j - 1].value) {
        // swap
        Card tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
      }
    }
  }
}

void selectionSort(Card a[], int n) {
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i + 1; j < n; j++) {
      /* code */
      if (a[j].value < a[minj].value) {
        minj = j;
      }
    }

    // swap
    Card tmp = a[minj];
    a[minj] = a[i];
    a[i] = tmp;
  }
}

bool isStable(Card c1[], Card c2[], int n) {
  for (int i = 0; i < n; i++) {
    if (c1[i].suit != c2[i].suit) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  char buf[MAX_STR];
  Card c1[MAX], c2[MAX];

  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%s", buf);
    c1[i].suit = buf[0];
    c1[i].value = buf[1];
  }

  // copy
  for (int i = 0; i < n; i++) {
    c2[i] = c1[i];
  }

  bubbleSort(c1, n);
  trace(c1, n);
  cout << "Stable" << endl;

  selectionSort(c2, n);
  trace(c2, n);
  if (isStable(c1, c2, n)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  return 0;
}