#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int main() {
  int n, a, src;
  cin >> n;
  v2i GT(n);
  vi dist(n, n + 1), deg(n, 0), H(n), dest(n, -1), res(n, -1);
  queue<tuple<int, int>> Q;
  for (int i = 0, j; i < n; ++i) {
    cin >> j;
    if (j < 0) {
      Q.emplace(i, i), dist[i] = 0;
    } else {
      GT[j].push_back(i);
      ++deg[j];
    }
  }
  while (!Q.empty()) {
    tie(src, a) = Q.front(); Q.pop();
    for (int b : GT[a]) {
#ifdef DEBUG
      printf("%d => %d\n", a, b);
#endif
      if (dist[b] > dist[a] + 1) {
        dist[b] = dist[a] + 1;
        Q.emplace(src, b);
        if (!deg[b] && res[src] < 0) H[src] = dist[b];
      }
      if (H[src] == dist[b] && !deg[b]) {
        if (res[src] < 0) res[src] = b;
        else res[src] = min(res[src], b);
      }
      if (!deg[b]) dest[b] = src;
    }
  }

#ifdef DEBUG
  printf("dist:\n");
  for (int i = 0; i < n; ++i) printf("%d ", dist[i]);
  printf("\ndest:\n");
  for (int i = 0; i < n; ++i) printf("%d ", dest[i]);
  printf("\nres:\n");
  for (int i = 0; i < n; ++i) printf("%d ", res[i]);
  printf("\n");
#endif

  cin >> n;
  while (n--) {
    int i;
    cin >> i;
    printf("%d\n", res[dest[i]]);
  }
  return 0;
}
