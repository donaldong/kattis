#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
int INF = 1e8;
int DA[] = { 1,  0, -1, -2};
int DB[] = {-1, -1,  0,  0};
int DN[] = { 4,  1,  4,  2};
v3i DP;

int solve(int c, int a, int b) {
  if (a < 0 || b < 0) return INF;
  if (a == 0 && b == 0) return 8 * c;
  if (c == 0) return 0;
  if (DP[c][b][a] >= 0) return DP[c][b][a];
  int res = INF;
  for (int d = 0; d < 4; ++d) {
    res = min(res, solve(c - 1, a + DA[d], b + DB[d]) + DN[d]);
  }
  DP[c][b][a] = res;
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T, C, c, n, i, j, k;
  cin >> T;
  while (T--) {
    cin >> C >> i >> j >> k;
    DP.assign(C + 1, v2i(k + 1, vi(j + k + 1, -1)));
    printf("%d\n", solve(C, j, k));
  }
  return 0;
}
