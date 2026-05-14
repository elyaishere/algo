#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int d, x, y;

  std::cin >> d >> x >> y;

  std::vector<double> dists{std::sqrt(x * x + y * y),
                            std::sqrt((x - d) * (x - d) + y * y),
                            std::sqrt((y - d) * (y - d) + x * x)};
  std::vector<double> p{(dists[0] + dists[1] + d) / 2.0,
                        (dists[1] + dists[2] + d * std::sqrt(2)) / 2.0,
                        (dists[0] + dists[2] + d) / 2.0};
  std::vector<double> sqrs{
      std::sqrt(p[0] * (p[0] - dists[0]) * (p[0] - dists[1]) * (p[0] - d)),
      std::sqrt(p[1] * (p[1] - dists[1]) * (p[1] - dists[2]) *
                (p[1] - d * std::sqrt(2))),
      std::sqrt(p[2] * (p[2] - dists[0]) * (p[2] - dists[2]) * (p[2] - d)),
  };

  if (std::fabs(double(d * d) / 2.0 - (sqrs[0] + sqrs[1] + sqrs[2])) < 1e-8) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << std::min_element(dists.begin(), dists.end()) - dists.begin() +
                     1
              << std::endl;
  }

  return 0;
}
