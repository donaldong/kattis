#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using v2b = vector<vb>;

vi parse(string &s) {
  vi R;
  for (int i = 0; i < 4; ++i) {
    char a = s[2 * i], b = s[2 * i + 1];
    if (a == '0' && b == '0') continue;
    R.push_back((a - 'A') * 2 + (b == '+'));
  }
  return R;
}

void connect(v2b &G, string &s, vb &E) {
  vi N = parse(s);
  for (auto a : N) E[a] = true;
  for (size_t i = 0; i < N.size(); ++i) for (size_t j = 0; j < N.size(); ++j) {
    if (i == j) continue;
    int a = N[i] ^ 1, b = N[j];
    G[a][b] = true;
  }
}

bool dfs(v2b &G, int n, vi &V) {
  V[n] = -1;
  for (size_t i = 0; i < G.size(); ++i) {
    if (!G[n][i]) continue;
    if (V[i] == -1) return true;
    if (!V[i] && dfs(G, i, V)) return true;
  }
  V[n] = 1;
  return false;
}

bool has_cycle(v2b &G, vb &E) {
  vi V(G.size(), 0);
  for (size_t i = 0; i < G.size(); ++i) {
    if (!V[i] && E[i] && dfs(G, i, V)) return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  v2b G(52, vb(52, false));
  vb E(52, false);
  bool f = false;
  string s;
  while (n--) {
    cin >> s;
    connect(G, s, E);
  }
  cout << (has_cycle(G, E) ? "unbounded" : "bounded") << endl;
  return 0;
}
