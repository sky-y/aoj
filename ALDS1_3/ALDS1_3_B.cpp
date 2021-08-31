#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_QUEUE = 100100;
const int MAX_INPUT = 100000;
const int MAX_NAME = 10;

struct Process {
  char name[MAX_NAME];
  int time;
};

Process Q[MAX_QUEUE];

int head;
int tail;

void enqueue(Process x) {
  Q[tail] = x;
  tail = (tail + 1) % MAX_QUEUE;
}

Process dequeue() {
  Process x = Q[head];
  head = (head + 1) % MAX_QUEUE;
  return x;
}

bool isEmpty() { return (head == tail); }

bool isFull() { return (head == (tail + 1) % MAX_QUEUE); }

int main() {
  int elaps = 0;

  int n, q;
  scanf("%d%d", &n, &q);

  for (int i = 0; i < n; i++) {
    char bufName[MAX_NAME];
    scanf("%s%d", Q[i].name, &Q[i].time);
  }

  // initialize
  head = 0;
  tail = n;

  while (!isEmpty()) {
    Process p = dequeue();

    // 必要時間 p.time または q だけ処理を行う
    int consume = min(p.time, q);

    // 残りの必要時間
    p.time -= consume;

    // 経過時間
    elaps += consume;

    if (p.time > 0) {
      enqueue(p);
    } else {
      printf("%s %d\n", p.name, elaps);
    }
  }
}