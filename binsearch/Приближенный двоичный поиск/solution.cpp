#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;
  map<int, int> produced;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    if (produced.find(x) != produced.end()) {
      cout << produced[x] << endl;
      continue;
    }
    if (x >= arr[n - 1]) {
      produced[x] = arr[n - 1];
      cout << produced[x] << endl;
      continue;
    }
    if (x <= arr[0]) {
      produced[x] = arr[0];
      cout << produced[x] << endl;
      continue;
    }
    int left = 0, right = n - 1;
    bool found = false;
    while (left < right) {
      int m = (left + right) / 2;
      if (arr[m] == x) {
        produced[x] = arr[m];
        found = true;
        break;
      }
      if (arr[m] < x) {
        left = m + 1;
      } else {
        right = m;
      }
    }
    if (found)
      cout << produced[x] << endl;
    else {
      if (abs(arr[left] - x) < abs(arr[left - 1] - x)) {
        produced[x] = arr[left];
      } else {
        produced[x] = arr[left - 1];
      }
      cout << produced[x] << endl;
    }
  }
  return 0;
}
