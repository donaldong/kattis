#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;

vb MR, MC, AR, AC;

bool md(int r, int c) {
  int k = min(r, c);
  r -= k;
  c -= k;
  if (!r) {
    if (MC[c]) return false;
    MC[c] = true;
  } else {
    if (MR[r]) return false;
    MR[r] = true;
  }
  return true;
}

bool ad(int r, int c) {
  if (r >= c) {
    if (AC[c]) return false;
    AC[c] = true;
  } else {
    if (AR[r]) return false;
    AR[r] = true;
  }
  return true;
}

int main() {
  int n, r, c, m, a;
  cin >> n;
  vb R(n, false), C(n, false);
  MR = vb(n, false);
  MC = vb(n, false);
  AR = vb(n, false);
  AC = vb(n, false);
  bool f = true;
  while (n--) {
    cin >> r >> c;
    if (R[r] || C[c] || !md(r, c) || !ad(r, c)) f = false;
    R[r] = C[c] = true;
  }
  cout << (f ? "CORRECT" : "INCORRECT") << endl;
  return 0;
}
