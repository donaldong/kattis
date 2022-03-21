#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
vi st, V;

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }

void build(int p, int L, int R) {
  if (L == R) st[p] = V[L];
  else {
    int mid = (L + R) / 2;
    build(left(p), L, mid);
    build(right(p), mid + 1, R);
    st[p] = max(st[left(p)], st[right(p)]);
  }
}

int rmq(int p, int L, int R, int i, int j) {
  if (i > R || j < L) return 0;
  if (L >= i && R <= j) return st[p];
  int mid = (L + R) / 2;
  return max(
    rmq(left(p), L, mid, i, j),
    rmq(right(p), mid + 1, R, i, j)
  );
}

int main() {
  ios::sync_with_stdio(0);

  while (true) {
    int n, m, x, y;
    scanf("%d", &n);
    if (!n) break;

    vi Y(n);
    V.resize(n);
    st.assign(4 * n, 0);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &Y[i], &V[i]);
    }
    build(1, 0, n - 1);

    scanf("%d", &m);
    while (m--) {
      int res;
      scanf("%d %d", &y, &x);
      auto a = lower_bound(Y.begin(), Y.end(), y);
      auto b = lower_bound(Y.begin(), Y.end(), y + 1);
      auto c = lower_bound(Y.begin(), Y.end(), x);
#ifdef DEBUG
      printf("a: %d, ", a == Y.end() ? -1 : *a);
      printf("b: %d, ", b == Y.end() ? -1 : *b);
      printf("c: %d\n", c == Y.end() ? -1 : *c);
#endif
      bool dne_a = a == Y.end() || *a != y;
      bool dne_b = b == Y.end() || b == c;
      bool dne_c = c == Y.end() || *c != x;
      int i = distance(Y.begin(), a);
      int j = distance(Y.begin(), b);
      int k = distance(Y.begin(), c);
      int va = dne_a ? INT_MAX : V[i];
      int vb = dne_b ? 0 : rmq(1, 0, n - 1, j, k - 1);
      int vc = dne_c ? va : V[k];

      if (dne_a) {
        if (dne_b || dne_c) res = 2;
        else res = vb < vc ? 2 : 0;
      } else {
        if (dne_b) {
          if (dne_c) res = 2;
          else {
            res = vc <= va ? 2 : 0;
            if (res && y + 1 == x) res = 1;
          }
        } else {
          if (dne_c) res = vb < va ? 2 : 0;
          else {
            res = vc <= va && vb < vc;
            if (res && k - i != x - y) res = 2;
          }
        }
      }

      if (res == 0) printf("false\n");
      else if (res == 1) printf("true\n");
      else printf("maybe\n");
    }
    printf("\n");
  }
  return 0;
}
