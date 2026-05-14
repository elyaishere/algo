#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int M;
  std::cin >> M;
  std::vector<std::pair<int, int>> segments;
  int left, right;
  for (;;) {
    std::cin >> left >> right;
    if (left == 0 && right == 0)
      break;
    if (left > M || right < 0)
      continue;
    segments.emplace_back(left, right);
  }

  std::sort(segments.begin(), segments.end());
  std::vector<std::pair<int, int>> answer;
  int curr_right = 0, next_right = 0;
  std::pair<int, int> curr_best;
  for (const auto &s : segments) {
    const auto [left, right] = s;
    if (left > curr_right) {
      answer.push_back(curr_best);
      curr_right = next_right;
      if (curr_right >= M)
        break;
    }
    if (left <= curr_right && right > next_right) {
      next_right = right;
      curr_best = s;
    }
  }
  if (curr_right < M) {
    curr_right = next_right;
    answer.push_back(curr_best);
  }
  if (curr_right < M) {
    std::cout << "No solution" << std::endl;
  } else {
    std::cout << answer.size() << std::endl;
    for (const auto &s : answer)
      std::cout << s.first << ' ' << s.second << std::endl;
  }
}
