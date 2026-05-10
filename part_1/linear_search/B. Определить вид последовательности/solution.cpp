#include <iostream>
#include <string>
using namespace std;

int main() {
  int prev, cur;
  cin >> prev >> cur;
  string ans = "NONE";
  while (cur != -2000000000 && ans != "RANDOM") {
    if (cur == prev) {
      if (ans == "ASCENDING") {
        ans = "WEAKLY ASCENDING";
      } else if (ans == "DESCENDING") {
        ans = "WEAKLY DESCENDING";
      } else if (ans == "NONE") {
        ans = "CONSTANT";
      }
    } else if (prev < cur) {
      if (ans == "CONSTANT") {
        ans = "WEAKLY ASCENDING";
      } else if (ans == "DESCENDING" || ans == "WEAKLY DESCENDING") {
        ans = "RANDOM";
      } else if (ans == "NONE") {
        ans = "ASCENDING";
      }
    } else {
      if (ans == "CONSTANT") {
        ans = "WEAKLY DESCENDING";
      } else if (ans == "ASCENDING" || ans == "WEAKLY ASCENDING") {
        ans = "RANDOM";
      } else if (ans == "NONE") {
        ans = "DESCENDING";
      }
    }
    prev = cur;
    cin >> cur;
  }
  if (ans == "NONE")
    ans = "CONSTANT";
  cout << ans << endl;
  return 0;
}
