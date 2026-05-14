#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, i, j;

  std::cin >> N >> i >> j;

  std::cout << std::min(abs(i - j) - 1, N - 1 - abs(i - j)) << std::endl;

  return 0;
}
