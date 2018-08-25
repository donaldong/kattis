#include <bits/stdc++.h>
using namespace std;

using hset = unordered_set<int>;
using vs = vector<string>;
using hmap = unordered_map<string, hset>;

hmap build(vs &G) {
  hmap M;
  for (size_t i = 0; i < G.size(); ++i) {
    auto &s = G[i];
    for (size_t j = 0; j < s.size(); ++j) {
      for (size_t size = 1; size <= s.size() - j; ++size) {
        string sub = s.substr(j, size);
        M[sub].insert(i);
      }
    }
  }
  return M;
}

string solve(hmap &M, string &s) {
  vs R;
  for (size_t i = 0; i < s.size(); ++i) {
    for (size_t size = 1; size <= s.size() - i; ++size) {
      string sub = s.substr(i, size);
      if (M[sub].size() == 1) {
        R.push_back(sub);
      }
    }
  }
  if (R.empty()) return ":(";
  sort(R.begin(), R.end(), [](string &a, string &b) {
      if (a.size() != b.size()) return a.size() < b.size();
      return a < b;
  });
  return "\"" + R[0] + "\"";
}

int main() {
  string line;
  int T;
  getline(cin, line);
  T = stoi(line);
  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i + 1 << ":" << endl;
    getline(cin, line);
    int n = stoi(line);
    vs G(n);
    for (auto &g : G) {
      getline(cin, g);
      for (char &c : g) c = toupper(c);
    }
    if (n == 1) {
      cout << "\"\"" << endl;
      continue;
    }
    auto M = build(G);
    for (int j = 0; j < n; ++j) {
      cout << solve(M, G[j]) << endl;
    }
  }
  return 0;
}
