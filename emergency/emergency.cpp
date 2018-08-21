#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;
  ll res = K;
  ll a = (N - 1)/ K;
  if (a > 1) res += (N - 1) % K + 1;
  else res = N - 1;
  cout << res << endl;
  return 0;
}
