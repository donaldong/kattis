#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string prev;
  int n;
  cin >> prev >> n;
  unordered_map<char,vector<string>> words;
  while (n--) {
    string s;
    cin >> s;
    words[s[0]].push_back(move(s));
  }
  char c = prev.back();
  if (words[c].empty()) {
    cout << '?' << endl;
  } else {
    for (auto& s : words[c]) {
      char c2 = s.back();
      if (c == c2) {
        if (words[c2].size() <= 1) {
          cout << s << '!' << endl;
          return 0;
        }
      } else {
        if (words[c2].empty()) {
          cout << s << '!' << endl;
          return 0;
        }
      }
    }
    cout << words[c][0] << endl;
  }
  return 0;
}
