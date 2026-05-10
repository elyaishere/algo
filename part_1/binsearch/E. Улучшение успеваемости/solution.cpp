#include <iostream>
using namespace std;

int main() {
  long a, b, c;
  cin >> a >> b >> c;
  long S = a * 2 + b * 3 + c * 4;
  long l = 0, r = a + b + c;
  while (l < r) {
    long m = (l + r) / 2;
    if (2 * (S + m * 5) < 7 * (a + b + c + m)) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
