#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int MAX_M = 5e5;
vi RANK(MAX_M + 1, 1), P(MAX_M + 1, -1);

int find(int n) {
  if (P[n] == n || P[n] == -1) return n;
  return P[n] = find(P[n]);
}

void join(int a, int b) {
  if (RANK[a] >= RANK[b]) {
    RANK[a] += RANK[b], RANK[b] = 0;
    P[b] = a;
  } else {
    RANK[b] += RANK[a], RANK[a] = 0;
    P[a] = b;
  }
#ifdef DEBUG
  printf("rank[%d] = %d, rank[%d] = %d\n",
    a, RANK[a], b, RANK[b]);
#endif
}

bool solve(vi &M) {
  unordered_map<int, int> R;
  for (int m : M) {
    int p = find(m);
    R[p] = RANK[p];
  }
  for (int m : M) --R[find(m)];
  for (auto &e : R) if (e.second) return false;
  for (int i = 1; i < M.size(); ++i) {
    int a = find(M[0]), b = find(M[i]);
    if (a != b) join(a, b);
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, k, res = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> m;
    vi M(m);
    for (auto &e : M) cin >> e;
    if (solve(M)) ++res;
  }
  printf("%d\n", res);
  return 0;
}
