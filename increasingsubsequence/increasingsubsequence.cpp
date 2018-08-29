#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int INF = 1e9;

vi lis(vi &N) {
  int k = 0;
  vi T(N.size(), 1);
  for (size_t i = 0; i < T.size(); ++i) {
    for (size_t j = i + 1; j < T.size(); ++j) {
      if (N[j] > N[i] && T[j] <= T[i]) T[j] = T[i] + 1;
      k = max(k, T[j]);
    }
  }
  vi res(k, INF);
  size_t i = 0;
  while (i < N.size()) {
    int l = T[i] - 1;
    if (!l) res[0] = min(res[0], N[i]);
    else if (N[i] > res[l - 1]) res[l] = min(res[l], N[i]);
    ++i;
  }
  return res;
}

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    vi N(n);
    for (auto &e : N) cin >> e;
    auto res = lis(N);
    cout << res.size() << " ";
    for (auto r : res) cout << r << " ";
    cout << endl;
  }
  return 0;
}
