#include <bits/stdc++.h>
using namespace std;

#define hmap unordered_map
using ll = long long;
using ld = long double;

int main() {
  ll N;
  cin >> N;
  ld a = log(N);
  a /= log(2);
  ll k = a;
  cout << k + 1 << endl;
  ll i = 1;
  while (i <= N) {
    cout << i << " ";
    i *= 2;
  }
  cout << endl;
  return 0;
}
