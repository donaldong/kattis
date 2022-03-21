#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int N, M, D;
vi AX, AY, BX, BY, vis, match;

int as_int(string &s) {
  int res = 0;
  for (char c : s) if (c != '.') res = 10 * res + c - '0';
  return res;
}

bool reach(int a, int b) {
  int dx = AX[a] - BX[b];
  int dy = AY[a] - BY[b];
  return dx * dx + dy * dy <= D * D;
}

bool aug(int a) {
  if (vis[a]) return false;
  vis[a] = 1;
  for (int b = 0; b < M; ++b) {
    if (reach(a, b) && (match[b] < 0 || aug(match[b]))) {
      match[b] = a;
      return true;
    }
  }
  return false;
}

int max_match() {
  int res = 0;
  match.assign(M, -1);
  for (int i = 0; i < N; ++i) {
    vis.assign(N, 0);
    if (aug(i)) ++res;
  }
  return res;
}

int main() {
  int s, v;
  while (cin >> N >> M >> s >> v) {
    AX.resize(N), AY.resize(N);
    BX.resize(M), BY.resize(M);
    D = s * v * 10;
    string x, y;
    for (int i = 0; i < N; ++i) {
      cin >> x >> y;
      AX[i] = as_int(x), AY[i] = as_int(y);
    }
    for (int i = 0; i < M; ++i) {
      cin >> x >> y;
      BX[i] = as_int(x), BY[i] = as_int(y);
    }
    printf("%d\n", N - max_match());
  }
  return 0;
}
