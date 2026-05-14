#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  uint64_t n, k;
  std::cin >> n >> k;
  std::vector<int64_t> x(n);
  for (auto &i : x)
    std::cin >> i;
  std::sort(x.begin(), x.end());
  int64_t left{0}, right{x[n - 1] - x[0]};
  while (left < right) {
    int64_t mid = ((left + right) >> 1);
    uint64_t cnt{0};
    auto maxright = x[0] - 1;
    for (auto xi : x) {
      if (xi > maxright) {
        ++cnt;
        maxright = xi + mid;
      }
    }
    if (cnt <= k) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  std::cout << left << std::endl;
  return 0;
}
