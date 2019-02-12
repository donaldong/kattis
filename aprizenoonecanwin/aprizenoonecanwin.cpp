#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  uint n, x, a = 0, k, res = 0;
  cin >> n >> x;
  
  while (n--) {
    cin >> k;
    if (a + k <= x) {
      ++res;
      a = max(a, k);
    } else {
      a = min(a, k);
    }
  }

  printf("%u\n", max(res, 1u));
  return 0;
}
