#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<double,double>> T;
vector<int> uf;

int ufFind(int i) {
  if (uf[i] == i || uf[i] < 0) return uf[i] = i;
  return uf[i] = ufFind(uf[i]);
}

void ufUnion(int a, int b) {
  uf[b] = a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int E, P;
  cin >> N >> E >> P;
  T.resize(N), uf.assign(N, -1);
  for (auto& p : T) cin >> p.first >> p.second;

  for (int i = 1; i < E; ++i) {
    int a = ufFind(0), b = ufFind(i);
    if (a != b) ufUnion(a, b);
  }

  while (P--) {
    int a, b;
    cin >> a >> b;
    a = ufFind(a-1), b = ufFind(b-1);
    if (a != b) ufUnion(a, b);
  }

  vector<tuple<double,int,int>> edges;
  edges.reserve(N*N);
  for (int i = 0; i < N; ++i) for (int j = i+1; j < N; ++j) {
    double dx = T[i].first-T[j].first, dy = T[i].second-T[j].second;
    edges.emplace_back(sqrt(dx*dx+dy*dy), i, j);
  }
  sort(edges.begin(), edges.end());

  double res = 0.0;
  for (auto& [d, i, j] : edges) {
    int a = ufFind(i), b = ufFind(j);
    if (a == b) continue;
    ufUnion(a, b);
    res += d;
  }

  cout << setprecision(12) << res << endl;
  return 0;
}
