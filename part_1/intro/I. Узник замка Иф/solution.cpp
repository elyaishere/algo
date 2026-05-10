#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  if (a <= d && b <= e || a <= e && b <= d) {
    cout << "YES\n";
  } else if (a <= d && c <= e || a <= e && c <= d) {
    cout << "YES\n";
  } else if (b <= d && c <= e || b <= e && c <= d) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
