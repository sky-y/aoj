#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const int M = 1046527;
const int NIL = -1;
const int L = 14;

// 長さ M のvector
vector<string> H(M);

// 文字から数値に変換
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

// 文字列から数値へ変換して key を生成する
long long getKey(string str) {
  long long sum = 0, p = 1;
  for (long long i = 0; i < str.size(); i++) {
    sum += p * getChar(str[i]);
    p *= 5;
  }
  return sum;
}

int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }

bool find(string str) {
  long long key, h;
  key = getKey(str);
  for (long long i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;

    if (H[h] == str) {
      return true;
    } else if (H[h].size() == 0) {
      return false;
    }
  }
}

bool insert(string str) {
  long long key, h;
  key = getKey(str);

  for (long long i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (H[h] == str) {
      return true;
    } else if (H[h].size() == 0) {
      H[h] = str;
      return false;
    }
  }
  return false;
}

int main() {
  int n, h;
  string str, com;
  char bufstr[L], bufcom[9];

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %s", bufcom, bufstr);
    com = string(bufcom);
    str = string(bufstr);

    if (com[0] == 'i') {
      insert(str);
    } else {
      if (find(str)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }
}