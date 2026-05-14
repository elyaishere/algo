#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_set<int> search;
  std::unordered_set<int> unique;
  std::vector<int> numbers;
  int d;
  while (std::cin >> d) {
    numbers.push_back(d);
    if (search.find(d) != search.end() && unique.find(d) != unique.end()) {
      unique.erase(d);
    }
    if (search.find(d) == search.end()) {
      unique.insert(d);
    }
    search.insert(d);
  }
  for (auto i : numbers) {
    if (unique.find(i) != unique.end()) {
      std::cout << i << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}
