#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> points(n);
  for (auto &i : points)
    cin >> i.first >> i.second;
  vector<int> from_left(n, 0);
  vector<int> from_right(n, 0);
  for (int i = 1; i < n; ++i) {
    from_left[i] =
        from_left[i - 1] + max(points[i].second - points[i - 1].second, 0);
    from_right[n - i - 1] =
        from_right[n - i] +
        max(points[n - i - 1].second - points[n - i].second, 0);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;
    if (s < t) {
      cout << from_left[t - 1] - from_left[s - 1] << endl;
    } else {
      cout << from_right[t - 1] - from_right[s - 1] << endl;
    }
  }
  return 0;
}
