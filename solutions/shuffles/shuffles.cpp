#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n;
  int count = 0;
  vb expected(n + 2, false);
  while (n--) {
    cin >> k;
    if (!expected[k]) ++count;
    expected[k + 1] = true;
  }
  for (int i = 0; i < 32; ++i) {
    if ((1 << i) >= count) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
