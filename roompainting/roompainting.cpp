#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;

int INF = 1e9;

ll solve(vi &N, vi &M) {
  ll res = 0;
  sort(M.begin(), M.end());
  for (auto &n : N) if (n < M[0]) n = INF;
  sort(N.begin(), N.end());
  for (size_t i = M.size(); i-- > 0;) {
    int m = M[i];
    int cur = N.back();
    while (N.size() > i && N.back() >= m) {
      cur = N.back(), N.pop_back();
    }
    res += cur - m;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vi N(n), M(m);
  for (auto &e : N) cin >> e;
  for (auto &e : M) cin >> e;
  cout << solve(N, M) << endl;
  return 0;
}
