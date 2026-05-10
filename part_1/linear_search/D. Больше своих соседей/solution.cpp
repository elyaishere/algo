#include <iostream>
using namespace std;

int main() {
  int left, mid, right;
  cin >> left >> mid;
  int cnt = 0;
  while (cin >> right) {
    if (mid > left && mid > right)
      ++cnt;
    left = mid;
    mid = right;
  }
  cout << cnt << endl;
  return 0;
}
