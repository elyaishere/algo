#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  int x, y;
  cin >> n >> m >> k;
  vector<vector<char>> field(n + 2, vector<char>(m + 2, '0'));
  for (int i = 0; i < k; ++i) {
    cin >> x >> y;
    field[x][y] = '*';
    if (field[x + 1][y] != '*') {
      field[x + 1][y] = ((field[x + 1][y] - '0') + 1) + '0';
    }
    if (field[x - 1][y] != '*') {
      field[x - 1][y] = ((field[x - 1][y] - '0') + 1) + '0';
    }
    if (field[x][y + 1] != '*') {
      field[x][y + 1] = ((field[x][y + 1] - '0') + 1) + '0';
    }
    if (field[x][y - 1] != '*') {
      field[x][y - 1] = ((field[x][y - 1] - '0') + 1) + '0';
    }
    if (field[x + 1][y + 1] != '*') {
      field[x + 1][y + 1] = ((field[x + 1][y + 1] - '0') + 1) + '0';
    }
    if (field[x + 1][y - 1] != '*') {
      field[x + 1][y - 1] = ((field[x + 1][y - 1] - '0') + 1) + '0';
    }
    if (field[x - 1][y + 1] != '*') {
      field[x - 1][y + 1] = ((field[x - 1][y + 1] - '0') + 1) + '0';
    }
    if (field[x - 1][y - 1] != '*') {
      field[x - 1][y - 1] = ((field[x - 1][y - 1] - '0') + 1) + '0';
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      cout << field[i][j] << " ";
    cout << endl;
  }
  return 0;
}
