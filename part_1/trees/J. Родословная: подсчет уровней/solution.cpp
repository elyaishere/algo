#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Node {
  string name;
  int cnt;
  vector<Node *> children;
  Node(string s = "") : name(s), cnt(1) {}
};

void calc(Node *root) {
  if (!root)
    return;
  for (auto &j : root->children) {
    j->cnt = 1 + root->cnt;
    calc(j);
  }
}

int main() {
  map<string, string> child_parent;
  map<string, vector<string>> parent_children;
  set<string> all;
  set<string> with_par;
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    string c, p;
    cin >> c >> p;
    with_par.insert(c);
    all.insert(p);
    child_parent[c] = p;
    if (parent_children.find(p) == parent_children.end())
      parent_children[p] = {};
    parent_children[p].push_back(c);
  }
  for (auto i : with_par)
    if (all.find(i) != all.end())
      all.erase(i);
  Node *root = new Node;
  map<string, Node *> table;
  root->name = *all.begin();
  table[root->name] = root;
  root->children = {};
  deque<Node *> d;
  for (auto i : parent_children[root->name]) {
    root->children.push_back(new Node(i));
    table[i] = root->children[root->children.size() - 1];
    d.push_back(table[i]);
  }
  while (!d.empty()) {
    auto cur = d.front();
    d.pop_front();
    for (auto i : parent_children[cur->name]) {
      cur->children.push_back(new Node(i));
      table[i] = cur->children[cur->children.size() - 1];
      d.push_back(table[i]);
    }
  }
  calc(root);
  for (auto i : table)
    cout << i.first << " " << i.second->cnt - 1 << endl;

  return 0;
}
