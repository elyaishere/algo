#include <iostream>

using namespace std;

struct Node {
  int data;
  int level;
  Node *left;
  Node *right;
  Node(int x = 0, int l = 0)
      : data(x), level(l), left(nullptr), right(nullptr) {}
};

int main() {
  Node *root = new Node;
  int h = 0;
  while (true) {
    int c;
    cin >> c;
    if (c == 0)
      break;
    if (h == 0)
      root->data = c, ++h, root->level = 1;
    else {
      auto tmp = root;
      auto prev = tmp;
      bool f = false;
      while (tmp) {
        if (tmp->data == c) {
          f = true;
          break;
        }
        prev = tmp;
        if (tmp->data > c) {
          tmp = tmp->left;
        } else {
          tmp = tmp->right;
        }
      }
      if (f)
        continue;
      if (prev->data > c)
        prev->left = new Node(c, prev->level + 1);
      else
        prev->right = new Node(c, prev->level + 1);
      if (prev->level + 1 > h)
        h = prev->level + 1;
    }
  }
  cout << h << endl;
  return 0;
}
