#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

int main() {
  int n, a, b, v, t = 0;
  while (cin >> n) {
    printf("Case %d: ", ++t);
    a = INF, b = -INF;
    while (n--) {
      cin >> v;
      a = min(a, v), b = max(b, v);
    }
    printf("%d %d %d\n", a, b, b - a);
  }
  return 0;
}
