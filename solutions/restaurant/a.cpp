#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    if (!n) break;

    vector<int> pile{0, 0};
    int i = 0;
    while (n--) {
      string cmd;
      int v;
      cin >> cmd >> v;
      if (cmd[0] == 'D') {
        pile[i] += v;
        printf("DROP %d %d\n", i+1, v);
      } else {
        int j = 1-i;
        int d = min(pile[j], v);
        pile[j] -= d, v -= d;
        if (d) printf("TAKE %d %d\n", j+1, d);
        if (!v) continue;

        pile[j] = pile[i];
        pile[i] = 0;
        printf("MOVE %d->%d %d\n", i+1, j+1, pile[j]);

        pile[j] -= v;
        printf("TAKE %d %d\n", j+1, v);
      }
    }
    printf("\n");
  }
  return 0;
}
