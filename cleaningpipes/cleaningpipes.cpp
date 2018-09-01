#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ti2 = tuple<int, int>;
using ti3 = tuple<int, int, int>;
using vti2 = vector<ti2>;
using vti3 = vector<ti3>;

vi N;

int find(int n) {
  if (N[n] == -1) return n;
  return N[n] = find(N[n]);
}

bool intersect(vti2 &W, ti3& A, ti3 &B) {
  vi X(4), Y(4);
  int i, j; 
  tie(i, X[1], Y[1]) = A;
  tie(j, X[3], Y[3]) = B;
  if (i == j) return false;
  tie(X[0], Y[0]) = W[i];
  tie(X[2], Y[2]) = W[j];
  bool aymin = min(Y[0], Y[1]);
  bool aymax = max(Y[0], Y[1]);
  bool bymin = min(Y[2], Y[3]);
  bool bymax = max(Y[2], Y[3]);
  if (aymin > bymax || bymin > aymax) return false;
  bool axmin = min(X[0], X[1]);
  bool axmax = max(X[0], X[1]);
  bool bxmin = min(X[2], X[3]);
  bool bxmax = max(X[2], X[3]);
  return axmin <= bxmax && bxmin <= axmax;
}

bool possible(vti2 &W, vti3 &P) {
  for (size_t i = 0; i < P.size(); ++i) {
    for (size_t j = i + 1; j < P.size(); ++j) {
      if (!intersect(W, P[i], P[j])) continue;
      int a = find(i), b = find(j);
      if (a == b) return false;
      N[b] = a; // join
    }
  }
  return true;
}

int main() {
  int w, p;
  cin >> w >> p;
  vti2 W(w);
  for (auto &e : W) {
    int x, y;
    cin >> x >> y;
    e = make_tuple(x, y);
  } 
  vti3 P(p);
  N = vi(p, -1);
  for (auto &e : P) {
    int s, x, y;
    cin >> s >> x >> y;
    e = make_tuple(--s, x, y);
  }
  cout << (possible(W, P) ? "possible" : "impossible") << endl;
  return 0;
}
