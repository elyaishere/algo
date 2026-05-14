#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <unordered_set>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  std::cin >> N;
  std::vector<std::pair<double, int>> angles(2 * N);
  double rmin = 0;
  double rmax = 1000001;
  double r1, r2;
  for (int i = 0; i < N; ++i) {
    std::cin >> r1 >> r2;
    rmin = std::max(rmin, r1);
    rmax = std::min(rmax, r2);
    std::cin >> angles[2 * i].first >> angles[2 * i + 1].first;
    angles[2 * i].second = -(i + 1);
    angles[2 * i + 1].second = i + 1;
  }
  std::sort(angles.begin(), angles.end());

  int seg_cnt{0};
  std::unordered_set<int> used;
  for (const auto &[phi, s] : angles) {
    if (s < 0) {
      ++seg_cnt;
      used.insert(-s);
    } else if (used.find(s) != used.end()) {
      --seg_cnt;
    }
  }

  double ans = 0;
  for (int i = 0; i < angles.size(); ++i) {
    const auto &[phi, s] = angles[i];
    if (s < 0) {
      ++seg_cnt;
    } else {
      --seg_cnt;
    }
    if (seg_cnt == N) {
      if (i < angles.size() - 1) {
        ans += (angles[i + 1].first - phi) * (rmax * rmax - rmin * rmin) / 2;
      } else {
        ans += (angles[0].first - angles.back().first + 2 * M_PI) *
               (rmax * rmax - rmin * rmin) / 2;
      }
    }
  }
  std::cout << std::setprecision(7) << ans << std::endl;
}
