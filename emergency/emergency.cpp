#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;
  ll res = K;
  ll a = N / K;
  if (a) res += N % a;
  else res = N - 1;
  cout << res << endl;
  return 0;
}
