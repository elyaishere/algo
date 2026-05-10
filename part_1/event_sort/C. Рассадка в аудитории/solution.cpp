#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> x(n);
  map<pair<int, int>, int> Ox;
  set<int> not_used;
  for (int i = 1; i <= n; ++i)
    not_used.insert(i);
  for (int i = 0; i < n; ++i) {
    int xi;
    cin >> xi;
    x[i] = xi;
    Ox[{xi, 0}] = 0;
    Ox[{xi + d, 1}] = 0;
  }
  int max_cnt = 0;
  for (auto &i : Ox) {
    if (i.first.second == 0) {
      i.second = *not_used.begin();
      not_used.erase(i.second);
      int cnt = n - not_used.size();
      max_cnt = max(cnt, max_cnt);
    } else if (i.first.second == 1) {
      not_used.insert(Ox[{i.first.first - d, 0}]);
    }
  }
  cout << max_cnt << endl;
  for (auto i : x)
    cout << Ox[{i, 0}] << " ";
  return 0;
}
