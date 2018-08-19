#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ld = long double;

struct node {
  string name;
  ull q;

  node() {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<node> N(n);
  for (int i = 0; i < n; ++i) {
    cin >> N[i].q >> N[i].name;
    N[i].q *= i + 1;
  }
  stable_sort(N.begin(), N.end(), [](const node &a, const node &b) {
    return a.q > b.q;
  });
  for (int i = 0; i < m; ++i) cout << N[i].name << endl;
  return 0;
}
