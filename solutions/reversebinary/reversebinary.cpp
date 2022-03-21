#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int res = 0, j;
  for (int i = 0; i < 32; ++i) {
    j = 1 << i;
    if (j > n) break;
    res *= 2;
    if (n & j) res += 1;
  }
  cout << res << endl;
  return 0;
}
