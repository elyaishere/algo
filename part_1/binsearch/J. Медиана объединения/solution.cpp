#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<vector<int>> ch(n, vector<int>(l));
  for (int i = 0; i < n; ++i)
    for (auto &j : ch[i])
      cin >> j;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int a = 0, b = 0, cnt = 1;
      int cur;
      if (ch[i][0] < ch[j][0]) {
        cur = ch[i][0];
        ++a;
      } else {
        cur = ch[j][0];
        ++b;
      }
      while (cnt < l) {
        if (a < l && b < l) {
          if (ch[i][a] < ch[j][b]) {
            cur = ch[i][a];
            ++a;
          } else {
            cur = ch[j][b];
            ++b;
          }
        } else if (a < l) {
          cur = ch[i][a + l - cnt - 1];
          break;
        } else {
          cur = ch[j][b + l - cnt - 1];
          break;
        }
        ++cnt;
      }
      cout << cur << endl;
    }
  }
  return 0;
}
