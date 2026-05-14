#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string input;
  std::map<std::string, int> res;
  while (std::getline(std::cin, input)) {
    std::string name;
    int count;
    std::istringstream ss(input);
    ss >> name >> count;
    res[name] += count;
  }
  for (const auto &[k, v] : res) {
    std::cout << k << " " << v << std::endl;
  }

  return 0;
}
