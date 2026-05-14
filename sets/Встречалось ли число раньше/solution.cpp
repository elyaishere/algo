#include <iostream>
#include <unordered_set>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_set<int> numbers;
  int d;
  while (std::cin >> d) {
    if (numbers.find(d) == numbers.end()) {
      numbers.insert(d);
      std::cout << "NO" << std::endl;
      continue;
    }
    std::cout << "YES" << std::endl;
  }
  return 0;
}
