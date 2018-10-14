#include <bits/stdc++.h>
using namespace std;

int fix(int n) {
  while (n % 10 == 0) n /= 10;
  return n % 10;
}

int f(int n) {
  int res = 1;
  for (int i = 2; i <= n; ++i) {
    res *= i;
    res = fix(res);
  }
  return res % 10;
}

int solve(int a, int b) {
  if (!b) return 1;
  int res = fix(a * a);
  if (b & 1) return fix(res * a);
  return res;
}

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    int k = n / 10;
    int res = f(n % 10);
    cout << res << " " << k << endl;
    cout << fix(res * solve(8, k)) << endl;
  }
  return 0;
}
