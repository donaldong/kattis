#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<tuple<ll, int>> vt;

vt S;
vi st;

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }

void insert(int p, int L, int R, int n) {
  if (L == R) st[p] = 1;
  else {
    int mid = (L + R) / 2;
    if (L <= n && n <= mid) insert(left(p), L, mid, n);
    if (mid + 1 <= n && n <= R) insert(right(p), mid + 1, R, n);
    ++st[p];
  }
}

int query(int p, int L, int R, int n) {
  if (n < L) return 0;
  if (R <= n) return st[p];
  int mid = (L + R) / 2;
  return query(left(p), L, mid, n) + \
    query(right(p), mid + 1, R, n);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, p, j;
  cin >> n;
  vi N(n);
  for (int i = 0; i < n; ++i) cin >> N[i];
  cin >> p;
  ll sum = 0, res = 0;
  S.resize(n);
  st.assign(4 * n, 0);
  for (int i = 0; i < n; ++i) {
    sum += N[i] - p;
    S[i] = {sum, i};
    if (sum >= 0) ++res;
  }
  sort(S.begin(), S.end());
  for (int i = 0; i < n; ++i) {
    tie(sum, j) = S[i];
#ifdef DEBUG
    printf("sum: %lld, index: %d, res: %lld\n", sum, j, res);
#endif
    res += query(1, 0, n - 1, j);
#ifdef DEBUG
    printf("new res: %lld\n", res);
#endif
    insert(1, 0, n - 1, j);
  }
  printf("%lld\n", res);
  return 0;
}
