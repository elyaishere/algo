#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, r, c;
  cin >> n >> r >> c;
  vector<long> h(n);
  for (auto &i : h)
    cin >> i;
  sort(h.begin(), h.end());
  long left = 0, right = h[n - 1] - h[0];
  while (left < right) {
    long m = (left + right) / 2;
    int i = 0, brigades = 0;
    while (i < n - c + 1) {
      if (h[i + c - 1] - h[i] <= m) {
        brigades++;
        i += c;
      } else {
        i += 1;
      }
    }
    if (brigades >= r) {
      right = m;
    } else {
      left = m + 1;
    }
  }
  cout << left << endl;
  return 0;
}
