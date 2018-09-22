#include <bits/stdc++.h>
using namespace std;

using ti2 = tuple<int, int>;
using vti2 = vector<ti2>;
using v2ti2 = vector<vti2>;

bool possible(ti2 &a, ti2 &b) {
  int dr = get<0>(a) - get<0>(b);
  int dc = get<1>(a) - get<1>(b);
  return dr * dr + dc * dc == 5;
}

bool possible(v2ti2 &G, int a, int b) {
  for (auto ta : G[a]) for (auto tb : G[b]) {
    if (possible(ta, tb)) return true;
  }
  return false;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  v2ti2 G(26);
  for (size_t i = 0; i < s.size(); ++i) {
    G[s[i] - 'A'].emplace_back(i / n, i % n);
  }
  bool f = true;
  string T = "ICPCASIASG";
  for (size_t i = 1; i < T.size(); ++i) {
    if (!possible(G, T[i - 1] - 'A', T[i] - 'A')) {
      f = false; break;
    }
  }
  cout << (f ? "YES" : "NO") << endl;
  return 0;
}
