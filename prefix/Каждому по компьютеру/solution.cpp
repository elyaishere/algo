#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  std::cin >> N >> M;

  struct Info {
    int count;
    int index;

    bool operator<(const Info &rhs) const { return count <= rhs.count; };
  };

  std::vector<Info> X(N + 1, {.count = 0, .index = 0});
  std::vector<Info> Y(M + 1, {.count = 0, .index = 0});

  for (int i = 1; i <= N; ++i) {
    std::cin >> X[i].count;
    X[i].count += 1;
    X[i].index = i;
  }
  for (int i = 1; i <= M; ++i) {
    std::cin >> Y[i].count;
    Y[i].index = i;
  }
  std::sort(X.begin(), X.end());
  std::sort(Y.begin(), Y.end());

  std::vector<int> ans(N + 1, 0);
  int y_ptr = 1;
  int count = 0;
  for (int i = 1; i <= N; ++i) {
    while (y_ptr <= M && Y[y_ptr].count < X[i].count)
      ++y_ptr;
    if (y_ptr > M)
      break;
    ans[X[i].index] = Y[y_ptr].index;
    ++y_ptr;
    ++count;
  }
  std::cout << count << std::endl;
  for (int i = 1; i <= N; ++i)
    std::cout << ans[i] << " ";
  return 0;
}
