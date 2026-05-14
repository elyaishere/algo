#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int s1 = max(a, c) * (b + d), s2 = max(a, d) * (b + c),
      s3 = max(b, d) * (a + c), s4 = max(b, c) * (a + d);
  if (s1 < s2) {
    if (s1 < s3) {
      if (s1 < s4) {
        cout << max(a, c) << " " << b + d << endl;
      } else {
        cout << max(b, c) << " " << a + d << endl;
      }
    } else {
      if (s3 < s4) {
        cout << max(b, d) << " " << a + c << endl;
      } else {
        cout << max(b, c) << " " << a + d << endl;
      }
    }
  } else {
    if (s2 < s3) {
      if (s2 < s4) {
        cout << max(a, d) << " " << b + c << endl;
      } else {
        cout << max(b, c) << " " << a + d << endl;
      }
    } else {
      if (s3 < s4) {
        cout << max(b, d) << " " << a + c << endl;
      } else {
        cout << max(b, c) << " " << a + d << endl;
      }
    }
  }
  return 0;
}
