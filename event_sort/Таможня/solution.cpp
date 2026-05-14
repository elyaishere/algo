#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<std::pair<uint64_t, bool>> time_points(2 * N);
  for (int i = 0; i < N; ++i) {
    // start
    std::cin >> time_points[2 * i].first;
    time_points[2 * i].second = true;
    // end
    std::cin >> time_points[2 * i + 1].first;
    time_points[2 * i + 1].first += time_points[2 * i].first;
    time_points[2 * i + 1].second = false;
  }

  std::sort(time_points.begin(), time_points.end());
  int count{0};
  int working = 0;
  for (const auto &point : time_points) {
    const auto [coord, is_start] = point;
    if (is_start) {
      working++;
    } else {
      working--;
    }
    count = std::max(count, working);
  }
  std::cout << count << std::endl;
}
