#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ti2 = tuple<int, int>;
using vti2 = vector<ti2>;

int N, K;
vti2 A, B;

void update(vti2 &T, size_t k, int t) {
  if (!t) return;
  if (k >= T.size()) return;
  int a, b;
  tie(a, b) = T[k];
  T[k] = make_tuple(a, b - t);
}

ll solve(vti2 &T) {
  ll res = 0;
  sort(T.rbegin(), T.rend());
  size_t i = 0;
  int x, t, r, l;
  ll k;
  while (i < T.size()) {
    tie(x, t) = T[i];
    if (t < 0) {
      update(T, ++i, -t);
      continue;
    }
    k = t / K;
    r = t % K;
    if (r) ++k;
    l = k * K - t;
    res += k * x * 2;
    update(T, ++i, l);
  }
  return res;
}

int main() {
  cin >> N >> K;
  while (N--) {
    int x, t;
    cin >> x >> t;
    if (x < 0) A.emplace_back(-x, t);
    else if (x > 0) B.emplace_back(x, t);
  }
  ll res = solve(A);
  res += solve(B);
  cout << res << endl;
  return 0;
}
