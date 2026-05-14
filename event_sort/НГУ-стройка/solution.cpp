#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, w, l;
  cin >> n >> w >> l;
  vector<vector<int>> blocks;
  for (int i = 0; i < n; ++i) {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    int s = abs(x2 - x1) * abs(y1 - y2);
    blocks.push_back({z1, 1, s, i});
    blocks.push_back({z2, -1, s, i});
  }
  set<int> cur_cubes;
  set<int> best_cubes;
  int S = 0, S0 = w * l;
  sort(blocks.begin(), blocks.end());
  for (auto i : blocks) {
    if (i[1] == 1) {
      S += i[2];
      cur_cubes.insert(i[3]);
    } else {
      if (S == S0) {
        if (best_cubes.empty() || best_cubes.size() > cur_cubes.size())
          best_cubes = cur_cubes;
      }
      S -= i[2];
      cur_cubes.erase(i[3]);
    }
  }
  if (best_cubes.empty()) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << best_cubes.size() << endl;
    for (auto i : best_cubes)
      cout << i + 1 << endl;
  }
  return 0;
}
