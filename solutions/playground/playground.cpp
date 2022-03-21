#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef vector<ld> vld;

bool possible(vld &P) {
  ld sum = 0, p = 0;
  sort(P.begin(), P.end());
  for (size_t i = 0; i < P.size(); ++i) {
    p = P[i] > p ? P[i] : p;
    sum += P[i];
    if (p + p <= sum) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  while (cin >> k) {
    if (!k) break;
    vld P(k);
    for (int i = 0; i < k; ++i) cin >> P[i];
    printf("%s\n", possible(P) ? "YES" : "NO");
  }
  return 0;
}
