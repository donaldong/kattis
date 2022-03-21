#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long d = gcd(n, m);
  n /= d;
  m /= d;
  if (n%2 && m%2) cout << d << endl;
  else cout << 0 << endl;
  return 0;
}
