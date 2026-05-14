#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c < 0) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  if (a == 0) {
    if (b == c * c) {
      cout << "MANY SOLUTIONS\n";
    } else {
      cout << "NO SOLUTION\n";
    }
    return 0;
  }
  int x = (c * c - b) / a;
  if (x * a + b == c * c) {
    cout << x << endl;
  } else {
    cout << "NO SOLUTION\n";
  }
  return 0;
}
