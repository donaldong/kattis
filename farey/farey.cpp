#include <bits/stdc++.h>
using namespace std;

int MAX = 1e4 + 1;
using uint = unsigned int;
using vi = vector<uint>;

vi T(MAX, -1);

vi factors(uint n) {
  vi R;
  uint i = 2;
  for (; i * i < n; ++i) {
    if (n % i == 0) {
      R.push_back(i);
      R.push_back(n / i);
    }
  }
  if (i * i == n) R.push_back(i);
  return R;
}

uint solve(uint n) {
  if (T[n] != -1) return T[n];
  vi F = factors(n);
  uint res = n - 1;
  for (auto f : F) res -= solve(f);
  T[n] = res;
  return res;
}

int main() {
  T[1] = 2;
  vi R(MAX);
  R[1] = 2;
  for (int i = 2; i < MAX; ++i) R[i] = R[i - 1] + solve(i);
  int t;
  cin >> t;
  while (t--) {
    int k, n;
    cin >> k >> n;
    cout << k << " " << R[n] << endl;
  }
  return 0;
}
