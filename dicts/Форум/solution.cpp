#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::string input;
  int mark;
  std::vector<std::string> topics;
  std::unordered_map<std::string, int> counts;
  std::unordered_map<int, std::string> message_to_topic;
  for (int i = 1; i <= N; ++i) {
    std::cin >> mark;
    std::getline(std::cin, input);
    if (mark == 0) {
      std::getline(std::cin, input);
      topics.push_back(input);
      counts[input] = 1;
      message_to_topic[i] = input;
    } else {
      auto topic = message_to_topic[mark];
      ++counts[topic];
      message_to_topic[i] = topic;
    }
    std::getline(std::cin, input);
  }
  int mx{0};
  for (const auto &[_, v] : counts) {
    mx = std::max(mx, v);
  }
  for (const auto &v : topics) {
    if (counts[v] == mx) {
      std::cout << v << std::endl;
      break;
    }
  }

  return 0;
}
