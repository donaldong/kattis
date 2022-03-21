#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi P, R;

int find(int n) {
  if (P[n] == -1 || P[n] == n) return n;
  return P[n] = find(P[n]);
}

void join(int a, int b) {
  if (R[a] < R[b]) swap(a, b);
  R[a] += R[b], P[b] = a;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q, a, b, ra, rb;
  char cmd;
  cin >> n >> q;
  P.assign(n + 1, -1), R.assign(n + 1, 1);
  while (q--) {
    cin >> cmd;
    if (cmd == 't') {
      cin >> a >> b;
      ra = find(a), rb = find(b);
      if (ra != rb) join(ra, rb);
    } else {
      cin >> a;
      ra = find(a);
      printf("%d\n", R[ra]);
    }
  }
  return 0;
}
