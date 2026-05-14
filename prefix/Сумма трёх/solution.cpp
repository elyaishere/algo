#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

struct Info {
  int index;
  uint64_t value;

  bool operator<(const Info &rhs) const {
    return value < rhs.value || (value == rhs.value && index < rhs.index);
  };
};

template <class Iterator>
bool BinSearch(Iterator begin, Iterator end, Info &cmp) {
  int left = 0;
  int right = end - begin;
  while (left < right) {
    int m = (left + right) >> 1;
    if (cmp.value <= (begin + m)->value) {
      right = m;
    } else
      left = m + 1;
  }
  if ((begin + left)->value == cmp.value) {
    cmp.index = (begin + left)->index;
    return true;
  }
  return false;
}

std::vector<Info> ReadValues() {
  int n;
  std::cin >> n;

  std::vector<Info> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].value;
    a[i].index = i;
  }
  return a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  uint64_t S;
  std::cin >> S;

  auto a = ReadValues();
  auto b = ReadValues();
  auto c = ReadValues();

  std::sort(c.begin(), c.end());
  for (auto &i : a) {
    auto s = S - i.value;
    for (auto &j : b) {
      Info it{.index = 0, .value = s - j.value};
      if (it.value < 0)
        continue;
      auto cond = BinSearch(c.begin(), c.end(), it);
      if (cond) {
        std::cout << i.index << " " << j.index << " " << it.index << std::endl;
        return 0;
      }
    }
  }
  std::cout << -1 << std::endl;

  return 0;
}
