#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int M = 1046727;
const int L = 20;

string H[M];

// 文字を数値に変換
int getChar(char ch) {
  switch (ch) {
  case 'A':
    return 1;

  case 'C':
    return 2;

  case 'G':
    return 3;

  case 'T':
    return 4;

  default:
    return 0;
  }
}

// 文字列を数値に変換
int getKey(string key) {
  int sum, p, i;
  sum = 0;
  p = 1;

  for (i = 0; i < key.size(); i++) {
    sum += p * getChar(key[i]);
    p *= 5;
  }

  return sum;
}

int h1(int k) { return k % M; }

int h2(int k) { return 1 + (k % (M - 1)); }

int h(int k, int i) { return (h1(k) + i * h2(k)) % M; }

void insert(string key) {
  int i, j, k;
  i = 0;
  k = getKey(key);

  while (true) {
    j = h(k, i);
    if (H[j].empty()) {
      H[j] = key;
      return;
    } else {
      i++;
    }
  }
}

bool find(string key) {
  int i, j, k;
  i = 0;
  k = getKey(key);

  while (true) {
    j = h(k, i);
    if (H[j] == key) {
      return true;
    } else if (H[j].empty()) {
      return false;
    } else {
      i++;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    char com[10], str[L];
    scanf("%s%s", com, str);
    string s = string(str);

    if (com[0] == 'i') {
      // insert
      insert(s);
    } else if (com[0] == 'f') {
      // find
      if (find(s)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}