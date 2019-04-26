#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string team;
    long long res = 0, i = 1;
    vi R(n);
    for (auto &r : R) cin >> team >> r;
    sort(R.begin(), R.end());
    for (auto r : R) res += r > i ? r - i : i - r, ++i;
    printf("%lld\n", res);
  }
  return 0;
}
