#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  switch (m) {
  case 1: cout << 1 << endl; break;
  case 2: cout << 3 << endl; break;
  default: {
    m -= 2;
    queue<pair<int,int>> bits;
    bits.emplace(2,1);
    bits.emplace(2,2);
    int bit, len = 0;
    while (true) {
      auto [b,l] = bits.front();
      bit = b, len = l;
      bits.pop();
      if (m <= b) break;
      m -= b;
      bits.emplace(b<<1, l+2);
    }
#ifdef DEBUG
    printf("bit=%d, len=%d\n", bit, len);
#endif
    long long res = 1;
    while (len > 0) {
      res <<= 1;
      if (m > bit>>1) res += 1, m -= bit>>1;
      bit >>= 1;
      len -= 2;
    }
    long long rev = res;
    if (len < 0) rev >>= 1;
    while (rev) {
      res <<= 1;
      res += rev & 1;
      rev >>= 1;
    }
    cout << res << endl;
    break;
  }
  }
  return 0;
}
