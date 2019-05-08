#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int MAXN = 2e4 + 1;

double dist(int dx, int dy) {
  return sqrt(dx * dx + dy * dy);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  vi P(MAXN, 1);
  vi primes = {0};
  for (int i = 2; i < MAXN; ++i) {
    if (!P[i]) continue;
    primes.push_back(i);
    for (int j = i * i; j < MAXN; j += i) P[j] = 0;
  }

  int T, n, x, y, x1, y1, f;
  double d;
  cin >> T;
  while (T--) {
    cin >> n >> d;
    f = x = y = 0;
    while (n--) {
      cin >> x1 >> y1;
      if (d < 0) continue;
      d -= dist(x - x1, y - y1);
      if (d < 0) continue;
      x = x1, y = y1, ++f;
    }
    printf("%d\n", *(--upper_bound(primes.begin(), primes.end(), f)));
  }
  return 0;
}
