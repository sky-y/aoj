#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Process {
  string name;
  int time;
};

queue<Process> Q;

int main() {
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    Process p;
    cin >> p.name >> p.time;
    Q.push(p);
  }

  int elasp = 0;
  while (!Q.empty()) {
    Process p = Q.front();
    Q.pop();

    int c = min(p.time, q);
    p.time -= c;
    elasp += c;
    if (p.time > 0) {
      Q.push(p);
    } else {
      cout << p.name << " " << elasp << endl;
    }
  }

  return 0;
}