#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> m(n + 1, 0);
  int t;
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    m[i] = m[i - 1] + t;
  }
  int cnt = 0;
  int l = 0, r = 0;
  while (r <= n) {
    if (m[r] - m[l] == k) {
      ++cnt, ++l, ++r;
      continue;
    }
    if (m[r] - m[l] < k) {
      ++r;
      continue;
    }
    if (m[r] - m[l] > k) {
      ++l;
      continue;
    }
  }
  cout << cnt << endl;
  return 0;
}
