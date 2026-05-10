#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

string lower(const string &s) {
  string ans;
  for (auto i : s) {
    if (isupper(i))
      ans += tolower(i);
    else
      ans += i;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  map<string, set<string>> dict;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    string t_s = lower(s);
    if (dict.find(t_s) == dict.end()) {
      dict[t_s] = {};
    }
    dict[t_s].insert(s);
  }
  int ans = 0;
  while (cin >> s) {
    string t_s = lower(s);
    if (dict.find(t_s) != dict.end()) {
      if (dict[t_s].find(s) == dict[t_s].end())
        ans++;
    } else {
      int stresses = 0;
      for (auto i : s) {
        if (isupper(i))
          ++stresses;
      }
      if (stresses != 1)
        ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
