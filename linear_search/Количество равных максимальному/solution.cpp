#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int current_max;
  int counter = 0;
  std::cin >> current_max;
  int x = current_max;
  for (; x != 0; std::cin >> x) {
    if (x > current_max) {
      current_max = x;
      counter = 1;
      continue;
    }
    if (x == current_max) {
      ++counter;
    }
  }
  std::cout << counter << std::endl;
  return 0;
}
