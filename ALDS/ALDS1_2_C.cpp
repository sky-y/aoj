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
            return false;
        }
      }
    }
  }

  // 安定な場合
  return true;
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

  print(c1, n);
  if (isStable(c1, c2, n)) {
    cout << "stable" << endl;
  } else {
    cout << "unstable" << endl;
  }

  return 0;
}