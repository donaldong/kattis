#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ld A = log10(2), B = log10(11);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a = n, b = 0;
    while (int(A * a + B * b) != n - 1) {
      --a, ++b;
    }
    for (int i = 0; i < a; ++i) cout << "2 ";
    for (int i = 0; i < b; ++i) cout << "11 ";
    cout << endl;
  }
  return 0;
}
