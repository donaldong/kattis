#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using hmap = unordered_map<string, deque<int>>;
using vs = vector<string>;

int max_first_index(hmap &M) {
  int res = -1;
  for (auto &entry : M) res = max(res, entry.second.front());
  return res;
}

bool update(hmap &M, int i) {
  for (auto &entry : M) {
    auto &P = entry.second;
    while (!P.empty() && P.front() < i) P.pop_front();
    if (P.empty()) return false;
  }
  return true;
}

int solve(vs &S, hmap &M) {
  int res = 0, i;
  for (auto s : S) {
    if (M[s].empty()) return res;
  }
  do {
    i = max_first_index(M);
    ++res;
  } while (update(M, i));
  return res;
}

int main() {
  int T, s, q;
  string line;
  getline(cin, line);
  T = stoi(line);
  for (int t = 0; t < T; ++t) {
    getline(cin, line);
    s = stoi(line);
    vs S(s);
    hmap M;
    for (auto &e : S) getline(cin, e);
    getline(cin, line);
    q = stoi(line);
    for (int i = 0; i < q; ++i) {
      getline(cin, line);
      M[line].push_back(i);
    }
    printf("Case #%d: %d\n", t + 1, solve(S, M));
  }
  return 0;
}
