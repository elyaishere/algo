#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> st;
  int c;
  while (cin >> c)
    st.insert(c);
  cout << st.size() << endl;
  return 0;
}
