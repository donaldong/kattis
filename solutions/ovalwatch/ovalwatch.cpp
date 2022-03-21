#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<tuple<int, int>> vt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, l, h;
  cin >> n >> k;
  vi C(n);
  vt L(k);
  for (int i = 0; i < n; ++i) C[i] = i;
  for (int i = 0; i < k; ++i) {
    cin >> l >> h;
    L[i] = {h, l};
  }
  sort(L.begin(), L.end());
  for (int i = k; i-- > 0;) {
    tie(h, l) = L[i];
    swap(C[l], C[l + 1]);
  }
  for (int i = 0; i < n; ++i) printf("%d ", C[i]);
  printf("\n");
  return 0;
}
