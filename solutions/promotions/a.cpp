/**
 * @date        2022-03-27
 * @tags        graph, dfs, bfs
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int A,B,E,P;
  cin >> A >> B >> E >> P;
  vector<vector<int>> G(E), revG(E);
  vector<unordered_set<int>> cntF(E), cntB(E);
  for (int i = 0, a, b; i < P; ++i) {
    cin >> a >> b;
    G[a].push_back(b), revG[b].push_back(a);
  }
  function<int(int)> after = [&](int i) {
    auto& s = cntF[i];
    if (!s.empty()) return s.size()-1;
    for (int j : G[i]) {
      after(j);
      for (int k : cntF[j]) s.insert(k);
    }
    s.insert(i);
    return s.size()-1;
  };
  function<int(int)> before = [&](int i) {
    auto& s = cntB[i];
    if (!s.empty()) return s.size()-1;
    for (int j : revG[i]) {
      before(j);
      for (int k : cntB[j]) s.insert(k);
    }
    s.insert(i);
    return s.size()-1;
  };
  int r1 = 0, r2 = 0, r3 = 0;
  for (int i = 0; i < E; ++i) {
    int a = after(i), b = before(i);
    if ((E-a)<=A) ++r1;
    if ((E-a)<=B) ++r2;
    if (b >= B) ++r3;
  }
  printf("%d\n%d\n%d\n", r1, r2, r3);
  return 0;
}
