#include <iostream>
#include <vector>
using namespace std;

bool good(vector<int> seq, int left, int right) {
  while (right < seq.size()) {
    if (seq[left] != seq[right])
      return false;
    --left, ++right;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> seq;
  int c;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    seq.push_back(c);
  }
  int ans = 0;
  while (!good(seq, (n + ans) / 2 - 1, (n + ans) / 2 + (n + ans) % 2) &&
         ans < n - 1)
    ++ans;
  cout << ans << endl;
  for (int i = ans - 1; i >= 0; --i)
    cout << seq[i] << " ";
  cout << endl;
  return 0;
}
