// ALDS1_2_C: Stable Sort
#include <iostream>
using namespace std;

const int MAX = 100;

struct Card {
  char suit;
  char value;
};

void print(struct Card a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }

    cout << a[i].suit << a[i].value;
  }
  cout << endl;
}

bool isStable(Card in[], Card out[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
          if (in[i].value == in[i].value && in[i].suit == out[b].suit &&
              in[i].value == out[b].value && in[j].suit == out[a].suit &&
              in[j].value == out[a].value)
            // 安定でない場合
            return false;
        }
      }
    }
  }

  // 安定な場合
  return true;
}

void bubbleSort(Card c[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (c[j].value < c[j - 1].value) {
        // swap
        Card tmp;
        tmp = c[j];
        c[j] = c[j - 1];
        c[j - 1] = tmp;
      }
    }
  }
}

void selectionSort(Card c[], int n) {
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (c[j].value < c[minj].value) {
        minj = j;
      }
    }

    // swap
    Card tmp;
    tmp = c[i];
    c[i] = c[minj];
    c[minj] = tmp;
  }
}

int main() {
  Card c1[MAX], c2[MAX];
  int n;
  char c;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c1[i].suit >> c1[i].value;
  }

  // 配列をコピー
  for (int i = 0; i < n; i++) {
    c2[i] = c1[i];
  }

  bubbleSort(c1, n);
  print(c1, n);
  cout << "Stable" << endl;

  selectionSort(c2, n);
  print(c2, n);
  if (isStable(c1, c2, n)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  return 0;
}