#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

string lower(const string &s) {
  string ans;
  for (auto i : s) {
    if (isalpha(i) && isupper(i))
      ans += tolower(i);
    else
      ans += i;
  }
  return ans;
}
void only_letters_nums_underlines(string &s) {
  for (auto &i : s) {
    if (!isdigit(i) && !isalpha(i) && i != '_')
      i = ' ';
  }
}

int main() {
  int n;
  cin >> n;
  string str;
  bool case_sens, st_digit;
  cin >> str;
  case_sens = str == "yes";
  cin >> str;
  st_digit = str == "yes";
  set<string> keywords;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    if (!case_sens) {
      str = lower(str);
    }
    keywords.insert(str);
  }
  map<string, pair<int, int>> cnt_pos_ids;
  int max_count = 0;
  string id;
  int word_number = 0;
  while (getline(cin, str)) {
    only_letters_nums_underlines(str);
    stringstream ss(str);
    string s;
    while (ss >> s) {
      ++word_number;
      if (isdigit(s[0]) && !st_digit)
        continue;
      bool only_digits = true;
      for (auto &i : s) {
        if (!isdigit(i))
          only_digits = false;
        if (!case_sens && isalpha(i) && isupper(i))
          i = tolower(i);
      }
      if (only_digits || keywords.find(s) != keywords.end())
        continue;
      if (cnt_pos_ids.find(s) == cnt_pos_ids.end())
        cnt_pos_ids[s] = {0, word_number};
      cnt_pos_ids[s].first += 1;
    }
  }
  int first_app = word_number;
  for (auto i : cnt_pos_ids) {
    if (i.second.first > max_count) {
      max_count = i.second.first;
      first_app = i.second.second;
      id = i.first;
    } else if (i.second.first == max_count && i.second.second < first_app) {
      first_app = i.second.second;
      id = i.first;
    }
  }
  cout << id << endl;
  return 0;
}
