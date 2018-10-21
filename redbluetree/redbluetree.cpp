#include <bits/stdc++.h>
using namespace std;

struct edge {
  int a, b;
  char c;
};

using vi = vector<int>;
using ve = vector<edge>;

int find(vi &P, int n) {
  if (P[n] == -1) return n;
  return P[n] = find(P, P[n]);
}

void join(vi &P, edge &e) {
  int a, b;
  a = find(P, e.a), b = find(P, e.b);
  if (a != b) P[b] = a;
}

bool possible(ve &E, int n, int k) {
  int b = 0, r = 0;
  vi B(n, -1), R(n, -1);
  for (auto &e : E) {
    if (e.c == 'R') join(R, e);
    else join(B, e);
  }
  for (int e : B) if (e != -1) ++b;
  for (int e : R) if (e == -1) ++r;
  --r;
  return r <= k && k <= b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k, a, b;
  cin >> n >> m >> k;
  ve E(m);
  for (auto &e : E) {
    cin >> e.c >> e.a >> e.b;
    --e.a, --e.b;
  }
  cout << (possible(E, n, k) ? 1 : 0) << endl;
  return 0;
}
