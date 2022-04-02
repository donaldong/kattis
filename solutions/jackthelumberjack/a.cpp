/**
 * @date        2022-04-01
 * @tags        prefix sum
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXY = 2000002;
array<ll, MAXY> D{0}, T{0};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n,y,d,s,b;
  cin >> n;
  while (n--) {
    cin >> y >> d >> s >> b;
    T[b] += s;
    if (!d) continue;
    D[b+1] += d;
    int yStartDecr = b+1+y;
    D[yStartDecr] -= d*2;
    ll peak = (ll)y*d+s;
    ll yearsToDieOut = peak/d;
    int rem = peak%d;
    ll yDieOut = yStartDecr + yearsToDieOut;
    if (yDieOut < MAXY) D[yDieOut] += d-rem;
    if (yDieOut+1 < MAXY) D[yDieOut+1] += rem;
  }
  ll res = T[0]+D[0];
  for (int i = 1; i < MAXY; ++i) D[i] += D[i-1];
  for (int i = 1; i < MAXY; ++i) {
    T[i] += T[i-1] + D[i];
    res = max(res, T[i]);
  }
  cout << res << endl;
  return 0;
}
