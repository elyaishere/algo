#include <iostream>
#include <vector>

using namespace std;

vector<int> extend(const vector<int> &old, int ext) {
  return vector<int>{old[0] - ext, old[1] + ext, old[2] - ext, old[3] + ext};
}

vector<int> intersect(const vector<int> &pos, const vector<int> &nav) {
  return vector<int>{max(pos[0], nav[0]), min(pos[1], nav[1]),
                     max(pos[2], nav[2]), min(pos[3], nav[3])};
}

int main() {
  int t, d, n;
  cin >> t >> d >> n;
  vector<int> pos_rect{0, 0, 0, 0};
  for (int i = 0; i < n; ++i) {
    pos_rect = extend(pos_rect, t);
    int navX, navY;
    cin >> navX >> navY;
    vector<int> nav_rect = extend(
        vector<int>{navX + navY, navX + navY, navX - navY, navX - navY}, d);
    pos_rect = intersect(pos_rect, nav_rect);
  }
  vector<pair<int, int>> points;
  for (int xPlusY = pos_rect[0]; xPlusY <= pos_rect[1]; ++xPlusY) {
    for (int xMinusY = pos_rect[2]; xMinusY <= pos_rect[3]; ++xMinusY) {
      if ((xPlusY + xMinusY) % 2 == 0) {
        int x = (xPlusY + xMinusY) / 2;
        points.push_back({x, xPlusY - x});
      }
    }
  }
  cout << points.size() << endl;
  for (auto point : points)
    cout << point.first << " " << point.second << endl;
  return 0;
}
