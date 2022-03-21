#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, x, y, r, res = 0;
  map<int, multiset<int>> G;
  cin >> n;
  while (n--) {
    cin >> x >> y;
    G[x].insert(y);
  }
  cin >> n;
  while (n--) {
    cin >> x >> y >> r;
    for (auto i = G.lower_bound(x - r); i != G.end();) {
      if (i->first > x + r) break;
      int dx = i->first - x;
      if (dx < 0) dx *= -1;
      int h = sqrt(r * r - dx * dx);
      auto &s = i->second;
      for (auto j = s.lower_bound(y - h); j != s.end();) {
        if (*j > y + h) break;
        j = s.erase(j);
      }
      if (s.empty()) i = G.erase(i);
      else ++i;
    }
  }
  for (auto i = G.begin(); i != G.end(); ++i) {
    res += i->second.size();
#ifdef DEBUG
    for (int y : i->second) printf("p: %d %d\n", i->first, y);
#endif
  }
  printf("%d\n", res);
  return 0;
}
