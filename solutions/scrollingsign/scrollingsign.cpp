#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;

int K, W;
vs G;

int crawl(string &a, size_t i, string &b) {
  int res = 0;
  size_t j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i++] != b[j++]) return 0;
    ++res;
  }
  return res;
}

int overlap(string &a, string &b) {
  int res = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    res = crawl(a, i, b);
    if (res) break;
  }
  return K - res;
}

int solve() {
  int res = 0;
  string cur;
  int i = 0;
  while (i < W) {
    res += overlap(cur, G[i]);
    cur = G[i];
    ++i;
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> K >> W;
    G = vs(W);
    for (auto &g : G) cin >> g;
    cout << solve() << endl;
  }
  return 0;
}
