#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ti2 = tuple<int, int>;
int MAX = 101;

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

int solve(vi &N) {
  vector<bool> F(MAX, 0);
  queue<ti2> Q;
  int res = 0;
  for (size_t i = 0; i < N.size(); ++i) {
    int n = N[i];
    if (!F[n]) F[n] = true, ++res;
    Q.push(make_tuple(i, n));
  }
  int i, n;
  while (!Q.empty()) {
    tie(i, n) = Q.front();
    Q.pop();
    if (i + 1 == N.size()) continue;
    n = gcd(n, N[i + 1]);
    if (!F[n]) F[n] = true, ++res;
    if (n != 1) Q.push(make_tuple(i + 1, n));
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vi N(n);
  for (auto &e : N) cin >> e;
  cout << solve(N) << endl;
  return 0;
}
