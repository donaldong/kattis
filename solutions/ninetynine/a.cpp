#include <bits/stdc++.h>
using namespace std;
array<array<int, 100>, 2> DP;

int dfs(int i, int p) {
  if (i == 99) return p;
  if (i > 99) return 1-p;
  if (DP[p][i] >= 0) return DP[p][i];
  bool willWin = (dfs(i+1, 1-p) != 1-p) && (dfs(i+2, 1-p) != 1-p);
#ifdef DEBUG
  if (p == 0 && willWin) printf("will win at %d\n", i);
#endif
  return DP[p][i] = willWin ? p : 1-p;
}

int main() {
  for (auto& arr : DP) arr.fill(-1);
  printf("1\n");
  fflush(stdout);
  int i;
  while (cin >> i) {
    if (i+1 == 99 || i+2 == 99) {
      printf("99\n");
      fflush(stdout);
      break;
    }
    printf("%d\n", dfs(i+1, 0) == 0 ? i+1 : i+2);
    fflush(stdout);
  }
  return 0;
}
