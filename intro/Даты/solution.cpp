#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int x, y, z;

  std::cin >> x >> y >> z;

  if (x <= 12 && y <= 12 && x != y)
    std::cout << 0 << std::endl;
  else
    std::cout << 1 << std::endl;

  return 0;
}
