#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;

  std::cin >> N;
  std::vector<int64_t> houses(N);

  for (auto &h : houses)
    std::cin >> h;

  std::cout << houses[int(N / 2 + 0.5)] << std::endl;
  return 0;
}
