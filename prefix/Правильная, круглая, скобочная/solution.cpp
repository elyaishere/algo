#include <iostream>
#include <stdint.h>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  uint64_t left{0};
  std::string input;
  std::getline(std::cin, input);
  bool wrong = false;
  for (auto c : input) {
    if (c == '(') {
      ++left;
      continue;
    }
    if (left == 0) {
      wrong = true;
      break;
    }
    --left;
  }
  if (wrong || left != 0) {
    std::cout << "NO" << std::endl;
  } else {
    std::cout << "YES" << std::endl;
  }
  return 0;
}
