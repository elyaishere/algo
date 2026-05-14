#include <iostream>
using namespace std;

int main() {
  long n;
  int x, y;
  cin >> n >> x >> y;
  int t = min(x, y);
  long l = 0, r = min(x, y) * (n - 1);
  while (l < r) {
    long m = (l + r) / 2;
    if (long(m / x) + long(m / y) < n - 1) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  cout << l + t << endl;
  return 0;
}
