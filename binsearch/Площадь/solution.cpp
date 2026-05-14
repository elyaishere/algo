#include <iostream>
using namespace std;

int main() {
  long n, m;
  cin >> n >> m;
  long long t;
  cin >> t;
  long long l = 0, r = min(n / 2, m / 2);
  while (l < r) {
    long long mid = (l + r + 1) / 2;
    auto tmp = mid * n * 2 + (m - 2 * mid) * mid * 2;
    if (tmp == t) {
      cout << mid << endl;
      return 0;
    }
    if (tmp < t) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
