#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  unordered_map<int,int> h;
  for (int v, k = 1; k <= m; ++k) {
    cin >> v;
    h[v] = k;
    long long res = n-h.size();
    res *= k;
    for (auto& [_,c] : h) res += k-c;
    printf("%lld\n",res);
  }
  return 0;
}
