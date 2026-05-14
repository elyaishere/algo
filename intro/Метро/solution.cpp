#include <iostream>
using namespace std;

int main() {
  int a, b, n, m;
  cin >> a >> b >> n >> m;
  int max_t_1 = n + (n + 1) * a, max_t_2 = m + (m + 1) * b;
  int ans_1 = max(max_t_1 - 2 * a, max_t_2 - 2 * b),
      ans_2 = min(max_t_1, max_t_2);
  if (ans_1 <= ans_2) {
    cout << ans_1 << " " << ans_2 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
