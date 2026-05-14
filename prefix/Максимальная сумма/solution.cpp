#include <iostream>
#include <stdint.h>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int64_t> nums(n);
  int64_t ans;
  int64_t min_sum = 0;
  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
    if (i == 0) {
      ans = nums[i];
    }
    sum += nums[i];
    ans = std::max(ans, sum - min_sum);
    min_sum = std::min(min_sum, sum);
  }
  std::cout << ans << std::endl;

  return 0;
}
