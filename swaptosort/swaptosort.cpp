#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi P;

int find(int n) {
  if (P[n] == -1) return n;
  return P[n] = find(P[n]);
}

int main() {
  int n, k, a, b;
  cin >> n >> k;
  P = vi(n, -1);
  while (k--) {
    cin >> a >> b;
    --a, --b;
    int ra = find(a), rb = find(b);
    if (ra != rb) P[rb] = ra;
  }
  bool f = true;
  a = 0, b = n - 1;
  while (a < b) {
    if (find(a) != find(b)) {
      f = false;
      break;
    }
    ++a, --b;
  }
  cout << (f ? "Yes" : "No") << endl;
  return 0;
}
