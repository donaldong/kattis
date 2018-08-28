#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;

ll solve(vi &N, vi &M) {
  ll res = 0;
  sort(N.begin(), N.end());
  sort(M.begin(), M.end());
  for (auto itr = M.rbegin(); itr != M.rend(); ++itr) {
    int m = *itr;
    int cur = N.back();
    while (!N.empty() && N.back() >= m) {
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
