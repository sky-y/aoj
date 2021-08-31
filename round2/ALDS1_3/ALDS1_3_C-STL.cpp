#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  char buf[30];
  list<int> L;

  for (int i = 0; i < n; i++) {
    scanf("%s", buf);

    if (buf[0] == 'i') {
      // insert x
      scanf("%s", buf);
      int x = atoi(buf);
      L.push_front(x);
      continue;
    }

    switch (buf[6]) {
    case 'F':
      // deleteFirst
      L.pop_front();
      break;

    case 'L':
      // deleteLast
      L.pop_back();
      break;

    default:
      // delete x
      scanf("%s", buf);
      int x = atoi(buf);
      for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        if (*it == x) {
          L.erase(it);
          break;
        }
      }
      break;
    }
  }

  int count = 0;
  for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
    if (count++) {
      printf(" ");
    }

    printf("%d", *it);
  }
  printf("\n");

  return 0;
}