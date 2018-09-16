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
  int k = r + c;
  if (k >= AC.size()) {
    k -= AC.size() - 1;
    if (AC[k]) return false;
    AC[k] = true;
  } else {
    if (AR[k]) return false;
    AR[k] = true;
  }
  return true;
}

void print(vb &v) {
  cout << endl;
  for (auto e : v) cout << e << " ";
  cout << endl;
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
