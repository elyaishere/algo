#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, r;
  cin >> n >> r;
  vector<int> d(n);
  for (auto &i : d)
    cin >> i;
  long cnt = 0;
  int left = 0, right = 1;
  while (right < n) {
    if (d[right] - d[left] <= r) {
      ++right;
    } else {
      cnt += n - right;
      ++left;
    }
  }
  cout << cnt << endl;
  return 0;
}
