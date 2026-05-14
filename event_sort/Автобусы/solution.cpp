#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int make_minutes(string time) {
  int h = 0, m = 0;
  int i = 0;
  while (time[i] != ':') {
    h = 10 * h + (time[i] - '0');
    ++i;
  }
  ++i;
  while (i < time.size()) {
    m = 10 * m + (time[i] - '0');
    ++i;
  }
  return h * 60 + m;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cnt_buses(n + 1, 0);
  vector<int> bus_balance(n + 1, 0);
  vector<vector<int>> events;
  int overnight = 0;
  for (int i = 0; i < m; ++i) {
    int cdep, carr;
    string s_deptime, s_arrtime;
    cin >> cdep >> s_deptime >> carr >> s_arrtime;
    int deptime = make_minutes(s_deptime), arrtime = make_minutes(s_arrtime);
    if (arrtime < deptime)
      overnight++;
    bus_balance[cdep]--;
    bus_balance[carr]++;
    events.push_back({deptime, 1, cdep});
    events.push_back({arrtime, -1, carr});
  }
  bool disbalance = false;
  for (int i = 0; i < n + 1; ++i) {
    if (bus_balance[i] != 0)
      disbalance = true;
  }
  if (disbalance) {
    cout << -1 << endl;
  } else {
    sort(events.begin(), events.end());
    for (auto event : events) {
      if (event[1] == -1)
        cnt_buses[event[2]]++;
      else if (cnt_buses[event[2]] > 0)
        cnt_buses[event[2]]--;
    }
    int ans = 0;
    for (int i = 0; i < n + 1; ++i)
      ans += cnt_buses[i];
    cout << ans + overnight << endl;
  }
  return 0;
}
