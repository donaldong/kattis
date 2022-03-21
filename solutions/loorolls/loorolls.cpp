#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll L;

int solve(ll n) {
  if (L % n == 0) return 1;
  return solve(n - L % n) + 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ll n;
  cin >> L >> n;
  printf("%d\n", solve(n));
  return 0;
}
