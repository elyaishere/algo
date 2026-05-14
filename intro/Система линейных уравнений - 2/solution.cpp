#include <iostream>
using namespace std;

int main() {
  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  double D = a * d - b * c;
  if (D != 0) {
    cout << 2 << " " << (e * d - f * b) / D << " " << (a * f - c * e) / D
         << endl;
    return 0;
  }
  if (a == 0 && b == 0 && c == 0 && d == 0) {
    if (e == 0 && f == 0) {
      cout << 5 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }
  if (a * f != c * e || b * f != d * e) {
    cout << 0 << endl;
    return 0;
  }
  if (a == 0 && c == 0) {
    if (b != 0) {
      cout << 4 << " " << e / b << endl;
    } else {
      cout << 4 << " " << f / d << endl;
    }
    return 0;
  }
  if (b == 0 and d == 0) {
    if (a != 0) {
      cout << 3 << " " << e / a << endl;
    } else {
      cout << 3 << " " << f / c << endl;
    }
    return 0;
  }
  if (b != 0) {
    cout << 1 << " " << -a / b << " " << e / b << endl;
  } else {
    cout << 1 << " " << -c / d << " " << f / d << endl;
  }
  return 0;
}
