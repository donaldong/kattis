#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int MAXN = 2e5 + 1;
int SQRTN = 448;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q, t, a, b, c;
  cin >> n >> q;
  vi V(MAXN, 0);
  v2i T(SQRTN, vi(SQRTN, 0));
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> a >> b >> c;
      if (b < SQRTN) T[b][a] += c;
      else for (int i = a; i < MAXN; i += b) V[i] += c;
    } else {
      cin >> a;
      int res = V[a];
      for (int i = 1; i < SQRTN; ++i) res += T[i][a % i];
      printf("%d\n", res);
    }
  }
  return 0;
}
