/**
 * @date        2023-01-07
 * @tags        simulation, constructive algorithms
 * @difficulty  1950
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<vector<int>> G(n);
  for (int i = 0, p, k, l; i < 5; ++i) {
    cin >> p;
    while (p--) {
      cin >> k >> l;
      --k, --l;
      G[k].push_back(l), G[l].push_back(k);
    }
  }
  stack<int> S;
  vector<int> C(n, 0);
  for (int i = 0; i < n; ++i) S.push(i);
  while (!S.empty()) {
    array<int,2> cnt{0,0};
    int i = S.top();
    S.pop();
    for (int j : G[i]) ++cnt[C[j]];
    if (cnt[C[i]] <= 2) continue;
    C[i] ^= 1;
    for (int j : G[i]) S.push(j);
  }
  for (int c : C) cout << (c?'B':'A');
  cout << endl;
  return 0;
}
