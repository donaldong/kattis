/**
 * @date        2022-03-26
 * @tags        data structure, priority queue, segment tree, rational number
 * @difficulty  1900
 */
#include <bits/stdc++.h>
using namespace std;
struct Rat {
  long long a, b;
  Rat(long long a, long long b): a(abs(a)), b(abs(b)) {}
  bool operator < (const Rat & other) const {
    return a * other.b < other.a * b;
  }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;
  vector < long long > P(N), V(N);
  vector < int > tMin(N * 4, INT_MAX), tMax(N * 4, INT_MIN);
  vector < bool > crashed(N, false);
  for (int i = 0; i < N; ++i) cin >> P[i] >> V[i];

  using FuncBuild = function < void(int, int, int) > ;
  FuncBuild buildMin = [ & ](int v, int tl, int tr) -> void {
    if (tl == tr) {
      tMin[v] = tl;
    } else {
      int tm = (tl + tr) / 2;
      buildMin(v * 2, tl, tm);
      buildMin(v * 2 + 1, tm + 1, tr);
      tMin[v] = min(tMin[v * 2], tMin[v * 2 + 1]);
    }
  };

  FuncBuild buildMax = [ & ](int v, int tl, int tr) -> void {
    if (tl == tr) {
      tMax[v] = tl;
    } else {
      int tm = (tl + tr) / 2;
      buildMax(v * 2, tl, tm);
      buildMax(v * 2 + 1, tm + 1, tr);
      tMax[v] = max(tMax[v * 2], tMax[v * 2 + 1]);
    }
  };

  using FuncQuery = function < int(int, int, int, int, int) > ;
  FuncQuery queryMin = [ & ](int v, int tl, int tr, int l, int r) -> int {
    if (l > r) return INT_MAX;
    if (l == tl && r == tr) return tMin[v];
    int tm = (tl + tr) / 2;
    return min(queryMin(v * 2, tl, tm, l, min(r, tm)), queryMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  };

  FuncQuery queryMax = [ & ](int v, int tl, int tr, int l, int r) -> int {
    if (l > r) return INT_MIN;
    if (l == tl && r == tr) return tMax[v];
    int tm = (tl + tr) / 2;
    return max(queryMax(v * 2, tl, tm, l, min(r, tm)), queryMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  };

  using FuncUpdate = function < void(int, int, int, int, int) > ;
  FuncUpdate updateMin = [ & ](int v, int tl, int tr, int pos, int new_val) -> void {
    if (tl == tr) {
      tMin[v] = new_val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) updateMin(v * 2, tl, tm, pos, new_val);
    else updateMin(v * 2 + 1, tm + 1, tr, pos, new_val);
    tMin[v] = min(tMin[v * 2], tMin[v * 2 + 1]);
  };

  FuncUpdate updateMax = [ & ](int v, int tl, int tr, int pos, int new_val) -> void {
    if (tl == tr) {
      tMax[v] = new_val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) updateMax(v * 2, tl, tm, pos, new_val);
    else updateMax(v * 2 + 1, tm + 1, tr, pos, new_val);
    tMax[v] = max(tMax[v * 2], tMax[v * 2 + 1]);
  };

  auto getTime = [ & ](int l, int r) -> Rat {
    return Rat(P[r] - P[l], V[l] - V[r]);
  };

  using Tuple = tuple < Rat, int, int > ;
  priority_queue < Tuple, vector < Tuple > , greater < Tuple >> pq;
  for (int i = 1; i < N; ++i) {
    pq.emplace(getTime(i - 1, i), i - 1, i);
  }
  buildMin(1, 0, N - 1), buildMax(1, 0, N - 1);
  while (!pq.empty()) {
    auto[_, l, r] = pq.top();
    pq.pop();
    if (crashed[l] || crashed[r]) continue;
    if (V[l] - V[r] <= 0) continue; // never gonna crash
    int l2 = queryMax(1, 0, N - 1, 0, l - 1);
    int r2 = queryMin(1, 0, N - 1, r + 1, N - 1);
    updateMax(1, 0, N - 1, l, INT_MIN), updateMax(1, 0, N - 1, r, INT_MIN);
    updateMin(1, 0, N - 1, l, INT_MAX), updateMin(1, 0, N - 1, r, INT_MAX);
    crashed[l] = crashed[r] = true;
    if (0 <= l2 && l2 < N && 0 <= r2 && r2 < N) pq.emplace(getTime(l2, r2), l2, r2);
  }
  int cnt = 0;
  for (bool f: crashed) if (!f) ++cnt;
  printf("%d\n", cnt);
  for (int i = 0; i < N; ++i) if (!crashed[i]) printf("%d ", i + 1);
  printf("\n");
  return 0;
}
