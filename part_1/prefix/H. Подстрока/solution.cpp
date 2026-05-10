#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  int left = 0, right = 0;
  int max_len = 0;
  int first_sym = left;
  map<char, int> sym_stat;
  while (right < n) {
    if (sym_stat.find(str[right]) == sym_stat.end())
      sym_stat[str[right]] = 0;
    if (sym_stat[str[right]] + 1 > k) {
      if (right - left > max_len) {
        max_len = right - left;
        first_sym = left;
      }
      while (str[left] != str[right]) {
        sym_stat[str[left]]--;
        ++left;
      }
      ++left;
    } else
      ++sym_stat[str[right]];
    ++right;
  }
  if (right - left > max_len) {
    max_len = right - left;
    first_sym = left;
  }
  cout << max_len << " " << first_sym + 1 << endl;
  return 0;
}
