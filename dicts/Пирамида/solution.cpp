#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> wh;
  long h_max = 0;
  int w, h;
  for (int i = 0; i < n; ++i) {
    cin >> w >> h;
    if (wh.find(w) != wh.end()) {
      if (wh[w] < h) {
        h_max -= wh[w] - h;
        wh[w] = h;
      }
    } else {
      wh[w] = h;
      h_max += h;
    }
  }
  cout << h_max << endl;
  return 0;
}
