#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;

vi SC, SR;

bool solve(int r, int c) {
  printf("[%d %d] %d %d \n", r + 1, c + 1, SC[r], SR[c]);
  if (r < 0 || c < 0) return false;
  if (r + 1 < SR[c] || c + 1 < SC[r]) return false;
  if (r == 0 && SC[0] <= c + 1) return true;
  if (c == 0 && SR[0] <= r + 1) return true;
  if (SC[r] && SR[c]) {
    bool f = true;
    --SC[r];
    f = f && solve(r, c - 1);
    ++SC[r];
    --SR[c];
    f = f && solve(r - 1, c);
    ++SR[c];
    if (f) return true;
  }
  return solve(r - 1, c) && solve(r, c - 1);
}

int main() {
  int n, m;
  cin >> n >> m;
  SC = vi(n), SR = vi(m);
  for (auto &num : SC) cin >> num;
  for (auto &num : SR) cin >> num;
  cout << (solve(n - 1, m - 1) ? "Yes" : "No") << endl;
  return 0;
}
