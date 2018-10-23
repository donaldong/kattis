#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll next(ll n) {
  if (n & 1) return 3 * n + 1;
  return n / 2;
}

void solve(int _a, int _b) {
  ll a = _a, b = _b;
  int sa = 0, sb = 0;
  unordered_map<ll, int> A;
  while (a != 1) {
    A[a] = sa++;
    a = next(a);
  }
  A[1] = sa;
  while (A.find(b) == A.end()) {
    b = next(b);
    ++sb;
  }
  printf(
    "%d needs %d steps, %d needs %d steps, they meet at %lld\n",
    _a, A[b], _b, sb, b
  );
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  while (cin >> a >> b) {
    if (!a && !b) break;
    solve(a, b);
  }
  cout << flush;
  return 0;
}
