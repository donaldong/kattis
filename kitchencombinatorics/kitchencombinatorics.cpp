#include <bits/stdc++.h>
using namespace std;

typedef long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> v2i;
typedef vector<ull> vull;
int s, m, d;
vb vis;
vi R, A, B, C;
v2i G, ING;
ull INF = 1e18;

bool add(ull &a, ull b) {
  if (b == -1) {
    a = -1;
    return false;
  }
  __int128 t = a;
  t += b;
  if (t > INF) {
    a = -1;
    return false;
  }
  a = t;
  return true;
}

bool mul(ull &a, ull b) {
  if (b == -1) {
    a = -1;
    return false;
  }
  __int128 t = a;
  t *= b;
  if (t > INF) {
    a = -1;
    return false;
  }
  a = t;
  return true;
}

ull solve() {
  vi count(R.size(), 0);
  for (int i = 0; i < vis.size(); ++i) {
    if (vis[i]) for (int r : ING[i]) ++count[r];
#ifdef DEBUG
    if (vis[i]) printf("use dish %d\n", i + 1);
#endif
  }
#ifdef DEBUG
  printf("ingrediants count:\n");
  for (int i = 0; i < count.size(); ++i) {
    printf("%d ", count[i]);
  }
  printf("\n");
#endif
  ull res = 1;
  for (int i = 0; i < count.size(); ++i) {
    if (!count[i]) continue;
    if (!mul(res, R[i])) break;
  }
#ifdef DEBUG
  for (int i = 0; i < count.size(); ++i) {
    if (!count[i]) printf("1 ");
    else printf("%d ", R[i]);
  }
  printf(" = %lld\n", res);
#endif
  return res;
}

bool skip(int i) {
  for (int c : G[i]) if (vis[c]) return true;
  return false;
}

ull solve(int k) {
  ull res = 0;
  if (k == 3) return solve();
  for (int i = A[k]; i < B[k]; ++i) {
    if (skip(i)) continue;
    vis[i] = true;
    ull r = solve(k + 1);
    vis[i] = false;
    if (!add(res, r)) break;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r, n;
  cin >> r >> s >> m >> d >> n;
  R.resize(r), G.resize(s + m + d), ING.resize(G.size());
  vis.assign(G.size(), false), C.assign(r, 0);
  A = {0, s, s + m};
  B = {s, s + m, s + m + d};
  for (int i = 0; i < r; ++i) cin >> R[i];
  for (int i = 0; i < ING.size(); ++i) {
    int k;
    cin >> k;
    ING[i] = vi(k);
    for (auto &e : ING[i]) cin >> e, --e;
  }
#ifdef DEBUG
  for (int i = 0; i < ING.size(); ++i) {
    for (auto &e : ING[i]) printf("dish %d has ing %d\n", i + 1, e + 1);
  }
#endif
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b), G[b].push_back(a);
  }
  ull res = solve(0);
  if (res == -1) printf("too many\n");
  else printf("%lld\n", res);
  return 0;
}
