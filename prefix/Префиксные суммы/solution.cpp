#include <iostream>
#include <stdint.h>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q;
  std::cin >> n >> q;
  std::vector<uint64_t> sums(n + 1, 0);
  int ch;
  for (int i = 1; i <= n; ++i) {
    std::cin >> ch;
    sums[i] = sums[i - 1] + ch;
  }
  int l, r;
  for (int i = 0; i < q; ++i) {
    std::cin >> l >> r;
    std::cout << sums[r] - sums[l - 1] << std::endl;
  }

  return 0;
}
