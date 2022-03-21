#include <bits/stdc++.h>
using namespace std;

int MAXN = 251;
int b, c, d, l;

bool solve() {
  bool f = false;
  for (int i = 0; i < MAXN; ++i) for (int j = 0; j < MAXN; ++j) {
    for (int k = 0; k < MAXN; ++k) {
      if (i * b + j * c + k * d == l) {
        f = true;
        printf("%d %d %d\n", i, j, k);
      }
    }
  }
  return f;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> b >> c >> d >> l;
  if (!solve()) printf("impossible\n");
  return 0;
}
