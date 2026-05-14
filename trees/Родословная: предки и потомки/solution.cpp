#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct Node {
  Node *parent{nullptr};
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_map<std::string, Node *> name_to_node;
  int N;
  std::cin >> N;
  for (int i = 1; i < N; ++i) {
    std::string child, parent;
    std::cin >> child >> parent;
    auto parent_it = name_to_node.find(parent);
    auto child_it = name_to_node.find(child);

    if (parent_it == name_to_node.end()) {
      parent_it = name_to_node.emplace(std::move(parent), new Node).first;
    }
    if (child_it == name_to_node.end()) {
      child_it = name_to_node.emplace(std::move(child), new Node).first;
    }

    child_it->second->parent = parent_it->second;
  }

  std::string child, parent;
  while (std::cin >> child >> parent) {
    auto parent_it = name_to_node.find(parent);
    auto child_it = name_to_node.find(child);
    auto tmp = child_it->second->parent;
    while (tmp && tmp != parent_it->second)
      tmp = tmp->parent;

    if (tmp) {
      std::cout << "2\n";
      continue;
    }

    tmp = parent_it->second->parent;
    while (tmp && tmp != child_it->second)
      tmp = tmp->parent;

    if (tmp) {
      std::cout << "1\n";
      continue;
    }

    std::cout << "0\n";
  }

  return 0;
}
