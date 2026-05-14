#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int m;
  std::cin >> m;
  std::vector<uint64_t> symbols(m);
  std::string input;
  for (int i = 0; i < m; ++i) {
    std::cin >> input;
    uint64_t tmp{0};
    for (auto c : input) {
      if (std::isalpha(c)) {
        tmp |= (1 << (c - 'A'));
      } else {
        tmp |= (1 << (26 + c - '0'));
      }
    }
    symbols[i] = tmp;
  }
  int n;
  std::cin >> n;
  std::vector<std::string> numbers;
  std::vector<int> counts;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> input;
    uint64_t tmp{0};
    for (auto c : input) {
      if (std::isalpha(c)) {
        tmp |= (1 << (c - 'A'));
      } else {
        tmp |= (1 << (26 + c - '0'));
      }
    }
    int cnt = 0;
    for (auto j : symbols) {
      if ((tmp & j) == j) {
        ++cnt;
      }
    }
    numbers.push_back(input);
    counts.push_back(cnt);
    mx = std::max(mx, counts.back());
  }
  for (int i = 0; i < n; ++i) {
    if (counts[i] == mx) {
      std::cout << numbers[i] << std::endl;
    }
  }
  return 0;
}
