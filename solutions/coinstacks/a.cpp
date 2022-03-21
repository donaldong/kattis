#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  set<pair<int,int>> s;
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    if (v) s.emplace(v, i+1);
    tot += v;
  }
  vector<pair<int,int>> moves;
  moves.reserve(tot/2);
  while (s.size() >= 2) {
    auto l = s.begin();
    auto [v1, s1] = *l;
    s.erase(l);

    if (s.empty()) {
      cout << "no" << endl;
      return 0;
    }

    auto r = prev(s.end());
    auto [v2, s2] = *r;
    s.erase(r);

    moves.emplace_back(s1, s2);
    if (v1-1) s.emplace(v1-1, s1);
    if (v2-1) s.emplace(v2-1, s2);
  }
  if (!s.empty()) cout << "no" << endl;
  else {
    cout << "yes" << endl;
    for (auto [a, b] : moves) cout << a << ' ' << b << endl;
  }
  return 0;
}
