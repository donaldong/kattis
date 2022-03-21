#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;

int INF = 1e9;

ll solve(vi &N, vi &M) {
  ll res = 0;
  sort(N.begin(), N.end());
  sort(M.begin(), M.end());
  size_t j = 0;
  for (size_t i = 0; i < M.size();) {
    while (j < N.size() && N[j] < M[i]) ++j;
    while (i < M.size() && M[i] <= N[j]) {
      res += N[j] - M[i];
      ++i;
    }
    ++j;
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
