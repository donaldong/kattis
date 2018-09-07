#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using vld = vector<ld>;
using vi = vector<int>;
using v2i = vector<vi>;

struct comb {
  vi list;
  int sum = 0;

  comb() {}
  comb(const comb &c) {
    list = c.list;
    sum = c.sum;
  }
  void add(int i, int n) {
    list.push_back(i);
    sum += n;
  }
};

ld calc(vld &P, comb &c) {
  ld res = 1.0;
  for (auto i : c.list) res *= P[i];
  return res;
}

ld solve(vi &S, vld &P) {
  vector<comb> C;
  ld res = 0;
  for (size_t i = 0; i < S.size(); ++i) {
    size_t j = C.size();
    for (size_t k = 0; k < j; ++k) {
      comb new_comb(C[k]);
      new_comb.add(i, S[i]);
      if (new_comb.sum < 76) {
        C.push_back(new_comb);
      } else {
        res = max(res, calc(P, new_comb));
      }
    }
    comb c;
    c.add(i, S[i]);
    C.push_back(c);
  }
  return res;
}

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vi S(n);
    vld P(n);
    for (int i = 0; i < n; ++i) {
      cin >> S[i] >> P[i];
      P[i] /= 100.0;
    }
    printf("%.1Lf\n", solve(S, P) * 100.0);
  }
  return 0;
}
