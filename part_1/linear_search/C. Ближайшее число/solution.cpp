#include <iostream>
using namespace std;

int main() {
  int N, x, ans, min_dist;
  int elems[1000];
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> elems[i];
  }
  cin >> x;
  min_dist = abs(x - elems[0]);
  ans = elems[0];
  for (int i = 1; i < N; ++i) {
    if (abs(x - elems[i]) < min_dist) {
      min_dist = abs(x - elems[i]);
      ans = elems[i];
    }
  }
  cout << ans << endl;
  return 0;
}
