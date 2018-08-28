#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;

int INF = 1e9;

ll solve(vi &N, vi &M) {
  ll res = 0;
  sort(N.begin(), N.end());
  sort(M.begin(), M.end());
  queue<int> Q;
  for (int n : N) Q.push(n);
  for (size_t i = 0; i < M.size(); ++i) {
    while (!Q.empty() && Q.front() < M[i]) Q.pop();
    res += Q.front() - M[i];
    Q.pop();
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
