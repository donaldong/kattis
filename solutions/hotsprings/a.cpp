/**
 * @date        2022-03-26
 * @tags        sorting, greedy
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;
  vector<int> T(N), res;
  res.reserve(N);
  for (int& t : T) cin >> t;
  sort(T.begin(), T.end());
  int lo = 0, hi = N-1;
  while (lo < hi) {
    res.push_back(T[lo++]);
    res.push_back(T[hi--]);
  }
  if (lo == hi) res.push_back(T[lo]);
  for (int i = N-1; i >= 0; --i) printf("%d ", res[i]);
  printf("\n");
  return 0;
}
