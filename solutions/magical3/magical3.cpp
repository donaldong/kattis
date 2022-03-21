#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  if (n < 0) return 0;
  if (!n) return 4;
  int c2 = 0, c3 = 0, res = 0;
  while (n % 2 == 0) ++c2, n /= 2;
  while (n % 3 == 0) ++c3, n /= 3;
  if (c2 >= 2) res = 4;
  if (c3 >= 2) {
    if (!res) res = 9;
    else res = min(res, 9);
  }
  if (c2 >= 1 && c3 >= 1) {
    if (!res) res = 6;
    else res = min(res, 6);
  }
  long long k = 5;
  while (k * k <= n) {
    if (n % k == 0) {
      n = k;
      break;
    }
    k += 2;
  }
  if (n <= 3) return res;
  if (!res) return n;
  return min(res, n);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, r;
  while (cin >> n) {
    if (!n) break;
    r = solve(n - 3);
    if (r <= 3) printf("No such base\n");
    else printf("%d\n", r);
  }
  return 0;
}
