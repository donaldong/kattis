/**
 * @date        2022-03-23
 * @tags        combinatorics, inclusion-exclusion, bitmask
 * @difficulty  1900
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int E, zeros = 0;
  string N;
  cin >> N >> E;
  string T = to_string(1LL<<E);

  auto calc = [&](int len) -> ll {
    ll res = 0;
    for (int mask = (1<<len)-1; mask > 0; --mask) {
      int bits = 0;
      bool valid = true;
      string D(len, '-');
      for (int i = 0; valid && i < len; ++i) {
        int bit = 1<<i;
        if (!(mask&bit)) continue;
        ++bits;
        if (i+T.size()>=D.size()+1) valid = false;
        for (int j = 0; valid && j < T.size(); ++j) {
          auto& d = D[i+j];
          if (d == '-') d = T[j];
          else if (d == T[j]) continue;
          else valid = false;
        }
      }
      if (!valid) continue;
      ll p = 1;
      if (len != N.size()) {
        if (D[0] == '-') p *= 9;
        for (int i = 1; i < D.size(); ++i) {
          if (D[i] != '-') continue;
          p *= 10;
        }
        if (bits&1) res += p;
        else res -= p;
        continue;
      }
      ll p1 = 0, pb = 0, p2 = 1, A = 0, B = 0;
      for (int i = 0; i < len; ++i) {
        if (D[i] == '-') {
          if (A!=B) p2 *= 10;
          else {
            p1 = p1*10+N[i]-'0';
            if (i==0) pb = 1;
            else pb *= 10;
          }
        } else {
          A = A*10+N[i]-'0';
          B = B*10+D[i]-'0';
        }
      }
      p = (p1-pb+(A>=B?1:0))*p2;
      if (bits&1) res += p;
      else res -= p;
    }
    return res;
  };

  ll res = 0;
  for (int i = T.size(); i <= N.size(); ++i) {
    res += calc(i);
  }
  cout << res << endl;
  return 0;
}
