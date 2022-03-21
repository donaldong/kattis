#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

ll MOD = 1e9 + 7;

int size_of_clique(vll &D) {
  int empty_nodes = 0;
  for (ll d : D) if (!d) ++empty_nodes;
  int k = D.size() - empty_nodes - 1;
  int res = 0;
  for (ll d : D) {
    if (!d) continue;
    if (d != k) return -1;
    ++res;
  }
  return res;
}

ll sum_of_combinatiion(int k) {
  vll C = {1, 1};
  for (int i = 0; i < k - 1; ++i) {
    vll C2(C.size() + 1, 1);
    for (size_t i = 1; i < C.size(); ++i) {
      C2[i] = (C[i] + C[i - 1]) % MOD;
    }
    C = C2;
  }
  return (C[k - 1] + 1) % MOD;
}

int main() {
  int n, m;
  cin >> n >> m;
  vll D(n, 0);
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ++D[a], ++D[b];
  }
  int k = size_of_clique(D);
  if (k < 0) cout << 0 << endl;
  else if (k == 0) cout << D.size() + 1 << endl;
  else cout << sum_of_combinatiion(k) << endl;
  return 0;
}
