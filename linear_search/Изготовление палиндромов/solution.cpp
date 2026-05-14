#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string str;
  std::cin >> str;
  int total{0};
  int left{0}, right{(int)str.size() - 1};
  while (left < right) {
    if (str[left] != str[right])
      ++total;
    ++left, --right;
  }

  std::cout << total << std::endl;

  return 0;
}
