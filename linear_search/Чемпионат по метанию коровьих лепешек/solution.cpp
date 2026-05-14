#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> results(n);
  cin >> results[0] >> results[1] >> results[2];
  int best_score, first_pos;
  if (results[0] >= results[1]) {
    if (results[0] >= results[2]) {
      best_score = results[0];
      first_pos = 0;
    } else {
      best_score = results[2];
      first_pos = 2;
    }
  } else {
    if (results[1] >= results[2]) {
      best_score = results[1];
      first_pos = 1;
    } else {
      best_score = results[2];
      first_pos = 2;
    }
  }
  int probably_Vasya = 0;
  if (results[1] % 10 == 5 && first_pos == 0 && results[1] > results[2])
    probably_Vasya = results[1];
  for (int i = 3; i < n; ++i) {
    cin >> results[i];
    if (results[i] > best_score) {
      best_score = results[i];
      first_pos = i;
      probably_Vasya = 0;
      continue;
    }
    if (results[i - 1] % 10 == 5 && results[i] < results[i - 1] &&
        first_pos < i - 1 && probably_Vasya < results[i - 1]) {
      probably_Vasya = results[i - 1];
    }
  }
  if (probably_Vasya == 0) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 0;
  for (auto i : results) {
    if (i > probably_Vasya)
      ++ans;
  }
  cout << ans + 1 << endl;
  return 0;
}
