#include <bits/stdc++.h>
using namespace std;

using ti2 = tuple<int, int>;
using vti2 = vector<ti2>;

int solve(vti2 &N) {
  int res = 0, cur = 0, l, r;
  sort(N.begin(), N.end());
  for (size_t i = 0; i < N.size(); ++i) {
    tie(l, r) = N[i];
    if (l <= cur && cur <= r) continue;
    ++res;
    cur = r;
  }
  return res;
}

int main() {
  int n, l, r;
  cin >> n;
  vti2 N(n);
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    N[i] = make_tuple(l, r);
  }
  cout << solve(N) << endl;
  return 0;
}
