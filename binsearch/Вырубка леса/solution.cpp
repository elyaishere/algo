#include <iostream>
#include <stdint.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  uint64_t a, k, b, m, x;
  std::cin >> a >> k >> b >> m >> x;
  uint64_t left{1}, right{2 * (x + 1) / (a + b)};
  while (left < right) {
    uint64_t mid = ((left + right) >> 1);
    uint64_t val =
        (mid - (uint64_t)(mid / k)) * a + (mid - (uint64_t)(mid / m)) * b;
    if (val < x) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  std::cout << left << std::endl;
  return 0;
}
