#include <bits/stdc++.h>
using namespace std;

int main() {
  int b, br, bs, a, as;
  cin >> b >> br >> bs >> a >> as;
  int t = (br - b) * bs;
  int r = t / as;
  if (r * as <= t) r++;
  cout << a + r << endl;
  return 0;
}
