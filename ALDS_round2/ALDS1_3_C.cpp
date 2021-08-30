#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int LEN = 30;

struct Node {
  int key;
  Node *next;
  Node *prev;
};

// 番兵
Node *nil;

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

Node *search(int key) {
  Node *t;
  t = nil->next;

  while (t != nil && t->key != key) {
    t = t->next;
  }

  return t;
}

void insert(int k) {
  Node *t = (Node *)malloc(sizeof(Node));
  t->key = k;

  // nil の次のノードと接続
  t->next = nil->next;
  nil->next->prev = t;

  // nil と接続
  nil->next = t;
  t->prev = nil;
}

void deleteNode(Node *t) {
  if (t == nil) {
    return;
  }

  // t の前後のノードとの接続を解除
  t->next->prev = t->prev;
  t->prev->next = t->next;

  free(t);
}

void deleteKey(int k) { deleteNode(search(k)); }

void deleteFirst() { deleteNode(nil->next); }

void deleteLast() { deleteNode(nil->prev); }

void printList() {
  Node *t = nil->next;
  int count;

  while (t != nil) {
    if (count++ > 0) {
      printf(" ");
    }
    printf("%d", t->key);
    t = t->next;
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);

  init();

  for (int i = 0; i < n; i++) {
    char c[LEN];
    int key;
    scanf("%s", c);

    if (c[0] == 'i') {
      // insert x
      scanf("%s", c);
      key = atoi(c);
      insert(key);
    } else {
      if (c[6] == 'F') {
        // deleteFirst
        deleteFirst();
      } else if (c[6] == 'L') {
        // deleteLast
        deleteLast();
      } else {
        // delete x
        scanf("%s", c);
        key = atoi(c);
        deleteKey(key);
      }
    }
  }

  printList();

  return 0;
}