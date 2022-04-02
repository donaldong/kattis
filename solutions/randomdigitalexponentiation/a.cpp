/**
 * @date        2022-04-01
 * @tags        math, dfs
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
string N;
vi dfs(int v, int i) {
  int d = N[i]-'0';
  ll p = 1;
  for (int k = 0; p <= v; p *= d, ++k) {
    if ((v-p)%10) continue;
    if (i+1 == N.size()) {
      if (v==p) return {k};
      continue;
    }
    auto res = dfs((v-p)/10, i+1);
    if (!res.empty()) {
      res.push_back(k);
      return res;
    }
  }
  return {};
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int b;
  cin >> N >> b;
  reverse(N.begin(), N.end());
  auto res = dfs(b,0);
  for (int i : res) printf("%d ", i);
  printf("\n");
  return 0;
}
