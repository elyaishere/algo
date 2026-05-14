#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_set<int> numbers;
  {
    std::string str;
    std::getline(std::cin, str);
    std::istringstream ss(str);
    int d;
    while (ss >> d) {
      numbers.insert(d);
    }
  }
  std::unordered_set<int> res;
  {
    std::string str;
    std::getline(std::cin, str);
    std::istringstream ss(str);
    int d;
    while (ss >> d) {
      if (numbers.find(d) != numbers.end()) {
        res.insert(d);
      }
    }
  }
  std::cout << res.size() << std::endl;
  return 0;
}
