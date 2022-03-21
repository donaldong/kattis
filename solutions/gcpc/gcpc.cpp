#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, t, p;
  cin >> n >> m;
  vi N(n + 1, 0), P(n + 1, 0);
  multiset<tuple<int, int>> S;
  while (m--) {
    cin >> t >> p;
    auto itr = S.find({N[t], -P[t]});
    ++N[t], P[t] += p;
    tuple<int, int> a = {N[1], -P[1]},
                    b = {N[t], -P[t]};
    if (t == 1) {
      for (itr = S.begin(); itr != S.end();) {
        if (*itr <= a) itr = S.erase(itr);
        else break;
      }
    } else {
      if (itr != S.end()) S.erase(itr);
      if (b > a) S.insert(b);
    }
    printf("%lu\n", S.size() + 1);
  }
  return 0;
}
