#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, int, int> ti;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<ti> vti;

vb vis;
vi popped, SCC_ID; // popped nodes, the scc the node belongs to
v2i G, GT; // Graph, and its transpose

bool reachable(const ti &A, const ti &B, bool left) {
  int x1 = get<0>(A), x2 = get<0>(B), r = get<1>(B);
  ll t = x2;
  t = left ? t - r : t + r;
  return left ? (t <= x1 && x1 < x2) : (t >= x1 && x1 > x2);
}

vi build(const vti & P, bool left) {
  int x, r, a, b;
  vi S;
  vi res(P.size());
  for (size_t i = 0; i < P.size(); ++i)
    res[get<2>(P[i])] = left ? i : P.size() - i - 1;
  for (size_t i = 0; i < P.size(); ++i) {
    a = get<2>(P[i]);
    while (!S.empty() && reachable(P[S.back()], P[i], left)) {
      b = get<2>(P[S.back()]), S.pop_back();
#ifdef DEBUG
    printf("add edge: %d => %d\n", a + 1, b + 1);
#endif
      G[a].push_back(b), GT[b].push_back(a);
      if (left) res[a] = min(res[a], res[b]);
      else res[a] = max(res[a], res[b]);
    }
    S.push_back(i);
  }
  return res;
}

void dfs_sort(int n) {
  for (int c : G[n]) if (!vis[c]) {
#ifdef DEBUG
    printf("dfs_sort: %d => %d\n", n + 1, c + 1);
#endif
    vis[c] = true;
    dfs_sort(c);
  }
#ifdef DEBUG
    printf("dfs_sort add: %d\n", n + 1);
#endif
  popped.push_back(n);
}

void dfs_mark(int n, int id) {
  for (int c : GT[n]) if (!vis[c]) {
#ifdef DEBUG
    printf("dfs_mark: %d => %d\n", n + 1, c + 1);
#endif
    vis[c] = true;
    dfs_mark(c, id);
  }
#ifdef DEBUG
  printf("node %d belongs to scc %d\n", n + 1, id);
#endif
  SCC_ID[n] = id;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, r, i, id = 0;
  cin >> n;
  vti P(n), SCC; // points, strongly connected components
  vis.assign(n, false);
  SCC_ID.resize(n);
  G.resize(n), GT.resize(n);
  for (i = 0; i < n; ++i) {
    cin >> x >> r;
    P[i] = {x, r, i};
  }
  vi L, R;
  sort(P.begin(), P.end());
  L = build(P, true);
  reverse(P.begin(), P.end());
  R = build(P, false);
#ifdef DEBUG
  printf("left most: ");
  for (int i = 0; i < n; ++i) printf("%d ", L[i]);
  printf("\n");
  printf("right most: ");
  for (int i = 0; i < n; ++i) printf("%d ", R[i]);
  printf("\n");
#endif

  for (i = 0; i < n; ++i) if (!vis[i]) vis[i] = true, dfs_sort(i);
  vis.assign(n, false);
  while (!popped.empty()) {
    r = popped.back(), popped.pop_back();
    if (!vis[r]) vis[r] = true, dfs_mark(r, id++);
  }

  vi SCC_L(id, -1), SCC_R(id, -1);
  for (i = 0; i < n; ++i) {
    id = SCC_ID[i];
    if (SCC_L[id] < 0) SCC_L[id] = L[i];
    else SCC_L[id] = min(L[i], SCC_L[id]);
    if (SCC_R[id] < 0) SCC_R[id] = R[i];
    else SCC_R[id] = max(R[i], SCC_R[id]);
  }
#ifdef DEBUG
  for (i = 0; i < n; ++i) {
    printf("%d ", SCC_ID[i]);
  }
  printf("\n");
#endif

  for (i = 0; i < n; ++i) {
    id = SCC_ID[i];
    printf("%d ", SCC_R[id] - SCC_L[id] + 1);
  }
  printf("\n");
  return 0;
}
