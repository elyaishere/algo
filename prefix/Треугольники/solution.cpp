#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> points(n);
  for (auto &i : points)
    cin >> i.first >> i.second;
  long ans = 0;
  for (int i = 0; i < n; ++i) {
    set<pair<long, long>> used_vectors;
    vector<long> neig;
    for (int j = 0; j < n; ++j) {
      long vec_x = points[i].first - points[j].first;
      long vec_y = points[i].second - points[j].second;
      long vec_len = vec_x * vec_x + vec_y * vec_y;
      neig.push_back(vec_len);
      if (used_vectors.find({vec_x, vec_y}) != used_vectors.end())
        --ans;
      used_vectors.insert({-vec_x, -vec_y});
    }
    sort(neig.begin(), neig.end());
    long r = 0;
    for (int l = 0; l < neig.size(); ++l) {
      while (r < neig.size() && neig[l] == neig[r]) {
        ++r;
      }
      ans += r - l - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
