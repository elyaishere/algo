#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<std::pair<int64_t, bool>> segments(2 * N);
  for (int i = 0; i < N; ++i) {
    // left
    std::cin >> segments[2 * i].first;
    segments[2 * i].second = true;
    // right
    std::cin >> segments[2 * i + 1].first;
    segments[2 * i + 1].second = false;
  }

  std::sort(segments.begin(), segments.end());
  uint64_t len{0};
  int open_segments = 0;
  int64_t last_position = 0;
  for (const auto &point : segments) {
    const auto [coord, is_left] = point;
    if (open_segments > 0) {
      len += coord - last_position;
    }
    if (is_left) {
      open_segments++;
    } else {
      open_segments--;
    }
    last_position = coord;
  }
  std::cout << len << std::endl;
}
