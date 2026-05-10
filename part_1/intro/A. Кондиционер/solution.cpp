#include <iostream>
#include <string>
using namespace std;

int main() {
  int troom, tcond;
  cin >> troom >> tcond;
  string reg;
  cin >> reg;
  if (reg == "freeze") {
    cout << min(troom, tcond) << endl;
    return 0;
  }
  if (reg == "heat") {
    cout << max(troom, tcond) << endl;
    return 0;
  }
  if (reg == "auto") {
    cout << tcond << endl;
    return 0;
  }
  if (reg == "fan") {
    cout << troom << endl;
  }
  return 0;
}
