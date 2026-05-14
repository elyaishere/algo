#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long n, k;
  cin >> n >> k;
  vector<long> l(n);
  long long len = 0;
  for (auto &i : l)
    cin >> i, len += i;
  if (len < k) {
    cout << 0 << endl;
    return 0;
  }
  sort(l.begin(), l.end());
  long left = 1, right = l[n - 1];
  long ans = 0;
  while (left <= right) {
    long mid = (left + right) / 2;
    long cnt = 0, j = n - 1;
    while (j >= 0 && l[j] >= mid) {
      cnt += l[j] / mid;
      --j;
    }
    if (cnt < k) {
      right = mid - 1;
    } else {
      left = mid + 1;
      ans = max(ans, mid);
    }
  }
  cout << ans << endl;
  return 0;
}
