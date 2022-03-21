#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int N, d;
vi st;

#define LSB(i) (i & -i)

int sum(int i) {
  int res = 0;
  for (; i > 0; i -= LSB(i)) res += st[i];
  return res;
}

void add(int i, int v) {
  for (; i < st.size(); i += LSB(i)) st[i] += v;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N;
  d = N / 2;
  if (N & 1) ++d;
  int end = 2 * d + N;
  st.assign(1 + end, 0);
  int k, f = 0, i = 0, a = 1, b = N;
  vi ord(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> k;
    ord[k] = d + i; add(d + i, 1);
  }
  while (i < N) {
    if (f) { // insert back
      printf("%d\n", sum(end - a + 1) - sum(ord[b]));
      add(ord[b], -1), add(end - a + 1, 1), --b;
    } else { // insert front
      printf("%d\n", sum(ord[a]) - a);
      add(ord[a], -1), add(a, 1), ++a;
    }
    f = !f, ++i;
  }
  return 0;
}
