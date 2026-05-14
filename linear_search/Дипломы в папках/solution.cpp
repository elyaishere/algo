#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;
  int sum{0};
  int mx{-1};
  int a;
  for (int i = 0; i < N; ++i) {
    std::cin >> a;
    sum += a;
    mx = std::max(mx, a);
  }
  std::cout << sum - mx << std::endl;
  return 0;
}
