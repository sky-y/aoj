#include <iostream>
#include <list>
using namespace std;

int main() {
  list<char> l;

  l.push_front('b'); // [b]
  l.push_back('c');  // [bc]
  l.push_front('a'); // [abc]

  cout << l.front(); // a
  cout << l.back();  // c

  l.pop_front();    // [bc]
  l.push_back('d'); // [bcd]

  cout << l.front();        // b
  cout << l.back() << endl; // d

  return 0;
}