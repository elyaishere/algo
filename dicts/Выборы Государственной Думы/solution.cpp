#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::unordered_map<std::string, uint64_t> counts;
  std::vector<std::string> parties;
  std::string input;
  uint64_t total{0};
  while (std::getline(std::cin, input)) {
    std::istringstream ss(input);
    std::string name = "";
    std::string chunk;
    while (ss >> chunk) {
      if (ss.eof()) {
        auto number = std::stoll(chunk);
        auto party = name.substr(0, name.size() - 1);
        counts[party] += number;
        total += number;
        parties.push_back(party);
      } else {
        name += chunk;
        name += " ";
      }
    }
  }
  double quotient = (double)total / 450.;
  std::unordered_map<std::string, uint64_t> places;
  std::unordered_map<std::string, double> fractionals;
  int counter = 0;
  for (const auto &[k, v] : counts) {
    double frac = v / quotient;
    places[k] = (uint64_t)(frac);
    fractionals[k] = frac - places[k];
    counter += places[k];
  }
  if (counter < 450) {
    std::vector<std::pair<std::string, double>> v{fractionals.begin(),
                                                  fractionals.end()};
    std::sort(v.begin(), v.end(), [&](auto &a, auto &b) {
      return a.second > b.second ||
             (a.second == b.second && counts[a.first] > counts[b.first]);
    });
    for (const auto &i : v) {
      if (counter++ == 450)
        break;
      ++places[i.first];
    }
  }
  for (const auto &name : parties) {
    std::cout << name << " " << places[name] << std::endl;
  }

  return 0;
}
