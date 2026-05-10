#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int x = 0) : data(x), left(nullptr), right(nullptr) {}
};

void print_leaves(Node *root) {
  if (!root)
    return;
  print_leaves(root->left);
  if (!root->left && !root->right)
    cout << root->data << endl;
  print_leaves(root->right);
}

int main() {
  Node *root = new Node;
  while (true) {
    int c;
    cin >> c;
    if (c == 0)
      break;
    if (root->data == 0)
      root->data = c;
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
      if (f) {
        continue;
      }
      if (prev->data > c)
        prev->left = new Node(c);
      else
        prev->right = new Node(c);
    }
  }
  print_leaves(root);
  return 0;
}
