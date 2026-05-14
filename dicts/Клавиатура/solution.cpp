#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, p;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i)
    cin >> c[i];
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> p;
    c[p - 1] -= 1;
  }
  for (auto i : c) {
    (i < 0) ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
