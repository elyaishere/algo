#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> events;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (y - x < 5)
      continue;
    events.push_back({x, -1, i});
    events.push_back({y - 5, 1, i});
  }
  sort(events.begin(), events.end());
  if (events.empty()) {
    cout << "0 10 20" << endl;
  } else if (events.size() == 2) {
    cout << "1 " << get<0>(events[0]) << " " << get<0>(events[0]) + 10 << endl;
  } else {
    int best_ans = 0;
    int f_best = 0, s_best = 0;
    set<int> f_ad;
    for (int i = 0; i < events.size(); ++i) {
      auto ev1 = events[i];
      if (get<1>(ev1) == -1) {
        f_ad.insert(get<2>(ev1));
        if (f_ad.size() > best_ans) {
          best_ans = f_ad.size();
          f_best = get<0>(ev1);
          s_best = f_best + 5;
        }
      }
      int s_ad_cnt = 0;
      for (int j = i + 1; j < events.size(); ++j) {
        auto ev2 = events[j];
        if (get<1>(ev2) == -1 && f_ad.find(get<2>(ev2)) == f_ad.end())
          s_ad_cnt++;
        if (get<0>(ev2) - 5 >= get<0>(ev1) &&
            f_ad.size() + s_ad_cnt > best_ans) {
          best_ans = f_ad.size() + s_ad_cnt;
          f_best = get<0>(ev1);
          s_best = get<0>(ev2);
        }
        if (get<1>(ev2) == 1 && f_ad.find(get<2>(ev2)) == f_ad.end())
          s_ad_cnt--;
      }
      if (get<1>(ev1) == 1)
        f_ad.erase(get<2>(ev1));
    }
    cout << best_ans << " " << f_best << " " << s_best << endl;
  }
  return 0;
}
