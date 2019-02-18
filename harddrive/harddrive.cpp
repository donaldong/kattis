#include <bits/stdc++.h>
using namespace std;

char next(bool &on, int &c, bool b) {
#ifdef DEBUG
  printf("[%d %d %d] %d\n", on, c, b, c > 0 && (!b || (b && on)));
#endif
  if (c > 0 && (!b || (b && on))) {
    --c;
    on = !on;
  }
  return on ? '1' : '0';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c, b;
  cin >> n >> c >> b;

  int B[b];
  for (int i = 0; i < b; ++i) cin >> B[i];

  bool on = false, f = c % 2;
  if (f) --c;
  string res;
  for (int i = b - 1; i >= 0; --i) {
    while (n > B[i]) --n, res += next(on, c, false);
    res += next(on, c, true);
    --n;
  }
  while (n > 1) --n, res += next(on, c, false);
  res += f ? '1' : '0';

  for (auto itr = res.rbegin(); itr != res.rend(); ++itr) printf("%c", *itr);
  printf("\n");

  return 0;
}
