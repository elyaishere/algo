#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<string, map<string, long>> spisok;
  string name, item;
  int cnt;
  while (cin >> name >> item >> cnt) {
    if (spisok.find(name) != spisok.end()) {
      auto &personal_spisok = spisok[name];
      if (personal_spisok.find(item) != personal_spisok.end()) {
        personal_spisok[item] += cnt;
      } else {
        personal_spisok[item] = cnt;
      }
    } else {
      spisok[name][item] = cnt;
    }
  }
  for (auto i : spisok) {
    cout << i.first << ":\n";
    for (auto j : i.second) {
      cout << j.first << " " << j.second << endl;
    }
  }
  cout << endl;
  return 0;
}
