#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> d(n);
  for (auto &i : d)
    cin >> i;
  map<int, int> types;
  int left = 0;
  int res_l = 0, res_r = n;
  for (int right = 0; right < n; ++right) {
    if (types.find(d[right]) == types.end())
      types[d[right]] = 0;
    types[d[right]] += 1;
    if (types.size() == k) {
      while (types[d[left]] > 1) {
        types[d[left]] -= 1;
        ++left;
      }
      if (right - left < res_r - res_l) {
        res_r = right;
        res_l = left;
      }
    }
  }
  cout << res_l + 1 << " " << res_r + 1 << endl;
  return 0;
}
