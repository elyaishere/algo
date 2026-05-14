#include <iostream>
#include <vector>
using namespace std;

int n, l;

int cnt_less(const vector<int> &seq, int x) {
  int left = 0, right = l - 1;
  while (left < right) {
    int m = (left + right) / 2;
    if (seq[m] >= x) {
      right = m;
    } else {
      left = m + 1;
    }
  }
  if (seq[left] < x) {
    return l;
  }
  return left;
}

int cnt_gt(const vector<int> &seq, int x) { return l - cnt_less(seq, x + 1); }

int main() {
  cin >> n >> l;
  vector<vector<int>> seqs(n, vector<int>(l));
  for (int i = 0; i < n; ++i) {
    int x, d, a, c, m;
    cin >> x >> d >> a >> c >> m;
    seqs[i][0] = x;
    for (int j = 1; j < l; ++j) {
      seqs[i][j] = seqs[i][j - 1] + d;
      d = (a * d + c) % m;
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int left = min(seqs[i][0], seqs[j][0]);
      int right = max(seqs[i][l - 1], seqs[j][l - 1]);
      while (left < right) {
        int m = (left + right) / 2;
        int less = cnt_less(seqs[i], m) + cnt_less(seqs[j], m);
        int gt = cnt_gt(seqs[i], m) + cnt_gt(seqs[j], m);
        if (less <= l - 1 && gt <= l) {
          left = m;
          break;
        }
        if (gt > l)
          left = m + 1;
        if (less > l - 1)
          right = m - 1;
      }
      cout << left << endl;
    }
  return 0;
}
