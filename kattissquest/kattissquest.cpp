#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef multiset<tuple<int, int>> tset;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, e, g;
  cin >> n;
  string s;
  tset S;
  while (n--) {
    cin >> s;
    if (s[0] == 'a') cin >> e >> g, S.emplace(-e, -g);
    else {
      cin >> e;
      ll res = 0;
      while (true) {
        auto itr = S.lower_bound(make_tuple(-e, INT_MIN));
        if (itr != S.end()) e += get<0>(*itr), res -= get<1>(*itr), S.erase(itr);
        else break;
      }
      printf("%lld\n", res);
    }
  }
  return 0;
}
