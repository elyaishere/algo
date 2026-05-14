#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<string, long> bank;
  string op, name, name2;
  int cnt;
  while (cin >> op) {
    if (op == "DEPOSIT") {
      cin >> name >> cnt;
      if (bank.find(name) != bank.end()) {
        bank[name] += cnt;
      } else {
        bank[name] = cnt;
      }
    } else if (op == "WITHDRAW") {
      cin >> name >> cnt;
      if (bank.find(name) != bank.end()) {
        bank[name] -= cnt;
      } else {
        bank[name] = -cnt;
      }
    } else if (op == "BALANCE") {
      cin >> name;
      if (bank.find(name) != bank.end()) {
        cout << bank[name] << endl;
      } else {
        cout << "ERROR\n";
      }
    } else if (op == "TRANSFER") {
      cin >> name >> name2 >> cnt;
      if (bank.find(name) != bank.end()) {
        bank[name] -= cnt;
      } else {
        bank[name] = -cnt;
      }
      if (bank.find(name2) != bank.end()) {
        bank[name2] += cnt;
      } else {
        bank[name2] = cnt;
      }
    } else if (op == "INCOME") {
      cin >> cnt;
      for (auto &i : bank)
        if (i.second > 0) {
          i.second = i.second + i.second * cnt / 100;
        }
    }
  }

  return 0;
}
