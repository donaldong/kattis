#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using v2ll = vector<vll>;

ll ways(int r, int c) {
  if (r == 2 && c == 2) return 7;
  return 0;
}

int main() {
  int n = 4;
  vll A(n), B(n), D(n);
  A[0] = 3, A[1] = 17;
  B[0] = 2, B[1] = 6;
  for (int i = 2; i < n; ++i) {
    A[i] = A[i - 1] * 3 + A[i - 2] * 13;
  }
  for (int i = 0; i < n; ++i) cout << A[i] << " ";
  cout << endl;
  return 0;
}
