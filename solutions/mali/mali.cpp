#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int solve(vi A, vi B) {
  int a = 1, b = 100, k, res = 0;
  while (a <= 100 && b > 0) {
    if (!A[a]) {
      ++a;
      continue;
    }
    if (!B[b]) {
      --b;
      continue;
    }
    k = min(A[a], B[b]);
    A[a] -= k, B[b] -= k;
    res = max(res, a + b);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, a, b;
  cin >> n;
  vi A(101, 0), B(101, 0);
  while (n--) {
    cin >> a >> b;
    ++A[a], ++B[b];
    printf("%d\n", solve(A, B));
  }
  return 0;
}
