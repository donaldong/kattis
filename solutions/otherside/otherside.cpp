#include <bits/stdc++.h>
using namespace std;

bool solve(int w, int s, int c, int k) {
  if (!k) return false;
  if (!s) return true;
  if (!w && !c) return true;
  if (w + s + c <= k) return true;
  if (w + s < k || w + c < k || s + c < k) return true;
  return (
    s <= k && w + c <= 2 * k
  ) || (
    w + c <= k && s <= 2 * k
  );
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int w, s, c, k;
  cin >> w >> s >> c >> k;
  printf("%s\n", solve(w, s, c, k) ? "YES" : "NO");
  return 0;
}
