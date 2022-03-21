#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int w, h, n, x, y, x2, y2, b;
  string name;
  while (cin >> w >> h) {
    cin >> n;
    v2i G(h + 1, vi(w + 1, 0));
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
      cin >> names[i] >> x >> y;
      b = 1 << i;
      G[y][x] += b;
      cin >> x2 >> y2;
      G[y2][x] -= b, G[y][x2] -= b, G[y2][x2] += b;
    }
    for (int i = 0; i < h; ++i) for (int j = 1; j < w; ++j) 
      G[i][j] += G[i][j - 1];
    for (int j = 0; j < w; ++j) for (int i = 1; i < h; ++i) 
      G[i][j] += G[i - 1][j];
#ifdef DEBUG
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cout << G[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
#endif
    vi count(n, 0);
    int tot = w * h, free_space = 0, contested = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        b = G[i][j];
        if (!b) {
          ++free_space;
          continue;
        }
        int lsb = b & (-b);
        if (b - lsb) {
          ++contested;
          continue;
        }
        int k = 0;
        while (lsb) ++k, lsb >>= 1;
        ++count[k - 1];
      }
    }
    printf("Total %d\n", tot);
    printf("Unallocated %d\n", free_space);
    printf("Contested %d\n", contested);
    for (int i = 0; i < n; ++i) {
      printf("%s %d\n", names[i].c_str(), count[i]);
    }
    printf("\n");
  }
  return 0;
}
