#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;

int MAX_W = 200;

ll ways(int n) {
  vll C = {1, 1};
  while (--n) {
    vll C2(C.size() + 1, 1);
    for (size_t i = 1; i < C.size(); ++i) {
      C2[i] = C[i - 1] + C[i];
    }
    C = C2;
  } 
  ll res = 0;
  for (ll c : C) res += c;
  return res;
}

int main() {
  int n;
  cin >> n;
  vi N(n);
  ll sum = 0;
  for (auto &num : N) cin >> num, sum += num;
  ll res = ways(n) / 2 * sum;
  for (int a = 0; a < n; ++a) {
    int sum_a = N[a];
    if (sum_a >= MAX_W) continue;
    res -= sum_a;
    for (int b = a + 1; b < n; ++b) {
      int sum_b = sum_a + N[b];
      if (sum_b >= MAX_W) continue;
      res -= sum_b;
      for (int c = b + 1; c < n; ++c) {
        int sum_c = sum_b + N[c];
        if (sum_c >= MAX_W) continue;
        res -= sum_c;
        for (int d = c + 1; d < n; ++d) {
          int sum_d = sum_c + N[d];
          if (sum_d >= MAX_W) continue;
          res -= sum_d;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
