#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

enum PointType { LEFT, CAT, RIGHT };

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  std::vector<int> counts(M, 0);
  std::vector<std::tuple<int, PointType, int>> points(N + 2 * M);
  int i = 0;
  for (; i < N; ++i) {
    std::cin >> std::get<0>(points[i]); // coord
    std::get<1>(points[i]) = PointType::CAT;
  }
  for (; i < N + 2 * M; i += 2) {
    std::cin >> std::get<0>(points[i]); // coord
    std::get<1>(points[i]) = PointType::LEFT;
    std::get<2>(points[i]) = ((i - N) >> 1); // segment number

    std::cin >> std::get<0>(points[i + 1]); // coord
    std::get<1>(points[i + 1]) = PointType::RIGHT;
    std::get<2>(points[i + 1]) = ((i - N) >> 1); // segment number
  }
  std::sort(points.begin(), points.end());

  int running_cats_counter = 0;
  for (const auto &p : points) {
    const auto [coord, tp, segment_num] = p;
    if (tp == PointType::CAT)
      ++running_cats_counter;
    else if (tp == PointType::LEFT) {
      counts[segment_num] -= running_cats_counter;
    } else {
      counts[segment_num] += running_cats_counter;
    }
  }
  for (auto i : counts)
    std::cout << i << std::endl;
}
