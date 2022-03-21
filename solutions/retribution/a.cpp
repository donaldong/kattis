#include <bits/stdc++.h>
using namespace std;
using vec = vector<pair<int,int>>;
double calc(vec& s, vec& t) {
  vector<bool> visS(s.size(), false), visT(t.size(), false);
  vector<tuple<double,int,int>> dists;
  dists.reserve(s.size()*t.size());
  for (int i = 0; i < s.size(); ++i) for (int j = 0; j < t.size(); ++j) {
    double dx = s[i].first-t[j].first, dy = s[i].second-t[j].second;
    dists.emplace_back(sqrt(dx*dx+dy*dy), i, j);
  }
  sort(dists.begin(), dists.end());
  double res = 0.0;
  for (auto& [d, i, j] : dists) {
    if (visS[i] || visT[j]) continue;
    visS[i] = visT[j] = true;
    res += d;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N,M,P;
  cin >> N >> M >> P;
  vec s(N), t1(M), t2(P);
  for (int i = 0; i < N; ++i) {
    int x,y;
    cin >> x >> y;
    s[i] = {x, y};
  }
  for (int i = 0; i < M; ++i) {
    int x,y;
    cin >> x >> y;
    t1[i] = {x, y};
  }
  for (int i = 0; i < P; ++i) {
    int x,y;
    cin >> x >> y;
    t2[i] = {x, y};
  }
  double res = 0.0;
  res += calc(s, t1);
  res += calc(s, t2);
  cout << setprecision(12) << res << endl;
  return 0;
}
