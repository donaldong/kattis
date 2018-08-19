#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct node {
  string name;
  ll q;

  node() {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<node> N(n);
  for (int i = 0; i < n; ++i) {
    ll f;
    cin >> f >> N[i].name;
    N[i].q = f;
    N[i].q *= i;
  }
  stable_sort(N.begin(), N.end(), [](const node &a, const node &b) {
    return a.q > b.q;
  });
  for (int i = 0; i < m; ++i) cout << N[i].name << endl;
  return 0;
}
