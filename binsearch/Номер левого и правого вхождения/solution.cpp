#include <iostream>
#include <stdint.h>
#include <vector>

template <typename Iterator>
Iterator UpperBound(Iterator begin, Iterator end, int64_t value) {
  auto count = end - begin;
  Iterator it;
  while (count > 0) {
    it = begin + (count >> 1);
    if (value >= *it) {
      begin = ++it;
    } else {
      end = it;
    }
    count = end - begin;
  }
  return begin;
}

template <typename Iterator>
Iterator LowerBound(Iterator begin, Iterator end, int64_t value) {
  auto count = end - begin;
  Iterator it;
  while (count > 0) {
    it = begin + (count >> 1);
    if (value > *it) {
      begin = ++it;
    } else {
      end = it;
    }
    count = end - begin;
  }
  return begin;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int64_t> numbers(n);
  for (auto &i : numbers)
    std::cin >> i;

  int m;
  std::cin >> m;
  int64_t ch;
  while (m-- > 0) {
    std::cin >> ch;
    auto ub = UpperBound(numbers.begin(), numbers.end(), ch);
    auto lb = LowerBound(numbers.begin(), numbers.end(), ch);
    if (lb == numbers.end() || *lb != ch) {
      std::cout << 0 << " " << 0 << "\n";
      continue;
    }
    std::cout << lb - numbers.begin() + 1 << " " << ub - numbers.begin()
              << "\n";
  }

  return 0;
}
