#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<vs> v2s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, h, w;
  string line;
  cin >> n >> h >> w;
  v2s G(h, vs(w));
  while (n--) {
    for (int i = 0; i < h; ++i) {
      cin >> line;
      for (int j = 0; j < w; ++j) {
        G[i][j] += line[j];
      }
    }
  }
  unordered_set<string> S;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
    S.insert(G[i][j]);
  }
  printf("%lu\n", S.size());
  return 0;
}
