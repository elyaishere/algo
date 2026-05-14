#include <iomanip>
#include <iostream>

double f(int a, int b, int c, int d, double val) {
  return a * val * val * val + b * val * val + c * val + d;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  double left{-1}, right{1};
  while (f(a, b, c, d, left) * f(a, b, c, d, right) >= 0) {
    left *= 2;
    right *= 2;
  }
  for (int i = 0; i < 100; i++) {
    double x = (left + right) / 2;
    double v1 = f(a, b, c, d, x);
    double v2 = f(a, b, c, d, right);
    (v1 * v2 <= 0) ? left = x : right = x;
  }
  std::cout << std::setprecision(11) << left << std::endl;

  return 0;
}
