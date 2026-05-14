#include <iostream>

struct Node {
  int data{0};
  Node *left{0};
  Node *right{0};
};

bool search(Node *root, int value) {
  if (!root)
    return false;
  if (root->data == value)
    return true;
  return root->data > value ? search(root->left, value)
                            : search(root->right, value);
}

bool insert(Node *&root, int value) {
  if (!root) {
    root = new Node{value};
    return true;
  }

  if (value == root->data)
    return false;
  return value < root->data ? insert(root->left, value)
                            : insert(root->right, value);
}

void print(Node *root, int height) {
  if (!root)
    return;
  print(root->left, height + 1);
  std::cout << std::string(height, '.') << root->data << '\n';
  print(root->right, height + 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Node *root{nullptr};

  std::string cmd;
  while (std::cin >> cmd) {
    if (cmd == "ADD") {
      int value;
      std::cin >> value;
      insert(root, value) ? (std::cout << "DONE\n")
                          : (std::cout << "ALREADY\n");
    } else if (cmd == "SEARCH") {
      int value;
      std::cin >> value;
      search(root, value) ? (std::cout << "YES\n") : (std::cout << "NO\n");
    } else { // PRINTTREE
      print(root, 0);
    }
  }

  return 0;
}
