/**
 * @date        2022-03-26
 * @tags        interactive, grid, binary search
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N, l,r,b,t;
  ll d;
  cin >> N;

  auto reset = [&]() {
    l = 0, r = 1e6, t = 0, b = 1e6;
  };

  auto pickNext = [&]() {
    int mc = (l+r)/2, mr = (t+b)/2;
    int r1 = (t+mr)/2, r2 = (b+mr)/2;
    int c1 = (l+mc)/2, c2 = (r+mc)/2;
    if (r1 == r2) r2 = r1+1;
    if (c1 == c2) c2 = c1+1;
    vector<pair<int,int>> pos {
      make_pair(r1, c1),
      make_pair(r1, c2),
      make_pair(r2, c2),
      make_pair(r2, c1),
    };
    vector<ll> D(4);
    ll minD = LLONG_MAX;
    for (int i = 0; i < 4; ++i) {
      cout << pos[i].first << ' ' << pos[i].second << endl;
      cin >> d;
      if (d == 0) {
        --N;
        reset();
        return;
      }
      D[i] = d;
      minD = min(d, minD);
    }
    for (int i =  0; i < 4; ++i) {
      if (minD != D[i]) continue;
      switch (i) {
        case 0: r = mc, b = mr; break;
        case 1: l = mc, b = mr; break;
        case 2: l = mc, t = mr; break;
        case 3: r = mc, t = mr; break;
      }
      return;
    }
  };
  reset();
  while (N) pickNext();
  return 0;
}
