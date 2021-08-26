#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> A{1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
  vector<int>::iterator pos;
  int idx;

  pos = lower_bound(A.begin(), A.end(), 3);
  idx = distance(A.begin(), pos);
  cout << "A[" << idx << "] =" << *pos << endl;

  pos = lower_bound(A.begin(), A.end(), 2);
  idx = distance(A.begin(), pos);
  cout << "A[" << idx << "] =" << *pos << endl;
}