#include <iostream>
using namespace std;

int main() {
  int prev, cur;
  cin >> prev;
  while (cin >> cur) {
    if (cur <= prev) {
      cout << "NO\n";
      return 0;
    }
    prev = cur;
  }
  cout << "YES\n";
  return 0;
}
