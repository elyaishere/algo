#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, t, x;
  cin >> a;
  bool plus = a[0] == '+';
  for (auto j : a) {
    if (isdigit(j)) {
      if (plus) {
        x += '8';
        plus = false;
      } else {
        x += j;
      }
    }
  }
  if (x.size() == 7) {
    x = "8495" + x;
  } else if (x.size() < 11) {
    x = x.substr(0, 1) + "495" + x.substr(1);
  }
  a = x;
  for (int i = 0; i < 3; ++i) {
    cin >> t;
    x = "";
    plus = t[0] == '+';
    for (auto j : t) {
      if (isdigit(j)) {
        if (plus) {
          x += '8';
          plus = false;
        } else {
          x += j;
        }
      }
    }
    if (x.size() == 7) {
      x = "8495" + x;
    } else if (x.size() < 11) {
      x = x.substr(0, 1) + "495" + x.substr(1);
    }
    if (a == x) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
