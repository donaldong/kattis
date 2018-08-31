#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
int MAX = 101;

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

int solve(vi &N) {
  vb F(MAX, false), T(MAX, false);
  for (int n : N) {
    vb B(MAX, false);
    for (size_t i = 1; i < F.size(); ++i) {
      if (F[i]) {
        int d = gcd(i, n);
        B[d] = true;
        T[d] = true;
      }
    }
    B[n] = true;
    T[n] = true;
    swap(F, B);
  }
  int res = 0;
  for (bool f : T) if (f) ++res;
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
