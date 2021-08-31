#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
  int key;
  Node *next;
  Node *prev;
};

Node *nil;

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

Node *listSearch(int key) {
  Node *cur = nil->next;
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }

  return cur;
}

void printList() {
  Node *cur = nil->next;
  int count;

  while (true) {
    if (cur == nil) {
      break;
    }

    // 2回目以降のみ空白を入れる
    if (count++ > 0) {
      printf(" ");
    }

    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
}

void insertKey(int key) {
  Node *x = (Node *)malloc(sizeof(Node));

  x->key = key;

  // 番兵の直後に要素を追加
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

void deleteNode(Node *t) {
  // t が番兵の場合は処理しない
  if (t == nil)
    return;

  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() { deleteNode(nil->next); }

void deleteLast() { deleteNode(nil->prev); }

void deleteKey(int key) { deleteNode(listSearch(key)); }

int main() {
  char command[20];

  int n;
  scanf("%d", &n);

  init();

  for (int i = 0; i < n; i++) {
    int k;

    scanf("%s%d", command, &k);

    // insert x
    if (command[0] == 'i') {
      insertKey(k);
      continue;
    }

    // どのコマンドでもない
    if (command[0] != 'd') {
      continue;
    }

    // delete系
    if (strlen(command) > 6) {
      if (command[6] == 'F') {
        // deleteFirst
        deleteFirst();
      } else if (command[6] == 'L') {
        // deleteLast
        deleteLast();
      }
    } else {
      // delete
      deleteKey(k);
    }
  }

  printList();

  return 0;
}