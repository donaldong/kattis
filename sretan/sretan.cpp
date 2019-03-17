#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll n, cur = 2;
  cin >> n;
  --n;
  while (n >= cur) n -= cur, cur <<= 1;
  while (cur > 1) {
    cur >>= 1;
    if (n & cur) cout << '7';
    else cout << '4';
  }
  cout << endl;
  return 0;
}
