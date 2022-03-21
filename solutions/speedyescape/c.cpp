#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
  ifstream in("4.in");
  int t;
  int n, m, e, a, b, l, x, y;
  in >> t;
  cin >> t;
  vi A, B, C, E;
  while (t--) {
    in >> n >> m >> e;
    A = vi(m);
    B = A;
    C = A;
    for (int i = 0; i < m; ++i) {
      in >> A[i] >> B[i] >> C[i];
    }
    E = vi(e);
    for (auto &num : E) in >> num;
    in >> x >> y;
  }
  cout << 1 << endl;
  printf("%d %d %d\n", n, m, e);
  for (int i = 0; i < m; ++i) {
    printf("%d %d %d\n", A[i], B[i], C[i]);
  }
  for (auto num : E) cout << num << " ";
  cout << endl;
  cout << x << " " << y << endl;
  return 0;
}
