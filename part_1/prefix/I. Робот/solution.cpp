#include <iostream>
#include <string>
using namespace std;

int main() {
  int k;
  string s;
  cin >> k;
  cin >> s;
  int n = s.size();
  int prevlen = 0;
  long ans = 0;
  for (int i = k; i < n; ++i) {
    if (s[i] == s[i - k])
      prevlen++, ans += prevlen;
    else
      prevlen = 0;
  }
  cout << ans << endl;
  return 0;
}
