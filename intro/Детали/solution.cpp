#include <iostream>
using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  if (m > k || k > n) {
    cout << 0 << endl;
    return 0;
  }
  int ost_zagotovki = k % m;
  int cnt_detail = k / m;
  int ans = 0;
  while (n >= k) {
    int cnt_zagotovki = n / k;
    ans += cnt_detail * cnt_zagotovki;
    n = n % k + ost_zagotovki * cnt_zagotovki;
  }
  cout << ans << endl;
  return 0;
}
