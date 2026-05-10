#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> minutes(24 * 60, 0);
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a = 60 * a + b;
    c = 60 * c + d;
    if (a >= c) {
      for (int i = a; i < 24 * 60; ++i)
        minutes[i]++;
      for (int i = 0; i < c; ++i)
        minutes[i]++;
    } else {
      for (int i = a; i < c; ++i)
        minutes[i]++;
    }
  }
  int res = 0;
  for (auto i : minutes)
    res += (i == n);
  cout << res << endl;
  return 0;
}
