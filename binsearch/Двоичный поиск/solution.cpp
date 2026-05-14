#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < k; ++i) {
    int x;
    int left = 0, right = n - 1;
    cin >> x;
    bool found = false;
    while (left < right) {
      int m = (left + right) / 2;
      if (arr[m] == x) {
        found = true;
        break;
      }
      if (arr[m] < x) {
        left = m + 1;
      } else {
        right = m;
      }
    }
    if (found || arr[left] == x)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
