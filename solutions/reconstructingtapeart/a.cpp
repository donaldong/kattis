/**
 * @date        2022-04-01
 * @tags        greedy, data structure
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
using Tuple = tuple<int,int,int>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<int> C(n);
  vector<vector<int>> P(n+1);
  for (auto& c : C) cin >> c;
  for (int i = 0; i < n; ++i) P[C[i]].push_back(i);
  vector<Tuple> ranges;
  ranges.reserve(n);
  for (int c = 1; c <= n; ++c) {
    auto& pos = P[c];
    if (pos.empty()) continue;
    ranges.emplace_back(pos[0], pos.back(), c);
  }
  sort(ranges.begin(), ranges.end(), [&](const Tuple& a, const Tuple& b) {
    auto [la,ra,ca] = a;
    auto [lb,rb,cb] = b;
    return ra-la>rb-lb;
  });
  auto possible = [&]() {
    set<int> R;
    for (auto [l,r,c] : ranges) {
      auto a = R.upper_bound(l);
      auto b = R.upper_bound(r);
      if (a != b) return false;
      for (int i : P[c]) R.insert(i);
    }
    return true;
  };
  if (!possible()) cout << "IMPOSSIBLE" << endl;
  else {
    cout << ranges.size() << endl;
    for (auto [l,r,c] : ranges) printf("%d %d %d\n", l+1,r+1,c);
  }

  return 0;
}
