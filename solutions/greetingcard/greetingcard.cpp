#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll get_key(int a, int b) {
  ll res = a;
  res <<= 32;
  res += b;
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, x, y, res = 0;
  cin >> n;
  vi X(n), Y(n);
  unordered_set<ll> P;
  for (int i = 0; i < n; ++i) {
    cin >> X[i] >> Y[i];
    P.insert(get_key(X[i], Y[i]));
  }

  vi DX = {-2018, -1680, -1680, -1118, -1118, 0, 0, 1118, 1118, 1680, 1680, 2018};
  vi DY = {0, -1118, 1118, -1680, 1680, -2018, 2018, -1680, 1680, -1118, 1118, 0};
  for (int i = 0; i < n; ++i) {
    P.erase(get_key(X[i], Y[i]));
    for (int j = 0; j < DX.size(); ++j) {
      x = X[i] + DX[j], y = Y[i] + DY[j];
      if (x < 0 || y < 0) continue;
      if (P.find(get_key(x, y)) != P.end()) ++res;
    }
  }
  printf("%d\n", res);
  return 0;
}
