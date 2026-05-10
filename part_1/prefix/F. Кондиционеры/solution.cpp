#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  cin >> m;
  vector<pair<int, int>> bc(m);
  for (auto &i : bc)
    cin >> i.first >> i.second;
  sort(a.begin(), a.end());
  sort(bc.begin(), bc.end(), [](pair<int, int> i, pair<int, int> j) {
    return (i.second < j.second) || (i.second == j.second && i.first > j.first);
  });
  long S = 0;
  int p = 0;
  for (int i = 0; i < n; ++i) {
    if (bc[p].first < a[i]) {
      ++p;
      while (bc[p].first < a[i])
        ++p;
    }
    S += bc[p].second;
  }
  cout << S << endl;
  return 0;
}
