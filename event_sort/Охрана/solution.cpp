#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int k;
  cin >> k;
  vector<string> ans(k);
  for (int i = 0; i < k; ++i) {
    int n;
    cin >> n;
    vector<vector<int>> events;
    for (int j = 0; j < n; ++j) {
      int x, y;
      cin >> x >> y;
      events.push_back({x, -1, j});
      events.push_back({y, 1, j});
    }
    sort(events.begin(), events.end());
    set<int> good_seq;
    set<int> now_seq;
    bool good_flag = true;
    int prev_time = -1;
    for (auto event : events) {
      if (event[0] != 0 && now_seq.empty()) {
        good_flag = false;
        break;
      }
      if (now_seq.size() == 1 && event[0] != prev_time) {
        for (auto t : now_seq)
          good_seq.insert(t);
      }
      if (event[1] == -1)
        now_seq.insert(event[2]);
      else
        now_seq.erase(event[2]);
      prev_time = event[0];
    }
    if (events[2 * n - 1][0] != 10000)
      good_flag = false;
    if (good_flag && good_seq.size() == n) {
      ans[i] = "Accepted";
    } else {
      ans[i] = "Wrong Answer";
    }
  }
  for (auto i : ans)
    cout << i << endl;
  return 0;
}
