/**
 * @date        2022-03-25
 * @tags        greedy, data structure, map
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N,M;
  cin >> N >> M;
  vector<pair<int, int>> P(N);
  vector<int> V(M);
  map<int,int> res;
  map<int, vector<int>> mapV;
  map<int, vector<int>> mapP;
  for (auto& p : P) {
    cin >> p.first >> p.second;
    if (p.first > p.second) swap(p.first, p.second);
  }
  for (auto& v : V) cin >> v;
  for (int i = 0; i < M; ++i) {
    mapV[V[i]].push_back(i);
  }
  for (int i = 0; i < N; ++i) {
    auto& p = P[i];
    auto& v = mapV[p.first];
    if (p.first == p.second && !v.empty()) {
      res[v.back()] = i;
      v.pop_back();
    } else if (p.first != p.second) mapP[p.first].push_back(i);
  }
  for (auto& [d, v] : mapV) {
    auto& prev = mapP[d-1];
    while (!v.empty() && !prev.empty()) {
      res[v.back()] = prev.back();
      prev.pop_back(), v.pop_back();
    }
    auto& curr = mapP[d];
    while (!v.empty() && !curr.empty()) {
      res[v.back()] = curr.back();
      curr.pop_back(), v.pop_back();
    }
  }
  if (res.size() != M) printf("impossible\n");
  else {
    for (auto [v, p] : res) printf("%d\n", p+1);
  }
  return 0;
}
