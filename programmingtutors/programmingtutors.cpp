#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using ti = tuple<int, int>;
using vti = vector<ti>;

int dist(ti &a, ti &b) {
  return abs(get<0>(a) - get<0>(b)) + 
    abs(get<1>(a) - get<1>(b));
}

void connect(v2i &G, int a, int b) {
  G[a][b] = 1;
  G[b][a] = 0;
}

bool bfs(v2i &G, int s, int t, vi &P) {
  vector<bool> M(G.size(), false);
  M[s] = true;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (size_t i = 0; i < G[cur].size(); ++i) {
      if (!M[i] && G[cur][i] > 0) {
        M[i] = true;
        P[i] = cur;
        Q.push(i);
      }
    }
  }
  return M[t];
}

int max_flow(v2i &G, int s, int t) {
  int res = 0;
  vi P(G.size(), -1);
  while (bfs(G, s, t, P)) {
    int flow = 2;
    for (int cur = t; cur != s; cur = P[cur]) {
      int prev = P[cur];
      flow = min(flow, G[prev][cur]);
    }
    for (int cur = t; cur != s; cur = P[cur]) {
      int prev = P[cur];
      G[prev][cur] -= flow;
      G[cur][prev] += flow;
    }
    res += flow;
  }
  return res;
}

bool match(vti &S, vti &T, int d) {
  int size = S.size() + T.size() + 2;
  v2i G(size, vi(size, 0));
  int s = size - 2, t = size - 1;
  for (size_t i = 0; i < S.size(); ++i) {
    connect(G, s, i);
    for (size_t j = 0; j < T.size(); ++j) {
      if (dist(S[i], T[j]) <= d) {
        int k = j + S.size();
        connect(G, i, k);
        connect(G, k, t);
      }
    }
  }
  return max_flow(G, s, t) == S.size();
}

int main() {
  int n, x, y;
  cin >> n;
  vti S(n), T(n);
  for (int i = 0; i < n; ++i) cin >> x >> y, S[i] = make_tuple(x, y);
  for (int i = 0; i < n; ++i) cin >> x >> y, T[i] = make_tuple(x, y);
  vi D(n * n);
  int k = 0;
  for (auto &s : S) for (auto &t : T) D[k++] = dist(s, t);
  sort(D.begin(), D.end());
  int lo = 0, hi = D.size() - 1;
  while (hi > lo) {
    int mid = (lo + hi) / 2;
    if (!match(S, T, D[mid])) lo = mid + 1;
    else hi = mid;
  }
  cout << D[lo] << endl;
  return 0;
}
