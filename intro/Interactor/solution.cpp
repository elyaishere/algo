#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int r, i, c;

  std::cin >> r >> i >> c;

  switch (i) {
  case 0:
    if (r != 0)
      std::cout << 3 << std::endl;
    else
      std::cout << c << std::endl;
    break;
  case 1:
    std::cout << c << std::endl;
    break;
  case 4:
    if (r != 0)
      std::cout << 3 << std::endl;
    else
      std::cout << 4 << std::endl;
    break;
  case 6:
    std::cout << 0 << std::endl;
    break;
  case 7:
    std::cout << 1 << std::endl;
    break;

  default:
    std::cout << i << std::endl;
    break;
  }

  return 0;
}
