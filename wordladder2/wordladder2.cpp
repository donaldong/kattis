#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;
using v2i = vector<vi>;
using ti2 = tuple<int, int>;
using ti3 = tuple<int, int, int>;
using vti2 = vector<ti2>;
using vti3 = vector<ti3>;
int N, INF = 1e9;
vs words;
v2i D;

int word_dist(int a, int b) {
  int res = 0;
  for (size_t i = 0; i < words[a].size(); ++i) {
    if (words[a][i] != words[b][i]) ++res;
  }
  return res;
}

vs diffs(int a, int b) {
  vs res;
  vi pos;
  for (size_t i = 0; i < words[a].size(); ++i) {
    if (words[a][i] != words[b][i]) pos.push_back(i);
  }
  string A, B = words[b];
  A = words[a];
  A[pos[0]] = B[pos[0]];
  res.push_back(A);
  A = words[a];
  A[pos[1]] = B[pos[1]];
  res.push_back(A);
  return res;
}

string solve(vti2 &pairs) {
  int a, b;
  string res;
  for (auto &p : pairs) {
    tie(a, b) = p;
    vs R = diffs(a, b);
    if (res.empty()) res = R[0];
    res = min(res, R[0]);
    res = min(res, R[1]);
  }
  return res;
}

vti2 trace(v2i &dist, int cur) {
  vti2 res;
  queue<int> Q;
  Q.push(cur);
  while (!Q.empty()) {
    cur = Q.front(); Q.pop();
    for (int i = 0; i < N; ++i) {
      int d = D[i][cur];
      if (d > 2) continue;
      if (d == 2 && dist[i][0] + d == dist[cur][1]) {
        res.emplace_back(i, cur);
      }
      if (d == 1 && dist[i][1] + d == dist[cur][1]) {
        Q.push(i);
      }
    }
  }
  return res;
}

int dijkstra(int src, int dest, vti2 &pairs) {
  int cur, nxt, k, nk, s, ns, d;
  v2i dist(N, vi(2, INF));
  priority_queue<ti3, vti3, greater<ti3>> Q;
  Q.emplace(0, 0, src);
  dist[src][0] = 0;
  while (!Q.empty()) {
    tie(s, k, cur) = Q.top(); Q.pop();
    for (nxt = 0; nxt < N; ++nxt) {
      d = D[cur][nxt];
      nk = d == 2;
      if (d > 2 || (nk && k)) continue;
      if (k) nk = 1;
      if (s + d < dist[nxt][nk]) {
        dist[nxt][nk] = s + d;
        Q.emplace(s + d, d == 2 ? 1 : k, nxt);
      }
    }
  }
  if (dist[dest][0] <= dist[dest][1]) return dist[dest][0];
  pairs = trace(dist, dest);
  return dist[dest][1];
}

int main() {
  cin >> N;
  words.resize(N);
  D.assign(N, vi(N, INF));
  for (auto &word : words) cin >> word;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      D[i][j] = D[j][i] = word_dist(i, j);
    }
  }
  vti2 pairs;
  int steps = dijkstra(0, 1, pairs);
  if (steps == -1 || pairs.empty()) cout << 0 << endl;
  else cout << solve(pairs) << endl;
  cout << (steps == INF ? -1 : steps) << endl;
  return 0;
}
