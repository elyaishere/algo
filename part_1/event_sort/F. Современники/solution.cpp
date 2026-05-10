#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<tuple<int, int, int, int, int>> dates;
  for (int i = 0; i < n; ++i) {
    int d1, d2, m1, m2, y1, y2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;
    // дожил ли до 18?
    if (y1 + 18 > y2 || (y1 + 18 == y2 && (m1 > m2 || (m1 == m2 && d1 > d2))))
      continue;
    tuple<int, int, int, int, int> day18{y1 + 18, m1, d1, 0, i + 1};
    dates.push_back(day18);
    tuple<int, int, int, int, int> last_day;
    if (y1 + 80 < y2 || (y1 + 80 == y2 && (m1 < m2 || (m1 == m2 && d1 < d2)))) {
      // 80-летие
      if (d1 == 1) {
        if (m1 == 1) {
          --y1, m1 = 12, d1 = 31;
        } else if (m1 == 3) {
          if (y1 % 4 == 0) {
            if (y1 % 100 == 0) {
              if (y1 % 400 == 0)
                d1 = 29;
              else
                d1 = 28;
            } else
              d1 = 29;
          } else
            d1 = 28;
          --m1;
        } else if (m1 == 2 || m1 == 4 || m1 == 6 || m1 == 8 || m1 == 9 ||
                   m1 == 11) {
          d1 = 31, --m1;
        } else {
          d1 = 30, --m1;
        }
      } else {
        d1--;
      }
      last_day = {y1 + 80, m1, d1, 1, i + 1};
    } else {
      // смерть
      if (d2 == 1) {
        if (m2 == 1) {
          --y2, m2 = 12, d2 = 31;
        } else if (m2 == 3) {
          if (y2 % 4 == 0) {
            if (y2 % 100 == 0) {
              if (y2 % 400 == 0)
                d2 = 29;
              else
                d2 = 28;
            } else
              d2 = 29;
          } else
            d2 = 28;
          --m2;
        } else if (m2 == 2 || m2 == 4 || m2 == 6 || m2 == 8 || m2 == 9 ||
                   m2 == 11) {
          d2 = 31, --m2;
        } else {
          d2 = 30, --m2;
        }
      } else {
        d2--;
      }
      last_day = {y2, m2, d2, 1, i + 1};
    }
    dates.push_back(last_day);
  }
  if (dates.empty()) {
    cout << 0 << endl;
    return 0;
  }
  sort(dates.begin(), dates.end());
  vector<int> prev(n + 1, 0), next(n + 1, 0);
  int beg = 0, last;
  bool f =
      false; // выводим только когда убирается человек после добавления человека
  for (auto i : dates) {
    if (get<3>(i) == 0) {
      f = true;
      if (beg == 0) {
        beg = get<4>(i);
        prev[beg] = 0;
        next[beg] = 0;
        last = beg;
      } else {
        int cur = get<4>(i);
        next[last] = cur;
        prev[cur] = last;
        next[cur] = 0;
        last = cur;
      }
    } else {
      int cur = beg;
      while (cur) {
        if (f)
          cout << cur << " ";
        if (cur == get<4>(i)) {
          if (cur == beg)
            beg = next[cur];
          else if (cur == last)
            last = prev[cur];
          prev[next[cur]] = prev[cur];
          next[prev[cur]] = next[cur];
          int tmp = next[cur];
          prev[cur] = 0, next[cur] = 0;
          cur = tmp;
        } else {
          cur = next[cur];
        }
      }
      if (f)
        cout << endl;
      f = false;
    }
  }
  return 0;
}
