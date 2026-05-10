#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> m >> n;
  vector<int> balls(n, 0);
  vector<vector<int>> volunteers(n, vector<int>(6));
  for (int i = 0; i < n; ++i) {
    int t, z, y;
    cin >> t >> z >> y;
    volunteers[i] = {t, t, z, y, 0, i};
  }
  sort(volunteers.begin(), volunteers.end());
  int cnt = 0, total = 0;
  while (cnt < m) {
    int min_time = volunteers[0][0];
    total += min_time;
    for (int i = 0; i < n; ++i) {
      volunteers[i][0] -= min_time;
      if (volunteers[i][0] == 0) {
        volunteers[i][4]++;
        balls[volunteers[i][5]]++;
        cnt++;
        if (cnt == m)
          break;
        if (volunteers[i][4] == volunteers[i][2]) {
          volunteers[i][0] = volunteers[i][1] + volunteers[i][3];
          volunteers[i][4] = 0;
        } else {
          volunteers[i][0] = volunteers[i][1];
        }
      }
      if (volunteers[i][0] < volunteers[0][0]) {
        swap(volunteers[0], volunteers[i]);
      }
    }
  }
  cout << total << endl;
  for (auto i : balls)
    cout << i << " ";
  cout << endl;
  return 0;
}
