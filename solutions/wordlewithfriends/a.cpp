/**
 * @date        2022-09-27
 * @tags        implementation, case work
 * @difficulty  1550
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, w;
  cin >> n >> w;
  string G(5, '-');
  unordered_set<char> no_include; // letters should not be included in the word
  unordered_map<char, int> min_req; // the min # occurrence for each letter
  vector<unordered_set<char>> guessed(5);
  for (int i = 0; i < n; ++i) {
    string g, f;
    cin >> g >> f;
    unordered_map<char, int> req;
    for (int j = 0; j < f.size(); ++j) {
      auto c = g[j];
      switch (f[j]) {
        case 'G':
          G[j] = c;
          ++req[c];
          break;
        case 'Y':
          ++req[c];
          guessed[j].insert(c);
          break;
        case '-':
          no_include.insert(c);
          guessed[j].insert(c);
          break;
      }
    }
    for (auto [c, count] : req) {
      no_include.erase(c);
      min_req[c] = max(min_req[c], count);
    }
  }

  auto valid = [&](const string& s) {
    auto req = min_req;
    for (int i = 0; i < s.size(); ++i) {
      auto c = s[i];
      if (G[i] != '-' && c != G[i]) return false; // 1. greens must match
      if (no_include.count(c)) return false; // 2. guessing a letter that's not in the word
      if (guessed[i].count(c)) return false; // 3. guessing again and we know it will fail
      --req[c];
    }
    for (auto [c, count] : req) {
      if (count > 0) return false; // 4. satisfy min occurrence requirement
    }
    return true;
  };

  for (int i = 0; i < w; ++i) {
    string s;
    cin >> s;
    if (valid(s)) printf("%s\n", s.c_str());
  }
  return 0;
}
