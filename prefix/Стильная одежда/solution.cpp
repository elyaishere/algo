#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> tops(n);
  for (auto &i : tops)
    cin >> i;
  int m;
  cin >> m;
  vector<int> pants(m);
  for (auto &i : pants)
    cin >> i;
  int p1 = 0, p2 = 0;
  int diff = tops[p1] - pants[p2];
  int ans = abs(diff), a1 = p1, a2 = p2;
  while (p1 < n && p2 < m) {
    if (abs(diff) < ans) {
      ans = abs(diff);
      a1 = p1, a2 = p2;
    }
    if (ans == 0)
      break;
    if (diff < 0) {
      ++p1;
      diff = tops[p1] - pants[p2];
    } else if (diff > 0) {
      ++p2;
      diff = tops[p1] - pants[p2];
    }
  }
  cout << tops[a1] << " " << pants[a2] << endl;
  return 0;
}
