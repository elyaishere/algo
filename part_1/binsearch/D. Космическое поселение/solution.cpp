#include <iostream>
using namespace std;

int main() {
  long n, a, b, w, h;
  cin >> n >> a >> b >> w >> h;
  long l = 0, r = 1000000000000000000;
  while (l < r - 1) {
    long m = (l + r) / 2;
    long t = max((w / (a + 2 * m)) * (h / (b + 2 * m)),
                 (w / (b + 2 * m)) * (h / (a + 2 * m)));
    if (t >= n) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
