/**
 * @date        2022-03-26
 * @tags        union find, graph
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N,M,K;
  cin >> N >> M >> K;
  vector<int> P(K, -1);
  vector<string> G(N);
  for (auto& row : G) cin >> row;

  function<int(int)> ufFind = [&](int i) {
    if (P[i] == -1 || P[i] == i) return i;
    return P[i] = ufFind(P[i]);
  };

  for (int c = 0; c < M; ++c) for (int r = 1; r < N; ++r)  {
    int a = ufFind(G[r-1][c]-'A'), b = ufFind(G[r][c]-'A');
    if (a != b) P[b] = a;
  }

  set<int> S;
  for (int i = 0; i < K; ++i) S.insert(ufFind(i));
  cout << S.size() << endl;
  return 0;
}
