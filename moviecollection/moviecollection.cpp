#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define LSB(i) (i & -i)
vi st;

int sum(int i) {
  int res = 0;
  for (; i > 0; i-= LSB(i)) res += st[i];
  return res;
}

void add(int i, int v) {
  for (; i < st.size(); i += LSB(i)) st[i] += v;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int m, r, k;
    cin >> m >> r;
    st.assign(m + r + 1, 0);
    vi T(m);
    for (int i = 0; i < m; ++i) T[i] = i + r + 1, add(T[i], 1);
    for (int i = 0; i < r; ++i) {
      cin >> k, --k;
      printf("%d ", sum(T[k]) - 1);
      add(T[k], -1), T[k] = r - i, add(T[k], 1);
    }
    printf("\n");
  }
  return 0;
}
