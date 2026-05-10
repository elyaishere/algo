#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int g, s;
  cin >> g >> s;
  string str;
  cin >> str;
  vector<int> W(150, 0);
  for (auto i : str) {
    W[i] += 1;
  }
  cin >> str;
  int cnt = 0;
  vector<int> W_t(150, 0);
  for (int j = 0; j < g; ++j)
    W_t[str[j]] += 1;
  if (W == W_t)
    ++cnt;
  for (int j = g; j < s; ++j) {
    W_t[str[j - g]] -= 1;
    W_t[str[j]] += 1;
    if (W == W_t)
      ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
