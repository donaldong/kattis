#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ti = tuple<int, int>;
using vti = vector<ti>;

int main() {
  int n, val, index;
  while (cin >> n) {
    if (!n) break;
    vti A(n);
    for (int i = 0; i < n; ++i) {
      cin >> val;
      A[i] = make_tuple(val, i);
    }
    sort(A.begin(), A.end());
    vi order(n), B(n);
    for (int i = 0; i < n; ++i) {
      tie(val, index) = A[i];
      order[index] = i;
    }
    for (int &b : B) cin >> b;
    sort(B.begin(), B.end());
    for (int i : order) cout << B[i] << endl;
    cout << endl;
  }
  return 0;
}
