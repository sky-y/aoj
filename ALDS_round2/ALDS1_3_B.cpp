#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100005;

struct Process {
  string name;
  int time;
};

Process Q[MAX];
int head, tail;

void init() { head = tail = 0; }

void enqueue(Process p) {
  Q[tail] = p;
  tail = (tail + 1) % MAX;
}

bool isEmpty() { return head == tail; }

Process dequeue() {
  Process p;
  p = Q[head];
  head = (head + 1) % MAX;
  return p;
}

int main() {
  int n, q;
  cin >> n >> q;

  init();

  for (int i = 0; i < n; i++) {
    Process p;
    cin >> p.name >> p.time;
    enqueue(p);
  }

  int elasp = 0;

  while (!isEmpty()) {
    Process p = dequeue();
    int c = min(p.time, q);
    p.time -= c;
    elasp += c;
    if (p.time > 0) {
      enqueue(p);
    } else {
      cout << p.name << " " << elasp << endl;
    }
  }

  return 0;
}