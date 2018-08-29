#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using tf3 = tuple<ld, ld, ld>;
using vtf3 = vector<tf3>;

vtf3 N, M;
ld DELTA = 1e-8;

ld dot(const tf3 &a, const tf3 &b) {
  return get<0>(a) * get<0>(b) +
    get<1>(a) * get<1>(b) +
    get<2>(a) * get<2>(b);
}

bool possible(tf3 &a, tf3 &b) {
  return dot(a, b) > DELTA;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;
    N = vtf3(n), M = vtf3(m);
    while (n--) {
      ld x, y, z;
      cin >> x >> y >> z;
      N[n] = make_tuple(x, y, z);
    }
    while (m--) {
      ld x, y, z;
      cin >> x >> y >> z;
      M[m] = make_tuple(x, y, z);
    }
    int res = 0;
    for (auto t : M) {
      for (auto s : N) {
        if (possible(t, s)) {
          ++res;
          break;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}

