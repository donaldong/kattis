#include <bits/stdc++.h>
using namespace std;

using ti2 = tuple<int, int>;
using vti2 = vector<ti2>;
using v2ti2 = vector<vti2>;
using v3ti2 = vector<v2ti2>;
using v4ti2 = vector<v3ti2>;

int INF = 1e9;
int P, Q;
v4ti2 M;

int happiness(int p, int q, int h) {
  if ((p & 1) && (q & 1)) {
    return h ? 1 : -1;
  } 
  return 0;
}

ti2 S(int p, int q, int h);

ti2 B(int p, int q, bool h) {
  int res, k;
  tie(res, k) = M[0][p][q][h];
  if (k != -1) return M[0][p][q][h];
  res = happiness(p, q, h), k = p;
  for (int i = 1; i < p; ++i) {
    bool h1 = h;
    if (i & 1) h1 = !h1;
    int l = p - i;
    int r = happiness(i, q, h) + get<0>(
      B(l,  q - get<1>(S(l, q, h1)), h1)
    );
    if (r > res) {
      res = r;
      k = i;
    }
  }
  M[0][p][q][h] = make_tuple(res, k);
  return M[0][p][q][h]; 
}

ti2 S(int p, int q, int h) {
  int res, k;
  tie(res, k) = M[1][p][q][h];
  if (k != -1) return M[1][p][q][h];
  res = happiness(p, q, h), k = q;
  for (int i = 1; i < q; ++i) {
    bool h1 = h, h2 = h;
    if (i & 1) h1 = !h1;
    int l = q - i;
    int d = get<1>(B(p, l, h));
    if (d & 1) h2 = !h2;
    int r = happiness(p, i, h1) + get<0>(S(p - d, l, h2));
    if (r > res) {
      res = r;
      k = i;
    }
  }
  M[1][p][q][h] = make_tuple(res, k);
  return M[1][p][q][h]; 
}

int solve() {
  int a, b, c;
  bool f = true;
  tie(a, c) = B(P, Q, f);
  if (c & 1) f = !f;
  tie(b, c) = S(P - c, Q, f);
  return a - b;
}

int main() {
  cin >> Q >> P;
  M = v4ti2(
    2, v3ti2(
      P + 1, v2ti2(
        Q + 1, vti2(
          2, make_tuple(-INF, -1)
        )
      )
    )
  );
  cout << solve() << endl;
  return 0;
}
