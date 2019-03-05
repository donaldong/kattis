#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int solve(const vi &H) {
  for (size_t i = 0; i < H.size(); ++i) {
#ifdef DEBUG
    printf("%zu: %d\n", i, H[i]);
#endif
    if (H[i] >= i + 1) continue;
    return i;
  }
  return H.size();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  vi H(n);
  for (int i = 0; i < n; ++i) cin >> H[i];
  sort(H.rbegin(), H.rend());

  printf("%d\n", solve(H));
  return 0;
}
