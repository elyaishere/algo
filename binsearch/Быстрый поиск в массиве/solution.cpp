#include <algorithm>
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
  std::sort(numbers.begin(), numbers.end());

  int k;
  std::cin >> k;
  int64_t l, r;
  while (k-- > 0) {
    std::cin >> l >> r;
    auto ub = UpperBound(numbers.begin(), numbers.end(), r);
    auto lb = LowerBound(numbers.begin(), numbers.end(), l);
    std::cout << ub - lb << " ";
  }
  std::cout << std::endl;

  return 0;
}
