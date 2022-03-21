#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<string> G;
vector<vector<string>> dp;
using Mask = __int128;

Mask getMask(int i, char c) {
  Mask res = 0, b = 1;
  for (int j = 0; j < N; ++j, b <<= 1) {
    if (G[j][i] == c) res += b;
  }
  return res;
}

pair<bool,bool> apply(int i, Mask mask) {
  if (i < 0) return {false, false};
  Mask b = 1;
  bool t = false, f = false;
  for (int j = 0; j < N; ++j, b <<= 1) {
    if (!(mask & b)) continue;
    if (G[j][i] == 'T') t = true;
    if (G[j][i] == 'F') f = true;
  }
  return {t, f};
}

bool valid(string& s) {
  Mask mask = 0;
  for (int i = 0; i < s.size(); ++i) {
    auto b = getMask(i, s[i]);
    if (mask & b) return false;
    mask += b;
  }
  return true;
}

string dfs(int i, char c) {
  if (i < 0) return "";
  int j = c == 'F' ? 0 : 1;
  if (!dp[i][j].empty()) return dp[i][j];
  Mask mask = getMask(i, c);
  auto [t, f] = apply(i-1, mask);
  if (t && f) return dp[i][j] = "x";
  string s;
  if (f) s = dfs(i-1, 'T')+c;
  else if (t) s = dfs(i-1, 'F')+c;
  else {
    s = dfs(i-1, 'F')+c;
    auto s2 = dfs(i-1, 'T')+c;
    if (!valid(s)) s = move(s2);
    else if (valid(s2)) s = min(s, s2);
  }
  if (!valid(s)) s = "x";
#ifdef DEBUG
  cout << min(s, string("x")) << endl;
  printf("dfs(%d, %c)=%s  prev[t=%d, f=%d]\n", i, c, s.c_str(),t,f);
#endif
  return dp[i][j] = move(s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> K;
  G.resize(N);
  dp.assign(K, vector<string>(2));
  for (auto& s : G) cin >> s;
  string s = min(
    dfs(K-1, 'F'),
    dfs(K-1, 'T')
  );
  if (s == "x") cout << -1 << endl;
  else cout << s << endl;
  return 0;
}
