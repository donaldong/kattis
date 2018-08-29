#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int INF = 1e9;

vi lis(vi &N) {
  int k = 0;
  vi T(N.size(), 1);
  for (size_t i = 1; i < T.size(); ++i) {
    for (size_t j = 0; j < i; ++j) {
      if (N[i] > N[j] && T[i] <= T[j]) T[i] = T[j] + 1;
      k = max(k, T[i]);
    }
  }
  vi res(k, INF);
  size_t size = N.size() - 1;
  for (size_t i = k; i-- > 0;) {
    int l = i + 1;
    size_t size2;
    for (size_t j = 0; j <= size; ++j) {
      if (i + 1 == k) {
        if (T[j] == l && N[j] < res[i]) {
          res[i] = N[j];
          size2 = j;
        } 
      } else {
        if (T[j] == l && N[j] < res[i + 1] && N[j] < res[i]) {
          res[i] = N[j];
          size2 = j;
        }
      }
    }
    size = size2;
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
