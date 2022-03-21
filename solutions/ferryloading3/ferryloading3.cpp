#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T, n, t, m;
  cin >> T;
  while (T--) {
    cin >> n >> t >> m;
    int cur = 0, a, s = 0;
    string S;
    queue<int> Q[2], ID[2];
    for (int i = 0; i < m; ++i) {
      cin >> a >> S;
      int j = S[0] == 'r';
      Q[j].push(a), ID[j].push(i);
    }
    vector<tuple<int, int>> res;
    res.reserve(m);
    while (!Q[0].empty() || !Q[1].empty()) {
      int k = 0;
      while (!Q[s].empty() && Q[s].front() <= cur && k < n) {
        res.emplace_back(ID[s].front(), cur + t);
        Q[s].pop(), ID[s].pop(), ++k;
      }
      if (k) s = !s, cur += t;
      else if (!Q[!s].empty() && Q[!s].front() <= cur) s = !s, cur += t;
      else if (!Q[!s].empty() && !Q[s].empty() && Q[!s].front() < Q[s].front()) cur = Q[!s].front() + t, s = !s;
      else if (!Q[s].empty()) cur = Q[s].front();
      else cur = Q[!s].front() + t, s = !s;
    }
    sort(res.begin(), res.end());
    for (auto &r : res) printf("%d\n", get<1>(r));
    printf("\n");
  }
  return 0;
}
