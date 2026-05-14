#include <iostream>
#include <map>
#include <stdint.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::map<int64_t, int64_t> res;
  int64_t a, d;
  for (int i = 0; i < n; ++i) {
    std::cin >> d >> a;
    res[d] += a;
  }
  for (auto [k, v] : res) {
    std::cout << k << " " << v << std::endl;
  }

  return 0;
}
