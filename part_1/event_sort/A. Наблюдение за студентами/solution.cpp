#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> be;
  for (auto i = 0; i < m; ++i) {
    int b, e;
    cin >> b >> e;
    be.push_back({b, 0});
    be.push_back({e, 1});
  }
  sort(be.begin(), be.end());
  int cnt = 0;
  int num_teachers = 0;
  int r = 0;
  for (auto i : be) {
    if (i.second == 0) {
      if (num_teachers == 0) {
        cnt += (i.first - r);
      }
      ++num_teachers;
    } else {
      --num_teachers;
      if (num_teachers == 0) {
        r = i.first + 1;
      }
    }
  }
  cnt += (n - r);
  cout << cnt << endl;
  return 0;
}
