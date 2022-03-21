#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  int n, p, s, tot = 0;
  cin >> n >> p;
  for (int i = 0; i < n; ++i) cin >> s, tot += p - s;

  if (p == 100) printf("impossible\n");
  else {
    int k = 100 - p;
    s = tot / k;
    if (tot % k) ++s;
    printf("%d\n", s);
  }
  return 0;
}
