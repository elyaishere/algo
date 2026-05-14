#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int k1, m, k2, p2, n2;

  cin >> k1 >> m >> k2 >> p2 >> n2;

  vector<int> ans{0, 0};
  set<int> possible_p;
  set<int> possible_n;
  int n, p;
  vector<int> possible_num; // возможное количество квартир на этаже
  for (int i = 0; i < k2; ++i) {
    n = (p2 - 1) * i * m + i * (n2 - 1);
    if (k2 > n) {
      if (k2 <= n + i)
        possible_num.push_back(i);
    } else
      break;
  }
  if (k2 <= (p2 - 1) * m + n2 - 1 || (n2 != 1 && possible_num.empty()) ||
      n2 > m) {
    cout << "-1 -1\n";
    return 0;
  }
  if (k1 == k2) {
    cout << p2 << " " << n2 << endl;
    return 0;
  }
  for (auto i : possible_num) {
    p = k1 / (m * i) + 1;
    if (k1 % (m * i) == 0) {
      p -= 1;
    }
    n = (k1 - (p - 1) * m * i) / i + 1;
    if ((k1 - (p - 1) * m * i) % i == 0) {
      n -= 1;
    }
    possible_n.insert(n);
    possible_p.insert(p);
  }
  if (p2 == 1) {
    if (n2 == 1) {
      if (k1 > k2 * m) {
        ans[0] = 0;
        ans[1] = m == 1;
      } else {
        ans[0] = 1;
        ans[1] = (m == 1 || k1 < k2);
      }
      cout << ans[0] << " " << ans[1] << endl;
      return 0;
    }
    if (k1 < k2) {
      ans[0] = 1;
      if (k2 == n2) {
        ans[1] = k1;
      } else {
        ans[1] = (possible_n.size() == 1) ? *possible_n.begin() : 0;
      }
      cout << ans[0] << " " << ans[1] << endl;
      return 0;
    }
    if (k1 <= (k2 / n2 + 1) * m) {
      ans[0] = 1;
      ans[1] = (possible_n.size() == 1) ? *possible_n.begin() : 0;
      cout << ans[0] << " " << ans[1] << endl;
      return 0;
    }
  }
  ans[0] = (possible_p.size() == 1) ? *possible_p.begin() : 0;
  ans[1] = (possible_n.size() == 1) ? *possible_n.begin() : 0;
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
