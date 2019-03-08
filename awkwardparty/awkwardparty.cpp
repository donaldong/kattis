#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<int, int> hmap;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n;
  hmap D;
  int res = n;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    if (D.find(k) != D.end()) {
      res = min(res, i - D[k]);
    }
    D[k] = i;
  }
  printf("%d\n", res);
  return 0;
}
