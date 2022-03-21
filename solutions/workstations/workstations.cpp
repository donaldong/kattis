#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int> ti;
typedef vector<int> vi;
typedef vector<ti> vti;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, a, s;
  cin >> n >> m;
  vti N;
  N.reserve(2 * n);
  for (int i = 0; i < n; ++i) {
    cin >> a >> s;
    N.emplace_back(a, i);
    N.emplace_back(a + s - 1, i + n);
  }
  sort(N.begin(), N.end());

  int res = 0, j;
  multiset<int> S;
  for (size_t i = 0; i < N.size(); ++i) {
    tie(a, j) = N[i];
#ifdef DEBUG
    printf("%zu: %d %d\n", i, a, j);
#endif
    if (j < n) {
      auto itr = S.lower_bound(a);
      if (itr != S.end()) {
#ifdef DEBUG
        printf("saved after %d\n", *itr);
#endif
        ++res;
        S.erase(itr);
      }
    } else S.insert(a + m + 1);
  }
  printf("%d\n", res);
  return 0;
}
