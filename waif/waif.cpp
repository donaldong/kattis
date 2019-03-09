#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> v2i;
int INF = 1e9;
int SIZE, S, T, group, toy;
v2i G;

#ifdef DEBUG
void tag(int n) {
  if (n == T) printf("Target");
  else if (n == S) printf("Source");
  else if (n >= toy) printf("toy %d", n - toy + 1);
  else if (n >= group) printf("group %d", n - group);
  else printf("child %d", n + 1);
}
#endif

bool bfs(vi &P) {
  int a, b;
  queue<int> Q;
  vb vis(SIZE, false);
  vis[S] = true;
  Q.push(S);
  while (!Q.empty()) {
    a = Q.front(), Q.pop();
    for (b = 0; b < SIZE; ++b) {
      if (G[a][b] <= 0 || vis[b]) continue;
#ifdef DEBUG
      tag(a), printf(" => "), tag(b);
      printf("\n");
#endif
      P[b] = a;
      if (b == T) return true;
      vis[b] = true;
      Q.push(b);
    }
  }
  return false;
}

int max_flow() {
  int res = 0, a, b;
  vi P(SIZE, -1);
  while (bfs(P)) {
    for (b = T; b != S; b = a) {
      a = P[b];
      G[a][b] -= 1;
      G[b][a] += 1;
    }
    ++res;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p, k, r;
  cin >> n >> m >> p;

  vi P(m);
  ++p; // cat unknown
  group = n, toy = n + p;
  S = toy + m, T = S + 1, SIZE = T + 1;
  G.assign(SIZE, vi(SIZE, 0));
  for (int i = 0; i < n; ++i) {
    cin >> k;
    int t;
    G[S][i] = 1; // src -> child
    while (k--) cin >> t, G[i][toy + t - 1] = 1; // child -> toy
  }
  G[group][T] = INF;
  for (int i = 1; i < p; ++i) {
    cin >> k;
    vi toys(k);
    for (auto &t : toys) cin >> t, --t;
    cin >> G[group + i][T]; // group -> target
    for (auto t : toys) P[t] = i;
  }
  for (int i = 0; i < m; ++i) G[toy + i][group + P[i]] = 1; // toy -> group
  printf("%d\n", max_flow());
  return 0;
}
