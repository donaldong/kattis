#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;

int MAXN = 501;
v3i DP;

bool solve(int b, int d, int h) {
  if (b == 1 && d == 1) return 0;
  auto &res = DP[b][d][h];
  if (res >= 0) return res;
  if (h) {
    for (int i = 1; i < d; ++i) {
      if (solve(b, i, !h)) {
        if (solve(b, d - i, h)) return res = 1;
      } else {
        if (!solve(b, d - i, !h)) return res = 1;
      }
    }
  } else {
    for (int i = 1; i < b; ++i) {
      if (solve(i, d, !h)) {
        if (solve(b - i, d, h)) return res = 1;
      } else {
        if (!solve(b - i, d, !h)) return res = 1;
      }
    }
  }
  return res = 0;
}

int main() {
  int T, b, d;
  string start;
  cin >> T;
  DP.assign(MAXN, v2i(MAXN, vi(2, -1)));
  while (T--) {
    cin >> b >> d >> start;
    printf(
      "%s %s win\n",
      start.c_str(),
      solve(b, d, start[0] == 'H') ? "can" : "cannot"
    );
  }
  return 0;
}
