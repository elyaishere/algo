#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<int> x(10);
  for (int i = 0; i < 10; ++i) {
    std::cin >> x[i];
  }
  int current_max = 0;
  int left{0}, right{0};
  for (int i = 0; i < 10; ++i) {
    if (x[i] == 2) {
      left = i;
      break;
    }
  }
  for (int i = 0; i < left; ++i) {
    if (x[i] == 1) {
      current_max = left - i;
      break;
    }
  }
  while (left < 10) {
    for (right = left + 1; right < 10; ++right) {
      if (x[right] == 2) {
        break;
      }
    }
    if (right == 10) {
      for (int i = 9; i > left; --i) {
        if (x[i] == 1) {
          current_max = std::max(current_max, i - left);
          break;
        }
      }
    }
    for (int i = left + 1; i < right; ++i) {
      if (x[i] == 1) {
        current_max = std::max(current_max, std::min(i - left, right - i));
      }
    }
    left = right;
  }
  std::cout << current_max << std::endl;
  return 0;
}
