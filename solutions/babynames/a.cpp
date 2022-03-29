/**
 * @date        2022-03-29
 * @tags        data structure, trie, dfs
 * @difficulty  1800
 */
#include <bits/stdc++.h>
using namespace std;
struct Node {
  int cnt = 0;
  unordered_map<char,int> children;
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int q, t;
  string s, e;
  constexpr int max_nodes = 200000*30;
  vector<Node> nodes;
  nodes.reserve(max_nodes+1);
  auto newNode = [&]() -> int {
    int i = nodes.size();
    nodes.emplace_back();
    return i;
  };

  array<unordered_set<string>,2> S;
  array<int, 2> T;
  T[0] = newNode(), T[1] = newNode();
  while (cin >> q) {
    switch (q) {
    case 0: return 0;
    case 1: {
      cin >> s >> t;
      S[t-1].insert(s);
      for (int i = 0, curr = T[t-1]; i < s.size(); ++i) {
        auto& next = nodes[curr].children[s[i]];
        if (!next) next = newNode();
        ++nodes[next].cnt;
        curr = next;
      }
      break;
    }
    case 2: {
      cin >> s;
      for (int t = 0; t < 2; ++t) {
        if (!S[t].count(s)) continue;
        S[t].erase(s);
        for (int i = 0, curr = T[t]; i < s.size(); ++i) {
          auto next = nodes[curr].children[s[i]];
          --nodes[next].cnt;
          curr = next;
        }
      }
      break;
    }
    case 3: {
      int res  = 0;
      cin >> s >> e >> t;
      vector<int> targets;
      if (t == 0) targets = {0,1};
      else targets = {t-1};
      for (int t : targets) {
        for (char c = s[0]; c < e[0]; ++c) {
          int n = nodes[T[t]].children[c];
          if (!n) continue;
          res += nodes[n].cnt;
        }
        for (int i = 0, curr = T[t]; curr && i < s.size(); ++i) {
          for (char c = 'A'; c < s[i]; ++c) {
            auto neigh = nodes[curr].children[c];
            if (!neigh) continue;
            res -= nodes[neigh].cnt;
          }
          auto next = nodes[curr].children[s[i]];
          curr = next;
        }
        for (int i = 1, curr = nodes[T[t]].children[e[0]]; curr && i < e.size(); ++i) {
          for (char c = 'A'; c < e[i]; ++c) {
            auto neigh = nodes[curr].children[c];
            if (!neigh) continue;
            res += nodes[neigh].cnt;
          }
          auto next = nodes[curr].children[e[i]];
          curr = next;
        }
      }
      printf("%d\n", res);
      break;
    }
    }
  }
  return 0;
}
