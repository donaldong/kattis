#include <bits/stdc++.h>
using namespace std;

int N, M;
// Parents
vector<int> P;

int find(int n) {
  if (P[n] == -1) return n;
  P[n] = find(P[n]);
  return P[n];
}

int main() {
  cin >> N >> M;
  P = vector<int>(N, -1);
  vector<tuple<int, int, int>> L(M);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    L[i] = make_tuple(c, a, b);
  }
  sort(L.begin(), L.end());
  int res = 0;
  for (auto &l : L) {
    int a, b, c;
    tie(c, a, b) = l;
    int pa = find(a), pb = find(b);
    if (pa != pb) {
      P[pb] = pa;
      res = max(res, c);
    }
  }
  for (int i = 1; i < N; ++i) {
    if (find(i) != find(i - 1)) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  cout << res << endl;
  return 0;
}
