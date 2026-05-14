#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string input;
  std::unordered_map<std::string, int> res;
  while (std::getline(std::cin, input)) {
    std::string word;
    std::istringstream ss(input);
    while (ss >> word) {
      ++res[word];
    }
  }

  std::vector<std::pair<std::string, int>> v{res.begin(), res.end()};

  auto lexicographical = [](const std::string &a, const std::string &b) {
    for (int i = 0; i < std::min(a.size(), b.size()); ++i) {
      if (a[i] > b[i])
        return false;
      if (a[i] < b[i])
        return true;
    }
    if (a.size() < b.size())
      return true;
    return false;
  };

  std::sort(v.begin(), v.end(), [&lexicographical](auto &a, auto &b) {
    return a.second > b.second ||
           (a.second == b.second && lexicographical(a.first, b.first));
  });

  for (const auto &i : v) {
    std::cout << i.first << std::endl;
  }

  return 0;
}
