#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unordered_map<string, string> lang;
  string line;
  string a, b;
  while (getline(cin, line)) {
    if (line.empty()) break;
    int i = line.find(' ');
    a = line.substr(0, i);
    b = line.substr(i + 1, line.size() - a.size() - 1);
    lang[b] = a;
  }
  while (getline(cin, a)) {
    if (lang.find(a) == lang.end()) printf("eh\n");
    else printf("%s\n", lang[a].c_str());
  }
  cout << flush;
  return 0;
}
