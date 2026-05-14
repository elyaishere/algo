#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  map<pair<int, int>, int> ab;
  vector<int> tch(m);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (ab.find({min(a, b), -1}) == ab.end())
      ab[{min(a, b), -1}] = 0;
    if (ab.find({max(a, b), 1}) == ab.end())
      ab[{max(a, b), 1}] = 0;
    ab[{min(a, b), -1}] += 1;
    ab[{max(a, b), 1}] -= 1;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    ab[{x, 0}] = 0;
    tch[i] = x;
  }
  int cnt = 0;
  for (auto &i : ab) {
    if (i.second != 0) {
      cnt += i.second;
    } else {
      i.second = cnt;
    }
  }
  for (auto i : tch) {
    cout << ab[{i, 0}] << " ";
  }
  return 0;
}
