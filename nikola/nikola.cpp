#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using vi = vector<uint>;
using v2i = vector<vi>;

vi N;
v2i T;

uint solve(int n, int l) {
  if (n < 0 || n >= N.size()) return -1;
  if (l <= 0 || l >= N.size()) return -1;
  if (T[n][l] != -1) return T[n][l];
  uint res = -1;
  res = min(res, solve(n - l, l - 1));
  res = min(res, solve(n + l, l));
  if (res == -1 || res == -2) return -2;
  res += N[n];
  T[n][l] = res;
  return res; 
}

uint solve(int n) {
  uint res = -1;
  for (int l = 1; l <= n; ++l) {
    res = min(res, solve(n, l));
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  N = vi(n);
  for (auto &e : N) cin >> e;
  T = v2i(n, vi(n, -1));
  T[1][1] = N[1];
  T[0][1] = N[0] + N[1];
  cout << solve(n - 1) << endl;
  return 0;
}
