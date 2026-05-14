#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int L, K;
  std::cin >> L >> K;
  std::vector<int> x(K);
  int left{0};
  int mid{-1};
  for (auto &i : x) {
    std::cin >> i;
    if (i < L / 2)
      ++left;
    if (i == L / 2 && L % 2 == 1)
      mid = left;
  }
  if (mid != -1) {
    std::cout << x[mid] << std::endl;
  } else {
    std::cout << x[left - 1] << " " << x[left] << std::endl;
  }

  return 0;
}
